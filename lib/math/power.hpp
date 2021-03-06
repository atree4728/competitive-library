#pragma once

#include <cstdint>

constexpr intmax_t power(intmax_t a, intmax_t b) {
    intmax_t ans = 1;
    for (; b; b >>= 1) {
        if (b & 1) ans *= a;
        a *= a;
    }
    return ans;
}

