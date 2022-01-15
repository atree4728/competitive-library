---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/union_find.hpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.test.cpp
    title: test/aoj/GRL_2_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/graph/kruskal.hpp\"\n\n#include <utility>\n#line 2 \"\
    lib/data_structure/union_find.hpp\"\n\n#include <algorithm>\n#include <vector>\n\
    \nstruct UnionFind {\n    std::size_t n;\n    std::vector<int> node;\n    explicit\
    \ UnionFind(const std::size_t n): n(n), node(n, -1) {}\n    bool unite(std::size_t\
    \ u, std::size_t v) {\n        u = root(u), v = root(v);\n        if (u == v)\
    \ return false;\n        if (node[u] > node[v]) std::swap(u, v);\n        node[u]\
    \ += node[v];\n        node[v] = (int) u;\n        return true;\n    }\n    std::size_t\
    \ root(const std::size_t &v) { return node[v] < 0 ? v : node[v] = (int) root(node[v]);\
    \ }\n    std::size_t size(const std::size_t &v) { return (std::size_t) -node[root(v)];\
    \ }\n    bool same(const std::size_t &u, const std::size_t &v) { return root(u)\
    \ == root(v); }\n    std::vector<std::vector<std::size_t>> group() {\n       \
    \ std::vector ret(n, std::vector<std::size_t>{});\n        for (std::size_t i\
    \ = 0; i < n; i++) ret[root(i)].push_back(i);\n        ret.erase(std::remove_if(begin(ret),\
    \ end(ret), [&](const auto &ri) { return empty(ri); }));\n        return ret;\n\
    \    }\n};\n#line 5 \"lib/graph/kruskal.hpp\"\n\ntemplate<typename T> std::vector<std::tuple<size_t,\
    \ size_t, T>> kruskal(std::vector<std::vector<std::pair<size_t, T>>> const& graph)\
    \ {\n    using namespace std;\n    using Edge = tuple<size_t, size_t, T>;\n  \
    \  vector<Edge> edges{};\n    const size_t n = size(graph);\n    if (n == 1) return\
    \ {};\n    for (size_t i = 0; i < n; i++)\n        for (const auto& [j, cost]:\
    \ graph[i]) edges.emplace_back(Edge{ i, j, cost });\n    sort(begin(edges), end(edges),\
    \ [](Edge a, Edge b) { return get<2>(a) < get<2>(b); });\n    UnionFind uf(n);\n\
    \    vector<Edge> ret{};\n    for (const auto& [u, v, cost]: edges) {\n      \
    \  if (not uf.same(u, v)) {\n            ret.emplace_back(Edge{ u, v, cost });\n\
    \            uf.unite(u, v);\n        }\n        if (size(ret) + 1 == n) break;\n\
    \    }\n    return ret;\n}\n"
  code: "#pragma once\n\n#include <utility>\n#include \"lib/data_structure/union_find.hpp\"\
    \n\ntemplate<typename T> std::vector<std::tuple<size_t, size_t, T>> kruskal(std::vector<std::vector<std::pair<size_t,\
    \ T>>> const& graph) {\n    using namespace std;\n    using Edge = tuple<size_t,\
    \ size_t, T>;\n    vector<Edge> edges{};\n    const size_t n = size(graph);\n\
    \    if (n == 1) return {};\n    for (size_t i = 0; i < n; i++)\n        for (const\
    \ auto& [j, cost]: graph[i]) edges.emplace_back(Edge{ i, j, cost });\n    sort(begin(edges),\
    \ end(edges), [](Edge a, Edge b) { return get<2>(a) < get<2>(b); });\n    UnionFind\
    \ uf(n);\n    vector<Edge> ret{};\n    for (const auto& [u, v, cost]: edges) {\n\
    \        if (not uf.same(u, v)) {\n            ret.emplace_back(Edge{ u, v, cost\
    \ });\n            uf.unite(u, v);\n        }\n        if (size(ret) + 1 == n)\
    \ break;\n    }\n    return ret;\n}\n"
  dependsOn:
  - lib/data_structure/union_find.hpp
  isVerificationFile: false
  path: lib/graph/kruskal.hpp
  requiredBy: []
  timestamp: '2021-10-13 18:08:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_2_A.test.cpp
documentation_of: lib/graph/kruskal.hpp
layout: document
title: "Kruskal's Algorithm / Minimum Spanning Tree\uFF08\u6700\u5C0F\u5168\u57DF\u6728\
  \uFF09"
---

## 概要
無向グラフ$G=(V,E)$について、$G=(V,E')$が木になるような$E'\subset E$の中で$\sum_{e\in E'}weight(e)$が最小であるような$G$を返す。

## 使い方
- `kruskal(g)`: `g`の最小全域木の辺集合を`tuple<index, index, weight>`として返す。(辺重の総和は`accumulate(cbegin(kruskal(g)), cend(kruskal(g)), 0, [](T acc, auto e) { return acc + get<2>(e); })`)

## 計算量
$\mathcal{O}(|E|log|E)$。