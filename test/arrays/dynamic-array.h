/**
 * Copyright (c) 2018, Vardan Grigoryan (vardanator)
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef ULTRON_TEST_ARRAYS_DYNAMIC_ARRAY_H
#define ULTRON_TEST_ARRAYS_DYNAMIC_ARRAY_H

#include <string>
#include <iostream>

#include "./../../src/arrays/dynamic-array.h"

namespace ultron {

namespace tests {

struct DynamicArrayTester {
    static void RunAllTests() {
        TestCreation();
        TestInsertion();
        TestIterators();
    }

    static void TestCreation() {
        try {
            arrays::DynamicArray<std::string> d;
            arrays::DynamicArray<int> d2(100);
            arrays::DynamicArray<double> d3(998877);
            std::cout << "DynamicArray creation - [OK]" << std::endl;
        } catch(...) {
            std::cout << "DynamicArray creation - [FAIL]" << std::endl;
        }
    }

    static void TestInsertion() {
        try {
            arrays::DynamicArray<int> d;
            d.PushBack(1);
            d.PushBack(2);
            d.PushBack(3);
            d.Print();
        } catch (...) {
            std::cout << "DynamicArray insertion - [FAIL]" << std::endl;
        }
    }

    static void TestIterators() {
        try {
            arrays::DynamicArray<int> d;
            d.PushBack(1);
            d.PushBack(2);
            d.PushBack(3);
            std::cout << "Initial DynamicArray " << std::endl;
            d.Print();
            arrays::DynamicArray<int>::iterator iter = d.Begin();
            std::cout << "value by iterator = " << *iter << std::endl;
            iter++;
            std::cout << "value by iterator after ++ = " << *iter << std::endl;
            std::cout << "Looping with iterators" << std::endl;
            arrays::DynamicArray<int>::iterator it = d.Begin();
            for ( ; it != d.End(); ++it) {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        } catch (...) {
            std::cout << "DynamicArray iterators - [FAIL]" << std::endl;
        }
    }
};

}
}

#endif // ULTRON_TEST_ARRAYS_DYNAMIC_ARRAY_H
