#pragma once

#include "../include.hpp"

/**
 * @brief 2D Partial Sum / 二次元累積和
 * @docs docs/partial_sum_2D.md
 */

template<class T> struct CumSum2D {
    vector<vector<T>> data;
    explicit CumSum2D(const vector<vector<T>> &a):
        data(size(a) + 1, vector<T>(size(a[0]) + 1, 0)) {
        static_assert(is_integral_v<T>);
        rep(i, size(data) - 1) copy(begin(a[i]), end(a[i]), begin(data[i + 1]) + 1);
        rep(i, 1, size(data)) rep(j, 1, size(data[i])) data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
    }
    T operator()(int sx, int sy, int gx, int gy) const { return data[gx][gy] - data[sx][gy] - data[gx][sy] + data[sx][sy]; }
};
