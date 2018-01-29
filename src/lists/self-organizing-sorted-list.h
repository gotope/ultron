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
        if (pos >= size_) {
            return;
        }
        Node* tmp;
        if (pos == 0) {
            tmp = head_;
            head_ = head_ ? head_->next : nullptr;
            if (head_) {
                head_->prev = nullptr;
            }
        } else if (pos == size_ - 1) {
            tmp = tail_;
            tail_ = tail_ ? tail_->prev : nullptr;
            if (tail_) {
                tail_->next = nullptr;
            }
        } else {
            std::size_t count = 0;
            tmp = head_;
            while (tmp != nullptr && count < pos) {
                tmp = tmp->next;
                ++count;
            }
            if (tmp->prev) {
                tmp->prev->next = tmp->next;
            }
            if (tmp->next) {
                tmp->next->prev = tmp->prev;
            }
        }
        RemoveSortedNode_(tmp);
        delete tmp;
    }

    const T GetAt(const std::size_t pos) { return T(); }

    const T Find(const T& item) { return T(); }

    void Traverse(void (*visit)(const T&), bool forward = true)
    {
        Node* cur = forward ? head_ : tail_;
        while (cur != nullptr) {
            visit(cur->item);
            cur = forward ? cur->next : cur->prev;
        }
    }

    void TraverseSorted(void (*visit)(const T&), bool asc = true)
    {
        Node* cur = asc ? asc_head_ : desc_head_;
        while (cur != nullptr) {
            visit(cur->item);
            cur = asc ? cur->greater : cur->lesser;
        }
    }

    std::vector<T> Range(const std::size_t from, const std::size_t to)
    {
        std::vector<T> items;
        items.reserve(size_);
        if (from > to) {
            return items;
        }
        std::size_t count = 0;
        Node* cur = head_;
        while (count < from) {
            if (cur == nullptr) {
                return items;
            }
            cur = cur->next;
            ++count;
        }
        while (cur != nullptr && count <= to) {
            items.push_back(cur->item);
            cur = cur->next;
            ++count;
        }
        return items;
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

    void RemoveSortedNode_(Node* tmp)
    {
        if (!tmp) return;
        if (tmp->smaller) {
            tmp->smaller->greater = tmp->greater;
        }
        if (tmp->greater) {
            tmp->greater->smaller = tmp->smaller;
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
