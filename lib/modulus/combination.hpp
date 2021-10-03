#pragma once

#include <cassert>
#include <vector>

/**
 * @brief Combination on mod
 * @note construct in $O(N)$, return $nCr$, $nHr$, $nPr$ in $O(1)$.
 */

template<class Modint> struct CombTable {
    std::vector<Modint> fact, ifact;
    CombTable(int n): fact(n + 1), ifact(n + 1) {
        assert(1 <= n);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; i--) ifact[i - 1] = ifact[i] * i;
    }
    Modint operator()(int n, int r) { return r < 0 or r > n ? 0 : fact[n] * ifact[r] * ifact[n - r]; }
    Modint H(int n, int r) { return operator()(n + r - 1, r); }
    Modint P(int n, int r) { return r < 0 or r > n ? 0 : fact[n] * ifact[n - r]; }
};
