#pragma once

#include "../include.hpp"

/**
 * @brief Prime Determination($O(√N)$)
 */

template<typename T = i64> bool is_prime(T n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    for (T i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}