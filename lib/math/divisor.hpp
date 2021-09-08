#pragma once

#include "../include.hpp"

/**
 * @brief Multiple Enumeration($O(√N)$)
 */

template<class T = i64> vector<T> divisor(T n) {
    vector<T> ret{};
    for (T p = 1; p * p <= n; p++) {
        if (n % p == 0) {
            ret.push_back(p);
            if (p * p != n) ret.push_back(n / p);
        }
    }
    sort(begin(ret), end(ret));
    return ret;
}