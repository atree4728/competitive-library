#pragma once

#include "../include.hpp"

/**
 * @brief Segment Tree
 * @docs docs/segment_tree.md
 */

template<class Monoid> struct SegmentTree {
    using T = typename Monoid::T;
    int n;
    vector<T> node;
    explicit SegmentTree(const int n):
        n(n), node(n * 2, Monoid::id) {}
    explicit SegmentTree(const vector<T> &a):
        n(size(a)), node(n * 2, Monoid::id) {
        copy(begin(a), end(a), begin(node) + n);
        for (int i = n - 1; i >= 0; i--) node[i] = Monoid::op(node[i * 2], node[i * 2 + 1]);
    };
    void update(int i, T val) { set(i, Monoid::op(node[i + n], val)); }
    void set(int i, T val) {
        i += n;
        node[i] = val;
        while ((i /= 2) >= 1) node[i] = Monoid::op(node[i * 2], node[i * 2 + 1]);
    }
    T fold(int l, int r) {
        T ret = Monoid::id;
        l += n;
        r += n;
        while (l < r) {
            if (l % 2 == 1) ret = Monoid::op(ret, node[l++]);
            if (r % 2 == 1) ret = Monoid::op(ret, node[--r]);
            l /= 2;
            r /= 2;
        }
        return ret;
    }
    T operator[](int i) { return node[i + n]; }
};