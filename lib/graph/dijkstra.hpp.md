---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_A.test.cpp
    title: test/aoj/GRL_1_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/graph/dijkstra.hpp\"\n\n#include <optional>\n#include\
    \ <queue>\n#include <vector>\n\ntemplate<class W, template<class, class> class\
    \ Tp>\nauto dijkstra(std::vector<std::vector<Tp<std::size_t, W>>> const& graph,\
    \ std::size_t root) {\n    using E = std::pair<W, size_t>;\n    std::vector<std::optional<W>>\
    \ dist(size(graph), std::nullopt);\n    std::priority_queue<E, std::vector<E>,\
    \ std::greater<>> pq{};\n    pq.emplace(*(dist[root] = W{}), root);\n    while\
    \ (not empty(pq)) {\n        const auto [c, from] = pq.top();\n        pq.pop();\n\
    \        if (*dist[from] < c) continue;\n        for (const auto& [to, cost]:\
    \ graph[from]) {\n            if (not dist[to] or *dist[to] > *dist[from] + cost)\
    \ {\n                dist[to] = dist[from].value() + cost;\n                pq.emplace(*dist[to],\
    \ to);\n            }\n        }\n    }\n    return dist;\n}\n"
  code: "#pragma once\n\n#include <optional>\n#include <queue>\n#include <vector>\n\
    \ntemplate<class W, template<class, class> class Tp>\nauto dijkstra(std::vector<std::vector<Tp<std::size_t,\
    \ W>>> const& graph, std::size_t root) {\n    using E = std::pair<W, size_t>;\n\
    \    std::vector<std::optional<W>> dist(size(graph), std::nullopt);\n    std::priority_queue<E,\
    \ std::vector<E>, std::greater<>> pq{};\n    pq.emplace(*(dist[root] = W{}), root);\n\
    \    while (not empty(pq)) {\n        const auto [c, from] = pq.top();\n     \
    \   pq.pop();\n        if (*dist[from] < c) continue;\n        for (const auto&\
    \ [to, cost]: graph[from]) {\n            if (not dist[to] or *dist[to] > *dist[from]\
    \ + cost) {\n                dist[to] = dist[from].value() + cost;\n         \
    \       pq.emplace(*dist[to], to);\n            }\n        }\n    }\n    return\
    \ dist;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2022-01-15 17:41:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_1_A.test.cpp
documentation_of: lib/graph/dijkstra.hpp
layout: document
title: "Dijkstra's Algorithm / \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF\u554F\
  \u984C"
---

## 概要
Dijkstra 法は、Bellman Ford 法などよりも高速に動作する、負辺を許さない最短経路問題を解くアルゴリズム。
Tropical semiring ($\mathbb{R} \cup{\{\infty \}}, min, +, \infty, 0$) の上で動作することが知られている。

## 使い方
- `dijkstra(std::vector<std::vector<Tp<size_t, W>> const& g, size_t r)`:`g`上で頂点`r`からの最短経路問題を解く。`dijkstra(g, r)[v]`=$dist(r, v)$である。

## 計算量
$G=(V,E)$について`\mathcal{O}(E \log V)`。
