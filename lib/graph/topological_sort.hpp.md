---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
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
    _deprecated_at_docs: docs/topological_sort.md
    document_title: Topological Sort
    links: []
  bundledCode: "#line 2 \"lib/graph/topological_sort.hpp\"\n\n#line 2 \"lib/include.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_1, _2,\
    \ _3, name, ...) name\n#define rep1(n) for (auto _tmp = 0; _tmp < (n); _tmp++)\n\
    #define rep2(i, n) for (auto i = 0; i < (n); i++)\n#define rep3(i, a, b) for (auto\
    \ i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n\
    template<class T> bool chmax(T &a, const T &b) { return a < b and (a = b, true);\
    \ }\ntemplate<class T> bool chmin(T &a, const T &b) { return a > b and (a = b,\
    \ true); }\nusing i64 = long long;\nusing f64 = long double;\n#line 4 \"lib/graph/topological_sort.hpp\"\
    \n\n/**\n * @brief Topological Sort\n * @docs docs/topological_sort.md\n*/\n\n\
    template<typename T = int> vector<T> topological_sort(vector<vector<T>> const\
    \ &graph) {\n    int n = size(graph);\n    vector<int> indegree(n, 0);\n    for\
    \ (const auto &edges: graph)\n        for (const auto &to: edges) indegree[to]++;\n\
    \    queue<T> indegree_is_0;\n    rep(i, n) if (indegree[i] == 0) indegree_is_0.push(i);\n\
    \    vector<T> ordered{};\n    while (not empty(indegree_is_0)) {\n        T from\
    \ = indegree_is_0.front();\n        ordered.push_back(from);\n        indegree_is_0.pop();\n\
    \        for (const auto &to: graph[from])\n            if (--indegree[to] ==\
    \ 0) indegree_is_0.push(to);\n    }\n    if ((int)size(ordered) < n) return {};\
    \ // graph is not a DAG.\n    return ordered;\n}\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief Topological\
    \ Sort\n * @docs docs/topological_sort.md\n*/\n\ntemplate<typename T = int> vector<T>\
    \ topological_sort(vector<vector<T>> const &graph) {\n    int n = size(graph);\n\
    \    vector<int> indegree(n, 0);\n    for (const auto &edges: graph)\n       \
    \ for (const auto &to: edges) indegree[to]++;\n    queue<T> indegree_is_0;\n \
    \   rep(i, n) if (indegree[i] == 0) indegree_is_0.push(i);\n    vector<T> ordered{};\n\
    \    while (not empty(indegree_is_0)) {\n        T from = indegree_is_0.front();\n\
    \        ordered.push_back(from);\n        indegree_is_0.pop();\n        for (const\
    \ auto &to: graph[from])\n            if (--indegree[to] == 0) indegree_is_0.push(to);\n\
    \    }\n    if ((int)size(ordered) < n) return {}; // graph is not a DAG.\n  \
    \  return ordered;\n}\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2021-09-14 22:20:52+09:00'
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