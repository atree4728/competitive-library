---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_A.test.cpp
    title: test/aoj/GRL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_B.test.cpp
    title: test/aoj/GRL_3_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/lowlink.md
    document_title: "Lowlink / \u6A4B\u30FB\u95A2\u7BC0\u70B9"
    links: []
  bundledCode: "#line 2 \"lib/graph/lowlink.hpp\"\n\n#include <algorithm>\n#include\
    \ <vector>\n\n/**\n * @brief Lowlink / \u6A4B\u30FB\u95A2\u7BC0\u70B9\n * @docs\
    \ docs/lowlink.md\n */\n\nstruct Lowlink {\n    using usize = std::size_t;\n \
    \   template<class T> using vector = std::vector<T>;\n    using edge_t = std::pair<usize,\
    \ usize>;\n\n    usize n;\n    vector<usize> order, lowlink, articulation;\n \
    \   vector<edge_t> bridge;\n    Lowlink(const vector<vector<usize>> &graph): n(size(graph)),\
    \ order(n, 0), lowlink(n, 0), seen(n, false) {\n        usize time = 0;\n    \
    \    for (usize i = 0; i < n; i++)\n            if (not seen[i]) time = dfs(i,\
    \ i, time, graph);\n        // When you comment below two lines out, the complexity\
    \ is $\\mathcal{O}(N \\log N)$.\n        // std::sort(articulation.begin(), articulation.end());\n\
    \        // std::sort(bridge.begin(), bridge.end());\n    }\n\n  private:\n  \
    \  vector<bool> seen;\n    usize dfs(const usize &v, const usize &prev, usize\
    \ &time, const vector<vector<usize>> &graph) {\n        seen[v] = true;\n    \
    \    order[v] = time++;\n        lowlink[v] = order[v];\n        bool is_aps =\
    \ false;\n        int count = 0;\n        for (const auto &u: graph[v]) {\n  \
    \          if (not seen[u]) {\n                count++;\n                time\
    \ = dfs(u, v, time, graph);\n                lowlink[v] = std::min(lowlink[v],\
    \ lowlink[u]);\n                if (prev != v && order[v] <= lowlink[u]) is_aps\
    \ = true;\n                if (order[v] < lowlink[u]) bridge.emplace_back(std::minmax(u,\
    \ v));\n            } else if (u != prev) {\n                lowlink[v] = std::min(lowlink[v],\
    \ order[u]);\n            }\n        }\n        if (prev == v && count >= 2) is_aps\
    \ = true;\n        if (is_aps) articulation.push_back(v);\n        return time;\n\
    \    }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <vector>\n\n/**\n * @brief\
    \ Lowlink / \u6A4B\u30FB\u95A2\u7BC0\u70B9\n * @docs docs/lowlink.md\n */\n\n\
    struct Lowlink {\n    using usize = std::size_t;\n    template<class T> using\
    \ vector = std::vector<T>;\n    using edge_t = std::pair<usize, usize>;\n\n  \
    \  usize n;\n    vector<usize> order, lowlink, articulation;\n    vector<edge_t>\
    \ bridge;\n    Lowlink(const vector<vector<usize>> &graph): n(size(graph)), order(n,\
    \ 0), lowlink(n, 0), seen(n, false) {\n        usize time = 0;\n        for (usize\
    \ i = 0; i < n; i++)\n            if (not seen[i]) time = dfs(i, i, time, graph);\n\
    \        // When you comment below two lines out, the complexity is $\\mathcal{O}(N\
    \ \\log N)$.\n        // std::sort(articulation.begin(), articulation.end());\n\
    \        // std::sort(bridge.begin(), bridge.end());\n    }\n\n  private:\n  \
    \  vector<bool> seen;\n    usize dfs(const usize &v, const usize &prev, usize\
    \ &time, const vector<vector<usize>> &graph) {\n        seen[v] = true;\n    \
    \    order[v] = time++;\n        lowlink[v] = order[v];\n        bool is_aps =\
    \ false;\n        int count = 0;\n        for (const auto &u: graph[v]) {\n  \
    \          if (not seen[u]) {\n                count++;\n                time\
    \ = dfs(u, v, time, graph);\n                lowlink[v] = std::min(lowlink[v],\
    \ lowlink[u]);\n                if (prev != v && order[v] <= lowlink[u]) is_aps\
    \ = true;\n                if (order[v] < lowlink[u]) bridge.emplace_back(std::minmax(u,\
    \ v));\n            } else if (u != prev) {\n                lowlink[v] = std::min(lowlink[v],\
    \ order[u]);\n            }\n        }\n        if (prev == v && count >= 2) is_aps\
    \ = true;\n        if (is_aps) articulation.push_back(v);\n        return time;\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/lowlink.hpp
  requiredBy: []
  timestamp: '2021-10-01 17:45:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_3_B.test.cpp
  - test/aoj/GRL_3_A.test.cpp
documentation_of: lib/graph/lowlink.hpp
layout: document
title: "Lowlink / \u6A4B\u30FB\u95A2\u7BC0\u70B9"
---

## 概要
無向連結グラフ$G=(V,E)$において、
- 「辺$(u,v)\in E$が**橋**である。」$\iff$「グラフ$G'=(V, E\{(u,v)})$の連結成分が$G$の連結成分よりも多い。」
- 「頂点$u\in V$が**関節点**である。」$\iff$「グラフ$G'=(V\{u}, E)$の連結成分が$G$の連結成分よりも多い。」  
である。
いま、このグラフについて**深さ優先探索木; DFS Tree**（任意にとった$v \in V$から深さ優先探索したときの walk は$v$を根とした根付き木を成す）を考える。
深さ優先探索木に用いられていない辺を**後退辺**と呼ぶ。
このとき、$ord_u:=深さ優先探索における u \in V の訪問時刻$、$low_u:=\min \{後退辺を高々 1 度だけ用いて到達することができる頂点の ord\}$とし、後者を **Lowlink** と呼ぶ。
いま、
- $(u,v) \in E$が橋であるとき、$ord_u < low_v$を満たす。
- $u \in V$が関節点であるとき、深さ優先探索木の根については子が$2$つ以上、それ以外の頂点については$u \in V$のある子$v$について$ord_u \leq low_v$を満たす。
が成立する（ベースになるのは、「後退辺で遡っても$u$の訪問時刻より早い頂点に訪れることが不可能」）。

## 使い方
- `Lowlink ll(graph)`: `graph`について lowlink を構築する。
- `ll.bridge`: 橋$(u,v)$の集合を`std::vector<std::pair<std::size_t, std::size_t>>`として表現したメンバ。
- `ll.articulation`: 関節点$u$の集合を`std::vector<std::size_t>`として表現したメンバ。

## 計算量
$\mathcal{O}(|V|+|E|)$。
