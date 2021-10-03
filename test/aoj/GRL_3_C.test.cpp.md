---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/strongly_connected_components.hpp
    title: "Strongly Connected Components / \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C
  bundledCode: "#line 1 \"test/aoj/GRL_3_C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C\"\
    \n\n#include <iostream>\n#line 2 \"lib/graph/strongly_connected_components.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\nstruct StronglyConnectedComponents\
    \ {\n    template<class T> using vector = std::vector<T>;\n    using usize = std::size_t;\n\
    \n    usize n;\n    vector<vector<usize>> rev_graph;\n    vector<vector<usize>>\
    \ contracted;\n    vector<usize> component;\n    vector<usize> post_order;\n\n\
    \    StronglyConnectedComponents(const vector<vector<usize>>& graph): n(std::size(graph)),\
    \ rev_graph(n, vector<usize>{}), component(n, -1), seen(n, false) {\n        for\
    \ (usize v = 0; v < n; v++) {\n            for (const auto& u: graph[v]) {\n \
    \               rev_graph[u].push_back(v);\n            }\n        }\n       \
    \ for (usize v = 0; v < n; v++) dfs(v, graph);\n        usize index = 0;\n   \
    \     std::reverse(std::begin(post_order), std::end(post_order));\n        for\
    \ (const auto& v: post_order)\n            if (component[v] == (usize) -1) rev_dfs(v,\
    \ index++);\n        contracted.resize(index);\n        for (usize i = 0; i <\
    \ n; i++) {\n            for (const auto& j: graph[i]) {\n                const\
    \ auto& [u, v] = std::pair{ component[i], component[j] };\n                if\
    \ (u != v) contracted[u].push_back(v);\n            }\n        }\n    }\n    usize&\
    \ operator[](usize v) {\n        return component[v];\n    }\n\n  private:\n \
    \   vector<bool> seen;\n    void dfs(usize v, const vector<vector<usize>>& graph)\
    \ {\n        if (seen[v]) return;\n        seen[v] = true;\n        for (const\
    \ auto& u: graph[v]) dfs(u, graph);\n        post_order.push_back(v);\n    }\n\
    \    void rev_dfs(usize v, usize index) {\n        if (component[v] != (usize)\
    \ -1) return;\n        component[v] = index;\n        for (const auto& u: rev_graph[v])\
    \ rev_dfs(u, index);\n    }\n};\n#line 5 \"test/aoj/GRL_3_C.test.cpp\"\n\nint\
    \ main() {\n    using namespace std;\n    size_t v, e;\n    cin >> v >> e;\n \
    \   vector graph(v, vector<size_t>{});\n    while (e--) {\n        size_t s, t;\n\
    \        cin >> s >> t;\n        graph[s].push_back(t);\n    }\n    auto scc =\
    \ StronglyConnectedComponents(graph);\n    size_t q;\n    cin >> q;\n    while\
    \ (q--) {\n        size_t ui, vi;\n        cin >> ui >> vi;\n        cout << (scc[ui]\
    \ == scc[vi] ? 1 : 0) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C\"\n\n\
    #include <iostream>\n#include \"lib/graph/strongly_connected_components.hpp\"\n\
    \nint main() {\n    using namespace std;\n    size_t v, e;\n    cin >> v >> e;\n\
    \    vector graph(v, vector<size_t>{});\n    while (e--) {\n        size_t s,\
    \ t;\n        cin >> s >> t;\n        graph[s].push_back(t);\n    }\n    auto\
    \ scc = StronglyConnectedComponents(graph);\n    size_t q;\n    cin >> q;\n  \
    \  while (q--) {\n        size_t ui, vi;\n        cin >> ui >> vi;\n        cout\
    \ << (scc[ui] == scc[vi] ? 1 : 0) << \"\\n\";\n    }\n}\n"
  dependsOn:
  - lib/graph/strongly_connected_components.hpp
  isVerificationFile: true
  path: test/aoj/GRL_3_C.test.cpp
  requiredBy: []
  timestamp: '2021-10-03 22:09:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_3_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_3_C.test.cpp
- /verify/test/aoj/GRL_3_C.test.cpp.html
title: test/aoj/GRL_3_C.test.cpp
---
