#pragma once

#include <vector>

using namespace std;

template <typename T>
class SimpleCombinationTable {
    vector<vector<T>> table;

   public:
    SimpleCombinationTable(int size) : table(size + 1, vector<T>(size + 1, 0)) {
        for (size_t i = 0; i <= size; i++) {
            table[i][0] = 1;
            table[i][i] = 1;
        }
        for (size_t j = 1; j <= size; j++) {
            for (size_t k = 1; k < j; k++) {
                table[j][k] = (table[j - 1][k - 1] + table[j - 1][k]);
            }
        }
    }
    T inline C(int n, int r) const {
        if (r < 0 or r > n) return 0;
        return table[n][min(n, n - r)];
    }
    T inline H(int n, int r) const { return table[n + r - 1][min(r, n - 1)]; }
};
