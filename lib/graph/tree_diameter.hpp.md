---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_5_A.test.cpp
    title: test/aoj/GRL_5_A.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/tree_diameter.md
    document_title: "Diameter of a Tree / \u6728\u306E\u76F4\u5F84"
    links: []
  bundledCode: "#line 2 \"lib/graph/tree_diameter.hpp\"\n\n#line 2 \"lib/include.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_NULL, _2,\
    \ _3, name, ...) name\n#define rep1(i, n) for (remove_const_t<remove_reference_t<decltype(n)>>\
    \ i = 0; i < (n); i++)\n#define rep2(i, a, b) for (remove_const_t<remove_reference_t<decltype(b)>>\
    \ i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)\n\
    using size_type = size_t;\n#line 4 \"lib/graph/tree_diameter.hpp\"\n\n/**\n *\
    \ @brief Diameter of a Tree / \u6728\u306E\u76F4\u5F84\n * @docs docs/tree_diameter.md\n\
    \ */\n\ntemplate<typename T> T tree_diameter(const vector<vector<pair<size_type,\
    \ T>>> &tree) {\n    const size_type n = size(tree);\n    const T INF = numeric_limits<T>::max();\n\
    \    vector<T> dist(n, INF);\n    auto dfs = [&](auto &&self, size_type v, size_type\
    \ prev) -> void {\n        for (const auto [u, w]: tree[v])\n            if (u\
    \ != prev) {\n                assert(dist[u] == INF); // graph must be a tree\n\
    \                dist[u] = dist[v] + w;\n                self(self, u, v);\n \
    \           }\n    };\n    dist[0] = 0;\n    dfs(dfs, 0, 0);\n    size_type farthest\
    \ = distance(begin(dist), max_element(begin(dist), end(dist)));\n    assert(dist[farthest]\
    \ != INF); // graph must be a tree\n    fill(begin(dist), end(dist), INF);\n \
    \   dist[farthest] = 0;\n    dfs(dfs, farthest, 0);\n    T ans = *max_element(begin(dist),\
    \ end(dist));\n    return ans;\n}\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief Diameter of\
    \ a Tree / \u6728\u306E\u76F4\u5F84\n * @docs docs/tree_diameter.md\n */\n\ntemplate<typename\
    \ T> T tree_diameter(const vector<vector<pair<size_type, T>>> &tree) {\n    const\
    \ size_type n = size(tree);\n    const T INF = numeric_limits<T>::max();\n   \
    \ vector<T> dist(n, INF);\n    auto dfs = [&](auto &&self, size_type v, size_type\
    \ prev) -> void {\n        for (const auto [u, w]: tree[v])\n            if (u\
    \ != prev) {\n                assert(dist[u] == INF); // graph must be a tree\n\
    \                dist[u] = dist[v] + w;\n                self(self, u, v);\n \
    \           }\n    };\n    dist[0] = 0;\n    dfs(dfs, 0, 0);\n    size_type farthest\
    \ = distance(begin(dist), max_element(begin(dist), end(dist)));\n    assert(dist[farthest]\
    \ != INF); // graph must be a tree\n    fill(begin(dist), end(dist), INF);\n \
    \   dist[farthest] = 0;\n    dfs(dfs, farthest, 0);\n    T ans = *max_element(begin(dist),\
    \ end(dist));\n    return ans;\n}\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/graph/tree_diameter.hpp
  requiredBy: []
  timestamp: '2021-09-29 20:09:01+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL_5_A.test.cpp
documentation_of: lib/graph/tree_diameter.hpp
layout: document
title: "Diameter of a Tree / \u6728\u306E\u76F4\u5F84"
---

## 概要

木グラフの直径（path 長の最大値）を求める。

## 使い方

- `tree_diameter(graph)`: 木`graph`の直径を求める。

## 計算量

$\mathcal{O}(N)$。任意に頂点$v$を選び、その頂点からの最遠点を$u$、 $u$からの最遠点を$t$として、$dist(u,t)$が直径になるためである。
