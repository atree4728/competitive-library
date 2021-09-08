#pragma once

#include "../include.hpp"

template<typename T> i64 power(T a, T b) {
    static_assert(is_integral<T>::value, "T must be integer!");
    assert(0 <= b);
    i64 ret = 1;
    while (b > 0) {
        if (b & 1) ret *= a;
        b >>= 1;
        a *= a;
    }
    return ret;
}

template<typename T> i64 power(T a, T b, T m) {
    static_assert(is_integral<T>::value, "T must be integer!");
    assert(0 <= b && 1 <= m);
    i64 ret = 1;
    while (b > 0) {
        if (b & 1) (ret *= a) %= m;
        b >>= 1;
        (a *= a) %= m;
    }
    return ret;
}
