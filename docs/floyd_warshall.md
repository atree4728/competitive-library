---
title: Floyd Warshall Algorithm / 負辺を許す全点対最短経路問題
documentation_of: //lib/graph/floyd_warshall.hpp
---

## 概要

Floyd Warshall 法は、低速ながら全点対最短経路問題(APSP; All Pair Shortest Path)を解くアルゴリズムである。

## 使い方

- `floyd_warshall(G)`: グラフ$G$について全点対最短経路問題を解く。 返り値の$_{(u,v)
  }$には頂点$u,v$間の最短経路（頂点$u,v$が連結でないなら`std::numeric_limits<T>::max()`）が格納される。 $G$上に負閉路が含まれる場合、空の`std::vector`が返る。

## 計算量

グラフ$G=(V,E)$について、$\mathcal{O}(\textbar V\textbar ^3)$。 余談だが、グラフがより疎な場合、全点を始点とした Dijkstra 法($\mathcal{O}(\textbar V\textbar\textbar E\textbar \log\textbar E)$)の方が高速になる場合がある。
