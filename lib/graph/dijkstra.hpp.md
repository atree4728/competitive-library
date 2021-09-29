---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
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
  bundledCode: "#line 2 \"lib/graph/dijkstra.hpp\"\n\n#line 2 \"lib/include.hpp\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_NULL, _2,\
    \ _3, name, ...) name\n#define rep1(i, n) for (remove_const_t<remove_reference_t<decltype(n)>>\
    \ i = 0; i < (n); i++)\n#define rep2(i, a, b) for (remove_const_t<remove_reference_t<decltype(b)>>\
    \ i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)\n\
    using size_type = size_t;\n#line 4 \"lib/graph/dijkstra.hpp\"\n\n/**\n * @brief\
    \ Dijkstra's Algorithm\n * @note  $O(|E|log|V|)$. There must be no negative edges.\
    \ Return -1 for unreachable vertex.\n */\n\ntemplate<class T> vector<T> dijkstra(vector<vector<pair<size_t,\
    \ T>>> const& graph, size_t root) {\n    static_assert(is_signed<T>::value, \"\
    template parameter T must be signed type!\");\n    using P = pair<T, size_t>;\n\
    \    constexpr T INF = numeric_limits<T>::max() / 2;\n    auto chmin = [](auto&\
    \ a, const auto& b) { return a > b and (a = b, true); };\n    vector<T> dist(size(graph),\
    \ INF);\n    priority_queue<P, vector<P>, greater<>> pq;\n    pq.emplace(dist[root]\
    \ = 0, root);\n    while (not empty(pq)) {\n        const auto [c, from] = pq.top();\n\
    \        pq.pop();\n        if (dist[from] < c) continue;\n        for (const\
    \ auto& [to, cost]: graph[from])\n            if (chmin(dist[to], dist[from] +\
    \ cost)) pq.emplace(dist[to], to);\n    }\n    for (auto&& e: dist)\n        if\
    \ (e == INF) e = -1;\n    return dist;\n}\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief Dijkstra's\
    \ Algorithm\n * @note  $O(|E|log|V|)$. There must be no negative edges. Return\
    \ -1 for unreachable vertex.\n */\n\ntemplate<class T> vector<T> dijkstra(vector<vector<pair<size_t,\
    \ T>>> const& graph, size_t root) {\n    static_assert(is_signed<T>::value, \"\
    template parameter T must be signed type!\");\n    using P = pair<T, size_t>;\n\
    \    constexpr T INF = numeric_limits<T>::max() / 2;\n    auto chmin = [](auto&\
    \ a, const auto& b) { return a > b and (a = b, true); };\n    vector<T> dist(size(graph),\
    \ INF);\n    priority_queue<P, vector<P>, greater<>> pq;\n    pq.emplace(dist[root]\
    \ = 0, root);\n    while (not empty(pq)) {\n        const auto [c, from] = pq.top();\n\
    \        pq.pop();\n        if (dist[from] < c) continue;\n        for (const\
    \ auto& [to, cost]: graph[from])\n            if (chmin(dist[to], dist[from] +\
    \ cost)) pq.emplace(dist[to], to);\n    }\n    for (auto&& e: dist)\n        if\
    \ (e == INF) e = -1;\n    return dist;\n}\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2021-09-29 20:09:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_1_A.test.cpp
documentation_of: lib/graph/dijkstra.hpp
layout: document
redirect_from:
- /library/lib/graph/dijkstra.hpp
- /library/lib/graph/dijkstra.hpp.html
title: Dijkstra's Algorithm
---
