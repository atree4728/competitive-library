---
title: Fenwick Tree / Binary Indexed Tree
documentation_of: //lib/data_structure/fenwick_tree.hpp
---

## 概要

Fenwick Tree は、可換 Monoid の列に対して、Prefix Sum、一点更新を高速に求めるデータ構造である。
また、可換群（Abelian 群）であるならば、Prefix Sum と逆元を用いて任意の区間和を求めることもできる。
この実装では抽象化は型（operator+ が必要）のみにとどめ、演算は加算を前提としている。

## 使い方

- `FenwickTree bit(n)`: 長さ`n`の単位元（`0`）からなる Fenwick Tree を構築する。
- `FenwickTree bit(a)`: `a`は`std::vector`とし、その列からなる Fenwick Tree を構築する。
- `operator(l, r)`: $\sum_{i \in [l, r)}a_{i}$ を求める。0-indexed。
- `add(i, v)`: i(0-indexed)番目の要素に `v` を加算する。

## 計算量

構築には$\mathcal{O}(N)$（列からの構築ではそれぞれに対して`add`が呼ばれる実装になっているため$\mathcal{O}(N \log N)$）。区間和・一点更新は$\mathcal{O}(\log N)$。
