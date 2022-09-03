---
title: Diameter of a Tree / 木の直径
documentation_of: //lib/graph/tree_diameter.hpp
---

## 概要

木グラフの直径（path 長の最大値）を求める。

## 使い方

- `tree_diameter(graph)`: 木`graph`の直径を構成する頂点列。

## 計算量

$\mathcal{O}(N)$。任意に頂点$v$を選び、その頂点からの最遠点を$u$、 $u$からの最遠点を$t$として、$dist(u,t)$が直径になるためである。
