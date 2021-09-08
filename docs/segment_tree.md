---
title: Segment Tree
documentation_of: //lib/data_structure/segment_tree.hpp
---

## 概要

Segment Tree は Monoid の列に関する一点変更と区間積を高速に処理するデータ構造である。

## 使い方

まず、クラス`Monoid`を定義する必要がある。 Monoid とは、単位元$e$を持つ集合$S$と、写像$op:S\times S\rightarrow S$の組$(S, op, e)$のことである。 ただし、$\forall(
a,b,c)\in S^3. op(op(a,b),c)=op(a,op(b,c))$が満たされる必要がある。  
この代数的構造を以下のように`C++`プログラムで表現する（これは[noshi91さんの記事](https://noshi91.hatenablog.com/entry/2020/04/22/212649)を参考としている）。

```c++
// $({i | -2^31\leq<2^31},+,0)$を例とする。
struct Add {
    using T = int;
    static T op(int l, int r) { return l + r; }
    static inline T id = 0;
};
```

以下、上の`Monoid`を前提とする。

- `SegmentTree<Monoid> segtree(n)`: $n$個の`Monoid::id`から成る列で Segment Tree を構築する。
- `SegmentTree<Monoid> segtree(a)`: 長さ$n$の列$a$(\forall 0\leqi<$n. a_i\in T$)で Segment Tree を構築する。
- `segtree.set(i, val)`: $a_i$を$val$にする。
- `segtree.update(i, val)`: $a_i$を$op(a_i,val)$にする。
- `segtree.fold(l, r)`: $\bigodot_{i\in[l,r)}a_i$を計算する。
- `operator[]`は使用可能である。

## 計算量

構築には$\mathcal{O}(n\log n)$、`set`,`update`,`fold`には$\mathcal{O}(\log n)$、`operator[]`には$\mathcal{O}(1)$時間を要する。