---
title: Strongly Connected Components / 強連結成分分解
documentation_of: //lib/graph/strongly_connected_components.hpp
---

## 概要
重みなし有向グラフ$G=(V,E)$に対して、**強連結成分分解、Strongly Connected Components(SCC)**をする。
「$S \subset{V}$が強連結である」とは、「$\forall (u,v)\in S^2$について$u$から$v$に到達できる」ということであり、さらに他のどのような頂点集合を$S$に付け加えても強連結でなくなるとき、$S$を強連結成分と呼ぶ。
また、任意の$G$には、強連結集合からなる$V$の分割が存在し、その分割を強連結成分分解と呼ぶ。

## 使い方
- `StronglyConnectedComponents scc(graph)`: `graph`を強連結成分分解する。
- `operator[]`: 元のグラフの頂点番号に対して、縮約されたグラフの頂点番号を返す。
- `scc.contracted`: 縮約されたグラフを隣接リスト形式で返す。

## 計算量
$\mathcal{O}(V+E)$。
