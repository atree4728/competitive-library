---
title: Dijkstra's Algorithm / 単一始点最短経路問題
documentation_of: //lib/graph/dijkstra.hpp
---

## 概要
Dijkstra 法は、Bellman Ford 法などよりも高速に動作する、負辺を許さない最短経路問題を解くアルゴリズム。
Tropical semiring ($\mathbb{R} \cup{\{\infty \}}, min, +, \infty, 0$) の上で動作することが知られている。

## 使い方
- `dijkstra(std::vector<std::vector<Tp<size_t, W>> const& g, size_t r)`:`g`上で頂点`r`からの最短経路問題を解く。`dijkstra(g, r)[v]`=$dist(r, v)$である。

## 計算量
$G=(V,E)$について`\mathcal{O}(E \log V)`。
