---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/bellman_ford.hpp
    title: Bellman-Ford's Algorithm
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
    #include <bits/stdc++.h>\n#include <experimental/iterator>\nusing namespace std;\n\
    #define overload3(_1, _2, _3, name, ...) name\n#define rep1(n) for (decltype(n)\
    \ _tmp = 0; _tmp < n; _tmp++)\n#define rep2(i, n) for (decltype(n) i = 0; i <\
    \ n; i++)\n#define rep3(i, a, b) for (decltype(b) i = a; i < b; i++)\n#define\
    \ rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\nstruct IOSetup\
    \ { IOSetup() noexcept { ios::sync_with_stdio(false); cin.tie(nullptr); cout <<\
    \ fixed << setprecision(10); cerr << fixed << setprecision(10); } } iosetup;\n\
    template <class T> bool chmax(T &a, const T &b) { return a < b and (a = b, true);\
    \ }\ntemplate <class T> bool chmin(T &a, const T &b) { return a > b and (a = b,\
    \ true); }\nusing i64 = long long;\nusing u64 = unsigned long long;\nusing f64\
    \ = long double;\n#line 4 \"lib/graph/bellman_ford.hpp\"\n\n/**\n * @brief Bellman-Ford's\
    \ Algorithm\n * @note Solve SSSP in $O(|V||E|)$ about graph $G = (V, E)$. It's\
    \ accepted to exist edges which have negative cost.\n * @nate Return an empty\
    \ vector when given graph has a negative cycle.\n * @note numeric_limits<T>::max()\
    \ for unreachable nodes.\n*/\n\ntemplate<typename T> vector<T> bellman_ford(vector<vector<pair<size_t,\
    \ T>>> const &graph, size_t root) {\n    static_assert(is_signed<T>::value, \"\
    template parameter T must be signed type!\");\n    constexpr T INF = numeric_limits<T>::max();\n\
    \    using Edge = tuple<size_t, size_t, T>;\n    vector<T> dist(size(graph), INF);\n\
    \    dist[root] = 0;\n    vector<Edge> edges{};\n    rep(i, size(graph)) for (const\
    \ auto &[j, w]: graph[i]) edges.emplace_back(Edge{i, j, w});\n    size_t n = size(edges);\n\
    \    rep(i, n) {\n        for (const auto &[u, v, w]: edges)\n            if (dist[u]\
    \ != INF and chmin(dist[v], dist[u] + w) and i == n - 1) return {};\n    }\n \
    \   return dist;\n}\n#line 4 \"test/aoj/GRL_1_B.test.cpp\"\n\nint main() {\n \
    \   size_t v, e, r;\n    cin >> v >> e >> r;\n    using P = pair<size_t, int>;\n\
    \    vector graph(v, vector<P>{});\n    rep(e) {\n        size_t s, t;\n     \
    \   int d;\n        cin >> s >> t >> d;\n        graph[s].emplace_back(P{t, d});\n\
    \    }\n    auto dist = bellman_ford(graph, r);\n    if (empty(dist)) {\n    \
    \    cout << \"NEGATIVE CYCLE\\n\";\n    } else {\n        for (const auto& d:\
    \ dist) {\n            if (d == numeric_limits<int>::max()) cout << \"INF\\n\"\
    ;\n            else\n                cout << d << \"\\n\";\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
    \n\n#include \"../../lib/graph/bellman_ford.hpp\"\n\nint main() {\n    size_t\
    \ v, e, r;\n    cin >> v >> e >> r;\n    using P = pair<size_t, int>;\n    vector\
    \ graph(v, vector<P>{});\n    rep(e) {\n        size_t s, t;\n        int d;\n\
    \        cin >> s >> t >> d;\n        graph[s].emplace_back(P{t, d});\n    }\n\
    \    auto dist = bellman_ford(graph, r);\n    if (empty(dist)) {\n        cout\
    \ << \"NEGATIVE CYCLE\\n\";\n    } else {\n        for (const auto& d: dist) {\n\
    \            if (d == numeric_limits<int>::max()) cout << \"INF\\n\";\n      \
    \      else\n                cout << d << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - lib/graph/bellman_ford.hpp
  - lib/include.hpp
  isVerificationFile: true
  path: test/aoj/GRL_1_B.test.cpp
  requiredBy: []
  timestamp: '2021-07-21 10:45:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_B.test.cpp
- /verify/test/aoj/GRL_1_B.test.cpp.html
title: test/aoj/GRL_1_B.test.cpp
---
