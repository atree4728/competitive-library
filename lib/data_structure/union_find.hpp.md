---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/graph/kruskal.hpp
    title: Kruskal's Algorithm
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_1_A.test.cpp
    title: test/aoj/DSL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.test.cpp
    title: test/aoj/GRL_2_A.test.cpp
  - icon: ':x:'
    path: test/library-checker/unionfind.test.cpp
    title: test/library-checker/unionfind.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/union_find.md
    document_title: Union Find
    links: []
  bundledCode: "#line 2 \"lib/data_structure/union_find.hpp\"\n\n#line 2 \"lib/include.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_NULL, _2,\
    \ _3, name, ...) name\n#define rep1(i, n) for (remove_const_t<remove_reference_t<decltype(n)>>\
    \ i = 0; i < (n); i++)\n#define rep2(i, a, b) for (remove_const_t<remove_reference_t<decltype(b)>>\
    \ i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)\n\
    using size_type = size_t;\n#line 4 \"lib/data_structure/union_find.hpp\"\n\n/**\n\
    \ * @brief Union Find\n * @docs docs/union_find.md\n */\n\nstruct UnionFind {\n\
    \    size_type n;\n    vector<int> node;\n    explicit UnionFind(const size_type\
    \ n):\n        n(n), node(n, -1) {}\n    bool unite(size_type u, size_type v)\
    \ {\n        u = root(u), v = root(v);\n        if (u == v) return false;\n  \
    \      if (node[u] > node[v]) swap(u, v);\n        node[u] += node[v];\n     \
    \   node[v] = (int)u;\n        return true;\n    }\n    size_type root(size_type\
    \ v) { return node[v] < 0 ? v : node[v] = (int)root(node[v]); }\n    size_type\
    \ size(size_type v) { return (size_type)-node[root(v)]; }\n    bool same(size_type\
    \ u, size_type v) { return root(u) == root(v); }\n    vector<vector<size_type>>\
    \ group() {\n        vector ret(n, vector<size_type>{});\n        rep(i, n) ret[root(i)].push_back(i);\n\
    \        ret.erase(remove_if(begin(ret), end(ret), [&](const auto &ri) { return\
    \ empty(ri); }));\n        return ret;\n    }\n};\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief Union Find\n\
    \ * @docs docs/union_find.md\n */\n\nstruct UnionFind {\n    size_type n;\n  \
    \  vector<int> node;\n    explicit UnionFind(const size_type n):\n        n(n),\
    \ node(n, -1) {}\n    bool unite(size_type u, size_type v) {\n        u = root(u),\
    \ v = root(v);\n        if (u == v) return false;\n        if (node[u] > node[v])\
    \ swap(u, v);\n        node[u] += node[v];\n        node[v] = (int)u;\n      \
    \  return true;\n    }\n    size_type root(size_type v) { return node[v] < 0 ?\
    \ v : node[v] = (int)root(node[v]); }\n    size_type size(size_type v) { return\
    \ (size_type)-node[root(v)]; }\n    bool same(size_type u, size_type v) { return\
    \ root(u) == root(v); }\n    vector<vector<size_type>> group() {\n        vector\
    \ ret(n, vector<size_type>{});\n        rep(i, n) ret[root(i)].push_back(i);\n\
    \        ret.erase(remove_if(begin(ret), end(ret), [&](const auto &ri) { return\
    \ empty(ri); }));\n        return ret;\n    }\n};\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/data_structure/union_find.hpp
  requiredBy:
  - lib/graph/kruskal.hpp
  timestamp: '2021-09-29 20:09:01+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/DSL_1_A.test.cpp
  - test/aoj/GRL_2_A.test.cpp
  - test/library-checker/unionfind.test.cpp
documentation_of: lib/data_structure/union_find.hpp
layout: document
title: Union Find
---

## 概要

Union Find はグラフの連結成分についての情報を非常に高速に管理するデータ構造である。

## 使い方

- `UnionFind uf(n)`: $n$頂点の空グラフについての Union Find を構築する。
- `uf.unite(u, v)`: 頂点$u$と$v$を連結にする。もともと連結だったならば`false`、そうでないなら`true`を返す。
- `uf.root(u)`: 頂点$u$の連結成分の代表元を返す。
- `uf.size(u)`: 頂点$u$の連結成分の大きさを返す。
- `uf.same(u, v)`: 頂点$u$と頂点$v$が連結かどうかを返す。

## 計算量

構築は$\mathcal{O}(n)$、それ以外は$\alpha(n)$を Ackermann 関数$Ack(n,n)$の逆数として$\mathcal{O}(\alpha(n))$。 これは、Union by size
による併合の工夫（高さをたかだか$(\log n)$で抑える）、path compression による経路圧縮が両方行われているためであり、片方のみだと$\mathcal{O}(\log n)$となる。
