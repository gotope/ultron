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
    static std::string DYNAMIC_ARRAY;

    static std::string DOUBLY_LINKED_LIST;
    static std::string SELF_ORGANIZING_SORTED_LIST;
};

std::string Types::BIT_ARRAY = "bitarray";
std::string Types::BIT_BOARD = "bitboard";
std::string Types::CIRCULAR_BUFFER = "circular-buffer";
std::string Types::DYNAMIC_ARRAY = "dynamic-array";
std::string Types::DOUBLY_LINKED_LIST = "doubly-linked-list";
std::string Types::SELF_ORGANIZING_SORTED_LIST = "self-organizing-sorted-list";

} // namepsace tests
} // namespace ultron

#endif // ULTRON_TEST_TYPES_H
