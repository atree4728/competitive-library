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
    \ <bits/stdc++.h>\nusing namespace std;\n#define overload3(_1, _2, _3, name, ...)\
    \ name\n#define rep1(n) for (decltype(n) _tmp = 0; _tmp < (n); _tmp++)\n#define\
    \ rep2(i, n) for (decltype(n) i = 0; i < (n); i++)\n#define rep3(i, a, b) for\
    \ (decltype(b) i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep3,\
    \ rep2, rep1)(__VA_ARGS__)\nstruct IOSetup {\n    IOSetup() noexcept {\n     \
    \   ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n        cout << fixed\
    \ << setprecision(10);\n        cerr << fixed << setprecision(10);\n    }\n} iosetup;\n\
    template<class T> bool chmax(T &a, const T &b) { return a < b and (a = b, true);\
    \ }\ntemplate<class T> bool chmin(T &a, const T &b) { return a > b and (a = b,\
    \ true); }\nusing i64 = long long;\nusing f64 = long double;\n#line 4 \"lib/graph/dijkstra.hpp\"\
    \n\n/**\n * @brief Dijkstra's Algorithm\n * @note Find SSSP;Single Source Shortest\
    \ Path in $O(|E|log|V|)$. There must be no negative edges. Return -1 for unreachable\
    \ vertex.\n */\n\ntemplate<class T = i64> vector<T> dijkstra(vector<vector<pair<int,\
    \ T>>> const& graph, int root) {\n    static_assert(is_signed<T>::value, \"template\
    \ parameter T must be signed type!\");\n    using P = pair<T, int>;\n    constexpr\
    \ T INF = numeric_limits<T>::max() / 2;\n    vector<T> dist(size(graph), INF);\n\
    \    priority_queue<P, vector<P>, greater<>> pq;\n    pq.emplace(dist[root] =\
    \ 0, root);\n    while (not empty(pq)) {\n        const auto [c, from] = pq.top();\n\
    \        pq.pop();\n        if (dist[from] < c) continue;\n        for (const\
    \ auto& [to, cost]: graph[from])\n            if (chmin(dist[to], dist[from] +\
    \ cost)) pq.emplace(dist[to], to);\n    }\n    for (auto&& e: dist)\n        if\
    \ (e == INF) e = -1;\n    return dist;\n}\n#line 4 \"test/aoj/GRL_1_A.test.cpp\"\
    \n\nint main() {\n    int v, e, r;\n    cin >> v >> e >> r;\n    using P = pair<int,\
    \ i64>;\n    vector<vector<P>> graph(v, vector<P>{});\n    while (e--) {\n   \
    \     int s, t;\n        i64 d;\n        cin >> s >> t;\n        cin >> d;\n \
    \       graph[s].emplace_back(P{t, d});\n    }\n    auto dist = dijkstra(graph,\
    \ r);\n    for (const auto &d: dist) {\n        if (d == -1) cout << \"INF\\n\"\
    ;\n        else\n            cout << d << \"\\n\";\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n\n#include \"../../lib/graph/dijkstra.hpp\"\n\nint main() {\n    int v, e, r;\n\
    \    cin >> v >> e >> r;\n    using P = pair<int, i64>;\n    vector<vector<P>>\
    \ graph(v, vector<P>{});\n    while (e--) {\n        int s, t;\n        i64 d;\n\
    \        cin >> s >> t;\n        cin >> d;\n        graph[s].emplace_back(P{t,\
    \ d});\n    }\n    auto dist = dijkstra(graph, r);\n    for (const auto &d: dist)\
    \ {\n        if (d == -1) cout << \"INF\\n\";\n        else\n            cout\
    \ << d << \"\\n\";\n    }\n    return 0;\n}\n"
  dependsOn:
  - lib/graph/dijkstra.hpp
  - lib/include.hpp
  isVerificationFile: true
  path: test/aoj/GRL_1_A.test.cpp
  requiredBy: []
  timestamp: '2021-08-31 17:00:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_A.test.cpp
- /verify/test/aoj/GRL_1_A.test.cpp.html
title: test/aoj/GRL_1_A.test.cpp
---
