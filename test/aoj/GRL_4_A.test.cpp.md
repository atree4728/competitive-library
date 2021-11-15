---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/topological_sort.hpp
    title: Topological Sort
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
    \n\n#include <iostream>\n#line 2 \"lib/graph/topological_sort.hpp\"\n\n#include\
    \ <queue>\n#include <vector>\n\nstd::vector<std::size_t> topological_sort(std::vector<std::vector<std::size_t>>\
    \ const &graph) {\n    using namespace std;\n    const size_t n = size(graph);\n\
    \    vector<unsigned int> indegree(n, 0);\n    for (const auto &edges: graph)\n\
    \        for (const auto &to: edges) indegree[to]++;\n    queue<size_t> indeg0{};\n\
    \    for (size_t i = 0; i < n; i++)\n        if (indegree[i] == 0) indeg0.push(i);\n\
    \    vector<size_t> ordered{};\n    while (not empty(indeg0)) {\n        size_t\
    \ from = indeg0.front();\n        ordered.push_back(from);\n        indeg0.pop();\n\
    \        for (const auto &to: graph[from])\n            if (--indegree[to] ==\
    \ 0) indeg0.push(to);\n    }\n    if (size(ordered) < n) return {};  // graph\
    \ is not a DAG.\n    return ordered;\n}\n#line 5 \"test/aoj/GRL_4_A.test.cpp\"\
    \n\nint main() {\n    using namespace std;\n    size_t n, m;\n    cin >> n >>\
    \ m;\n    vector graph(n, vector<size_t>{});\n    while (m--) {\n        int s,\
    \ t;\n        cin >> s >> t;\n        graph[s].push_back(t);\n    }\n    auto\
    \ is_dag = topological_sort(graph);\n    cout << (empty(is_dag) ? 1 : 0) << \"\
    \\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A\"\
    \n\n#include <iostream>\n#include \"lib/graph/topological_sort.hpp\"\n\nint main()\
    \ {\n    using namespace std;\n    size_t n, m;\n    cin >> n >> m;\n    vector\
    \ graph(n, vector<size_t>{});\n    while (m--) {\n        int s, t;\n        cin\
    \ >> s >> t;\n        graph[s].push_back(t);\n    }\n    auto is_dag = topological_sort(graph);\n\
    \    cout << (empty(is_dag) ? 1 : 0) << \"\\n\";\n}\n"
  dependsOn:
  - lib/graph/topological_sort.hpp
  isVerificationFile: true
  path: test/aoj/GRL_4_A.test.cpp
  requiredBy: []
  timestamp: '2021-11-15 23:22:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_4_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_4_A.test.cpp
- /verify/test/aoj/GRL_4_A.test.cpp.html
title: test/aoj/GRL_4_A.test.cpp
---
