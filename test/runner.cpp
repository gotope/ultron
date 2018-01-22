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

    std::string test_type = argv[1];
    if (runners.count(test_type) == 0) {
        print_help();
        return 2;
    }
    runners[test_type]();

    return 0;
}

void print_help() {
    std::cout << "Usage: './runner option', where option might be one of " << std::endl;
    std::cout << "\tbitarray - test bitarray" << std::endl;
    std::cout << "\tbitboard - test bitboard" << std::endl;
    std::cout << "\tcircular-buffer - test circular buffer" << std::endl;
    std::cout << "\tdynamic-array - test dynamic array" << std::endl;
}
