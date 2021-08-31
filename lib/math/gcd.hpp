#pragma once

#include <type_traits>

#include "../include.hpp"

template<typename T> T gcd(T a, T b) {
    static_assert(is_integral<T>::value);
    while (a % b != 0) {
        T u = a % b;
        a = b;
        b = u;
    }
    return b;
}
