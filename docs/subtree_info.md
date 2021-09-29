---
title: Subtree Info / 部分木の情報
documentation_of: //lib/graph/subtree_info.hpp
---

## 概要

木グラフについて、各頂点についての深さ、親、部分木の大きさをまとめて求める。

## 使い方

- `SubtreeInfo info(tree, root)`: 根を`root`、として木`tree`について構築する。木は重み付き・重みなしに対応している。
- `info.parent(u)`: 頂点$u$の親。`root`の親は`-1`である。
- `info.size(u)`: 頂点$u$を根とした部分木の大きさ。
- `info.depth(u)`: 頂点$u$の深さ。

## 計算量

構築には$\mathcal{O}(N)$。クエリ$\mathcal{O}(1)$。
