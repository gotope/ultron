/**
 * Copyright (c) 2018, Vardan Grigoryan (vardanator)
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef ULTRON_TEST_ARRAYS_CIRCULAR_BUFFER_H
#define ULTRON_TEST_ARRAYS_CIRCULAR_BUFFER_H

#include <string>
#include <iostream>

#include "./../../src/arrays/circular-buffer.h"

namespace ultron {

namespace tests {

struct CircularBufferTester {
    static void RunAllTests() {
        TestCreation();
        TestInsertAndFetch();
    }

    static void TestCreation() {
        try {
            arrays::CircularBuffer<int> b(1000);
            std::cout << "CircularBuffer<int> Creation - [OK]" << std::endl;
            arrays::CircularBuffer<std::string> b2(1000);
            std::cout << "CircularBuffer<std::string> Creation - [OK]" << std::endl;
            arrays::CircularBuffer<CircularBufferTester> b3(2000);
            std::cout << "CircularBuffer<CircularBufferTester> Creation - [OK]" << std::endl;
        } catch(...) {
            std::cout << "CircularBuffer Creation - [FAIL]" << std::endl;
        }
    }

    static void TestInsertAndFetch() {
        try {
            arrays::CircularBuffer<int> b(10);
            b.Insert(4);
            b.Insert(5);
            b.Insert(14);
            std::cout << "Inserted 4, 5, 14" << std::endl;
            b.Print();
            if (b.Fetch() != 4) {
                std::cout << "Fetch 4 - [FAIL]" << std::endl;
            } else {
                std::cout << "Fetch 4 - [OK]" << std::endl;
            }
            if (b.Fetch() != 5) {
                std::cout << "Fetch 5 - [FAIL]" << std::endl;
            } else {
                std::cout << "Fetch 5 - [OK]" << std::endl;
            }
            b.Print();
            std::cout << "Inserting 8 numbers in sequence" << std::endl;
            for (int ix = 0; ix < 8; ++ix) b.Insert(ix);
            b.Print();
            std::cout << "Fetching 3 times in sequence" << std::endl;
            std::cout << "First: " << b.Fetch() << std::endl;
            std::cout << "Second: " << b.Fetch() << std::endl;
            std::cout << "Third: " << b.Fetch() << std::endl;
            std::cout << "Final result" << std::endl;
            b.Print();
        } catch (...) {
            std::cout << "Insert - [FAIL]" << std::endl;
        }
    }
};

} // tests
} // ultron

#endif
