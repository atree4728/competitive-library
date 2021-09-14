---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/union_find.hpp
    title: Union Find
  - icon: ':heavy_check_mark:'
    path: lib/graph/kruskal.hpp
    title: Kruskal's Algorithm
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A
  bundledCode: "#line 1 \"test/aoj/GRL_2_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A\"\
    \n\n#line 2 \"lib/graph/kruskal.hpp\"\n\n#line 2 \"lib/data_structure/union_find.hpp\"\
    \n\n#line 2 \"lib/include.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #define overload3(_1, _2, _3, name, ...) name\n#define rep1(n) for (auto _tmp\
    \ = 0; _tmp < (n); _tmp++)\n#define rep2(i, n) for (auto i = 0; i < (n); i++)\n\
    #define rep3(i, a, b) for (auto i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\ntemplate<class T> bool chmax(T &a, const T &b)\
    \ { return a < b and (a = b, true); }\ntemplate<class T> bool chmin(T &a, const\
    \ T &b) { return a > b and (a = b, true); }\nusing i64 = long long;\nusing f64\
    \ = long double;\n#line 4 \"lib/data_structure/union_find.hpp\"\n\n/**\n * @brief\
    \ Union Find\n * @docs docs/union_find.md\n */\n\nstruct UnionFind {\n    int\
    \ n;\n    vector<int> node;\n    explicit UnionFind(const int n):\n        n(n),\
    \ node(n, -1) {}\n    bool unite(int u, int v) {\n        u = root(u), v = root(v);\n\
    \        if (u == v) return false;\n        if (node[u] > node[v]) swap(u, v);\n\
    \        node[u] += node[v];\n        node[v] = u;\n        return true;\n   \
    \ }\n    int root(int v) { return node[v] < 0 ? v : node[v] = root(node[v]); }\n\
    \    int size(int v) { return -node[root(v)]; }\n    bool same(int u, int v) {\
    \ return root(u) == root(v); }\n    vector<vector<int>> group() {\n        vector\
    \ ret(n, vector<int>{});\n        rep(i, n) ret[root(i)].push_back(i);\n     \
    \   ret.erase(remove_if(begin(ret), end(ret), [&](const auto &ri) { return empty(ri);\
    \ }));\n        return ret;\n    }\n};\n#line 4 \"lib/graph/kruskal.hpp\"\n\n\
    /**\n * @brief Kruskal's Algorithm\n * @note Solve MST; Minimum Spanning Tree\
    \ in $O(|E|log|E)$.\n * @note The sum of the weights of the edges can be obtained\
    \ from\n * ```accumulate(begin(ret), end(ret), 0, [](T acc, auto e) { return acc\
    \ + get<2>(e); })```.\n * @return Set of edges by vector<tuple<u, v, weight>>\n\
    */\n\ntemplate<typename T> vector<tuple<int, int, T>> kruskal(vector<vector<pair<int,\
    \ T>>> const& graph) {\n    using Edge = tuple<int, int, T>;\n    vector<Edge>\
    \ edges{};\n    int n = size(graph);\n    if (n == 1) return {};\n    rep(i, n)\
    \ for (const auto& [j, cost]: graph[i]) edges.emplace_back(Edge{i, j, cost});\n\
    \    sort(begin(edges), end(edges), [](Edge a, Edge b) { return get<2>(a) < get<2>(b);\
    \ });\n    UnionFind uf(n);\n    vector<Edge> ret{};\n    for (const auto& [u,\
    \ v, cost]: edges) {\n        if (not uf.same(u, v)) {\n            ret.emplace_back(Edge{u,\
    \ v, cost});\n            uf.unite(u, v);\n        }\n        if ((int)size(ret)\
    \ + 1 == n) break;\n    }\n    return ret;\n}\n#line 4 \"test/aoj/GRL_2_A.test.cpp\"\
    \n\nint main() {\n    size_t v, e;\n    cin >> v >> e;\n    using Edge = pair<int,\
    \ int>;\n    vector<vector<Edge>> graph(v, vector<Edge>{});\n    rep(e) {\n  \
    \      int s, t, w;\n        cin >> s >> t >> w;\n        graph[s].emplace_back(Edge{t,\
    \ w});\n    }\n    auto mst = kruskal(graph);\n    int ans = accumulate(begin(mst),\
    \ end(mst), 0, [](int acc, auto e) { return acc + get<2>(e); });\n    cout <<\
    \ ans << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A\"\n\n\
    #include \"../../lib/graph/kruskal.hpp\"\n\nint main() {\n    size_t v, e;\n \
    \   cin >> v >> e;\n    using Edge = pair<int, int>;\n    vector<vector<Edge>>\
    \ graph(v, vector<Edge>{});\n    rep(e) {\n        int s, t, w;\n        cin >>\
    \ s >> t >> w;\n        graph[s].emplace_back(Edge{t, w});\n    }\n    auto mst\
    \ = kruskal(graph);\n    int ans = accumulate(begin(mst), end(mst), 0, [](int\
    \ acc, auto e) { return acc + get<2>(e); });\n    cout << ans << \"\\n\";\n}\n"
  dependsOn:
  - lib/graph/kruskal.hpp
  - lib/data_structure/union_find.hpp
  - lib/include.hpp
  isVerificationFile: true
  path: test/aoj/GRL_2_A.test.cpp
  requiredBy: []
  timestamp: '2021-09-14 22:20:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_2_A.test.cpp
- /verify/test/aoj/GRL_2_A.test.cpp.html
title: test/aoj/GRL_2_A.test.cpp
---
