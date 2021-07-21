#pragma once

#include "../include.hpp"

/**
 * @brief Combination without mod
 * @note construct in $O(N^2)$, return nCr / nHr in $O(1)$.
 */

template<typename T> struct SimpleCombinationTable {
    vector<vector<T>> table;
    SimpleCombinationTable(size_t size):
        table(size + 1, vector<T>(size + 1, 0)) {
        for (size_t i = 0; i <= size; i++) {
            table[i][0] = 1;
            table[i][i] = 1;
        }
        for (size_t i = 1; i <= size; i++) {
            for (size_t j = 1; j < i; j++) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]);
            }
        }
    }
    T operator()(int n, int r) {
        if (r < 0 or r > n) return 0;
        return table[n][min(n, n - r)];
    }
    T H(int n, int r) const { return table[n + r - 1][min(r, n - 1)]; }
};
