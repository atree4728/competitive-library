---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/utility/rec_lambda.hpp
    title: lib/utility/rec_lambda.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_C.test.cpp
    title: test/aoj/GRL_5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/lca.test.cpp
    title: test/library-checker/lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/graph/lowest_common_ancestor.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n#line 2 \"lib/utility/rec_lambda.hpp\"\n\n#include <utility>\n\
    \ntemplate<class F> struct rec_lambda {\n    F f;\n    explicit constexpr rec_lambda(F&&\
    \ f): f(std::forward<F>(f)) {}\n    template<class... Args> constexpr decltype(auto)\
    \ operator()(Args&&... args) const {\n        return f(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n#line 6 \"lib/graph/lowest_common_ancestor.hpp\"\n\nstruct LowestCommonAncestor\
    \ {\n    std::size_t n, height;\n    std::vector<int> depth;\n    std::vector<std::vector<int>>\
    \ dp;\n    LowestCommonAncestor(const std::vector<std::vector<std::size_t>>& tree,\
    \ std::size_t root)\n        : n(size(tree)), height(32 - __builtin_clz(n)), depth(n,\
    \ -1), dp(height, std::vector<int>(n, -1)) {\n        depth[root] = 0;\n     \
    \   rec_lambda([&](auto&& self, const auto v, const auto p) -> void {\n      \
    \      for (const auto u: tree[v]) {\n                if (u == p) continue;\n\
    \                assert(depth[u] == -1 and dp[0][u] == -1);  // The graph may\
    \ not be a tree Graph.\n                dp[0][u] = static_cast<int>(v);\n    \
    \            depth[u] = depth[v] + 1;\n                self(u, v);\n         \
    \   }\n            return;\n        })(root, root);\n        for (std::size_t\
    \ k = 0; k + 1 < height; k++)\n            for (std::size_t v = 0; v < n; v++)\
    \ {\n                if (dp[k][v] == -1) dp[k + 1][v] = -1;\n                else\
    \ dp[k + 1][v] = dp[k][dp[k][v]];\n            }\n    }\n    std::size_t operator()(std::size_t\
    \ u, std::size_t v) {\n        assert(u < n and v < n);\n        if (depth[u]\
    \ < depth[v]) std::swap(u, v);\n        for (std::size_t k = 0; k < height; ++k)\n\
    \            if ((depth[u] - depth[v]) >> k & 1) u = dp[k][u];\n        if (u\
    \ == v) return u;\n        for (size_t k = height; k--;) {\n            if (dp[k][u]\
    \ != dp[k][v]) {\n                u = dp[k][u];\n                v = dp[k][v];\n\
    \            }\n        }\n        return dp[0][u];\n    }\n    int dist(size_t\
    \ u, size_t v) { return depth[u] + depth[v] - depth[(*this)(u, v)] * 2; }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n#include \"lib/utility/rec_lambda.hpp\"\
    \n\nstruct LowestCommonAncestor {\n    std::size_t n, height;\n    std::vector<int>\
    \ depth;\n    std::vector<std::vector<int>> dp;\n    LowestCommonAncestor(const\
    \ std::vector<std::vector<std::size_t>>& tree, std::size_t root)\n        : n(size(tree)),\
    \ height(32 - __builtin_clz(n)), depth(n, -1), dp(height, std::vector<int>(n,\
    \ -1)) {\n        depth[root] = 0;\n        rec_lambda([&](auto&& self, const\
    \ auto v, const auto p) -> void {\n            for (const auto u: tree[v]) {\n\
    \                if (u == p) continue;\n                assert(depth[u] == -1\
    \ and dp[0][u] == -1);  // The graph may not be a tree Graph.\n              \
    \  dp[0][u] = static_cast<int>(v);\n                depth[u] = depth[v] + 1;\n\
    \                self(u, v);\n            }\n            return;\n        })(root,\
    \ root);\n        for (std::size_t k = 0; k + 1 < height; k++)\n            for\
    \ (std::size_t v = 0; v < n; v++) {\n                if (dp[k][v] == -1) dp[k\
    \ + 1][v] = -1;\n                else dp[k + 1][v] = dp[k][dp[k][v]];\n      \
    \      }\n    }\n    std::size_t operator()(std::size_t u, std::size_t v) {\n\
    \        assert(u < n and v < n);\n        if (depth[u] < depth[v]) std::swap(u,\
    \ v);\n        for (std::size_t k = 0; k < height; ++k)\n            if ((depth[u]\
    \ - depth[v]) >> k & 1) u = dp[k][u];\n        if (u == v) return u;\n       \
    \ for (size_t k = height; k--;) {\n            if (dp[k][u] != dp[k][v]) {\n \
    \               u = dp[k][u];\n                v = dp[k][v];\n            }\n\
    \        }\n        return dp[0][u];\n    }\n    int dist(size_t u, size_t v)\
    \ { return depth[u] + depth[v] - depth[(*this)(u, v)] * 2; }\n};\n"
  dependsOn:
  - lib/utility/rec_lambda.hpp
  isVerificationFile: false
  path: lib/graph/lowest_common_ancestor.hpp
  requiredBy: []
  timestamp: '2022-01-16 23:42:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
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

- `LowestCommonAncestor lca(tree, r)`: 頂点$r$を根とした根付き木$tree$をもとに最近共通祖先を求めるための前処理をする。
- `lca(u, v)`(`operator()`): 頂点$u$と$v$の最近共通祖先の index を返す。
- `lca.dist(u, v)`: 頂点$u$と$v$の最短距離を返す。

## 計算量

構築には$\mathcal{O}(n\log n)$時間、そのほかに対しては$\mathcal{O}(\log n)$時間を要する。
