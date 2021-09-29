#pragma once

#include "../include.hpp"

/**
 * @brief Segment Tree
 * @docs docs/segment_tree.md
 */

template<class Monoid> struct SegmentTree {
    using T = typename Monoid::T;
    size_type n;
    vector<T> node;
    explicit SegmentTree(const size_type n):
        n(n), node(n * 2, Monoid::id) {}
    explicit SegmentTree(const vector<T>& a):
        n(size(a)), node(n * 2, Monoid::id) {
        copy(begin(a), end(a), begin(node) + n);
        for (size_type i = n - 1; i--;) node[i] = Monoid::op(node[i * 2], node[i * 2 + 1]);
    };
    void update(size_type i, T val) { set(i, Monoid::op(node[i + n], val)); }
    void set(size_type i, T val) {
        assert(i < n);
        i += n;
        node[i] = val;
        while ((i /= 2) >= 1) node[i] = Monoid::op(node[i * 2], node[i * 2 + 1]);
    }
    T fold(size_type l, size_type r) {
        assert(l <= n and r <= n);
        if (l == 0 and r == n) return node[1];
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
    T& operator[](size_type i) {
        assert(i < n);
        return &node[i + n];
    }
};
