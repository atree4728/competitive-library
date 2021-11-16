#pragma once

#include <cassert>

constexpr intmax_t euler_phi(intmax_t n) {
    assert(n > 0);
    intmax_t ret = n;
    for (intmax_t i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ret -= ret / i;
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) ret -= ret / n;
    return ret;
}
