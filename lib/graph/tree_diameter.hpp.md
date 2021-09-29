---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_A.test.cpp
    title: test/aoj/GRL_5_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/tree_diameter.md
    document_title: "Diameter of a Tree / \u6728\u306E\u76F4\u5F84"
    links: []
  bundledCode: "#line 2 \"lib/graph/tree_diameter.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <limits>\n#include <vector>\nusing namespace std;\n\
    \n/**\n * @brief Diameter of a Tree / \u6728\u306E\u76F4\u5F84\n * @docs docs/tree_diameter.md\n\
    \ */\n\ntemplate<typename T> T tree_diameter(const vector<vector<pair<size_t,\
    \ T>>> &tree) {\n    const size_t n = size(tree);\n    const T INF = numeric_limits<T>::max();\n\
    \    vector<T> dist(n, INF);\n    auto dfs = [&](auto &&self, size_t v, size_t\
    \ prev) -> void {\n        for (const auto &[u, w]: tree[v]) {\n            if\
    \ (u == prev) continue;\n            assert(dist[u] == INF);  // graph must be\
    \ a tree\n            dist[u] = dist[v] + w;\n            self(self, u, v);\n\
    \        }\n    };\n    dist[0] = 0;\n    dfs(dfs, 0, 0);\n    size_t farthest\
    \ = distance(begin(dist), max_element(begin(dist), end(dist)));\n    assert(dist[farthest]\
    \ != INF);  // graph must be a tree\n    fill(begin(dist), end(dist), INF);\n\
    \    dist[farthest] = 0;\n    dfs(dfs, farthest, 0);\n    T ans = *max_element(begin(dist),\
    \ end(dist));\n    return ans;\n}\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <limits>\n\
    #include <vector>\nusing namespace std;\n\n/**\n * @brief Diameter of a Tree /\
    \ \u6728\u306E\u76F4\u5F84\n * @docs docs/tree_diameter.md\n */\n\ntemplate<typename\
    \ T> T tree_diameter(const vector<vector<pair<size_t, T>>> &tree) {\n    const\
    \ size_t n = size(tree);\n    const T INF = numeric_limits<T>::max();\n    vector<T>\
    \ dist(n, INF);\n    auto dfs = [&](auto &&self, size_t v, size_t prev) -> void\
    \ {\n        for (const auto &[u, w]: tree[v]) {\n            if (u == prev) continue;\n\
    \            assert(dist[u] == INF);  // graph must be a tree\n            dist[u]\
    \ = dist[v] + w;\n            self(self, u, v);\n        }\n    };\n    dist[0]\
    \ = 0;\n    dfs(dfs, 0, 0);\n    size_t farthest = distance(begin(dist), max_element(begin(dist),\
    \ end(dist)));\n    assert(dist[farthest] != INF);  // graph must be a tree\n\
    \    fill(begin(dist), end(dist), INF);\n    dist[farthest] = 0;\n    dfs(dfs,\
    \ farthest, 0);\n    T ans = *max_element(begin(dist), end(dist));\n    return\
    \ ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/tree_diameter.hpp
  requiredBy: []
  timestamp: '2021-09-29 22:27:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
