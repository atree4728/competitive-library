---
title: Topological Sort
documentation_of: //lib/graph/topological_sort.hpp
---

## 概要

与えられたグラフをトポロジカルソートする。 トポロジカルソートするとは、ある DAG(Directed Acyclic Graph) についてのトポロジカル順序$ord$があったときに、 任意の有向辺$(u,v)$について$ord_{u}<
ord_{v}$が成り立つような$ord$を求めることである。（違くない？）

## 使い方

- `topological_sort(graph)`: `graph`をトポロジカルソートした頂点の順列を返す。 グラフ$G$がトポロジカルソート可能であることと$G$が DAG であることは同値であるので、`graph`が DAG
  でなかった場合には空の`std::vector`を返す。

## 計算量

$\mathcal{O}(V+E)$。