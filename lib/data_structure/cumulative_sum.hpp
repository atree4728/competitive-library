#pragma once

#include "../include.hpp"

/**
 * @brief Partial Sum
 * @note construct in $O(N)$, query in $O(1)$ to return partial sum
 */

template<class T> struct CumSum {
    vector<T> v;
    CumSum(vector<T> a):
        v(size(a) + 1, 0) {
        copy(begin(a), end(a), begin(v) + 1);
        rep(i, 1, size(v)) v[i] += v[i - 1];
    }
    T operator()(int r) { return v[r]; }
    T operator()(int l, int r) { return v[r] - v[l]; }
};
