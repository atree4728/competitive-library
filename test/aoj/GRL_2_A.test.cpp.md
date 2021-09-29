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
    #define overload3(_NULL, _2, _3, name, ...) name\n#define rep1(i, n) for (remove_const_t<remove_reference_t<decltype(n)>>\
    \ i = 0; i < (n); i++)\n#define rep2(i, a, b) for (remove_const_t<remove_reference_t<decltype(b)>>\
    \ i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)\n\
    using size_type = size_t;\n#line 4 \"lib/data_structure/union_find.hpp\"\n\n/**\n\
    \ * @brief Union Find\n * @docs docs/union_find.md\n */\n\nstruct UnionFind {\n\
    \    size_type n;\n    vector<int> node;\n    explicit UnionFind(const size_type\
    \ n):\n        n(n), node(n, -1) {}\n    bool unite(size_type u, size_type v)\
    \ {\n        u = root(u), v = root(v);\n        if (u == v) return false;\n  \
    \      if (node[u] > node[v]) swap(u, v);\n        node[u] += node[v];\n     \
    \   node[v] = (int)u;\n        return true;\n    }\n    size_type root(size_type\
    \ v) { return node[v] < 0 ? v : node[v] = (int)root(node[v]); }\n    size_type\
    \ size(size_type v) { return (size_type)-node[root(v)]; }\n    bool same(size_type\
    \ u, size_type v) { return root(u) == root(v); }\n    vector<vector<size_type>>\
    \ group() {\n        vector ret(n, vector<size_type>{});\n        rep(i, n) ret[root(i)].push_back(i);\n\
    \        ret.erase(remove_if(begin(ret), end(ret), [&](const auto &ri) { return\
    \ empty(ri); }));\n        return ret;\n    }\n};\n#line 4 \"lib/graph/kruskal.hpp\"\
    \n\n/**\n * @brief Kruskal's Algorithm\n * @note Solve MST; Minimum Spanning Tree\
    \ in $O(|E|log|E)$.\n * @note The sum of the weights of the edges can be obtained\
    \ from\n * ```accumulate(begin(ret), end(ret), 0, [](T acc, auto e) { return acc\
    \ + get<2>(e); })```.\n * @return Set of edges by vector<tuple<u, v, weight>>\n\
    */\n\ntemplate<typename T> vector<tuple<size_type, size_type, T>> kruskal(vector<vector<pair<size_t,\
    \ T>>> const& graph) {\n    using Edge = tuple<size_t, size_t, T>;\n    vector<Edge>\
    \ edges{};\n    const size_t n = size(graph);\n    if (n == 1) return {};\n  \
    \  rep(i, n) for (const auto& [j, cost]: graph[i]) edges.emplace_back(Edge{ i,\
    \ j, cost });\n    sort(begin(edges), end(edges), [](Edge a, Edge b) { return\
    \ get<2>(a) < get<2>(b); });\n    UnionFind uf(n);\n    vector<Edge> ret{};\n\
    \    for (const auto& [u, v, cost]: edges) {\n        if (not uf.same(u, v)) {\n\
    \            ret.emplace_back(Edge{ u, v, cost });\n            uf.unite(u, v);\n\
    \        }\n        if (size(ret) + 1 == n) break;\n    }\n    return ret;\n}\n\
    #line 4 \"test/aoj/GRL_2_A.test.cpp\"\n\nint main() {\n    size_t v, e;\n    cin\
    \ >> v >> e;\n    using Edge = pair<size_t, size_t>;\n    vector<vector<Edge>>\
    \ graph(v, vector<Edge>{});\n    while (e--) {\n        size_t s, t;\n       \
    \ int w;\n        cin >> s >> t >> w;\n        graph[s].emplace_back(Edge{ t,\
    \ w });\n    }\n    auto mst = kruskal(graph);\n    int ans = accumulate(cbegin(mst),\
    \ cend(mst), 0, [](int acc, auto e) { return acc + get<2>(e); });\n    cout <<\
    \ ans << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A\"\n\n\
    #include \"../../lib/graph/kruskal.hpp\"\n\nint main() {\n    size_t v, e;\n \
    \   cin >> v >> e;\n    using Edge = pair<size_t, size_t>;\n    vector<vector<Edge>>\
    \ graph(v, vector<Edge>{});\n    while (e--) {\n        size_t s, t;\n       \
    \ int w;\n        cin >> s >> t >> w;\n        graph[s].emplace_back(Edge{ t,\
    \ w });\n    }\n    auto mst = kruskal(graph);\n    int ans = accumulate(cbegin(mst),\
    \ cend(mst), 0, [](int acc, auto e) { return acc + get<2>(e); });\n    cout <<\
    \ ans << \"\\n\";\n}\n"
  dependsOn:
  - lib/graph/kruskal.hpp
  - lib/data_structure/union_find.hpp
  - lib/include.hpp
  isVerificationFile: true
  path: test/aoj/GRL_2_A.test.cpp
  requiredBy: []
  timestamp: '2021-09-29 20:09:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_2_A.test.cpp
- /verify/test/aoj/GRL_2_A.test.cpp.html
title: test/aoj/GRL_2_A.test.cpp
---
