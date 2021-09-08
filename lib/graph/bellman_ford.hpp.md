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
    document_title: Bellman-Ford's Algorithm
    links: []
  bundledCode: "#line 2 \"lib/graph/bellman_ford.hpp\"\n\n#line 2 \"lib/include.hpp\"\
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
    #line 4 \"lib/graph/bellman_ford.hpp\"\n\n/**\n * @brief Bellman-Ford's Algorithm\n\
    \ * @note Solve SSSP in $O(|V||E|)$ about graph $G = (V, E)$. It's accepted to\
    \ exist edges which have negative cost.\n * @nate Return an empty vector when\
    \ given graph has a negative cycle.\n * @note numeric_limits<T>::max() for unreachable\
    \ nodes.\n*/\n\ntemplate<typename T> vector<T> bellman_ford(vector<vector<pair<int,\
    \ T>>> const &graph, int root) {\n    static_assert(is_signed<T>::value, \"template\
    \ parameter T must be signed type!\");\n    constexpr T INF = numeric_limits<T>::max();\n\
    \    using Edge = tuple<int, int, T>;\n    vector<T> dist(size(graph), INF);\n\
    \    dist[root] = 0;\n    vector<Edge> edges{};\n    rep(i, size(graph)) for (const\
    \ auto &[j, w]: graph[i]) edges.emplace_back(Edge{i, j, w});\n    rep(i, size(graph))\
    \ {\n        for (const auto &[u, v, w]: edges)\n            if (dist[u] != INF\
    \ and chmin(dist[v], dist[u] + w) and i + 1 == size(graph)) return {};\n    }\n\
    \    return dist;\n}\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief Bellman-Ford's\
    \ Algorithm\n * @note Solve SSSP in $O(|V||E|)$ about graph $G = (V, E)$. It's\
    \ accepted to exist edges which have negative cost.\n * @nate Return an empty\
    \ vector when given graph has a negative cycle.\n * @note numeric_limits<T>::max()\
    \ for unreachable nodes.\n*/\n\ntemplate<typename T> vector<T> bellman_ford(vector<vector<pair<int,\
    \ T>>> const &graph, int root) {\n    static_assert(is_signed<T>::value, \"template\
    \ parameter T must be signed type!\");\n    constexpr T INF = numeric_limits<T>::max();\n\
    \    using Edge = tuple<int, int, T>;\n    vector<T> dist(size(graph), INF);\n\
    \    dist[root] = 0;\n    vector<Edge> edges{};\n    rep(i, size(graph)) for (const\
    \ auto &[j, w]: graph[i]) edges.emplace_back(Edge{i, j, w});\n    rep(i, size(graph))\
    \ {\n        for (const auto &[u, v, w]: edges)\n            if (dist[u] != INF\
    \ and chmin(dist[v], dist[u] + w) and i + 1 == size(graph)) return {};\n    }\n\
    \    return dist;\n}\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/graph/bellman_ford.hpp
  requiredBy: []
  timestamp: '2021-08-31 17:00:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_1_B.test.cpp
documentation_of: lib/graph/bellman_ford.hpp
layout: document
redirect_from:
- /library/lib/graph/bellman_ford.hpp
- /library/lib/graph/bellman_ford.hpp.html
title: Bellman-Ford's Algorithm
---
