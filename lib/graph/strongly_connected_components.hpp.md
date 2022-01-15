---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_C.test.cpp
    title: test/aoj/GRL_3_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/scc.test.cpp
    title: test/library-checker/scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/graph/strongly_connected_components.hpp\"\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <vector>\n\nstruct StronglyConnectedComponents\
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
    \ rev_dfs(u, index);\n    }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \nstruct StronglyConnectedComponents {\n    template<class T> using vector = std::vector<T>;\n\
    \    using usize = std::size_t;\n\n    usize n;\n    vector<vector<usize>> rev_graph;\n\
    \    vector<vector<usize>> contracted;\n    vector<usize> component;\n    vector<usize>\
    \ post_order;\n\n    StronglyConnectedComponents(const vector<vector<usize>>&\
    \ graph): n(std::size(graph)), rev_graph(n, vector<usize>{}), component(n, -1),\
    \ seen(n, false) {\n        for (usize v = 0; v < n; v++) {\n            for (const\
    \ auto& u: graph[v]) {\n                rev_graph[u].push_back(v);\n         \
    \   }\n        }\n        for (usize v = 0; v < n; v++) dfs(v, graph);\n     \
    \   usize index = 0;\n        std::reverse(std::begin(post_order), std::end(post_order));\n\
    \        for (const auto& v: post_order)\n            if (component[v] == (usize)\
    \ -1) rev_dfs(v, index++);\n        contracted.resize(index);\n        for (usize\
    \ i = 0; i < n; i++) {\n            for (const auto& j: graph[i]) {\n        \
    \        const auto& [u, v] = std::pair{ component[i], component[j] };\n     \
    \           if (u != v) contracted[u].push_back(v);\n            }\n        }\n\
    \    }\n    usize& operator[](usize v) {\n        return component[v];\n    }\n\
    \n  private:\n    vector<bool> seen;\n    void dfs(usize v, const vector<vector<usize>>&\
    \ graph) {\n        if (seen[v]) return;\n        seen[v] = true;\n        for\
    \ (const auto& u: graph[v]) dfs(u, graph);\n        post_order.push_back(v);\n\
    \    }\n    void rev_dfs(usize v, usize index) {\n        if (component[v] !=\
    \ (usize) -1) return;\n        component[v] = index;\n        for (const auto&\
    \ u: rev_graph[v]) rev_dfs(u, index);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/strongly_connected_components.hpp
  requiredBy: []
  timestamp: '2021-10-03 22:09:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_3_C.test.cpp
  - test/library-checker/scc.test.cpp
documentation_of: lib/graph/strongly_connected_components.hpp
layout: document
title: "Strongly Connected Components / \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
---

## 概要
重みなし有向グラフ$G=(V,E)$に対して、**強連結成分分解、Strongly Connected Components(SCC)**をする。
「$S \subset{V}$が強連結である」とは、「$\forall (u,v)\in S^2$について$u$から$v$に到達できる」ということであり、さらに他のどのような頂点集合を$S$に付け加えても強連結でなくなるとき、$S$を強連結成分と呼ぶ。
また、任意の$G$には、強連結集合からなる$V$の分割が存在し、その分割を強連結成分分解と呼ぶ。

## 使い方
- `StronglyConnectedComponents scc(graph)`: `graph`を強連結成分分解する。
- `operator[]`: 元のグラフの頂点番号に対して、縮約されたグラフの頂点番号を返す。
- `scc.contracted`: 縮約されたグラフを隣接リスト形式で返す。

## 計算量
$\mathcal{O}(V+E)$。
