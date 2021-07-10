#pragma once

#include "../include.hpp"

/**
 * @brief Partial Sum(2D)
 * @note construct in $O(N^2)$, query in $O(1)$ to return partial sum(2D)
 */

template<class T> class CumulativeSum2D {
    vector<vector<T>> vv;

  public:
    CumulativeSum2D(vector<vector<T>> a):
        vv(a.size() + 1, vector<int>(a[0].size() + 1, 0)) {
        for (size_t i = 0; i + 1 < vv.size(); i++) copy(begin(a[i]), end(a[i]), begin(vv[i + 1]) + 1);
        for (size_t i = 1; i < vv.size(); i++) {
            for (size_t j = 1; j < vv[i].size(); j++)
                vv[i][j] += vv[i][j - 1] + vv[i - 1][j] - vv[i - 1][j - 1];
        }
    }
    T operator()(size_t sx, size_t sy, size_t gx, size_t gy) { return vv[gx][gy] - vv[sx][gy] - vv[gx][sy] + vv[sx][sy]; }
    vector<vector<T>> raw() { return vv; }
};
