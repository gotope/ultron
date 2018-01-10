/*

 Copyright (c) 2018 Vardan Grigoryan (vardanator)

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
 OR OTHER DEALINGS IN THE SOFTWARE.

*/

#ifndef ULTRON_ARRAYS_BITARRAY_H
#define ULTRON_ARRAYS_BITARRAY_H

#include <cstddef>
#include <cstdint>
#include <limits>

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
        byte_array_ = new std::int_fast32_t[length_ / kBitsInType + kBitsInType];
    }




    ~BitArray() {
        delete [] byte_array_;
        byte_array_ = nullptr;
    }

private:
    std::size_t length_;
    std::int_fast32_t* byte_array_;
    std::int_fast32_t fallback_[];

private:
    static const int kMaxLength = 100 * 1024 * 1024; // 100Mb
    static const int kBitsInType = sizeof(std::int_fast32_t) * 8;
    static const int kMinLength = 10 * kBitsInType;
};

}

}

#endif
