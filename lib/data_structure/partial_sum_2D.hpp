#pragma once

#include <vector>

/**
 * @brief 2D Partial Sum / 二次元累積和
 * @docs docs/partial_sum_2D.md
 */

template<class T> struct CumSum2D {
    std::vector<std::vector<T>> data;
    explicit CumSum2D(const std::vector<std::vector<T>> &a): data(size(a) + 1, std::vector<T>(size(a[0]) + 1, 0)) {
        for (size_t i = 0; i + 1 < size(data); i++) copy(begin(a[i]), end(a[i]), begin(data[i + 1]) + 1);
        for (size_t i = 0; i + 1 < size(data); i++)
            for (size_t j = 0; j + 1 < size(data[i]); j++) data[i + 1][j + 1] += data[i][j + 1] + data[i + 1][j] - data[i][j];
    }
    T operator()(size_t sx, size_t sy, size_t gx, size_t gy) const { return data[gx][gy] - data[sx][gy] - data[gx][sy] + data[sx][sy]; }
};
