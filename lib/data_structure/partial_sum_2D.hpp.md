---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0560.test.cpp
    title: test/aoj/0560.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/partial_sum_2D.hpp\"\n\n#include <vector>\n\
    \ntemplate<class T> struct CumSum2D {\n    std::vector<std::vector<T>> data;\n\
    \    explicit CumSum2D(const std::vector<std::vector<T>> &a): data(size(a) + 1,\
    \ std::vector<T>(size(a[0]) + 1, 0)) {\n        for (size_t i = 0; i + 1 < size(data);\
    \ i++) copy(begin(a[i]), end(a[i]), begin(data[i + 1]) + 1);\n        for (size_t\
    \ i = 0; i + 1 < size(data); i++)\n            for (size_t j = 0; j + 1 < size(data[i]);\
    \ j++) data[i + 1][j + 1] += data[i][j + 1] + data[i + 1][j] - data[i][j];\n \
    \   }\n    T operator()(size_t sx, size_t sy, size_t gx, size_t gy) const { return\
    \ data[gx][gy] - data[sx][gy] - data[gx][sy] + data[sx][sy]; }\n};\n"
  code: "#pragma once\n\n#include <vector>\n\ntemplate<class T> struct CumSum2D {\n\
    \    std::vector<std::vector<T>> data;\n    explicit CumSum2D(const std::vector<std::vector<T>>\
    \ &a): data(size(a) + 1, std::vector<T>(size(a[0]) + 1, 0)) {\n        for (size_t\
    \ i = 0; i + 1 < size(data); i++) copy(begin(a[i]), end(a[i]), begin(data[i +\
    \ 1]) + 1);\n        for (size_t i = 0; i + 1 < size(data); i++)\n           \
    \ for (size_t j = 0; j + 1 < size(data[i]); j++) data[i + 1][j + 1] += data[i][j\
    \ + 1] + data[i + 1][j] - data[i][j];\n    }\n    T operator()(size_t sx, size_t\
    \ sy, size_t gx, size_t gy) const { return data[gx][gy] - data[sx][gy] - data[gx][sy]\
    \ + data[sx][sy]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/partial_sum_2D.hpp
  requiredBy: []
  timestamp: '2021-10-03 22:09:41+09:00'
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
- `sum(sx, sy, gx, gy)`: $\sum_{i\in[sx,sy)}\sum_{i\in[gx,gy)}a_{ij}$

## 計算量

構築に$\mathcal{O}(N^2)$。クエリは$\mathcal{O}(1)$。

