#pragma once

long long power(long long a, long long b) {
    long long ans = 1;
    for (; b; b >>= 1) {
        if (b & 1) ans *= a;
        a *= a;
    }
    return ans;
}

long long power(long long a, long long b, int m) {
    a %= m;
    long long ans = 1;
    for (; b; b >>= 1) {
        if (b & 1) (ans *= a) %= m;
        (a *= a) %= m;
    }
    return ans;
}
