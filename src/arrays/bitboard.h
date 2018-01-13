/**
 * Copyright (c) 2018, Vardan Grigoryan (vardanator)
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef ULTRON_ARRAYS_BITBOARD_H
#define ULTRON_ARRAYS_BITBOARD_H

#include <cstddef>

#include "./../core/utility.h"

namespace ultron {

namespace arrays {

class BitBoard {
public:
    explicit BitBoard(std::size_t size) {
        if (size < kMinSize) {
            size_ = kMinSize;
        } else if (size > kMaxSize) {
            size_ = kMaxSize;
        } else {
            size_ = size;
        }

        inner_array_size_ = size_ / kBitsInType + 1;
        bit_board_ = new std::int_fast32_t*[size_];
        for (std::size_t ix = 0; ix < size_; ++ix) {
            bit_board_[ix] = new std::int_fast32_t[inner_array_size_];
            std::memset(bit_board_[ix], '\0', inner_array_size_ * kSizeOfType);
        }
    }

    ~BitBoard() {
        for (std::size_t ix = 0; ix < inner_array_size_; ++ix) {
            delete [] bit_board_[ix];
        }
        delete [] bit_board_;
        bit_board_ = nullptr;
    }

    void set(std::size_t i, std::size_t j) {
        if (i > size_ || j > size_) return;
        // leaving 'i' as is
        // calculating j's index and bit offset
        auto column_index_bit = GetEffectiveIndexAndBit_(j);
        bit_board_[i][column_index_bit.first] |= (1 << column_index_bit.second);
    }

    void unset(std::size_t i, std::size_t j) {
        if (i > size_ || j > size_) return;
        // leaving 'i' as is
        // calculating j's index and bit offset
        auto column_index_bit = GetEffectiveIndexAndBit_(j);
        bit_board_[i][column_index_bit.first] &= ~(1 << column_index_bit.second);
    }

    bool get(std::size_t i, std::size_t j) {
        if (i > size_ || j > size_) return false;
        // leaving 'i' as is
        // calculating j's index and bit offset
        auto column_index_bit = GetEffectiveIndexAndBit_(j);
        return (bit_board_[i][column_index_bit.first] & (1 << column_index_bit.second));
    }

    bool toggle(std::size_t i, std::size_t j) {
        return false;
    }

    void printBits() const {
        for (std::size_t ix = 0; ix < size_; ++ix) {
            std::cout << "[" << ix << "]:";
            core::Utility::LogFastIntArrayBits(bit_board_[ix], inner_array_size_);
        }
    }

    // helpers
private:
    std::pair<std::size_t, std::size_t> GetEffectiveIndexAndBit_(std::size_t i) {
        std::size_t inner_array_index = i / kBitsInType;
        std::size_t bit_offset  = i - (inner_array_index * kBitsInType);
        return std::make_pair(inner_array_index, bit_offset);
    }

private:
    std::int_fast32_t** bit_board_;
    std::size_t size_;
    std::size_t inner_array_size_;

private:
    static const std::size_t kMaxSize = 10 * 1024; // 10Kb each row, 100Mb overall (10K rows of 10Kb's)
    static const std::size_t kSizeOfType = sizeof(std::int_fast32_t);
    static const std::size_t kBitsInType = kSizeOfType * 8;
    static const std::size_t kMinSize = kBitsInType;
};

} // namespace arrays

} // namespace ultron

#endif // ULTRON_ARRAYS_BITBOARD_H
