---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_C.test.cpp
    title: test/aoj/GRL_1_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/graph/floyd_warshall.hpp\"\n\n#include <utility>\n#include\
    \ <vector>\n\ntemplate<typename T> std::vector<std::vector<T>> floyd_warshall(std::vector<std::vector<std::pair<std::size_t,\
    \ T>>> const& graph) {\n    using namespace std;\n    const size_t n = size(graph);\n\
    \    constexpr T INF = numeric_limits<T>::max();\n    vector<vector<T>> dp(n,\
    \ vector<T>(n, INF));\n    for (size_t i = 0; i < n; i++) {\n        dp[i][i]\
    \ = 0;\n        for (const auto& [to, cost]: graph[i]) dp[i][to] = cost;\n   \
    \ }\n    for (size_t k = 0; k < n; k++)\n        for (size_t i = 0; i < n; i++)\n\
    \            for (size_t j = 0; j < n; j++)\n                if (dp[i][k] < INF\
    \ and dp[k][j] < INF) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);\n    for\
    \ (size_t i = 0; i < n; i++)\n        if (dp[i][i] < 0) return {};\n    return\
    \ dp;\n}\n"
  code: "#pragma once\n\n#include <utility>\n#include <vector>\n\ntemplate<typename\
    \ T> std::vector<std::vector<T>> floyd_warshall(std::vector<std::vector<std::pair<std::size_t,\
    \ T>>> const& graph) {\n    using namespace std;\n    const size_t n = size(graph);\n\
    \    constexpr T INF = numeric_limits<T>::max();\n    vector<vector<T>> dp(n,\
    \ vector<T>(n, INF));\n    for (size_t i = 0; i < n; i++) {\n        dp[i][i]\
    \ = 0;\n        for (const auto& [to, cost]: graph[i]) dp[i][to] = cost;\n   \
    \ }\n    for (size_t k = 0; k < n; k++)\n        for (size_t i = 0; i < n; i++)\n\
    \            for (size_t j = 0; j < n; j++)\n                if (dp[i][k] < INF\
    \ and dp[k][j] < INF) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);\n    for\
    \ (size_t i = 0; i < n; i++)\n        if (dp[i][i] < 0) return {};\n    return\
    \ dp;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/floyd_warshall.hpp
  requiredBy: []
  timestamp: '2021-10-03 22:09:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_1_C.test.cpp
documentation_of: lib/graph/floyd_warshall.hpp
layout: document
title: "Floyd Warshall Algorithm / \u8CA0\u8FBA\u3092\u8A31\u3059\u5168\u70B9\u5BFE\
  \u6700\u77ED\u7D4C\u8DEF\u554F\u984C"
---

## 概要

Floyd Warshall 法は、低速ながら全点対最短経路問題(APSP; All Pair Shortest Path)を解くアルゴリズムである。

## 使い方

- `floyd_warshall(G)`: グラフ$G$について全点対最短経路問題を解く。 返り値の$_{(u,v)
  }$には頂点$u,v$間の最短経路（頂点$u,v$が連結でないなら`std::numeric_limits<T>::max()`）が格納される。 $G$上に負閉路が含まれる場合、空の`std::vector`が返る。

## 計算量

$\mathcal{O}(V^3)$。 余談だが、グラフがより疎な場合、全点を始点とした Dijkstra 法($\mathcal{O}(VE\log E)$)の方が高速になる場合がある。
