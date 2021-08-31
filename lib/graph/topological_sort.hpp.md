---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    document_title: Topological Sort
    links: []
  bundledCode: "#line 2 \"lib/graph/topological_sort.hpp\"\n\n#line 2 \"lib/include.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_1, _2,\
    \ _3, name, ...) name\n#define rep1(n) for (decltype(n) _tmp = 0; _tmp < (n);\
    \ _tmp++)\n#define rep2(i, n) for (decltype(n) i = 0; i < (n); i++)\n#define rep3(i,\
    \ a, b) for (decltype(b) i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\nstruct IOSetup {\n    IOSetup() noexcept {\n\
    \        ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n        cout\
    \ << fixed << setprecision(10);\n        cerr << fixed << setprecision(10);\n\
    \    }\n} iosetup;\ntemplate<class T> bool chmax(T &a, const T &b) { return a\
    \ < b and (a = b, true); }\ntemplate<class T> bool chmin(T &a, const T &b) { return\
    \ a > b and (a = b, true); }\nusing i64 = long long;\nusing f64 = long double;\n\
    #line 4 \"lib/graph/topological_sort.hpp\"\n\n/**\n * @brief Topological Sort\n\
    \ * @note For any graph, it is an equivalence that topological sorting is possible\
    \ and that the graph is a DAG.\n * @note This implementation returns an empty\
    \ vector when the topological sort fails (<=> the given graph is not a DAG).\n\
    \ * @note This implementation makes use of breadth-first search and the property\
    \ that vertices with zero indegree are placed first after sorting.\n * @note The\
    \ complexity is $O(|E|+|V|)$\n*/\n\ntemplate<typename T = int> vector<T> topological_sort(vector<vector<T>>\
    \ const &graph) {\n    int n = size(graph);\n    vector<int> indegree(n, 0);\n\
    \    for (const auto &edges: graph)\n        for (const auto &to: edges) indegree[to]++;\n\
    \    queue<T> indegree_is_0;\n    rep(i, n) if (indegree[i] == 0) indegree_is_0.push(i);\n\
    \    vector<T> ordered{};\n    while (not empty(indegree_is_0)) {\n        T from\
    \ = indegree_is_0.front();\n        ordered.push_back(from);\n        indegree_is_0.pop();\n\
    \        for (const auto &to: graph[from])\n            if (--indegree[to] ==\
    \ 0) indegree_is_0.push(to);\n    }\n    if (size(ordered) < n) return {}; //\
    \ graph is not a DAG.\n    return ordered;\n}\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief Topological\
    \ Sort\n * @note For any graph, it is an equivalence that topological sorting\
    \ is possible and that the graph is a DAG.\n * @note This implementation returns\
    \ an empty vector when the topological sort fails (<=> the given graph is not\
    \ a DAG).\n * @note This implementation makes use of breadth-first search and\
    \ the property that vertices with zero indegree are placed first after sorting.\n\
    \ * @note The complexity is $O(|E|+|V|)$\n*/\n\ntemplate<typename T = int> vector<T>\
    \ topological_sort(vector<vector<T>> const &graph) {\n    int n = size(graph);\n\
    \    vector<int> indegree(n, 0);\n    for (const auto &edges: graph)\n       \
    \ for (const auto &to: edges) indegree[to]++;\n    queue<T> indegree_is_0;\n \
    \   rep(i, n) if (indegree[i] == 0) indegree_is_0.push(i);\n    vector<T> ordered{};\n\
    \    while (not empty(indegree_is_0)) {\n        T from = indegree_is_0.front();\n\
    \        ordered.push_back(from);\n        indegree_is_0.pop();\n        for (const\
    \ auto &to: graph[from])\n            if (--indegree[to] == 0) indegree_is_0.push(to);\n\
    \    }\n    if (size(ordered) < n) return {}; // graph is not a DAG.\n    return\
    \ ordered;\n}\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2021-08-31 17:00:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/my_stress_test/topological_sort.test.cpp
  - test/aoj/GRL_4_A.test.cpp
documentation_of: lib/graph/topological_sort.hpp
layout: document
redirect_from:
- /library/lib/graph/topological_sort.hpp
- /library/lib/graph/topological_sort.hpp.html
title: Topological Sort
---
