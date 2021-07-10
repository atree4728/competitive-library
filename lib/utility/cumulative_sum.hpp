#pragma once

#include "../include.hpp"

/**
 * @brief Partial Sum
 * @note construct in $O(N)$, query in $O(1)$ to return partial sum
 */

template<class T> class CumulativeSum1D {
    vector<T> v;

  public:
    CumulativeSum1D(vector<T> a):
        v(a.size() + 1, 0) {
        copy(begin(a), end(a), begin(v) + 1);
        for (size_t i = 1; i < v.size(); i++) v[i] += v[i - 1];
    }
    T operator()(int r) { return v[r]; }
    T operator()(int l, int r) { return v[r] - v[l]; }
    vector<T> raw() { return v; }
};
