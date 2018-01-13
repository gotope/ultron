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
        TestSetUnset();
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

    static void TestSetUnset() {
        try {
            ultron::arrays::BitArray b(100);
            std::cout << "Before set " << std::endl;
            b.printBits();
            std::cout << "Set 1, 5, 33, 49" << std::endl;
            b.set(1);
            b.set(5);
            b.set(33);
            b.set(49);
            b.printBits();
            std::cout << "Set completed, check the results above" << std::endl;
            std::cout << "Unset 1, 33, 20, 0" << std::endl;
            b.unset(1);
            b.unset(33);
            b.unset(20);
            b.unset(0);
            b.printBits();
            std::cout << "Unset completed, check the results above" << std::endl;
        } catch (...) {
            std::cout << "Set/unset - [FAIL]" << std::endl;
        }
    }

};

}

}

#endif // ULTRON_TEST_ARRAYS_BITARRAY_H
