---
title: Union Find
documentation_of: //lib/data_structure/union_find.hpp
---

## 概要

Union Find はグラフの連結成分についての情報を非常に高速に管理するデータ構造である。

## 使い方

- `UnionFind uf(n)`: $n$頂点の空グラフについての Union Find を構築する。
- `uf.unite(u, v)`: 頂点$u$と$v$を連結にする。もともと連結だったならば`false`、そうでないなら`true`を返す。
- `uf.root(u)`: 頂点$u$の連結成分の代表元を返す。
- `uf.size(u)`: 頂点$u$の連結成分の大きさを返す。
- `uf.same(u, v)`: 頂点$uと頂点$v$が連結かどうかを返す。

## 計算量

構築は$\mathcal{O}(n)$、それ以外は$\alpha(n)$を Ackermann 関数$Ack(n,n)$の逆数として$\mathcal{O}(\alpha(n))$。 これは、Union by size
による併合の工夫（高さをたかだか$(\log n)$で抑える）、path compression による経路圧縮が両方行われているためであり、片方のみだと$\mathcal{O}(\log n)$となる。