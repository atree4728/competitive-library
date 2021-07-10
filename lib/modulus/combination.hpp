#pragma once

#include "../include.hpp"
#include "lib/modulus/modint.hpp"

/**
 *@brief Combination on mod
 * @note construct in $O(N)$, return $nCr$, $nHr$, $nPr$ in $O(1)$
 */

template<int MOD> class CombinationTable {
    vector<Modint<MOD>> fact, ifact;

  public:
    CombinationTable<MOD>(int n):
        fact(n + 1), ifact(n + 1) {
        assert(1 <= n and n < MOD);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; i--) ifact[i - 1] = ifact[i] * i;
    }
    Modint<MOD> operator()(int n, int r) { return r < 0 or r > n ? 0 : fact[n] * ifact[r] * ifact[n - r]; }
    Modint<MOD> H(int n, int r) { return operator()(n + r - 1, r); }
    Modint<MOD> P(int n, int r) { return r < 0 or r > n ? 0 : fact[n] * ifact[n - r]; }
};
