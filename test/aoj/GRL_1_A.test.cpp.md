---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/graph/dijkstra.hpp
    title: "Dijkstra's Algorithm / \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF\
      \u554F\u984C"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#line 1 \"test/aoj/GRL_1_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n\n#include <iostream>\n#line 2 \"lib/graph/dijkstra.hpp\"\n\n#include <optional>\n\
    #include <queue>\n#include <vector>\n\ntemplate<class W, template<class, class>\
    \ class Tp>\nauto dijkstra(std::vector<std::vector<Tp<std::size_t, W>>> const&\
    \ graph, std::size_t root) {\n    using E = std::pair<W, size_t>;\n    std::vector<std::optional<W>>\
    \ dist(size(graph), std::nullopt);\n    std::priority_queue<E, std::vector<E>,\
    \ std::greater<>> pq{};\n    pq.emplace(*(dist[root] = W{}), root);\n    while\
    \ (not empty(pq)) {\n        const auto [c, from] = pq.top();\n        pq.pop();\n\
    \        if (*dist[from] < c) continue;\n        for (const auto& [to, cost]:\
    \ graph[from]) {\n            if (not dist[to] or *dist[to] > *dist[from] + cost)\
    \ {\n                dist[to] = dist[from].value() + cost;\n                pq.emplace(*dist[to],\
    \ to);\n            }\n        }\n    }\n    return dist;\n}\n#line 5 \"test/aoj/GRL_1_A.test.cpp\"\
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
  timestamp: '2022-01-15 17:41:33+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_A.test.cpp
- /verify/test/aoj/GRL_1_A.test.cpp.html
title: test/aoj/GRL_1_A.test.cpp
---
