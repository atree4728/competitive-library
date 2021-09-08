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
  - icon: ':heavy_check_mark:'
    path: test/library-checker/unionfind.test.cpp
    title: test/library-checker/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/union_find.md
    document_title: Union Find
    links: []
  bundledCode: "#line 2 \"lib/data_structure/union_find.hpp\"\n\n#line 2 \"lib/include.hpp\"\
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
    #line 4 \"lib/data_structure/union_find.hpp\"\n\n/**\n * @brief Union Find\n *\
    \ @docs docs/union_find.md\n */\n\nstruct UnionFind {\n    int n;\n    vector<int>\
    \ node;\n    explicit UnionFind(const int n):\n        n(n), node(n, -1) {}\n\
    \    bool unite(int u, int v) {\n        u = root(u), v = root(v);\n        if\
    \ (u == v) return false;\n        if (node[u] > node[v]) swap(u, v);\n       \
    \ node[u] += node[v];\n        node[v] = u;\n        return true;\n    }\n   \
    \ int root(int v) { return node[v] < 0 ? v : node[v] = root(node[v]); }\n    int\
    \ size(int v) { return -node[root(v)]; }\n    bool same(int u, int v) { return\
    \ root(u) == root(v); }\n    vector<vector<int>> group() {\n        vector ret(n,\
    \ vector<int>{});\n        rep(i, n) ret[root(i)].push_back(i);\n        ret.erase(remove_if(begin(ret),\
    \ end(ret), [&](const auto &ri) { return empty(ri); }));\n        return ret;\n\
    \    }\n};\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief Union Find\n\
    \ * @docs docs/union_find.md\n */\n\nstruct UnionFind {\n    int n;\n    vector<int>\
    \ node;\n    explicit UnionFind(const int n):\n        n(n), node(n, -1) {}\n\
    \    bool unite(int u, int v) {\n        u = root(u), v = root(v);\n        if\
    \ (u == v) return false;\n        if (node[u] > node[v]) swap(u, v);\n       \
    \ node[u] += node[v];\n        node[v] = u;\n        return true;\n    }\n   \
    \ int root(int v) { return node[v] < 0 ? v : node[v] = root(node[v]); }\n    int\
    \ size(int v) { return -node[root(v)]; }\n    bool same(int u, int v) { return\
    \ root(u) == root(v); }\n    vector<vector<int>> group() {\n        vector ret(n,\
    \ vector<int>{});\n        rep(i, n) ret[root(i)].push_back(i);\n        ret.erase(remove_if(begin(ret),\
    \ end(ret), [&](const auto &ri) { return empty(ri); }));\n        return ret;\n\
    \    }\n};\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/data_structure/union_find.hpp
  requiredBy:
  - lib/graph/kruskal.hpp
  timestamp: '2021-09-08 23:15:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/unionfind.test.cpp
  - test/aoj/GRL_2_A.test.cpp
  - test/aoj/DSL_1_A.test.cpp
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
- `uf.same(u, v)`: 頂点$uと頂点$v$が連結かどうかを返す。

## 計算量

構築は$\mathcal{O}(n)$、それ以外は$\alpha(n)$を Ackermann 関数$Ack(n,n)$の逆数として$\mathcal{O}(\alpha(n))$。 これは、Union by size
による併合の工夫（高さをたかだか$(\log n)$で抑える）、path compression による経路圧縮が両方行われているためであり、片方のみだと$\mathcal{O}(\log n)$となる。