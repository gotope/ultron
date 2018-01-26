/**
 * Copyright (c) 2018, Vardan Grigoryan (vardanator)
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef ULTRON_LISTS_SELF_ORGANIZING_SORTED_LIST_H
#define ULTRON_LISTS_SELF_ORGANIZING_SORTED_LIST_H

#include <iostream>

namespace ultron {
namespace lists {

template <typename T>
class SelfOrganizingSortedList
{
public:
    SelfOrganizingSortedList()
        : head_(nullptr)
        , tail_(nullptr)
        , asc_head_(nullptr)
        , desc_head_(nullptr)
        , size_(0)
    {}

    ~SelfOrganizingSortedList()
    {
        Node* cur = head_;
        Node* tmp = cur;
        while (cur) {
            tmp = cur;
            cur = cur->next;
            delete tmp;
        }
    }

public:
    void InsertAt(const T& item, const std::size_t pos, bool priority = false)
    {
        if (pos == 0) {
            return PushFront(item);
        }
        if (pos >= size_) {
            return PushBack(item);
        }
        Node* node = new Node(item);
        std::size_t count = 0;
        Node* cur = head_;
        while (count != pos) {
            ++count;
            cur = cur->next;
        }
        cur->prev->next = node;
        node->prev = cur->prev;
        cur->prev = node;
        node->next = cur;
        ++size_;

        PutInSortedOrder_(node);
    }

    void PushFront(const T& item)
    {
        Node* node = new Node(item);
        node->next = head_;
        if (head_) {
            head_->prev = node;
        } else {
            tail_ = node;
        }
        head_ = node;
        ++size_;

        PutInSortedOrder_(node);
    }

    void PushBack(const T& item)
    {
        Node* node = new Node(item);
        node->prev = tail_;
        if (tail_) {
            tail_->next = node;
        } else {
            head_ = node;
        }
        tail_ = node;
        ++size_;

        PutInSortedOrder_(node);
    }

    void RemoveAt(const std::size_t pos)
    {
    }

    const T GetAt(const std::size_t pos) { return T(); }

    const T Find(const T& item) { return T(); }

    void Traverse(void (*visit)(const T&), bool forward = true) {}
    void TraverseSorted(void (*visit)(const T&), bool asc = true) {}
    std::vector<T> Range(const std::size_t from, const std::size_t to)
    {
        return std::vector<T>();
    }

    void Print() const
    {
        Node* cur = head_;
        while (cur) {
            std::cout << cur->item << std::endl;
            cur = cur->next;
        }
    }

    void PrintSorted(bool asc = true) const
    {
        Node* cur = asc ? asc_head_ : desc_head_;
        while (cur) {
            std::cout << cur->item << std::endl;
            cur = asc ? cur->greater : cur->lesser;
        }
    }

protected:
    struct Node {
        explicit Node(const T& elem)
            : item(elem)
            , next(nullptr)
            , prev(nullptr)
            , greater(nullptr)
            , lesser(nullptr)
        {}

        T item;
        Node* next;
        Node* prev;
        Node* greater;
        Node* lesser;
    };

private:
    void PutInSortedOrder_(Node* node)
    {
        if (!node) return;
        if (!asc_head_) {
            asc_head_ = node;
            desc_head_ = node;
            return;
        }

        Node* cur = asc_head_;
        while (cur->item < node->item && cur->greater) {
            cur = cur->greater;
        }
        if (cur->item < node->item) {
            node->greater = cur->greater;
            cur->greater = node;
            node->lesser = cur;
            if (!node->greater) {
                desc_head_ = node;
            }
        } else {
            node->lesser = cur->lesser;
            if (cur->lesser) {
                cur->lesser->greater = node;
            } else {
                asc_head_ = node;
            }
            node->greater = cur;
            cur->lesser = node;
        }
    }

private:
    Node* head_;
    Node* tail_;
    Node* asc_head_;
    Node* desc_head_;
    std::size_t size_;
};

} // namespace lists
} // namespace ultron

#endif // ULTRON_LISTS_SELF_ORGANIZING_SORTED_LIST_H
