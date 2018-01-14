/**
 * Copyright (c) 2018, Vardan Grigoryan (vardanator)
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef ULTRON_ARRAYS_CIRCULAR_BUFFER_H
#define ULTRON_ARRAYS_CIRCULAR_BUFFER_H

#include <cstddef>
#include <stdexcept>

namespace ultron {

namespace arrays {

// Fixed size circular buffer, the size must be passed to constructor

template <typename T>
class CircularBuffer {
public:
    explicit CircularBuffer(std::size_t size)
        : start_(0)
        , end_(-1)
    {
        if (size > kMaxSize) {
            throw std::out_of_range("Your ambitions made you catch this exception");
        }
        size_ = size;
        buffer_ = new T[size_];
    }

    ~CircularBuffer() {
        delete [] buffer_;
        buffer_ = nullptr;
    }

    void Insert(const T& elem) {
        if (start_ == end_) {
            throw std::logic_error("Circular Buffer is full");
        }
        buffer_[start_] = elem;
        start_ = (start_ + 1) % size_;
    }

    const T Fetch() {
        if ((end_ + 1) % size_ == start_) {
            throw std::logic_error("Circular Buffer is empty");
        }
        end_ = (end_ + 1) % size_;
        return buffer_[end_];
    }

    void Print() const {
        for (std::size_t ix = (end_ + 1) % size_; ix != start_; ix = (ix + 1) % size_) {
            std::cout << buffer_[ix] << " ";
        }
        std::cout << std::endl;
    }

private:
    T* buffer_;
    std::size_t size_;
    std::size_t start_;
    std::size_t end_;

private:
    static const std::size_t kMaxSize = (100 * 1024 * 1024) / sizeof(T); // 100Mb
};

} // arrays
} // ultron

#endif
