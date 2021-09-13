---
title: Bellman-Ford Algorithm / 負辺を許す単一始点最短経路問題
documentation_of: //lib/graph/bellman_ford.hpp
---

## 概要

Bellman-Ford 法は Dijkstra 法よりは遅いが、負辺があってもよく、負閉路の検出も可能な、単一始点最短経路問題（SSSP; Single Source Shortest Path）を解くアルゴリズムである。

## 使い方

- `bellman_ford(G, r)`: グラフ$G$について、始点を$r$として最短経路長を求める。
  `G`は、辺の重みの型を`T`として`std::vector<std::vector<int, T>>`（辺の終点と重みのペア）として表現される。 返り値は`std::vector<T>`
  であり、$v$番目の要素は頂点$v$と$r$の最短経路長である。 $v$が$r$と連結でない場合には`std::numeric_limits<T>::max()`が最短経路長として処理される。
  また、グラフ$G$上に$r$と連結な負閉路が存在したときには空の`std::vector`を返す。

## 計算量

グラフ$G=(V,E)について、$$\mathcal{O}(\textbar V\textbar\textbar E\textbar)$。
