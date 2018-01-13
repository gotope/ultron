/**
 * Copyright (c) 2018, Vardan Grigoryan (vardanator)
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef ULTRON_ARRAYS_BITARRAY_H
#define ULTRON_ARRAYS_BITARRAY_H

#include <limits>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <iomanip>

#include "./../core/utility.h"

namespace ultron {

namespace arrays {

/*
 * bitarray, access each bit with subscript operator []
 * [] return 1 if bit is set, 0 if not
 * to set, use the same [] operator
 *
 * toggle(i) - toggles i-th bit (XOR)
 * invert(i) - invert i-th bit (NOT)
 * invert_all() - invert all bits
 * and(num) - AND
 * or(num) - OR
 * xor(num) - XOR
 * unset_all() - zero all bits
 * set_all() - set all bits
 */

class BitArray {
public:
    explicit BitArray(std::size_t length)
    {
        if (length > kMaxLength) {
            length_ = kMaxLength;
        } else if (length < kMinLength) {
            length_ = kMinLength;
        } else {
            length_ = length;
        }
        inner_array_size_ = length_ / kBitsInType + 1;
        byte_array_ = new std::int_fast32_t[inner_array_size_];
        std::memset(byte_array_, '\0', inner_array_size_ * kSizeOfType);
    }

    bool toggle(int i) {
        if (i < 0 || i > length_) return false;
        std::size_t inner_array_index = i / kBitsInType;
        std::size_t bit_offset  = i - (inner_array_index * kBitsInType);
        // toggle array's 'inner_array_index' element's 'bit_offset'th bit
        byte_array_[inner_array_index] ^= (1 << bit_offset);
        return (bool)(byte_array_[inner_array_index] & (1 << bit_offset));
    }

    void print() const {
        core::Utility::LogFastIntArrayBytes(byte_array_, inner_array_size_);
        std::cout << std::endl;
    }

    void printBits() const {
        core::Utility::LogFastIntArrayBits(byte_array_, inner_array_size_);
        std::cout << std::endl;
    }


    ~BitArray() {
        delete [] byte_array_;
        byte_array_ = nullptr;
    }

private:
    std::size_t length_;
    std::size_t inner_array_size_;
    std::int_fast32_t* byte_array_;
    std::int_fast32_t fallback_[];

private:
    static const int kMaxLength = 100 * 1024 * 1024; // 100Mb
    static const int kSizeOfType = sizeof(std::int_fast32_t);
    static const int kBitsInType = kSizeOfType * 8;
    static const int kMinLength = kBitsInType;
};

}

}

#endif
