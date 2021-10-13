---
title: Kruskal's Algorithm / Minimum Spanning Tree（最小全域木）
documentation_of: //lib/graph/kruskal.hpp
---

## 概要
無向グラフ$G=(V,E)$について、$G=(V,E')$が木になるような$E'\subset E$の中で$\sum_{e\in E'}weight(e)$が最小であるような$G$を返す。

## 使い方
- `kruskal(g)`: `g`の最小全域木の辺集合を`tuple<index, index, weight>`として返す。(辺重の総和は`accumulate(cbegin(kruskal(g)), cend(kruskal(g)), 0, [](T acc, auto e) { return acc + get<2>(e); })`)

## 計算量
$\mathcal{O}(|E|log|E)$。
