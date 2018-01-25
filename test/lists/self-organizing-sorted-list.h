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
        TestInsertion();
    }

    static void TestInsertion()
    {
        ultron::lists::SelfOrganizingSortedList<int> s;
        s.PushFront(5);
        s.PushFront(6);
        s.Print();
        s.PrintSorted();
    }
};

} // namespace tests
} // namespace ultron

#endif // ULTRON_TEST_LISTS_SELF_ORGANIZING_SORTED_LIST_H
