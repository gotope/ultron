/**
 * Copyright (c) 2018, Vardan Grigoryan (vardanator)
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef ULTRON_TEST_TYPES_H
#define ULTRON_TEST_TYPES_H

namespace ultron {

namespace tests {

struct Types {
    static std::string BIT_ARRAY;
    static std::string BIT_BOARD;
    static std::string CIRCULAR_BUFFER;
};

std::string Types::BIT_ARRAY = "bitarray";
std::string Types::BIT_BOARD = "bitboard";
std::string Types::CIRCULAR_BUFFER = "circular-buffer";

}

}

#endif // ULTRON_TEST_TYPES_H
