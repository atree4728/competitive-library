---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/dijkstra.hpp
    title: Dijkstra's Algorithm
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
    \n\n#include <iostream>\n#line 2 \"lib/graph/dijkstra.hpp\"\n\n#include <limits>\n\
    #include <queue>\n#include <utility>\n#include <vector>\n\n/**\n * @brief Dijkstra's\
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
    \ (e == INF) e = -1;\n    return dist;\n}\n#line 5 \"test/aoj/GRL_1_A.test.cpp\"\
    \n\nint main() {\n    using namespace std;\n    size_t v, e, r;\n    cin >> v\
    \ >> e >> r;\n    using P = pair<size_t, long long>;\n    vector<vector<P>> graph(v,\
    \ vector<P>{});\n    while (e--) {\n        size_t s, t;\n        long long d;\n\
    \        cin >> s >> t;\n        cin >> d;\n        graph[s].emplace_back(P{ t,\
    \ d });\n    }\n    auto dist = dijkstra(graph, r);\n    for (const auto &d: dist)\
    \ {\n        if (d == -1) cout << \"INF\\n\";\n        else\n            cout\
    \ << d << \"\\n\";\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n\n#include <iostream>\n#include \"lib/graph/dijkstra.hpp\"\n\nint main() {\n\
    \    using namespace std;\n    size_t v, e, r;\n    cin >> v >> e >> r;\n    using\
    \ P = pair<size_t, long long>;\n    vector<vector<P>> graph(v, vector<P>{});\n\
    \    while (e--) {\n        size_t s, t;\n        long long d;\n        cin >>\
    \ s >> t;\n        cin >> d;\n        graph[s].emplace_back(P{ t, d });\n    }\n\
    \    auto dist = dijkstra(graph, r);\n    for (const auto &d: dist) {\n      \
    \  if (d == -1) cout << \"INF\\n\";\n        else\n            cout << d << \"\
    \\n\";\n    }\n    return 0;\n}\n"
  dependsOn:
  - lib/graph/dijkstra.hpp
  isVerificationFile: true
  path: test/aoj/GRL_1_A.test.cpp
  requiredBy: []
  timestamp: '2021-10-03 22:04:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_A.test.cpp
- /verify/test/aoj/GRL_1_A.test.cpp.html
title: test/aoj/GRL_1_A.test.cpp
---
