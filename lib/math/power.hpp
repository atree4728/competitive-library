#pragma once

#include "../include.hpp"

i64 power(i64 a, i64 b) {
    i64 ans = 1;
    for (; b; b >>= 1) {
        if (b & 1) ans *= a;
        a *= a;
    }
    return ans;
}

i64 power(i64 a, i64 b, int m) {
    a %= m;
    i64 ans = 1;
    for (; b; b >>= 1) {
        if (b & 1) (ans *= a) %= m;
        (a *= a) %= m;
    }
    return ans;
}
