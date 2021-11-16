#pragma once

#include <cassert>
#include <vector>
using namespace std;

template<class T> struct FenwickTree {
    size_t n;
    vector<T> data;

    FenwickTree() = default;
    FenwickTree(const size_t n): n(n), data(n, T{}) {}
    template<typename InputIterator> FenwickTree(InputIterator first, InputIterator last): n(last - first), data(n, T{}) {
        for (auto it = first; it != last; it++) this->add(it - first, *it);
    }
    T prefix_sum(size_t i) {
        T ret = 0;
        while (i > 0) {
            ret += data[i - 1];
            i -= i & -i;
        }
        return ret;
    }
    T sum(size_t l, size_t r) {
        assert(l <= r and r <= n);
        return prefix_sum(r) - prefix_sum(l);
    }
    void add(size_t i, T v) {
        assert(i < n);
        i++;
        while (i <= n) {
            data[i - 1] += v;
            i += i & -i;
        }
    }
};
