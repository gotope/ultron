/**
 * Copyright (c) 2018, Vardan Grigoryan (vardanator)
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <string>
#include <iostream>
#include <unordered_map>

#include "types.h"
#include "./arrays/bitarray.h"
#include "./arrays/bitboard.h"
#include "./arrays/circular-buffer.h"
#include "./arrays/dynamic-array.h"

#include "./lists/doubly-linked-list.h"

void print_help();

int main(int argc, char** argv) {
    if (argc < 2) {
        print_help();
        return 1;
    }

    namespace Tests = ultron::tests;
    using TestTypes = Tests::Types;
    std::unordered_map<std::string, void (*)()> runners;
    runners[TestTypes::BIT_ARRAY] = Tests::BitArrayTester::RunAllTests;
    runners[TestTypes::BIT_BOARD] = Tests::BitBoardTester::RunAllTests;
    runners[TestTypes::CIRCULAR_BUFFER] = Tests::CircularBufferTester::RunAllTests;
    runners[TestTypes::DYNAMIC_ARRAY] = Tests::DynamicArrayTester::RunAllTests;
    runners[TestTypes::DOUBLY_LINKED_LIST] = Tests::DoublyLinkedListTester::RunAllTests;

    std::string test_type = argv[1];
    if (runners.count(test_type) == 0) {
        print_help();
        return 2;
    }
    runners[test_type]();

    return 0;
}

void print_help() {
    using TestTypes = ultron::tests::Types;
    std::cout << "Usage: './runner option', where option might be one of " << std::endl;
    std::cout << "\t" << TestTypes::BIT_ARRAY << " - test bitarray" << std::endl;
    std::cout << "\t" << TestTypes::BIT_BOARD << " - test bitboard" << std::endl;
    std::cout << "\t" << TestTypes::CIRCULAR_BUFFER << " - test circular buffer" << std::endl;
    std::cout << "\t" << TestTypes::DYNAMIC_ARRAY << " - test dynamic array" << std::endl;
    std::cout << "\t" << TestTypes::DOUBLY_LINKED_LIST << " - test doubly linked list" << std::endl;
}
