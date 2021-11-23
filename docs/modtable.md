---
title: Combinatorics Table on mod
documentation_of: //lib/modular/modtable.hpp
---

前計算により二項係数などのクエリを高速に処理する。全てのメンバは`constexpr`化されている。

## Usage
- `Modtable<Modint>(int n)`: クエリの最大値を$n$とした constructor.
- `constexpr Modint fact(const int n)`: $n!$. $\mathcal{O}(1).
- `constexpr Modint fact_inv(const int n)`: $n!^{-1}$. $\mathcal{O}(1).
- `constexpr Modint perm(const int n, const int r)`: $_nP_r$. $\mathcal{O}(1).
- `constexpr Modint binom(const int n, const int r)`: $_nC_r$. $\mathcal{O}(1).
- `constexpr Modint homo(const int n, const int r)`: $_nH_r$. $\mathcal{O}(1).
