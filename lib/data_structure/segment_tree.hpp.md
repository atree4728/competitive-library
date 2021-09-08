---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.test.cpp
    title: test/aoj/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B.test.cpp
    title: test/aoj/DSL_2_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/segment_tree.md
    document_title: Segment Tree
    links: []
  bundledCode: "#line 2 \"lib/data_structure/segment_tree.hpp\"\n\n#line 2 \"lib/include.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_1, _2,\
    \ _3, name, ...) name\n#define rep1(n) for (decltype(n) _tmp = 0; _tmp < (n);\
    \ _tmp++)\n#define rep2(i, n) for (decltype(n) i = 0; i < (n); i++)\n#define rep3(i,\
    \ a, b) for (decltype(b) i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\nstruct IOSetup {\n    IOSetup() noexcept {\n\
    \        ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n        cout\
    \ << fixed << setprecision(10);\n        cerr << fixed << setprecision(10);\n\
    \    }\n} iosetup;\ntemplate<class T> bool chmax(T &a, const T &b) { return a\
    \ < b and (a = b, true); }\ntemplate<class T> bool chmin(T &a, const T &b) { return\
    \ a > b and (a = b, true); }\nusing i64 = long long;\nusing f64 = long double;\n\
    #line 4 \"lib/data_structure/segment_tree.hpp\"\n\n/**\n * @brief Segment Tree\n\
    \ * @docs docs/segment_tree.md\n */\n\ntemplate<class Monoid> struct SegmentTree\
    \ {\n    using T = typename Monoid::T;\n    int n;\n    vector<T> node;\n    explicit\
    \ SegmentTree(const int n):\n        n(n), node(n * 2, Monoid::id) {}\n    explicit\
    \ SegmentTree(const vector<T> &a):\n        n(size(a)), node(n * 2, Monoid::id)\
    \ {\n        copy(begin(a), end(a), begin(node) + n);\n        for (int i = n\
    \ - 1; i >= 0; i--) node[i] = Monoid::op(node[i * 2], node[i * 2 + 1]);\n    };\n\
    \    void update(int i, T val) { set(i, Monoid::op(node[i + n], val)); }\n   \
    \ void set(int i, T val) {\n        i += n;\n        node[i] = val;\n        while\
    \ ((i /= 2) >= 1) node[i] = Monoid::op(node[i * 2], node[i * 2 + 1]);\n    }\n\
    \    T fold(int l, int r) {\n        T ret = Monoid::id;\n        l += n;\n  \
    \      r += n;\n        while (l < r) {\n            if (l % 2 == 1) ret = Monoid::op(ret,\
    \ node[l++]);\n            if (r % 2 == 1) ret = Monoid::op(ret, node[--r]);\n\
    \            l /= 2;\n            r /= 2;\n        }\n        return ret;\n  \
    \  }\n    T operator[](int i) { return node[i + n]; }\n};\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief Segment Tree\n\
    \ * @docs docs/segment_tree.md\n */\n\ntemplate<class Monoid> struct SegmentTree\
    \ {\n    using T = typename Monoid::T;\n    int n;\n    vector<T> node;\n    explicit\
    \ SegmentTree(const int n):\n        n(n), node(n * 2, Monoid::id) {}\n    explicit\
    \ SegmentTree(const vector<T> &a):\n        n(size(a)), node(n * 2, Monoid::id)\
    \ {\n        copy(begin(a), end(a), begin(node) + n);\n        for (int i = n\
    \ - 1; i >= 0; i--) node[i] = Monoid::op(node[i * 2], node[i * 2 + 1]);\n    };\n\
    \    void update(int i, T val) { set(i, Monoid::op(node[i + n], val)); }\n   \
    \ void set(int i, T val) {\n        i += n;\n        node[i] = val;\n        while\
    \ ((i /= 2) >= 1) node[i] = Monoid::op(node[i * 2], node[i * 2 + 1]);\n    }\n\
    \    T fold(int l, int r) {\n        T ret = Monoid::id;\n        l += n;\n  \
    \      r += n;\n        while (l < r) {\n            if (l % 2 == 1) ret = Monoid::op(ret,\
    \ node[l++]);\n            if (r % 2 == 1) ret = Monoid::op(ret, node[--r]);\n\
    \            l /= 2;\n            r /= 2;\n        }\n        return ret;\n  \
    \  }\n    T operator[](int i) { return node[i + n]; }\n};\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/data_structure/segment_tree.hpp
  requiredBy: []
  timestamp: '2021-09-08 23:15:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_B.test.cpp
  - test/aoj/DSL_2_A.test.cpp
documentation_of: lib/data_structure/segment_tree.hpp
layout: document
title: Segment Tree
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