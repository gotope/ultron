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

    ~SelfOrganizingSortedList() {}

public:
    void InsertAt(const T& item, const std::size_t pos, bool priority = false) {}

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

        // sorting order
        if (!asc_head_) {
            asc_head_ = node;
            desc_head_ = node;
        } else {
            Node* cur = asc_head_;
            while (cur->bigger && node->item > cur->item) {
                cur = cur->bigger;
            }
            if (cur->smaller) {
                cur->smaller->bigger = node;
            }
            node->smaller = cur->smaller;
            cur->smaller = node;
            node->bigger = cur;
        }
    }

    void PushBack(const T& item) {}
    void RemoveAt(const std::size_t pos) {}
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

    void PrintSorted() const
    {
        Node* cur = asc_head_;
        while (cur) {
            std::cout << cur->item << std::endl;
            cur = cur->bigger;
        }
    }

protected:
    struct Node {
        explicit Node(const T& elem)
            : item(elem)
            , next(nullptr)
            , prev(nullptr)
            , smaller(nullptr)
            , bigger(nullptr)
        {}

        T item;
        Node* next;
        Node* prev;
        Node* smaller;
        Node* bigger;
    };

private:
    Node* head_;
    Node* tail_;
    Node* asc_head_;
    Node* desc_head_;
    std::size_t size_;
    T min_item_;
    T max_item_;
};

} // namespace lists
} // namespace ultron

#endif // ULTRON_LISTS_SELF_ORGANIZING_SORTED_LIST_H
