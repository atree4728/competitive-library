---
title: Rerooting DP / 全方位木 DP
documentation_of: //lib/graph/rerooting_dp.hpp
---

木上の catamorphism を考える。
ある頂点を根とした catamorphism は自明な木 DP により $\mathcal{O}(N)$ で求まる。 これを各頂点から求めるとき、愚直な解法を用いると $\mathcal{O}(N^2)}$ だが、適切な工夫により $\mathcal{O}(N)$ に時間計算量を落とすことが可能である。

## Usage
- `rerooting_dp<value_type>(std::vector<std::vector<E>> const& g, F const& op, H const& id, G const& propagate) -> std::vector<value_type>`: `op`, `id`, `propagate` で全頂点からの catamorphism を求める。

## Reference
- https://rsk0315.github.io/library-rs/nekolib/graph/tree/struct.Tree.html
- https://qiita.com/keymoon/items/2a52f1b0fb7ef67fb89e
- https://ei1333.hateblo.jp/entry/2017/04/10/224413

