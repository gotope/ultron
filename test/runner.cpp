/*

 Copyright (c) 2018 Vardan Grigoryan (vardanator)

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
 OR OTHER DEALINGS IN THE SOFTWARE.

*/

#include <string>
#include <iostream>

#include "types.h"
#include "./arrays/bitarray.h"

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
}

void print_help() {
    std::cout << "Usage: './runner option', where option might be one of " << std::endl;
    std::cout << "\tbitarray - test bitarray" << std::endl;
}
