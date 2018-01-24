/**
 * Copyright (c) 2018, Vardan Grigoryan (vardanator)
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef ULTRON_TEST_LISTS_DOUBLY_LINKED_LIST_H
#define ULTRON_TEST_LISTS_DOUBLY_LINKED_LIST_H

#include <iostream>

#include "./../../src/lists/doubly-linked-list.h"

namespace ultron {

namespace tests {

struct DoublyLinkedListTester
{
    static void RunAllTests()
    {
        TestInsertion();
    }

    static void TestInsertion()
    {
        std::cout << "PushFront 5, 6, 7: " << std::endl;
        ultron::lists::DoublyLinkedList<int> l;
        l.PushFront(5);
        l.PushFront(6);
        l.PushFront(7);
        l.Print();

        std::cout << "PushBack 5, 6, 7: " << std::endl;
        ultron::lists::DoublyLinkedList<double> l2;
        l2.PushBack(5.5);
        l2.PushBack(6.6);
        l2.PushBack(7.7);
        l2.Print();

        std::cout << "PushFront a, PushBack b, PushFront c, d, PushBack e, f: " << std::endl;
        ultron::lists::DoublyLinkedList<char> l3;
        l3.PushFront('a');
        l3.PushBack('b');
        l3.PushFront('c');
        l3.PushFront('d');
        l3.PushBack('e');
        l3.PushBack('f');
        l3.Print();
        std::cout << "Print reverse: " << std::endl;
        l3.Print(true);

        std::cout << "Insert a[0], b[1], c[2], d[1], e[2]: " << std::endl;
        ultron::lists::DoublyLinkedList<char> l4;
        l4.Insert('a', 0);
        l4.Print();
        l4.Insert('b', 1);
        l4.Print();
        l4.Insert('c', 2);
        l4.Print();
        l4.Insert('d', 1);
        l4.Print();
        l4.Insert('e', 2);
        l4.Print();

        std::cout << "Previous list, calling 2 RemoveFront(): " << std::endl;
        l4.RemoveFront();
        l4.RemoveFront();
        l4.Print();
        std::cout << "Previous list, calling 2 RemoveBack(): " << std::endl;
        l4.RemoveBack();
        l4.RemoveBack();
        l4.Print();

        std::cout << "Creating list 1, 2, 3, 4, 5: " << std::endl;
        ultron::lists::DoublyLinkedList<int> l5;
        l5.PushBack(1);
        l5.PushBack(2);
        l5.PushBack(3);
        l5.PushBack(4);
        l5.PushBack(5);
        l5.Print();
        std::cout << "Item at 3: " << l5.ItemAt(3) << std::endl;
        std::cout << "Removing pos 2: " << std::endl;
        l5.Remove(2);
        l5.Print();
        std::cout << "Removing pos 2: " << std::endl;
        l5.Remove(2);
        l5.Print();
        std::cout << "Removing pos 134: " << std::endl;
        l5.Remove(134);
        l5.Print();
        std::cout << "Removing pos 0:" << std::endl;
        l5.Remove(0);
        l5.Print();

        std::cout << "Item at 0: " << l5.ItemAt(0) << std::endl;
    }
};

} // namespace tests
} // namespace ultron

#endif // ULTRON_TEST_LISTS_DOUBLY_LINKED_LIST_H
