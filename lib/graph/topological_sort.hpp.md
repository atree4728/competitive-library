---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_4_A.test.cpp
    title: test/aoj/GRL_4_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/my_stress_test/topological_sort.test.cpp
    title: test/my_stress_test/topological_sort.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/graph/topological_sort.hpp\"\n\n#include <queue>\n#include\
    \ <vector>\n\nstd::vector<std::size_t> topological_sort(std::vector<std::vector<std::size_t>>\
    \ const &graph) {\n    using namespace std;\n    const size_t n = size(graph);\n\
    \    vector<unsigned int> indegree(n, 0);\n    for (const auto &edges: graph)\n\
    \        for (const auto &to: edges) indegree[to]++;\n    queue<size_t> indeg0{};\n\
    \    for (size_t i = 0; i < n; i++)\n        if (indegree[i] == 0) indeg0.push(i);\n\
    \    vector<size_t> ordered{};\n    while (not empty(indeg0)) {\n        size_t\
    \ from = indeg0.front();\n        ordered.push_back(from);\n        indeg0.pop();\n\
    \        for (const auto &to: graph[from])\n            if (--indegree[to] ==\
    \ 0) indeg0.push(to);\n    }\n    if (size(ordered) < n) return {};  // graph\
    \ is not a DAG.\n    return ordered;\n}\n"
  code: "#pragma once\n\n#include <queue>\n#include <vector>\n\nstd::vector<std::size_t>\
    \ topological_sort(std::vector<std::vector<std::size_t>> const &graph) {\n   \
    \ using namespace std;\n    const size_t n = size(graph);\n    vector<unsigned\
    \ int> indegree(n, 0);\n    for (const auto &edges: graph)\n        for (const\
    \ auto &to: edges) indegree[to]++;\n    queue<size_t> indeg0{};\n    for (size_t\
    \ i = 0; i < n; i++)\n        if (indegree[i] == 0) indeg0.push(i);\n    vector<size_t>\
    \ ordered{};\n    while (not empty(indeg0)) {\n        size_t from = indeg0.front();\n\
    \        ordered.push_back(from);\n        indeg0.pop();\n        for (const auto\
    \ &to: graph[from])\n            if (--indegree[to] == 0) indeg0.push(to);\n \
    \   }\n    if (size(ordered) < n) return {};  // graph is not a DAG.\n    return\
    \ ordered;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2021-11-15 23:15:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/my_stress_test/topological_sort.test.cpp
  - test/aoj/GRL_4_A.test.cpp
documentation_of: lib/graph/topological_sort.hpp
layout: document
title: Topological Sort
---

## 概要

与えられたグラフをトポロジカルソートする。 トポロジカルソートするとは、ある DAG(Directed Acyclic Graph) についてのトポロジカル順序$ord$があったときに、 任意の有向辺$(u,v)$について$ord_{u}<
ord_{v}$が成り立つような$ord$を求めることである。（違くない？）

## 使い方

- `topological_sort(graph)`: `graph`をトポロジカルソートした頂点の順列を返す。 グラフ$G$がトポロジカルソート可能であることと$G$が DAG であることは同値であるので、`graph`が DAG
  でなかった場合には空の`std::vector`を返す。

## 計算量

$\mathcal{O}(V+E)$。