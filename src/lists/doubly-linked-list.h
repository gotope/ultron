/**
 * Copyright (c) 2018, Vardan Grigoryan (vardanator)
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef ULTRON_LISTS_DOUBLY_LINKED_LIST_H
#define ULTRON_LISTS_DOUBLY_LINKED_LIST_H

#include <iostream>

namespace ultron {

namespace lists {

template <typename T>
class DoublyLinkedList
{
public:
    struct Node {
        explicit Node(const T& elem)
            : item(elem)
            , next(nullptr)
            , prev(nullptr)
        {}
        T item;
        Node* next;
        Node* prev;
    };
public:
    DoublyLinkedList()
        : head_(nullptr)
        , tail_(nullptr)
        , size_(0)
    {}

    ~DoublyLinkedList()
    {
        Node* cur = head_;
        while (cur->next) {
            Node* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
    }

    void Insert(const T& elem, std::size_t pos)
    {
        if (pos == 0) {
            return PushFront(elem);
        }
        if (pos >= size_) {
            return PushBack(elem);
        }
        Node* node = new Node(elem);
        Node* cur = GetNodeAt_(pos);
        node->next = cur;
        node->prev = cur->prev;
        cur->prev->next = node;
        cur->prev = node;
        ++size_;
    }

    void PushFront(const T& elem)
    {
        Node* node = new Node(elem);
        if (head_) {
            head_->prev = node;
        } else {
            tail_ = node;
        }
        node->next = head_;
        head_ = node;
        ++size_;
    }

    void PushBack(const T& elem)
    {
        Node* node = new Node(elem);
        if (!head_) {
            head_ = node;
            tail_ = node;
        } else {
            tail_->next = node;
            node->prev = tail_;
            tail_ = node;
        }
        ++size_;
    }

    void Remove(std::size_t pos)
    {
        if (pos == 0) {
            return RemoveFront();
        }
        if (pos >= size_) {
            return RemoveBack();
        }
        Node* cur = GetNodeAt_(pos);
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        cur->next = nullptr;
        cur->prev = nullptr;
        delete cur;
        --size_;
    }

    void RemoveFront()
    {
        if (!head_) {
            return;
        }
        Node* tmp = head_;
        if (tmp->next) {
            tmp->next->prev = nullptr;
        }
        head_ = tmp->next;
        tmp->next = nullptr;
        delete tmp;
        --size_;
    }

    void RemoveBack()
    {
        if (!tail_) {
            return;
        }
        Node* tmp = tail_;
        if (tmp->prev) {
            tmp->prev->next = nullptr;
        }
        tail_ = tmp->prev;
        tmp->prev = nullptr;
        delete tmp;
        --size_;
    }

    const T ItemAt(std::size_t pos) const
    {
        if (pos >= size_) {
            throw std::out_of_range("Invalid position");
        }
        Node* cur = GetNodeAt_(pos);
        return cur->item;
    }

    std::size_t GetSize() const { return size_; }

public:
    void Traverse(void (*visit)(const T&), bool from_head = true) const
    {
        Node* cur = from_head ? head_ : tail_;
        while (cur) {
            visit(cur->item);
            cur = from_head ? cur->next : cur->prev;
        }
    }

    void Print(bool reverse = false)
    {
        Node* cur = reverse ? tail_ : head_;
        while (cur) {
            std::cout << cur->item << " ";
            cur = reverse? cur->prev : cur->next;
        }
        std::cout << std::endl;
    }

public:
    void Sort(bool asc = true) {}
    void Sort(bool (*comp)(const T&, const T&)) {}

private:
    Node* GetNodeAt_(std::size_t pos) const
    {
        // TODO: review needed
        std::size_t count = 0;
        Node* cur = nullptr;
        if (pos > size_ / 2) {
            cur = tail_;
            while (count != (size_ - pos)) {
                cur = cur->prev;
                ++count;
            }
        } else {
            cur = head_;
            while (count != pos) {
                cur = cur->next;
                ++count;
            }
        }
        return cur;
    }

private:
    Node* head_;
    Node* tail_;
    std::size_t size_;
};

} // namespace lists

} // namespace ultron

#endif // ULTRON_LISTS_DOUBLY_LINKED_LIST_H
