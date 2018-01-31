/**
 * Copyright (c) 2018, Vardan Grigoryan (vardanator)
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// TODO: level-medium
// http://epaperpress.com/sortsearch/download/skiplist.pdf

#ifndef ULTRON_LISTS_SKIP_LIST_H
#define ULTRON_LISTS_SKIP_LIST_H

#include <vector>

namespace ultron {
namespace lists {

template <typename T>
class Skiplist
{
protected:
    struct Node
    {
        T item;
        std::vector<Node*> forward;
    };
};

} // namespace lists
} // namespace ultron

#endif // ULTRON_LISTS_SKIP_LIST_H
