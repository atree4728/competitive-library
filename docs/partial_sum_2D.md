---
title: 2D Partial Sum / 二次元累積和
documentation_of: //lib/data_structure/partial_sum_2D.hpp
---

## 概要

二次元累積和。

## 使い方

- `CumSum2D sum(v)`: `v`の型を`std::vector<std::vector<T>>`（`T`は整数型）として二次元累積和を構築する。
- `sum(sx, sy, gx, gy)`: $\sum\limit_{i\in[sx,sy)}\sum\limit_{i\in[gx,gy)}a_ij$

## 計算量

構築に$\mathcal{O}(N^2)$。クエリは$\mathcal{O}(1)$。

