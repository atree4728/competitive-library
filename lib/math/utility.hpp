#pragma once

#include <string>
#include <algorithm>
#include <map>

using namespace std;

/**
 * @brief math utility
 */

constexpr long long ceil(long long a, long long b) { return (a + b - 1) / b; }

long long digit_sum(long long n) {
    if (n < 10) return n;
    return digit_sum(n / 10) + n % 10;
}

long long mypow(long long a, int e) {
    long long ret = 1;
    while (e--) ret *= a;
    return ret;
}

bool is_prime(long long n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

map<long long, int> prime_factorize(long long n) {
    map<long long, int> factor;
    for (long long p = 2; p * p <= n; p++) {
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

vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long p = 1; p * p <= n; p++) {
        if (n % p == 0) {
            ret.push_back(p);
            if (p * p != n) ret.push_back(n / p);
        }
    }
    sort(begin(ret), end(ret));
    return ret;
}
