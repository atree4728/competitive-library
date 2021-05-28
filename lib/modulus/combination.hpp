#pragma once

#include <cassert>
#include <vector>

using namespace std;

#include "lib/modulus/modint.hpp"

/**
 *@brief combination on mod including nCk, nHr, nPr
 */

template <int MOD>
class CombinationTable {
    vector<Modint<MOD>> fact, ifact;

   public:
    CombinationTable<MOD>(int n) : fact(n + 1), ifact(n + 1) {
        assert(1 <= n and n < MOD);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; i--) ifact[i - 1] = ifact[i] * i;
    }

    Modint<MOD> c(int n, int r) {
        if (r < 0 or r > n) return 0;
        return fact[n] * ifact[r] * ifact[n - r];
    }

    Modint<MOD> h(int n, int r) { return c(n + r - 1, r); }

    Modint<MOD> p(int n, int r) {
        if (r < 0 or r > n) return 0;
        return fact[n] * ifact[n - r];
    }
};
