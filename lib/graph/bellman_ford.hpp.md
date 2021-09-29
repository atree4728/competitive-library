---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_B.test.cpp
    title: test/aoj/GRL_1_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/bellman_ford.md
    document_title: "Bellman-Ford Algorithm / \u8CA0\u8FBA\u3092\u8A31\u3059\u5358\
      \u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF\u554F\u984C"
    links: []
  bundledCode: "#line 2 \"lib/graph/bellman_ford.hpp\"\n\n#line 2 \"lib/include.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_NULL, _2,\
    \ _3, name, ...) name\n#define rep1(i, n) for (remove_const_t<remove_reference_t<decltype(n)>>\
    \ i = 0; i < (n); i++)\n#define rep2(i, a, b) for (remove_const_t<remove_reference_t<decltype(b)>>\
    \ i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)\n\
    using size_type = size_t;\n#line 4 \"lib/graph/bellman_ford.hpp\"\n\n/**\n * @brief\
    \ Bellman-Ford Algorithm / \u8CA0\u8FBA\u3092\u8A31\u3059\u5358\u4E00\u59CB\u70B9\
    \u6700\u77ED\u7D4C\u8DEF\u554F\u984C\n * @docs docs/bellman_ford.md\n*/\n\ntemplate<typename\
    \ T> vector<T> bellman_ford(vector<vector<pair<size_t, T>>> const& graph, size_t\
    \ root) {\n    static_assert(is_signed_v<T>);\n    constexpr T INF = numeric_limits<T>::max();\n\
    \    using Edge = tuple<size_t, size_t, T>;\n    auto chmin = [](auto& a, const\
    \ auto& b) { return a > b and (a = b, true); };\n    vector<T> dist(size(graph),\
    \ INF);\n    dist[root] = 0;\n    vector<Edge> edges{};\n    rep(i, size(graph))\
    \ for (const auto& [j, w]: graph[i]) edges.emplace_back(Edge{ i, j, w });\n  \
    \  rep(i, size(graph)) {\n        for (const auto& [u, v, w]: edges)\n       \
    \     if (dist[u] != INF and chmin(dist[v], dist[u] + w) and i + 1 == size(graph))\
    \ return {};\n    }\n    return dist;\n}\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief Bellman-Ford\
    \ Algorithm / \u8CA0\u8FBA\u3092\u8A31\u3059\u5358\u4E00\u59CB\u70B9\u6700\u77ED\
    \u7D4C\u8DEF\u554F\u984C\n * @docs docs/bellman_ford.md\n*/\n\ntemplate<typename\
    \ T> vector<T> bellman_ford(vector<vector<pair<size_t, T>>> const& graph, size_t\
    \ root) {\n    static_assert(is_signed_v<T>);\n    constexpr T INF = numeric_limits<T>::max();\n\
    \    using Edge = tuple<size_t, size_t, T>;\n    auto chmin = [](auto& a, const\
    \ auto& b) { return a > b and (a = b, true); };\n    vector<T> dist(size(graph),\
    \ INF);\n    dist[root] = 0;\n    vector<Edge> edges{};\n    rep(i, size(graph))\
    \ for (const auto& [j, w]: graph[i]) edges.emplace_back(Edge{ i, j, w });\n  \
    \  rep(i, size(graph)) {\n        for (const auto& [u, v, w]: edges)\n       \
    \     if (dist[u] != INF and chmin(dist[v], dist[u] + w) and i + 1 == size(graph))\
    \ return {};\n    }\n    return dist;\n}\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/graph/bellman_ford.hpp
  requiredBy: []
  timestamp: '2021-09-29 20:09:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_1_B.test.cpp
documentation_of: lib/graph/bellman_ford.hpp
layout: document
title: "Bellman-Ford Algorithm / \u8CA0\u8FBA\u3092\u8A31\u3059\u5358\u4E00\u59CB\u70B9\
  \u6700\u77ED\u7D4C\u8DEF\u554F\u984C"
---

## 概要

Bellman-Ford 法は Dijkstra 法よりは遅いが、負辺があってもよく、負閉路の検出も可能な、単一始点最短経路問題（SSSP; Single Source Shortest Path）を解くアルゴリズムである。

## 使い方

- `bellman_ford(G, r)`: グラフ$G$について、始点を$r$として最短経路長を求める。
  `G`は、辺の重みの型を`T`として`std::vector<std::vector<int, T>>`（辺の終点と重みのペア）として表現される。 返り値は`std::vector<T>`
  であり、$v$番目の要素は頂点$v$と$r$の最短経路長である。 $v$が$r$と連結でない場合には`std::numeric_limits<T>::max()`が最短経路長として処理される。
  また、グラフ$G$上に$r$と連結な負閉路が存在したときには空の`std::vector`を返す。

## 計算量

グラフ$G=(V,E)$について、$$\mathcal{O}(\textbar V\textbar\textbar E\textbar)$。
