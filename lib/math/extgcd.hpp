#pragma once

#include <cassert>
#include <numeric>
#include <utility>

/**
 * @brief Extended Euclid's Algorithm
 * @note return pair of minimum x, y s.t. ax + by = gcd(x, y)
 * @ref https://noshi91.hatenablog.com/entry/2019/04/01/184957
 */

constexpr std::pair<intmax_t, intmax_t> extgcd(intmax_t a, intmax_t b) {
    intmax_t s = a, xs = 1, ys = 0, t = b, xt = 0, yt = 1;
    while (s % t != 0) {
        const intmax_t tmp = s / t,
                       u = s - t * tmp,
                       xu = xs - xt * tmp,
                       yu = ys - yt * tmp;
        s = t, xs = xt, ys = yt;
        t = u, xt = xu, yt = yu;
    }
    assert(t == std::gcd(a, b));
    return { xt, yt };
}
