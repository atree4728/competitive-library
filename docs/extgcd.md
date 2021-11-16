---
title: Extended Euclidean algorithm / 拡張 Euclid の互除法
documentation_of: //lib/math/extgcd.hpp
---

## 概要
$(a,b)\in\mathbb{Z}^2$ について、$ax+by=d$を満たす$(x,y)\in\mathbb{Z}^2$は、$\gcd(a,b)| d$のときのみに存在する。
この実装では、Euclid の互除法を用いて$\gcd(a,b)$を求めると同時に$(x,y)$を持つことで、$(x,y)\in\mathbb{Z}^2\mathrm{s.t.}ax+by=\gcd(a,b)$を求める。

## 使い方
- `extgcd(a, b)`: $(x,y)\in\mathbb{Z}^2\mathrm{s.t.}ax+by=\gcd(a,b)$ を`pair`として返す。

## 計算量
Euclid の互除法と同じく$\mathcal{O}(\log \max(a,b))$。
