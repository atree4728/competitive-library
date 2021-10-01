---
title: Lowlink / 橋・関節点
documentation_of: //lib/graph/lowlink.hpp
---

## 概要
無向連結グラフ$G=(V,E)$において、
- 「辺$(u,v)\in E$が**橋**である。」$\iff$「グラフ$G'=(V, E\{(u,v)})$の連結成分が$G$の連結成分よりも多い。」
- 「頂点$u\in V$が**関節点**である。」$\iff$「グラフ$G'=(V\{u}, E)$の連結成分が$G$の連結成分よりも多い。」
である。
いま、このグラフについて**深さ優先探索木; DFS Tree**（任意にとった$v \in V$から深さ優先探索したときの walk は$v$を根とした根付き木を成す）を考える。
深さ優先探索木に用いられていない辺を**後退辺**と呼ぶ。
このとき、$ord_u:=深さ優先探索における u \in V の訪問時刻$、$low_u:=\min {後退辺を高々 1 度だけ用いて到達することができる頂点の ord}$とし、後者を **Lowlink** と呼ぶ。
いま、
- $(u,v) \in E$が橋であるとき、$ord_u < low_v$を満たす。
- $u \in V$が関節点であるとき、深さ優先探索木の根については子が$2$つ以上、それ以外の頂点については$u \in V$のある子$v$について$ord_u \leq low_v$を満たす。
が成立する（ベースになるのは、「後退辺で遡っても$u$の訪問時刻より早い頂点に訪れることが不可能」）。

## 使い方
- `Lowlink ll(graph)`: `graph`について lowlink を構築する。
- `ll.bridge`: 橋$(u,v)$の集合を`std::vector<std::pair<std::size_t, std::size_t>>`として表現したメンバ。
- `ll.articulation`: 関節点$u$の集合を`std::vector<std::size_t>`として表現したメンバ。

## 計算量
$\mathcal{O}(|V|+|E|)$。
