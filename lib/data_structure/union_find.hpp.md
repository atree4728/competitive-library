---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/graph/kruskal.hpp
    title: Kruskal's Algorithm
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_11_D.test.cpp
    title: test/aoj/ALDS1_11_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_1_A.test.cpp
    title: test/aoj/DSL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.test.cpp
    title: test/aoj/GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/unionfind.test.cpp
    title: test/library-checker/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/union_find.hpp\"\n\n#include <algorithm>\n\
    #include <vector>\n\nstruct UnionFind {\n    std::size_t n;\n    std::vector<int>\
    \ node;\n    explicit UnionFind(const std::size_t n): n(n), node(n, -1) {}\n \
    \   bool unite(std::size_t u, std::size_t v) {\n        u = root(u), v = root(v);\n\
    \        if (u == v) return false;\n        if (node[u] > node[v]) std::swap(u,\
    \ v);\n        node[u] += node[v];\n        node[v] = (int) u;\n        return\
    \ true;\n    }\n    std::size_t root(const std::size_t &v) { return node[v] <\
    \ 0 ? v : node[v] = (int) root(node[v]); }\n    std::size_t size(const std::size_t\
    \ &v) { return (std::size_t) -node[root(v)]; }\n    bool same(const std::size_t\
    \ &u, const std::size_t &v) { return root(u) == root(v); }\n    std::vector<std::vector<std::size_t>>\
    \ group() {\n        std::vector ret(n, std::vector<std::size_t>{});\n       \
    \ for (std::size_t i = 0; i < n; i++) ret[root(i)].push_back(i);\n        ret.erase(std::remove_if(begin(ret),\
    \ end(ret), [&](const auto &ri) { return empty(ri); }));\n        return ret;\n\
    \    }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <vector>\n\nstruct UnionFind\
    \ {\n    std::size_t n;\n    std::vector<int> node;\n    explicit UnionFind(const\
    \ std::size_t n): n(n), node(n, -1) {}\n    bool unite(std::size_t u, std::size_t\
    \ v) {\n        u = root(u), v = root(v);\n        if (u == v) return false;\n\
    \        if (node[u] > node[v]) std::swap(u, v);\n        node[u] += node[v];\n\
    \        node[v] = (int) u;\n        return true;\n    }\n    std::size_t root(const\
    \ std::size_t &v) { return node[v] < 0 ? v : node[v] = (int) root(node[v]); }\n\
    \    std::size_t size(const std::size_t &v) { return (std::size_t) -node[root(v)];\
    \ }\n    bool same(const std::size_t &u, const std::size_t &v) { return root(u)\
    \ == root(v); }\n    std::vector<std::vector<std::size_t>> group() {\n       \
    \ std::vector ret(n, std::vector<std::size_t>{});\n        for (std::size_t i\
    \ = 0; i < n; i++) ret[root(i)].push_back(i);\n        ret.erase(std::remove_if(begin(ret),\
    \ end(ret), [&](const auto &ri) { return empty(ri); }));\n        return ret;\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/union_find.hpp
  requiredBy:
  - lib/graph/kruskal.hpp
  timestamp: '2021-10-03 22:09:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_11_D.test.cpp
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
