---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/bellman_ford.hpp
    title: "Bellman-Ford Algorithm / \u8CA0\u8FBA\u3092\u8A31\u3059\u5358\u4E00\u59CB\
      \u70B9\u6700\u77ED\u7D4C\u8DEF\u554F\u984C"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
  bundledCode: "#line 1 \"test/aoj/GRL_1_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
    \n\n#include <iostream>\n#include <limits>\n#line 2 \"lib/graph/bellman_ford.hpp\"\
    \n\n#include <tuple>\n#include <vector>\n\ntemplate<typename T> std::vector<T>\
    \ bellman_ford(std::vector<std::vector<std::pair<std::size_t, T>>> const& graph,\
    \ std::size_t root) {\n    using namespace std;\n    static_assert(is_signed_v<T>);\n\
    \    constexpr T INF = numeric_limits<T>::max();\n    auto chmin = [](auto& a,\
    \ const auto& b) { return a > b and (a = b, true); };\n\n    vector<T> dist(size(graph),\
    \ INF);\n    dist[root] = 0;\n    vector<tuple<size_t, size_t, T>> edges{};\n\
    \    for (size_t i = 0; i < size(graph); i++)\n        for (const auto& [j, w]:\
    \ graph[i]) edges.emplace_back(i, j, w);\n    for (size_t i = 0; i < size(graph);\
    \ i++) {\n        for (const auto& [u, v, w]: edges)\n            if (dist[u]\
    \ != INF and chmin(dist[v], dist[u] + w) and i + 1 == size(graph)) return {};\n\
    \    }\n    return dist;\n}\n#line 6 \"test/aoj/GRL_1_B.test.cpp\"\n\nint main()\
    \ {\n    using namespace std;\n    size_t v, e, r;\n    cin >> v >> e >> r;\n\
    \    using P = pair<size_t, int>;\n    vector graph(v, vector<P>{});\n    while\
    \ (e--) {\n        size_t s, t;\n        int d;\n        cin >> s >> t >> d;\n\
    \        graph[s].emplace_back(P{ t, d });\n    }\n    auto dist = bellman_ford(graph,\
    \ r);\n    if (empty(dist)) {\n        cout << \"NEGATIVE CYCLE\\n\";\n    } else\
    \ {\n        for (const auto& d: dist) {\n            if (d == numeric_limits<int>::max())\
    \ cout << \"INF\\n\";\n            else\n                cout << d << \"\\n\"\
    ;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
    \n\n#include <iostream>\n#include <limits>\n#include \"lib/graph/bellman_ford.hpp\"\
    \n\nint main() {\n    using namespace std;\n    size_t v, e, r;\n    cin >> v\
    \ >> e >> r;\n    using P = pair<size_t, int>;\n    vector graph(v, vector<P>{});\n\
    \    while (e--) {\n        size_t s, t;\n        int d;\n        cin >> s >>\
    \ t >> d;\n        graph[s].emplace_back(P{ t, d });\n    }\n    auto dist = bellman_ford(graph,\
    \ r);\n    if (empty(dist)) {\n        cout << \"NEGATIVE CYCLE\\n\";\n    } else\
    \ {\n        for (const auto& d: dist) {\n            if (d == numeric_limits<int>::max())\
    \ cout << \"INF\\n\";\n            else\n                cout << d << \"\\n\"\
    ;\n        }\n    }\n}\n"
  dependsOn:
  - lib/graph/bellman_ford.hpp
  isVerificationFile: true
  path: test/aoj/GRL_1_B.test.cpp
  requiredBy: []
  timestamp: '2021-10-03 22:09:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_B.test.cpp
- /verify/test/aoj/GRL_1_B.test.cpp.html
title: test/aoj/GRL_1_B.test.cpp
---
