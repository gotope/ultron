/**
 * Copyright (c) 2018, Vardan Grigoryan (vardanator)
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef ULTRON_CORE_UTILITY_H
#define ULTRON_CORE_UTILITY_H

#include <string>
#include <cstddef>
#include <bitset>
#include <iostream>

namespace ultron {

namespace core {

struct Utility {
    static void Log(int n, const std::string& description = "") {
        std::cout << description << ": " << n << std::endl;
    }

    static void Log(const std::string& s, const std::string& description = "") {
        std::cout << description << ": " << s << std::endl;
    }

    static void LogFastIntBytes(std::int_fast32_t n, const std::string& description = "") {
        std::cout << description << ": ";
        char* p = (char*)&n;
        for (int ix = 0; ix < sizeof(std::int_fast32_t); ++ix) {
            std::cout << (int)(*(p + ix));
        }
        std::cout << std::endl;
    }

    static void LogFastIntArrayBytes(std::int_fast32_t* arr, std::size_t size, const std::string& description = "") {
        for (int ax = 0; ax < size; ++ax) {
            char* p = (char*)&arr[ax];
            for (int ix = 0; ix < sizeof(std::int_fast32_t); ++ix) {
                std::cout << (int)(*(p + ix));
            }
        }
        std::cout << std::endl;
    }

    static void LogFastIntArrayBits(std::int_fast32_t* arr, std::size_t size, const std::string& description = "") {
        for (int ax = 0; ax < size; ++ax) {
            char* p = (char*)&arr[ax];
            std::cout << "[" << ax << "]";
            for (int ix = 0; ix < sizeof(std::int_fast32_t); ++ix) {
                std::cout << std::bitset<8>(*(p + ix));
            }
        }
        std::cout << std::endl;
    }
};

}

}


#endif // ULTRON_CORE_UTILITY_H
