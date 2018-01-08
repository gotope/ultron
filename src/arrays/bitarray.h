#ifndef ULTRON_ARRAYS_BITARRAY_H
#define ULTRON_ARRAYS_BITARRAY_H

#include <cstddef>
#include <cstdint>
#include <limits>

namespace ultron {

namespace arrays {

/*
 * bitarray, access each bit with subscript operator []
 * [] return 1 if bit is set, 0 if not
 * to set, use the same [] operator
 *
 * toggle(i) - toggles i-th bit (XOR)
 * invert(i) - invert i-th bit (NOT)
 * invert_all() - invert all bits
 * and(num) - AND
 * or(num) - OR
 * xor(num) - XOR
 * unset_all() - zero all bits
 * set_all() - set all bits
 */

class bitarray {
public:
    explicit bitarray(std::size_t length)
        : m_size((length > k_max_length) ? k_max_length : length)
    {
        m_array = new () std::int_fast32_t[size];
    }

    ~bitarray() {
        delete [] m_array;
        m_array = nullptr;
    }

private:
    std::size_t m_size;
    std::int_fast32_t* m_array;
    std::int_fast32_t m_fallback[];

private:
    static const k_max_length = 100 * 1024 * 1024; // 100Mb
};

}

}

#endif
