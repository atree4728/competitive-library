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
    document_title: Dijkstra's Algorithm
    links: []
  bundledCode: "#line 2 \"lib/graph/dijkstra.hpp\"\n\n#include <limits>\n#include\
    \ <queue>\n#include <utility>\n#include <vector>\n\n/**\n * @brief Dijkstra's\
    \ Algorithm\n * @note  $O(|E|log|V|)$. There must be no negative edges. Return\
    \ -1 for unreachable vertex.\n */\n\ntemplate<class T> std::vector<T> dijkstra(std::vector<std::vector<std::pair<std::size_t,\
    \ T>>> const& graph, std::size_t root) {\n    using namespace std;\n    static_assert(is_signed<T>::value,\
    \ \"template parameter T must be signed type!\");\n    using P = pair<T, size_t>;\n\
    \    constexpr T INF = numeric_limits<T>::max() / 2;\n    auto chmin = [](auto&\
    \ a, const auto& b) { return a > b and (a = b, true); };\n    vector<T> dist(size(graph),\
    \ INF);\n    priority_queue<P, vector<P>, greater<>> pq;\n    pq.emplace(dist[root]\
    \ = 0, root);\n    while (not empty(pq)) {\n        const auto [c, from] = pq.top();\n\
    \        pq.pop();\n        if (dist[from] < c) continue;\n        for (const\
    \ auto& [to, cost]: graph[from])\n            if (chmin(dist[to], dist[from] +\
    \ cost)) pq.emplace(dist[to], to);\n    }\n    for (auto&& e: dist)\n        if\
    \ (e == INF) e = -1;\n    return dist;\n}\n"
  code: "#pragma once\n\n#include <limits>\n#include <queue>\n#include <utility>\n\
    #include <vector>\n\n/**\n * @brief Dijkstra's Algorithm\n * @note  $O(|E|log|V|)$.\
    \ There must be no negative edges. Return -1 for unreachable vertex.\n */\n\n\
    template<class T> std::vector<T> dijkstra(std::vector<std::vector<std::pair<std::size_t,\
    \ T>>> const& graph, std::size_t root) {\n    using namespace std;\n    static_assert(is_signed<T>::value,\
    \ \"template parameter T must be signed type!\");\n    using P = pair<T, size_t>;\n\
    \    constexpr T INF = numeric_limits<T>::max() / 2;\n    auto chmin = [](auto&\
    \ a, const auto& b) { return a > b and (a = b, true); };\n    vector<T> dist(size(graph),\
    \ INF);\n    priority_queue<P, vector<P>, greater<>> pq;\n    pq.emplace(dist[root]\
    \ = 0, root);\n    while (not empty(pq)) {\n        const auto [c, from] = pq.top();\n\
    \        pq.pop();\n        if (dist[from] < c) continue;\n        for (const\
    \ auto& [to, cost]: graph[from])\n            if (chmin(dist[to], dist[from] +\
    \ cost)) pq.emplace(dist[to], to);\n    }\n    for (auto&& e: dist)\n        if\
    \ (e == INF) e = -1;\n    return dist;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2021-10-03 22:04:20+09:00'
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
- `dijkstra(g, r)`:`g`を`vector<vector<size_t, T>>`として、頂点`r`からの最短経路問題を解く。`dijkstra(g, r)[v]`=$dist(r, v)$である。

## 計算量
$G=(V,E)$について`\mathcal{O}(E \log V)`。
