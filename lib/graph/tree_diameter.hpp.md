---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_5_A.test.cpp
    title: test/aoj/GRL_5_A.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/graph/tree_diameter.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <limits>\n#include <queue>\n#include <vector>\n\n\
    template<class T> std::vector<T> tree_diameter(const std::vector<std::vector<T>>&\
    \ tree) {\n    const T n = size(tree);\n    const auto furthest = [&](T s) {\n\
    \        std::vector<T> dist(n, static_cast<T>(-1));\n        dist[s] = 0;\n \
    \       std::queue<T> que{ { s } };\n        while (not empty(que)) {\n      \
    \      const T u = que.front();\n            que.pop();\n            for (const\
    \ T& v: tree[u]) {\n                if (dist[v] != static_cast<T>(-1)) continue;\n\
    \                dist[v] = dist[u] + 1;\n                que.emplace(v);\n   \
    \         }\n        }\n        const T f = distance(cbegin(dist), max_element(cbegin(dist),\
    \ cend(dist)));\n        std::vector<T> path{ f };\n        while (dist[path.back()]\
    \ != 0) {\n            for (const T& u: tree[path.back()]) {\n               \
    \ if (dist[u] + 1 == dist[path.back()]) {\n                    path.emplace_back(u);\n\
    \                    break;\n                }\n            }\n        }\n   \
    \     reverse(begin(path), end(path));\n        return path;\n    };\n    return\
    \ furthest(furthest(0).back());\n}\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <limits>\n\
    #include <queue>\n#include <vector>\n\ntemplate<class T> std::vector<T> tree_diameter(const\
    \ std::vector<std::vector<T>>& tree) {\n    const T n = size(tree);\n    const\
    \ auto furthest = [&](T s) {\n        std::vector<T> dist(n, static_cast<T>(-1));\n\
    \        dist[s] = 0;\n        std::queue<T> que{ { s } };\n        while (not\
    \ empty(que)) {\n            const T u = que.front();\n            que.pop();\n\
    \            for (const T& v: tree[u]) {\n                if (dist[v] != static_cast<T>(-1))\
    \ continue;\n                dist[v] = dist[u] + 1;\n                que.emplace(v);\n\
    \            }\n        }\n        const T f = distance(cbegin(dist), max_element(cbegin(dist),\
    \ cend(dist)));\n        std::vector<T> path{ f };\n        while (dist[path.back()]\
    \ != 0) {\n            for (const T& u: tree[path.back()]) {\n               \
    \ if (dist[u] + 1 == dist[path.back()]) {\n                    path.emplace_back(u);\n\
    \                    break;\n                }\n            }\n        }\n   \
    \     reverse(begin(path), end(path));\n        return path;\n    };\n    return\
    \ furthest(furthest(0).back());\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/tree_diameter.hpp
  requiredBy: []
  timestamp: '2022-09-04 00:42:44+09:00'
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

- `tree_diameter(graph)`: 木`graph`の直径を構成する頂点列。

## 計算量

$\mathcal{O}(N)$。任意に頂点$v$を選び、その頂点からの最遠点を$u$、 $u$からの最遠点を$t$として、$dist(u,t)$が直径になるためである。
