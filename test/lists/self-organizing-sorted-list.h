/**
 * Copyright (c) 2018, Vardan Grigoryan (vardanator)
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef ULTRON_TEST_LISTS_SELF_ORGANIZING_SORTED_LIST_H
#define ULTRON_TEST_LISTS_SELF_ORGANIZING_SORTED_LIST_H

#include <iostream>

#include "./../../src/lists/self-organizing-sorted-list.h"

namespace ultron {

namespace tests {

struct SelfOrganizingSortedListTester
{
    static void RunAllTests()
    {
        //TestInsertion();
        TestAdvancing();
    }

    static void TestAdvancing()
    {
        ultron::lists::SelfOrganizingSortedList<double> s;
        s.PushFront(3.14);
        s.PushFront(2.22);
        s.PushBack(4.1);
        s.PushBack(4.5);
        s.InsertAt(1.3, 2);
        s.Print();
        std::cout << "Element at [4]: " << s.GetAt(4) << std::endl;
        s.Print();
        std::cout << "Element at [3]: " << s.GetAt(3) << std::endl;
        s.Print();
        std::cout << "Element at [2]: " << s.GetAt(2) << std::endl;
        s.Print();
        std::cout << "Element at [1]: " << s.GetAt(1) << std::endl;
        s.Print();
        std::cout << "Element at [0]: " << s.GetAt(0) << std::endl;
        s.Print();
        std::cout << "Find 1.3: " << s.Find(1.3) << std::endl;
        s.Print();
    }

    static void TestInsertion()
    {
        ultron::lists::SelfOrganizingSortedList<int> s;
        s.PushFront(5);
        s.PushFront(6);
        s.PushFront(7);
        s.PushFront(14);
        s.PushFront(22);
        s.PushFront(4);
        s.PushFront(5);
        s.Print();
        std::cout << "Sorted print:" << std::endl;
        s.PrintSorted();
        std::cout << "Desc Sorted print:" << std::endl;
        s.PrintSorted(false);

        ultron::lists::SelfOrganizingSortedList<double> d;
        d.PushBack(1.1);
        d.PushBack(2.2);
        d.PushBack(1.2);
        d.PushBack(1.3);
        d.PushBack(3.5);
        d.PushFront(2.8);
        d.Print();
        std::cout << "Print sorted: " << std::endl;
        d.PrintSorted();
        std::cout << "Insert 4.5 at pos 2:" << std::endl;
        d.InsertAt(4.5, 2);
        d.Print();
        std::cout << "Insert 9.4 at pos 4:" << std::endl;
        d.InsertAt(9.4, 4);
        d.Print();
        std::cout << "PrintSorted:" << std::endl;
        d.PrintSorted();
        std::cout << "Desc PrintSorted:" << std::endl;
        d.PrintSorted(false);
    }
};

} // namespace tests
} // namespace ultron

#endif // ULTRON_TEST_LISTS_SELF_ORGANIZING_SORTED_LIST_H
