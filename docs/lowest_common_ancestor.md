---
title: Lowest Common Ancestor(Doubling, Binary Search) / 最近共通祖先
documentation_of: //lib/graph/lowest_common_ancestor.hpp
---

## 概要

木グラフを受け取り、頂点$u$と$v$の最近共通祖先を高速に求める。

## 使い方

- `LowestCommonAncestor lca(tree, r)`: 頂点$r$を根とした根付き木$tree$をもとに最近共通祖先を求めるための前処理をする。
- `lca(u, v)`(`operator()`): 頂点$u$と$v$の最近共通祖先の index を返す。
- `lca.dist(u, v)`: 頂点$u$と$v$の最短距離を返す。

## 計算量

構築には$\mathcal{O}(n\log n)$時間、そのほかに対しては$\mathcal{O}(\log n)$時間を要する。
