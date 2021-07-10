#pragma once

#include "../include.hpp"

/**
 *@brief multiple enumeration
 * @note $O(NlogN)$
 */

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
