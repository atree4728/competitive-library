#pragma once

#include "../include.hpp"

/**
 * @brief Prime Factorize($O(√N)$)
 */

template<class T> map<T, int> prime_factorize(T n) {
    map<T, int> factor;
    for (auto p = 2; p * p <= n; p++) {
        if (n % p != 0) continue;
        int ex = 0;
        while (n % p == 0) {
            ex++;
            n /= p;
        }
        factor[p] = ex;
    }
    if (n != 1) factor[n] = 1;
    return factor;
}
