---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0560.test.cpp
    title: test/aoj/0560.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/partial_sum_2D.md
    document_title: "2D Partial Sum / \u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C"
    links: []
  bundledCode: "#line 2 \"lib/data_structure/partial_sum_2D.hpp\"\n\n#line 2 \"lib/include.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_1, _2,\
    \ _3, name, ...) name\n#define rep1(n) for (auto _tmp = 0; _tmp < (n); _tmp++)\n\
    #define rep2(i, n) for (auto i = 0; i < (n); i++)\n#define rep3(i, a, b) for (auto\
    \ i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n\
    template<class T> bool chmax(T &a, const T &b) { return a < b and (a = b, true);\
    \ }\ntemplate<class T> bool chmin(T &a, const T &b) { return a > b and (a = b,\
    \ true); }\nusing i64 = long long;\nusing f64 = long double;\n#line 4 \"lib/data_structure/partial_sum_2D.hpp\"\
    \n\n/**\n * @brief 2D Partial Sum / \u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C\n * @docs\
    \ docs/partial_sum_2D.md\n */\n\ntemplate<class T> struct CumSum2D {\n    vector<vector<T>>\
    \ data;\n    explicit CumSum2D(const vector<vector<T>> &a):\n        data(size(a)\
    \ + 1, vector<T>(size(a[0]) + 1, 0)) {\n        static_assert(is_integral_v<T>);\n\
    \        rep(i, size(data) - 1) copy(begin(a[i]), end(a[i]), begin(data[i + 1])\
    \ + 1);\n        rep(i, 1, size(data)) rep(j, 1, size(data[i])) data[i][j] +=\
    \ data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];\n    }\n    T operator()(int\
    \ sx, int sy, int gx, int gy) const { return data[gx][gy] - data[sx][gy] - data[gx][sy]\
    \ + data[sx][sy]; }\n};\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief 2D Partial\
    \ Sum / \u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C\n * @docs docs/partial_sum_2D.md\n\
    \ */\n\ntemplate<class T> struct CumSum2D {\n    vector<vector<T>> data;\n   \
    \ explicit CumSum2D(const vector<vector<T>> &a):\n        data(size(a) + 1, vector<T>(size(a[0])\
    \ + 1, 0)) {\n        static_assert(is_integral_v<T>);\n        rep(i, size(data)\
    \ - 1) copy(begin(a[i]), end(a[i]), begin(data[i + 1]) + 1);\n        rep(i, 1,\
    \ size(data)) rep(j, 1, size(data[i])) data[i][j] += data[i][j - 1] + data[i -\
    \ 1][j] - data[i - 1][j - 1];\n    }\n    T operator()(int sx, int sy, int gx,\
    \ int gy) const { return data[gx][gy] - data[sx][gy] - data[gx][sy] + data[sx][sy];\
    \ }\n};\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/data_structure/partial_sum_2D.hpp
  requiredBy: []
  timestamp: '2021-09-14 22:20:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0560.test.cpp
documentation_of: lib/data_structure/partial_sum_2D.hpp
layout: document
title: "2D Partial Sum / \u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C"
---

## 概要

二次元累積和。

## 使い方

- `CumSum2D sum(v)`: `v`の型を`std::vector<std::vector<T>>`（`T`は整数型）として二次元累積和を構築する。
- `sum(sx, sy, gx, gy)`: $\sum_{i\in[sx,sy)}\sum_{i\in[gx,gy)}a_ij$

## 計算量

構築に$\mathcal{O}(N^2)$。クエリは$\mathcal{O}(1)$。

