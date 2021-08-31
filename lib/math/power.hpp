#pragma once

#include <type_traits>

#include "../include.hpp"

template<typename T> T power(T a, T b) {
    static_assert(is_integral<T>::value, "T must be integer!");
    T ret = 1;
    while (b > 0) {
        if (b & 1) ret *= a;
        b >>= 1;
        a *= a;
    }
    return ret;
}
