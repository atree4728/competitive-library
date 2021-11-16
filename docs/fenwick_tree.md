---
title: Fenwick Tree / Binary Indexed Tree
documentation_of: //lib/data_structure/fenwick_tree.hpp
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

