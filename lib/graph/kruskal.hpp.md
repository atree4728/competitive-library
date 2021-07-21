---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/union_find.hpp
    title: Union Find
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.test.cpp
    title: test/aoj/GRL_2_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Kruskal's Algorithm
    links: []
  bundledCode: "#line 2 \"lib/graph/kruskal.hpp\"\n\n#line 2 \"lib/data_structure/union_find.hpp\"\
    \n\n#line 2 \"lib/include.hpp\"\n\n#include <bits/stdc++.h>\n#include <experimental/iterator>\n\
    using namespace std;\n#define overload3(_1, _2, _3, name, ...) name\n#define rep1(n)\
    \ for (decltype(n) _tmp = 0; _tmp < n; _tmp++)\n#define rep2(i, n) for (decltype(n)\
    \ i = 0; i < n; i++)\n#define rep3(i, a, b) for (decltype(b) i = a; i < b; i++)\n\
    #define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\nstruct\
    \ IOSetup { IOSetup() noexcept { ios::sync_with_stdio(false); cin.tie(nullptr);\
    \ cout << fixed << setprecision(10); cerr << fixed << setprecision(10); } } iosetup;\n\
    template <class T> bool chmax(T &a, const T &b) { return a < b and (a = b, true);\
    \ }\ntemplate <class T> bool chmin(T &a, const T &b) { return a > b and (a = b,\
    \ true); }\nusing i64 = long long;\nusing u64 = unsigned long long;\nusing f64\
    \ = long double;\n#line 4 \"lib/data_structure/union_find.hpp\"\n\n/**\n * @brief\
    \ Union Find\n * @note a.k.a DSU; Disjoint Set Union\n */\nstruct UnionFind {\n\
    \    vector<int> parents_or_size;\n    UnionFind(int size_):\n        parents_or_size(size_,\
    \ -1) {}\n    bool unite(int u, int v) {\n        u = root(u), v = root(v);\n\
    \        if (u == v) return false;\n        if (parents_or_size[u] > parents_or_size[v])\
    \ swap(u, v);\n        parents_or_size[u] += parents_or_size[v];\n        parents_or_size[v]\
    \ = u;\n        return true;\n    }\n    int root(int k) { return parents_or_size[k]\
    \ < 0 ? k : parents_or_size[k] = root(parents_or_size[k]); }\n    int size(int\
    \ k) { return -parents_or_size[root(k)]; }\n    bool same(int u, int v) { return\
    \ root(u) == root(v); }\n    vector<vector<int>> groups() {\n        size_t n\
    \ = parents_or_size.size();\n        vector<vector<int>> ret(n);\n        rep(i,\
    \ n) ret[root(i)].emplace_back(i);\n        ret.erase(remove_if(begin(ret), end(ret),\
    \ [&](const vector<int> &v) { return v.empty(); }));\n        return ret;\n  \
    \  }\n};\n#line 4 \"lib/graph/kruskal.hpp\"\n\n/**\n * @brief Kruskal's Algorithm\n\
    \ * @note Solve MST; Minimum Spanning Tree in $O(|E|log|E)$.\n * @note The sum\
    \ of the weights of the edges can be obtained from\n * ```accumulate(begin(ret),\
    \ end(ret), 0, [](T acc, auto e) { return acc + get<2>(e); })```.\n * @return\
    \ Set of edges by vector<tuple<u, v, weight>>\n*/\n\ntemplate<typename T> vector<tuple<size_t,\
    \ size_t, T>> kruskal(vector<vector<pair<size_t, T>>> const& graph) {\n    using\
    \ Edge = tuple<size_t, size_t, T>;\n    vector<Edge> edges{};\n    size_t n =\
    \ size(graph);\n    if (n == 1) return {};\n    rep(i, n) for (const auto& [j,\
    \ cost]: graph[i]) edges.emplace_back(Edge{i, j, cost});\n    sort(begin(edges),\
    \ end(edges), [](Edge a, Edge b) { return get<2>(a) < get<2>(b); });\n    UnionFind\
    \ uf(n);\n    vector<Edge> ret{};\n    for (const auto& [u, v, cost]: edges) {\n\
    \        if (not uf.same(u, v)) {\n            ret.emplace_back(Edge{u, v, cost});\n\
    \            uf.unite(u, v);\n        }\n        if (size(ret) == n - 1) break;\n\
    \    }\n    return ret;\n}\n"
  code: "#pragma once\n\n#include \"../data_structure/union_find.hpp\"\n\n/**\n *\
    \ @brief Kruskal's Algorithm\n * @note Solve MST; Minimum Spanning Tree in $O(|E|log|E)$.\n\
    \ * @note The sum of the weights of the edges can be obtained from\n * ```accumulate(begin(ret),\
    \ end(ret), 0, [](T acc, auto e) { return acc + get<2>(e); })```.\n * @return\
    \ Set of edges by vector<tuple<u, v, weight>>\n*/\n\ntemplate<typename T> vector<tuple<size_t,\
    \ size_t, T>> kruskal(vector<vector<pair<size_t, T>>> const& graph) {\n    using\
    \ Edge = tuple<size_t, size_t, T>;\n    vector<Edge> edges{};\n    size_t n =\
    \ size(graph);\n    if (n == 1) return {};\n    rep(i, n) for (const auto& [j,\
    \ cost]: graph[i]) edges.emplace_back(Edge{i, j, cost});\n    sort(begin(edges),\
    \ end(edges), [](Edge a, Edge b) { return get<2>(a) < get<2>(b); });\n    UnionFind\
    \ uf(n);\n    vector<Edge> ret{};\n    for (const auto& [u, v, cost]: edges) {\n\
    \        if (not uf.same(u, v)) {\n            ret.emplace_back(Edge{u, v, cost});\n\
    \            uf.unite(u, v);\n        }\n        if (size(ret) == n - 1) break;\n\
    \    }\n    return ret;\n}\n"
  dependsOn:
  - lib/data_structure/union_find.hpp
  - lib/include.hpp
  isVerificationFile: false
  path: lib/graph/kruskal.hpp
  requiredBy: []
  timestamp: '2021-07-21 10:45:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_2_A.test.cpp
documentation_of: lib/graph/kruskal.hpp
layout: document
redirect_from:
- /library/lib/graph/kruskal.hpp
- /library/lib/graph/kruskal.hpp.html
title: Kruskal's Algorithm
---
