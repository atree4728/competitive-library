---
title: Euler's totient function / $\varphi(n)$
documentation_of: //lib/math/euler_phi.hpp
---

## 概要
オイラーのトーシェント関数$\varphi(n)$は、正整数$n$に対して、 $n$と互いに素である$1$以上$n$以下の自然数の個数を与える数論的関数である。
$$\varphi(n)=\sum_{m \in [1, n] \cup{\mathbb{Z}}, gcd(n,m)=1}1$$
である。また、$\varphi(n)$は乗法的関数であることでも知られる。

## 使い方
- `euler_phi(n)`: $\varphi(n)$。

## 計算量
$\mathcal{O}(\sqrt{n})$。
