---
title: Max flow(with Ford-Fulkerson) / 最大費用流
documentation_of: //lib/graph/ford_fulkerson.hpp
---

## 概要

Ford-Fulkerson 法を用いて最大費用流問題を解く。

## 使い方

- `FordFulkerson graph()`: 空グラフを定義する。
- `FordFulkerson graph(n)`: $n$頂点のグラフを定義する。
- `graph.add_edge(u, v, c)`: 頂点$u$から頂点$v$に容量$c$の辺を張る。
- `graph.size()`: グラフの頂点数を`std::size_t`で返す。
- `graph.max_flow(s, t)`: 始点$s$、終点$t$についての最大費用流問題を解く。

## 計算量

$f$を最大費用流としたときに、$\mathcal{O}(fE)$。一回の`find`で$\mathcal{O}(E)$を要し、かつそれによって暫定流量は1以上増えるため、`find`
の回数は$f$で抑えられるためである。このように「数値に関しては多項式時間ではあるが、実際には多項式時間では無い計算量」を**擬多項式時間**と呼ぶ。