#pragma once

#include "../include.hpp"

/**
 * @brief Partial Sum(2D)
 * @note construct in $O(N^2)$, query in $O(1)$ to return partial sum(2D)
 */

template<class T> struct CumSum2D {
    vector<vector<T>> vv;
    explicit CumSum2D(vector<vector<T>> a):
        vv(size(a) + 1, vector<T>(size(a[0]) + 1, 0)) {
        rep(i, size(vv) - 1) copy(begin(a[i]), end(a[i]), begin(vv[i + 1]) + 1);
        rep(i, 1, size(vv)) rep(j, 1, size(vv[i])) vv[i][j] += vv[i][j - 1] + vv[i - 1][j] - vv[i - 1][j - 1];
    }
    T operator()(int sx, int sy, int gx, int gy) { return vv[gx][gy] - vv[sx][gy] - vv[gx][sy] + vv[sx][sy]; }
};
