---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/dijkstra.hpp
    title: Dijkstra's Algorithm
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#line 1 \"lib/test/aoj/GRL_1_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n#line 2 \"lib/graph/dijkstra.hpp\"\n\n#line 2 \"lib/include.hpp\"\n#include\
    \ <bits/stdc++.h>\n#include <experimental/iterator>\nusing namespace std;\n#define\
    \ overload3(_1, _2, _3, name, ...) name\n#define rep1(n) for (auto _i = 0; _i\
    \ < n; _i++)\n#define rep2(i, n) for (auto i = 0; i < n; i++)\n#define rep3(i,\
    \ a, b) for (auto i = a; i < b; i++)\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\ntemplate <class T> bool chmax(T &a, const T\
    \ &b) { return a < b ? a = b, true : false; }\ntemplate <class T> bool chmin(T\
    \ &a, const T &b) { return a > b ? a = b, true : false; }\nusing i64 = long long;\n\
    using f64 = long double;\n#line 4 \"lib/graph/dijkstra.hpp\"\n\n/**\n * @brief\
    \ Dijkstra's Algorithm\n * @note Find SSSP;Single Source Shortest Path in $O(|E|log|V|)$.\
    \ There must be no negative edges. Return -1 for unreachable vertex.\n */\n\n\
    template<class T = i64> vector<T> dijkstra(vector<vector<pair<size_t, T>>> const&\
    \ graph, size_t s) {\n    static_assert(is_signed<T>::value, \"template parameter\
    \ T must be signed type\");\n    using P = pair<T, size_t>;\n    constexpr T INF\
    \ = numeric_limits<T>::max() / 2;\n    vector<T> dist(size(graph), INF);\n   \
    \ priority_queue<P, vector<P>, greater<P>> pq;\n    pq.push({dist[s] = 0, s});\n\
    \    while (not empty(pq)) {\n        const auto [c, v] = pq.top();\n        pq.pop();\n\
    \        if (dist[v] < c) continue;\n        for (const auto& [to, cost]: graph[v])\n\
    \            if (chmin(dist[to], dist[v] + cost)) pq.emplace(dist[to], to);\n\
    \    }\n    for (auto&& e: dist) if (e == INF) e = -1;\n    return dist;\n}\n\
    #line 4 \"lib/test/aoj/GRL_1_A.test.cpp\"\n\nint main() {\n    size_t v, e, r;\n\
    \    cin >> v >> e >> r;\n    using P = pair<size_t, i64>;\n    vector<vector<P>>\
    \ graph(v, vector<P>{});\n    rep(e) {\n        size_t s, t;\n        cin >> s\
    \ >> t;\n        i64 d;\n        cin >> d;\n        graph[s].emplace_back(P{t,\
    \ d});\n    }\n    auto dist = dijkstra(graph, r);\n    for (const auto &d: dist)\
    \ {\n        if (d == -1) cout << \"INF\\n\";\n        else\n            cout\
    \ << d << \"\\n\";\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n#include \"../../graph/dijkstra.hpp\"\n#include \"../../include.hpp\"\n\nint\
    \ main() {\n    size_t v, e, r;\n    cin >> v >> e >> r;\n    using P = pair<size_t,\
    \ i64>;\n    vector<vector<P>> graph(v, vector<P>{});\n    rep(e) {\n        size_t\
    \ s, t;\n        cin >> s >> t;\n        i64 d;\n        cin >> d;\n        graph[s].emplace_back(P{t,\
    \ d});\n    }\n    auto dist = dijkstra(graph, r);\n    for (const auto &d: dist)\
    \ {\n        if (d == -1) cout << \"INF\\n\";\n        else\n            cout\
    \ << d << \"\\n\";\n    }\n    return 0;\n}"
  dependsOn:
  - lib/graph/dijkstra.hpp
  - lib/include.hpp
  isVerificationFile: true
  path: lib/test/aoj/GRL_1_A.test.cpp
  requiredBy: []
  timestamp: '2021-07-10 14:38:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: lib/test/aoj/GRL_1_A.test.cpp
layout: document
redirect_from:
- /verify/lib/test/aoj/GRL_1_A.test.cpp
- /verify/lib/test/aoj/GRL_1_A.test.cpp.html
title: lib/test/aoj/GRL_1_A.test.cpp
---
