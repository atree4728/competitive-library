---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B.test.cpp
    title: test/aoj/DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/point_add_range_sum.test.cpp
    title: test/library-checker/point_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/fenwick_tree.hpp\"\n\n#include <cassert>\n\
    #include <vector>\nusing namespace std;\n\ntemplate<class T> struct FenwickTree\
    \ {\n    size_t n;\n    vector<T> data;\n\n    FenwickTree() = default;\n    FenwickTree(const\
    \ size_t n): n(n), data(n, T{}) {}\n    template<typename InputIterator> FenwickTree(InputIterator\
    \ first, InputIterator last): n(last - first), data(n, T{}) {\n        for (auto\
    \ it = first; it != last; it++) this->add(it - first, *it);\n    }\n    T prefix_sum(size_t\
    \ i) {\n        T ret = 0;\n        while (i > 0) {\n            ret += data[i\
    \ - 1];\n            i -= i & -i;\n        }\n        return ret;\n    }\n   \
    \ T sum(size_t l, size_t r) {\n        assert(l <= r and r <= n);\n        return\
    \ prefix_sum(r) - prefix_sum(l);\n    }\n    void add(size_t i, T v) {\n     \
    \   assert(i < n);\n        i++;\n        while (i <= n) {\n            data[i\
    \ - 1] += v;\n            i += i & -i;\n        }\n    }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<class T> struct FenwickTree {\n    size_t n;\n    vector<T> data;\n\
    \n    FenwickTree() = default;\n    FenwickTree(const size_t n): n(n), data(n,\
    \ T{}) {}\n    template<typename InputIterator> FenwickTree(InputIterator first,\
    \ InputIterator last): n(last - first), data(n, T{}) {\n        for (auto it =\
    \ first; it != last; it++) this->add(it - first, *it);\n    }\n    T prefix_sum(size_t\
    \ i) {\n        T ret = 0;\n        while (i > 0) {\n            ret += data[i\
    \ - 1];\n            i -= i & -i;\n        }\n        return ret;\n    }\n   \
    \ T sum(size_t l, size_t r) {\n        assert(l <= r and r <= n);\n        return\
    \ prefix_sum(r) - prefix_sum(l);\n    }\n    void add(size_t i, T v) {\n     \
    \   assert(i < n);\n        i++;\n        while (i <= n) {\n            data[i\
    \ - 1] += v;\n            i += i & -i;\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/fenwick_tree.hpp
  requiredBy: []
  timestamp: '2021-11-16 22:42:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/point_add_range_sum.test.cpp
  - test/aoj/DSL_2_B.test.cpp
documentation_of: lib/data_structure/fenwick_tree.hpp
layout: document
title: Fenwick Tree / Binary Indexed Tree
---

Fenwick Tree は、可換 Monoid の列に対して、Prefix Sum、一点更新を高速に求めるデータ構造である。
また、可換群（Abelian 群）であるならば、Prefix Sum と逆元を用いて任意の区間和を求めることもできる。
この実装では抽象化は型（operator+ が必要）のみにとどめ、演算は加算を前提としている。

## Usage
- 0-indexed
- `FenwickTree(size_t n)`: `n`の単位元（`0`）からなる Fenwick Tree の constructor. $\mathcal{O}(N)$.
- `FenwickTree(InputIterator first, InputIterator last)`: iterator による constructor. $\mathcal{O}(N\log N)$. `T` を明示する必要がある。
- `T sum(size_t l, size_t r)`: $\sum_{i \in [l, r)}a_{i}$.$\mathcal{O}(\log N)$.
- `void add(size_t i, T v)`: `i`番目の要素に `v` を加算する。$\mathcal{O}(\log N)$.

