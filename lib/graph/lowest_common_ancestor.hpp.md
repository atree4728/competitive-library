---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_5_C.test.cpp
    title: test/aoj/GRL_5_C.test.cpp
  - icon: ':x:'
    path: test/library-checker/lca.test.cpp
    title: test/library-checker/lca.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/lowest_common_ancestor.md
    document_title: "Lowest Common Ancestor(Doubling, Binary Search) / \u6700\u8FD1\
      \u5171\u901A\u7956\u5148"
    links: []
  bundledCode: "#line 2 \"lib/graph/lowest_common_ancestor.hpp\"\n\n#line 2 \"lib/include.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_NULL, _2,\
    \ _3, name, ...) name\n#define rep1(i, n) for (remove_const_t<remove_reference_t<decltype(n)>>\
    \ i = 0; i < (n); i++)\n#define rep2(i, a, b) for (remove_const_t<remove_reference_t<decltype(b)>>\
    \ i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)\n\
    using size_type = size_t;\n#line 4 \"lib/graph/lowest_common_ancestor.hpp\"\n\n\
    /**\n * @brief Lowest Common Ancestor(Doubling, Binary Search) / \u6700\u8FD1\u5171\
    \u901A\u7956\u5148\n * @docs docs/lowest_common_ancestor.md\n*/\n\nstruct LCA\
    \ {\n    size_t n, height;\n    vector<int> depth;\n    vector<vector<int>> dp;\n\
    \    explicit LCA(const vector<vector<size_t>>& tree, size_t root): n(size(tree)),\n\
    \                                                                   height(32\
    \ - __builtin_clz(n)),\n                                                     \
    \              depth(n, -1),\n                                               \
    \                    dp(height, vector<int>(n, -1)) {\n        depth[root] = 0;\n\
    \        dfs(tree, root, -1);\n        rep(k, height - 1) rep(v, n) {\n      \
    \      if (dp[k][v] == -1) dp[k + 1][v] = -1;\n            else\n            \
    \    dp[k + 1][v] = dp[k][dp[k][v]];\n        }\n    }\n    size_t operator()(size_t\
    \ u, size_t v) {\n        assert(u < n and v < n);\n        if (depth[u] < depth[v])\
    \ swap(u, v);\n        for (size_t k = height - 1; k--;)\n            if (((depth[u]\
    \ - depth[v]) >> k) & 1) u = dp[k][u];\n        if (u == v) return u;\n      \
    \  for (size_t k = height - 1; k--;)\n            if (dp[k][u] != dp[k][v]) {\n\
    \                u = dp[k][u];\n                v = dp[k][v];\n            }\n\
    \        return dp[0][u];\n    }\n    int dist(size_t u, size_t v) { return depth[u]\
    \ + depth[v] - depth[(*this)(u, v)] * 2; }\n\n  private:\n    void dfs(const vector<vector<size_t>>&\
    \ tree, size_t v, size_t prev) {\n        for (const auto u: tree[v])\n      \
    \      if (u != prev) {\n                assert(depth[u] == -1 and dp[0][u] ==\
    \ -1);  // The graph may not be a tree Graph.\n                dp[0][u] = (int)\
    \ v;\n                depth[u] = depth[v] + 1;\n                dfs(tree, u, v);\n\
    \            }\n    }\n};\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief Lowest Common\
    \ Ancestor(Doubling, Binary Search) / \u6700\u8FD1\u5171\u901A\u7956\u5148\n *\
    \ @docs docs/lowest_common_ancestor.md\n*/\n\nstruct LCA {\n    size_t n, height;\n\
    \    vector<int> depth;\n    vector<vector<int>> dp;\n    explicit LCA(const vector<vector<size_t>>&\
    \ tree, size_t root): n(size(tree)),\n                                       \
    \                            height(32 - __builtin_clz(n)),\n                \
    \                                                   depth(n, -1),\n          \
    \                                                         dp(height, vector<int>(n,\
    \ -1)) {\n        depth[root] = 0;\n        dfs(tree, root, -1);\n        rep(k,\
    \ height - 1) rep(v, n) {\n            if (dp[k][v] == -1) dp[k + 1][v] = -1;\n\
    \            else\n                dp[k + 1][v] = dp[k][dp[k][v]];\n        }\n\
    \    }\n    size_t operator()(size_t u, size_t v) {\n        assert(u < n and\
    \ v < n);\n        if (depth[u] < depth[v]) swap(u, v);\n        for (size_t k\
    \ = height - 1; k--;)\n            if (((depth[u] - depth[v]) >> k) & 1) u = dp[k][u];\n\
    \        if (u == v) return u;\n        for (size_t k = height - 1; k--;)\n  \
    \          if (dp[k][u] != dp[k][v]) {\n                u = dp[k][u];\n      \
    \          v = dp[k][v];\n            }\n        return dp[0][u];\n    }\n   \
    \ int dist(size_t u, size_t v) { return depth[u] + depth[v] - depth[(*this)(u,\
    \ v)] * 2; }\n\n  private:\n    void dfs(const vector<vector<size_t>>& tree, size_t\
    \ v, size_t prev) {\n        for (const auto u: tree[v])\n            if (u !=\
    \ prev) {\n                assert(depth[u] == -1 and dp[0][u] == -1);  // The\
    \ graph may not be a tree Graph.\n                dp[0][u] = (int) v;\n      \
    \          depth[u] = depth[v] + 1;\n                dfs(tree, u, v);\n      \
    \      }\n    }\n};\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/graph/lowest_common_ancestor.hpp
  requiredBy: []
  timestamp: '2021-09-29 20:09:01+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL_5_C.test.cpp
  - test/library-checker/lca.test.cpp
documentation_of: lib/graph/lowest_common_ancestor.hpp
layout: document
title: "Lowest Common Ancestor(Doubling, Binary Search) / \u6700\u8FD1\u5171\u901A\
  \u7956\u5148"
---

## 概要

木グラフを受け取り、頂点$u$と$v$の最近共通祖先を高速に求める。

## 使い方

- `LCA lca(tree, r)`: 頂点$r$を根とした根付き木$tree$をもとに最近共通祖先を求めるための前処理をする。
- `lca(u, v)`(`operator()`): 頂点$u$と$v$の最近共通祖先の index を返す。
- `lca.dist(u, v)`: 頂点$u$と$v$の最短距離を返す。

## 計算量

構築には$\mathcal{O}(n\log n)$時間、そのほかに対しては$\mathcal{O}(\log n)$時間を要する。