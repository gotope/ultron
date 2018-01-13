/**
 * Copyright (c) 2018, Vardan Grigoryan (vardanator)
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef ULTRON_TEST_ARRAYS_BITBOARD_H
#define ULTRON_TEST_ARRAYS_BITBOARD_H

#include <iostream>

#include "./../../src/arrays/bitboard.h"

namespace ultron {

namespace tests {

struct BitBoardTester {

    static void RunAllTests() {
        TestCreation();
        TestPrinting();
        TestSetUnset();
    }

    static void TestCreation() {
        try {
            ultron::arrays::BitBoard b(1000);
            std::cout << "BitArray b(1000); - [OK]" << std::endl;
        } catch (...) {
            std::cout << "BitArray b(1000); - [FAIL]" << std::endl;
        }
        try {
            ultron::arrays::BitBoard b(10000);
            std::cout << "BitArray b(10000); - [OK]" << std::endl;
        } catch (...) {
            std::cout << "BitArray b(10000); - [FAIL]" << std::endl;
        }
    }

    static void TestPrinting() {
        try {
            ultron::arrays::BitBoard b(100);
            b.printBits();
            std::cout << "Printing empty - [OK]" << std::endl;
        } catch (...) {
            std::cout << "Printing - [FAIL]" << std::endl;
        }
    }

    static void TestSetUnset() {
        try {
            ultron::arrays::BitBoard b(50);
            std::cout << "Before set " << std::endl;
            b.printBits();
            std::cout << "Set (1, 1), (5, 1), (5, 2), (5, 3), (33, 40), (49, 49)" << std::endl;
            b.set(1, 1);
            b.set(5, 1);
            b.set(5, 2);
            b.set(5, 3);
            b.set(33, 40);
            b.set(49, 49);
            b.printBits();
            std::cout << "Set completed, check the results above" << std::endl;
            std::cout << "Unset 1, 33, 20, 0" << std::endl;
            b.unset(1, 1);
            b.unset(5, 2);
            b.unset(33, 1);
            b.unset(20, 2);
            b.unset(0, 0);
            b.printBits();
            std::cout << "Unset completed, check the results above" << std::endl;
            std::cout << "Final results for (1, 1), (5, 2), (33, 1), (20, 2), (0, 0) bits" << std::endl;
            std::cout << "(0, 0): " << b.get(0, 0) << std::endl;
            std::cout << "(1, 1): " << b.get(1, 1) << std::endl;
            std::cout << "(5, 1): " << b.get(5, 1) << std::endl;
            std::cout << "(5, 2): " << b.get(5, 2) << std::endl;
            std::cout << "(5, 3): " << b.get(5, 3) << std::endl;
            std::cout << "(33, 40): " << b.get(33, 40) << std::endl;
            std::cout << "(49, 49): " << b.get(49, 49) << std::endl;
        } catch (...) {
            std::cout << "Set/unset - [FAIL]" << std::endl;
        }
    }

};

}

}

#endif // ULTRON_TEST_ARRAYS_BITBOARD_H
