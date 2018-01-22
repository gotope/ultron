/**
 * Copyright (c) 2018, Vardan Grigoryan (vardanator)
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef ULTRON_ARRAYS_DYNAMIC_VECTOR_H
#define ULTRON_ARRAYS_DYNAMIC_VECTOR_H

#include <stdexcept>

namespace ultron {

namespace arrays {

template <typename T>
class DynamicArray
{
public:
    struct iterator {
        explicit iterator(T* ptr = nullptr)
            : elem_ptr_(ptr)
        {}

        T& operator*() {
            return *elem_ptr_;
        }

        const T operator++(int) {
            T elem = *elem_ptr_;
            ++elem_ptr_;
            return elem;
        }

        T& operator++() {
            ++elem_ptr_;
            return *elem_ptr_;
        }

        bool operator!=(const iterator& rhs) {
            return elem_ptr_ != rhs.elem_ptr_;
        }

    private:
        T* elem_ptr_;
    };
public:
    explicit DynamicArray(std::size_t cap = kDefaultMinSize)
        : capacity_(cap)
        , size_(0)
    {
        inner_vector_ = new T[capacity_ + 1];
    }

    ~DynamicArray()
    {
        delete [] inner_vector_;
    }

    void PushBack(const T& elem) {
        if (size_ == capacity_) {
            Resize_(2 * capacity_);
        }
        inner_vector_[size_++] = elem;
    }

    T& operator[](std::size_t ix) {
        return inner_vector_[ix];
    }

    const T operator[](std::size_t ix) const {
        return inner_vector_[ix];
    }

    T& at(std::size_t ix) {
        if (ix < 0 || ix < size_) {
            throw std::out_of_range("what what!?");
        }
        return inner_vector_[ix];
    }

    const T at(std::size_t ix) const {
        if (ix < 0 || ix < size_) {
            throw std::out_of_range("what what!?");
        }
        return inner_vector_[ix];
    }

    void Print() const {
        for (std::size_t ix = 0; ix < size_; ++ix) {
            std::cout << inner_vector_[ix] << " ";
        }
        std::cout << std::endl;
    }

    iterator Begin() {
        iterator begin(inner_vector_);
        return begin;
    }

    iterator End() {
        iterator end(inner_vector_ + (capacity_ + 1));
        return end;
    }

private:
    void Resize_(std::size_t new_cap)
    {
        T* new_vector = new T[new_cap + 1];
        for (std::size_t ix = 0; ix < new_cap; ++ix) {
            new_vector[ix] = inner_vector_[ix];
        }
        delete [] inner_vector_;
        inner_vector_ = new_vector;
    }

private:
    T* inner_vector_;
    std::size_t size_;
    std::size_t capacity_;

private:
    static const std::size_t kDefaultMinSize = 2;
};

}
}

#endif
