---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/dijkstra.hpp
    title: Dijkstra's Algorithm
  - icon: ':question:'
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
  bundledCode: "#line 1 \"test/aoj/GRL_1_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n\n#line 2 \"lib/graph/dijkstra.hpp\"\n\n#line 2 \"lib/include.hpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#define overload3(_NULL, _2, _3, name,\
    \ ...) name\n#define rep1(i, n) for (remove_const_t<remove_reference_t<decltype(n)>>\
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
    \ (e == INF) e = -1;\n    return dist;\n}\n#line 4 \"test/aoj/GRL_1_A.test.cpp\"\
    \n\nint main() {\n    size_t v, e, r;\n    cin >> v >> e >> r;\n    using P =\
    \ pair<size_t, long long>;\n    vector<vector<P>> graph(v, vector<P>{});\n   \
    \ while (e--) {\n        size_t s, t;\n        long long d;\n        cin >> s\
    \ >> t;\n        cin >> d;\n        graph[s].emplace_back(P{ t, d });\n    }\n\
    \    auto dist = dijkstra(graph, r);\n    for (const auto &d: dist) {\n      \
    \  if (d == -1)\n            cout << \"INF\\n\";\n        else\n            cout\
    \ << d << \"\\n\";\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n\n#include \"../../lib/graph/dijkstra.hpp\"\n\nint main() {\n    size_t v, e,\
    \ r;\n    cin >> v >> e >> r;\n    using P = pair<size_t, long long>;\n    vector<vector<P>>\
    \ graph(v, vector<P>{});\n    while (e--) {\n        size_t s, t;\n        long\
    \ long d;\n        cin >> s >> t;\n        cin >> d;\n        graph[s].emplace_back(P{\
    \ t, d });\n    }\n    auto dist = dijkstra(graph, r);\n    for (const auto &d:\
    \ dist) {\n        if (d == -1)\n            cout << \"INF\\n\";\n        else\n\
    \            cout << d << \"\\n\";\n    }\n    return 0;\n}\n"
  dependsOn:
  - lib/graph/dijkstra.hpp
  - lib/include.hpp
  isVerificationFile: true
  path: test/aoj/GRL_1_A.test.cpp
  requiredBy: []
  timestamp: '2021-09-29 20:09:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_A.test.cpp
- /verify/test/aoj/GRL_1_A.test.cpp.html
title: test/aoj/GRL_1_A.test.cpp
---
