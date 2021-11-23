---
title: Combinatorics Table on mod
documentation_of: //lib/modulus/modtable.hpp
---

前計算により二項係数などのクエリを高速に処理する。全てのメンバは`constexpr`化されている。
ref: https://noshi91.hatenablog.com/entry/2019/10/18/182935

## Usage
- `Modtable<Modint>(int n)`: クエリの最大値を$n$とした constructor. $\mathcal{O}(n)$.
- `constexpr Modint inv(const int n)`: $n^{-1}$. $\mathcal{O}(1)$.
- `constexpr Modint fact(const int n)`: $n!$. $\mathcal{O}(1)$.
- `constexpr Modint fact_inv(const int n)`: $n!^{-1}$. $\mathcal{O}(1)$.
- `constexpr Modint perm(const int n, const int r)`: $_nP_r$. $\mathcal{O}(1)$.
- `constexpr Modint binom(const int n, const int r)`: $_nC_r$. $\mathcal{O}(1)$.
- `constexpr Modint homo(const int n, const int r)`: $_nH_r$. $\mathcal{O}(1)$.
