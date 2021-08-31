#pragma once

#include <cassert>

#include "../include.hpp"

/**
 * @brief Extended Euclid's Algorithm
 * @note return pair of minimum x, y s.t. ax + by = gcd(x, y)
 * @ref https://noshi91.hatenablog.com/entry/2019/04/01/184957
 */

template<typename T> pair<T, T> extgcd(T a, T b) {
    static_assert(is_integral<T>::value);
    T s = a, xs = 1, ys = 0, t = b, xt = 0, yt = 1;
    while (s % t != 0) {
        T tmp = s / t,
          u = s - t * tmp,
          xu = xs - xt * tmp,
          yu = ys - yt * tmp;
        s = t, xs = xt, ys = yt;
        t = u, xt = xu, yt = yu;
    }
    assert(t == gcd(a, b));
    return {xt, yt};
}
