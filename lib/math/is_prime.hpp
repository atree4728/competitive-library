#pragma once

#include "../include.hpp"

/**
 *@brief prime determination
 * @note $O(√N)$
 */

auto is_prime(auto n) -> bool {
    if (n <= 1) return false;
    if (n == 2) return true;
    for (auto i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}