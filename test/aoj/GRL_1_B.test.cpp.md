---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/bellman_ford.hpp
    title: "Bellman-Ford Algorithm / \u8CA0\u8FBA\u3092\u8A31\u3059\u5358\u4E00\u59CB\
      \u70B9\u6700\u77ED\u7D4C\u8DEF\u554F\u984C"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
  bundledCode: "#line 1 \"test/aoj/GRL_1_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
    \n\n#line 2 \"lib/graph/bellman_ford.hpp\"\n\n#line 2 \"lib/include.hpp\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_NULL, _2, _3,\
    \ name, ...) name\n#define rep1(i, n) for (remove_const_t<remove_reference_t<decltype(n)>>\
    \ i = 0; i < (n); i++)\n#define rep2(i, a, b) for (remove_const_t<remove_reference_t<decltype(b)>>\
    \ i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)\n\
    using size_type = size_t;\n#line 4 \"lib/graph/bellman_ford.hpp\"\n\n/**\n * @brief\
    \ Bellman-Ford Algorithm / \u8CA0\u8FBA\u3092\u8A31\u3059\u5358\u4E00\u59CB\u70B9\
    \u6700\u77ED\u7D4C\u8DEF\u554F\u984C\n * @docs docs/bellman_ford.md\n*/\n\ntemplate<typename\
    \ T> vector<T> bellman_ford(vector<vector<pair<size_t, T>>> const& graph, size_t\
    \ root) {\n    static_assert(is_signed_v<T>);\n    constexpr T INF = numeric_limits<T>::max();\n\
    \    using Edge = tuple<size_t, size_t, T>;\n    auto chmin = [](auto& a, const\
    \ auto& b) { return a > b and (a = b, true); };\n    vector<T> dist(size(graph),\
    \ INF);\n    dist[root] = 0;\n    vector<Edge> edges{};\n    rep(i, size(graph))\
    \ for (const auto& [j, w]: graph[i]) edges.emplace_back(Edge{ i, j, w });\n  \
    \  rep(i, size(graph)) {\n        for (const auto& [u, v, w]: edges)\n       \
    \     if (dist[u] != INF and chmin(dist[v], dist[u] + w) and i + 1 == size(graph))\
    \ return {};\n    }\n    return dist;\n}\n#line 4 \"test/aoj/GRL_1_B.test.cpp\"\
    \n\nint main() {\n    size_t v, e, r;\n    cin >> v >> e >> r;\n    using P =\
    \ pair<size_t, int>;\n    vector graph(v, vector<P>{});\n    rep(_, e) {\n   \
    \     size_t s, t;\n        int d;\n        cin >> s >> t >> d;\n        graph[s].emplace_back(P{\
    \ t, d });\n    }\n    auto dist = bellman_ford(graph, r);\n    if (empty(dist))\
    \ {\n        cout << \"NEGATIVE CYCLE\\n\";\n    } else {\n        for (const\
    \ auto& d: dist) {\n            if (d == numeric_limits<int>::max()) cout << \"\
    INF\\n\";\n            else\n                cout << d << \"\\n\";\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
    \n\n#include \"../../lib/graph/bellman_ford.hpp\"\n\nint main() {\n    size_t\
    \ v, e, r;\n    cin >> v >> e >> r;\n    using P = pair<size_t, int>;\n    vector\
    \ graph(v, vector<P>{});\n    rep(_, e) {\n        size_t s, t;\n        int d;\n\
    \        cin >> s >> t >> d;\n        graph[s].emplace_back(P{ t, d });\n    }\n\
    \    auto dist = bellman_ford(graph, r);\n    if (empty(dist)) {\n        cout\
    \ << \"NEGATIVE CYCLE\\n\";\n    } else {\n        for (const auto& d: dist) {\n\
    \            if (d == numeric_limits<int>::max()) cout << \"INF\\n\";\n      \
    \      else\n                cout << d << \"\\n\";\n        }\n    }\n}\n"
  dependsOn:
  - lib/graph/bellman_ford.hpp
  - lib/include.hpp
  isVerificationFile: true
  path: test/aoj/GRL_1_B.test.cpp
  requiredBy: []
  timestamp: '2021-09-29 20:09:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_B.test.cpp
- /verify/test/aoj/GRL_1_B.test.cpp.html
title: test/aoj/GRL_1_B.test.cpp
---
