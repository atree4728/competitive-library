---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_C.test.cpp
    title: test/aoj/GRL_1_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/floyd_warshall.md
    document_title: "Floyd Warshall Algorithm / \u8CA0\u8FBA\u3092\u8A31\u3059\u5168\
      \u70B9\u5BFE\u6700\u77ED\u7D4C\u8DEF\u554F\u984C"
    links: []
  bundledCode: "#line 2 \"lib/graph/floyd_warshall.hpp\"\n\n#line 2 \"lib/include.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_NULL, _2,\
    \ _3, name, ...) name\n#define rep1(i, n) for (remove_const_t<remove_reference_t<decltype(n)>>\
    \ i = 0; i < (n); i++)\n#define rep2(i, a, b) for (remove_const_t<remove_reference_t<decltype(b)>>\
    \ i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)\n\
    using size_type = size_t;\n#line 4 \"lib/graph/floyd_warshall.hpp\"\n\n/**\n *\
    \ @brief Floyd Warshall Algorithm / \u8CA0\u8FBA\u3092\u8A31\u3059\u5168\u70B9\
    \u5BFE\u6700\u77ED\u7D4C\u8DEF\u554F\u984C\n * @docs docs/floyd_warshall.md\n\
    \ */\n\ntemplate<typename T> vector<vector<T>> floyd_warshall(vector<vector<pair<size_t,\
    \ T>>> const& graph) {\n    const size_t n = size(graph);\n    constexpr T INF\
    \ = numeric_limits<T>::max();\n    vector<vector<T>> dp(n, vector<T>(n, INF));\n\
    \    rep(i, n) {\n        dp[i][i] = 0;\n        for (const auto& [to, cost]:\
    \ graph[i]) dp[i][to] = cost;\n    }\n    auto chmin = [](auto& a, const auto&\
    \ b) { return a > b and (a = b, true); };\n    rep(k, n) rep(i, n) rep(j, n) if\
    \ (dp[i][k] < INF and dp[k][j] < INF) chmin(dp[i][j], dp[i][k] + dp[k][j]);\n\
    \    rep(i, n) if (dp[i][i] < 0) return {};\n    return dp;\n}\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief Floyd Warshall\
    \ Algorithm / \u8CA0\u8FBA\u3092\u8A31\u3059\u5168\u70B9\u5BFE\u6700\u77ED\u7D4C\
    \u8DEF\u554F\u984C\n * @docs docs/floyd_warshall.md\n */\n\ntemplate<typename\
    \ T> vector<vector<T>> floyd_warshall(vector<vector<pair<size_t, T>>> const& graph)\
    \ {\n    const size_t n = size(graph);\n    constexpr T INF = numeric_limits<T>::max();\n\
    \    vector<vector<T>> dp(n, vector<T>(n, INF));\n    rep(i, n) {\n        dp[i][i]\
    \ = 0;\n        for (const auto& [to, cost]: graph[i]) dp[i][to] = cost;\n   \
    \ }\n    auto chmin = [](auto& a, const auto& b) { return a > b and (a = b, true);\
    \ };\n    rep(k, n) rep(i, n) rep(j, n) if (dp[i][k] < INF and dp[k][j] < INF)\
    \ chmin(dp[i][j], dp[i][k] + dp[k][j]);\n    rep(i, n) if (dp[i][i] < 0) return\
    \ {};\n    return dp;\n}\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/graph/floyd_warshall.hpp
  requiredBy: []
  timestamp: '2021-09-29 20:09:01+09:00'
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
