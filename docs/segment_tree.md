---
title: Segment Tree
documentation_of: //lib/data_structure/segment_tree.hpp
---

Segment Tree は Monoid の列に関する一点変更と区間積を高速に処理するデータ構造である。

## Usage

まず、クラス`Monoid`を定義する必要がある。 Monoid とは、単位元$e$を持つ集合$S$と、写像$op:S\times S\rightarrow S$の組$(S, op, e)$のことである。 ただし、$\forall(
a,b,c)\in S^3. op(op(a,b),c)=op(a,op(b,c))$が満たされる必要がある。  

```c++
// $({i | -2^31\leq<2^31},+,0)$を例とする。
struct Add {
    using operand_type = int; // operand の型
    static operand_type opearaion(operand_type lhs, operand_type rhs) { return lhs + rhs; } // fucntion<operand_type(operand_type, operand_type)> の二項演算
    static operand_type identity { return 0; } // 単位元
};
```

ref: https://noshi91.hatenablog.com/entry/2020/04/22/212649

以下、上の`Monoid`を前提とする。

- `SegmentTree<Monoid>(size_t n)`: 長さ$n$の`identity()`から成る列で Segment Tree を構築する。$\mathcal{O}(n\log n)$.
- `SegmentTree<Monoid>(InputIterator first, InputIterator last)`: iterator による constructor. $\mathcal{O}(n\log n)$.
- `void set(size_t i, operand_type val)`: $a_i$を$val$にする。
- `void update(size_t i, operand_type val)`: $a_i$を$\mathrm{operation}(a_i,val)$にする。$\mathcal{O}(\log n)$.
- `operand_type fold(size_t l, size_t r)`: $\bigodot_{i\in[l,r)}a_i. $\mathcal{O}(\log n)$.
- `operator[]`

