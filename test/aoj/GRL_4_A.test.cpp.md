---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/topological_sort.hpp
    title: Topological Sort
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A
  bundledCode: "#line 1 \"test/aoj/GRL_4_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A\"\
    \n\n#line 2 \"lib/graph/topological_sort.hpp\"\n\n#line 2 \"lib/include.hpp\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_1, _2, _3,\
    \ name, ...) name\n#define rep1(n) for (auto _tmp = 0; _tmp < (n); _tmp++)\n#define\
    \ rep2(i, n) for (auto i = 0; i < (n); i++)\n#define rep3(i, a, b) for (auto i\
    \ = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n\
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
    \ // graph is not a DAG.\n    return ordered;\n}\n#line 4 \"test/aoj/GRL_4_A.test.cpp\"\
    \n\nint main() {\n    size_t n, m;\n    cin >> n >> m;\n    vector graph(n, vector<int>{});\n\
    \    while (m--) {\n        int s, t;\n        cin >> s >> t;\n        graph[s].push_back(t);\n\
    \    }\n    auto is_dag = topological_sort(graph);\n    cout << (empty(is_dag)\
    \ ? 1 : 0) << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A\"\
    \n\n#include \"../../lib/graph/topological_sort.hpp\"\n\nint main() {\n    size_t\
    \ n, m;\n    cin >> n >> m;\n    vector graph(n, vector<int>{});\n    while (m--)\
    \ {\n        int s, t;\n        cin >> s >> t;\n        graph[s].push_back(t);\n\
    \    }\n    auto is_dag = topological_sort(graph);\n    cout << (empty(is_dag)\
    \ ? 1 : 0) << \"\\n\";\n}\n"
  dependsOn:
  - lib/graph/topological_sort.hpp
  - lib/include.hpp
  isVerificationFile: true
  path: test/aoj/GRL_4_A.test.cpp
  requiredBy: []
  timestamp: '2021-09-14 22:20:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_4_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_4_A.test.cpp
- /verify/test/aoj/GRL_4_A.test.cpp.html
title: test/aoj/GRL_4_A.test.cpp
---
