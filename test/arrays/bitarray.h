/**
 * Copyright (c) 2018, Vardan Grigoryan (vardanator)
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef ULTRON_TEST_ARRAYS_BITARRAY_H
#define ULTRON_TEST_ARRAYS_BITARRAY_H

#include <iostream>

#include "./../../src/arrays/bitarray.h"

namespace ultron {

namespace tests {

struct BitArrayTester {

    static void RunAllTests() {
        TestCreation();
        TestPrinting();
        TestToggle();
    }

    static void TestCreation() {
        try {
            ultron::arrays::BitArray b(1000);
            std::cout << "BitArray b(1000); - [OK]" << std::endl;
        } catch (...) {
            std::cout << "BitArray b(1000); - [FAIL]" << std::endl;
        }
        try {
            ultron::arrays::BitArray b(10000);
            std::cout << "BitArray b(10000); - [OK]" << std::endl;
        } catch (...) {
            std::cout << "BitArray b(10000); - [FAIL]" << std::endl;
        }
        /*
        try {
            ultron::arrays::BitArray
        }
        */
    }

    static void TestPrinting() {
        try {
            ultron::arrays::BitArray b(100);
            b.print();
            b.printBits();
            std::cout << "Printing empty - [OK]" << std::endl;
        } catch (...) {
            std::cout << "Printing - [FAIL]" << std::endl;
        }
    }

    static void TestToggle() {
        try {
            ultron::arrays::BitArray b(100);
            std::cout << "Before toggle " << std::endl;
            b.printBits();
            std::cout << "Toggle 1 result " << b.toggle(1) << std::endl;
            std::cout << "Toggle 5 result " << b.toggle(5) << std::endl;
            std::cout << "Toggle 40 result " << b.toggle(40) << std::endl;
            std::cout << "Toggle 49 result " << b.toggle(49) << std::endl;
            std::cout << "After toggling 1, 5, 40, 49 bits" << std::endl;
            b.printBits();
            std::cout << "Toggling test completed, check results above" << std::endl;
            std::cout << "Toggling back" << std::endl;
            std::cout << "Toggle 1 result " << b.toggle(1) << std::endl;
            std::cout << "Toggle 5 result " << b.toggle(5) << std::endl;
            std::cout << "Toggle 40 result " << b.toggle(40) << std::endl;
            std::cout << "Toggle 49 result " << b.toggle(49) << std::endl;
            b.printBits();
            std::cout << "Toggling back test completed, check results above" << std::endl;
        } catch (...) {
            std::cout << "Toggling - [FAIL]" << std::endl;
        }
    }

};

}

}

#endif // ULTRON_TEST_ARRAYS_BITARRAY_H
