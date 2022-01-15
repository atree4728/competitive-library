#pragma once

#include <cassert>
#include <vector>

template<class Monoid> struct SegmentTree {
    using operand_type = typename Monoid::operand_type;
    size_t n;
    std::vector<operand_type> node;
    SegmentTree(const size_t n): n(n), node(n * 2, Monoid::identity()) {}
    template<typename InputIterator> SegmentTree(InputIterator first, InputIterator last)
        : n(last - first), node(n * 2, Monoid::identity()) {
        copy(first, last, begin(node) + n);
        for (size_t i = n - 1; i--;) node[i] = Monoid::operation(node[i * 2], node[i * 2 + 1]);
    };
    void update(size_t i, operand_type val) { set(i, Monoid::operation(node[i + n], val)); }
    void set(size_t i, operand_type val) {
        assert(i < n);
        i += n;
        node[i] = val;
        while ((i /= 2) >= 1) node[i] = Monoid::operation(node[i * 2], node[i * 2 + 1]);
    }
    operand_type fold(size_t l, size_t r) {
        assert(l <= n and r <= n);
        if (l == 0 and r == n) return node[1];
        operand_type ret = Monoid::identity();
        l += n;
        r += n;
        while (l < r) {
            if (l % 2 == 1) ret = Monoid::operation(ret, node[l++]);
            if (r % 2 == 1) ret = Monoid::operation(ret, node[--r]);
            l /= 2;
            r /= 2;
        }
        return ret;
    }
    operand_type& operator[](size_t i) {
        assert(i < n);
        return &node[i + n];
    }
};
