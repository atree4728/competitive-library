#pragma once

#include <vector>

using namespace std;

/**
 * @brief Cumulative-Sum(1D)
 */
template <class T>
class CumulativeSum1D {
    vector<T> v;

   public:
    CumulativeSum1D(vector<T> a) : v(size(a) + 1, 0) {
        copy(begin(a), end(a), begin(v) + 1);
        for (size_t i = 1; i < size(v); i++) v[i] += v[i - 1];
    }
    inline T operator()(int r) const { return v[r]; }
    inline T operator()(int l, int r) const { return v[r] - v[l]; }
    vector<T> raw() { return v; }
};

/**
 * @brief Cumulative-Sum(2D)
 */
template <class T>
class CumulativeSum2D {
    vector<vector<T>> vv;

   public:
    CumulativeSum2D(vector<vector<T>> a)
        : vv(size(a) + 1, vector<int>(size(a[0]) + 1, 0)) {
        for (size_t i = 0; i + 1 < size(vv); i++)
            copy(begin(a[i]), end(a[i]), begin(vv[i + 1]) + 1);
        for (size_t i = 1; i < size(vv); i++) {
            for (size_t j = 1; j < size(vv[i]); j++)
                vv[i][j] += vv[i][j - 1] + vv[i - 1][j] - vv[i - 1][j - 1];
        }
    }
    inline T operator()(int sx, int sy, int gx, int gy) const {
        return vv[gx][gy] - vv[sx][gy] - vv[gx][sy] + vv[sx][sy];
    }
    vector<vector<T>> raw() { return vv; }
};
