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
    document_title: Floyd Warshall's Algorithm
    links: []
  bundledCode: "#line 2 \"lib/graph/floyd_warshall.hpp\"\n\n#line 2 \"lib/include.hpp\"\
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
    #line 4 \"lib/graph/floyd_warshall.hpp\"\n\n/**\n * @brief Floyd Warshall's Algorithm\n\
    \ * @note Solve APSP; All Pair Shortest Path in $O(|V|^3)$ and if given graph\
    \ has a negative path.\n * @note Return an empty vector when given graph has a\
    \ negative cycle.\n * @note If there is no path, return std::numeric_limits<T>::max().\n\
    \ * @note When the graph is more dense, it runs faster than the Dijkstra's Algorithm\
    \ (O(|V||E|log|E)) from arbitrary vertices.\n */\n\ntemplate<typename T> vector<vector<T>>\
    \ floyd_warshall(vector<vector<pair<int, T>>> const& graph) {\n    int n = size(graph);\n\
    \    constexpr T INF = numeric_limits<T>::max();\n    vector<vector<T>> dp(n,\
    \ vector<T>(n, INF));\n    rep(i, n) {\n        dp[i][i] = 0;\n        for (const\
    \ auto& [to, cost]: graph[i]) dp[i][to] = cost;\n    }\n    rep(k, n) rep(i, n)\
    \ rep(j, n) if (dp[i][k] < INF and dp[k][j] < INF) chmin(dp[i][j], dp[i][k] +\
    \ dp[k][j]);\n    rep(i, n) if (dp[i][i] < 0) return {};\n    return dp;\n}\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief Floyd Warshall's\
    \ Algorithm\n * @note Solve APSP; All Pair Shortest Path in $O(|V|^3)$ and if\
    \ given graph has a negative path.\n * @note Return an empty vector when given\
    \ graph has a negative cycle.\n * @note If there is no path, return std::numeric_limits<T>::max().\n\
    \ * @note When the graph is more dense, it runs faster than the Dijkstra's Algorithm\
    \ (O(|V||E|log|E)) from arbitrary vertices.\n */\n\ntemplate<typename T> vector<vector<T>>\
    \ floyd_warshall(vector<vector<pair<int, T>>> const& graph) {\n    int n = size(graph);\n\
    \    constexpr T INF = numeric_limits<T>::max();\n    vector<vector<T>> dp(n,\
    \ vector<T>(n, INF));\n    rep(i, n) {\n        dp[i][i] = 0;\n        for (const\
    \ auto& [to, cost]: graph[i]) dp[i][to] = cost;\n    }\n    rep(k, n) rep(i, n)\
    \ rep(j, n) if (dp[i][k] < INF and dp[k][j] < INF) chmin(dp[i][j], dp[i][k] +\
    \ dp[k][j]);\n    rep(i, n) if (dp[i][i] < 0) return {};\n    return dp;\n}"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/graph/floyd_warshall.hpp
  requiredBy: []
  timestamp: '2021-09-08 23:15:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_1_C.test.cpp
documentation_of: lib/graph/floyd_warshall.hpp
layout: document
redirect_from:
- /library/lib/graph/floyd_warshall.hpp
- /library/lib/graph/floyd_warshall.hpp.html
title: Floyd Warshall's Algorithm
---
