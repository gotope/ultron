/**
 * Copyright (c) 2018, Vardan Grigoryan (vardanator)
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <string>
#include <iostream>

#include "types.h"
#include "./arrays/bitarray.h"
#include "./arrays/bitboard.h"
#include "./arrays/circular-buffer.h"

void print_help();

int main(int argc, char** argv) {
    if (argc < 2) {
        print_help();
        return 0;
    }
    std::string test_type = argv[1];
    if (test_type == ultron::tests::Types::BIT_ARRAY) {
        ultron::tests::BitArrayTester::RunAllTests();
    }

    if (test_type == ultron::tests::Types::BIT_BOARD) {
        ultron::tests::BitBoardTester::RunAllTests();
    }

    if (test_type == ultron::tests::Types::CIRCULAR_BUFFER) {
        ultron::tests::CircularBufferTester::RunAllTests();
    }
}

void print_help() {
    std::cout << "Usage: './runner option', where option might be one of " << std::endl;
    std::cout << "\tbitarray - test bitarray" << std::endl;
    std::cout << "\tbitboard - test bitboard" << std::endl;
}
