---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/graph/subtree_info.hpp\"\n\n#include <utility>\n#include\
    \ <vector>\n\ntemplate<typename T> struct SubtreeInfo {\n    using size_t = std::size_t;\n\
    \    template<class U> using vector = std::vector<U>;\n    size_t n;\n    vector<size_t>\
    \ parents, sizes;\n    vector<T> depths;\n    SubtreeInfo(const vector<vector<size_t>>&\
    \ tree, size_t root): n(size(tree)), parents(n, -1), sizes(n, -1), depths(n, -1)\
    \ {\n        parents[root] = -1;\n        depths[root] = 0;\n        auto dfs\
    \ = [&](auto&& self, size_t v, size_t prev) -> void {\n            if (size(tree[v])\
    \ == 1) sizes[v] = 1;\n            for (const auto u: tree[v])\n             \
    \   if (u != prev) {\n                    parents[u] = v;\n                  \
    \  depths[u] = depths[v] + 1;\n                    if (sizes[u] == -1) self(self,\
    \ u, v);\n                    sizes[v] += sizes[u];\n                }\n     \
    \       sizes[v]++;\n        };\n        dfs(dfs, root, -1);\n    }\n    SubtreeInfo(const\
    \ vector<vector<std::pair<size_t, T>>>& tree, size_t root): n(size(tree)), parents(n,\
    \ -1), sizes(n, -1), depths(n, -1) {\n        parents[root] = -1;\n        depths[root]\
    \ = 0;\n        auto dfs = [&](auto&& self, size_t v, size_t prev) -> void {\n\
    \            if (size(tree[v]) == 1) sizes[v] = 1;\n            for (const auto&\
    \ [u, w]: tree[v])\n                if (u != prev) {\n                    parents[u]\
    \ = v;\n                    depths[u] = depths[v] + w;\n                    if\
    \ (sizes[u] == -1) self(self, u, v);\n                    sizes[v] += sizes[u];\n\
    \                }\n            sizes[v]++;\n        };\n        dfs(dfs, root,\
    \ -1);\n    }\n    size_t parent(size_t u) { return parents[u]; }\n    size_t\
    \ size(size_t u) { return sizes[u]; }\n    int depth(size_t u) { return depths[u];\
    \ }\n};\n"
  code: "#pragma once\n\n#include <utility>\n#include <vector>\n\ntemplate<typename\
    \ T> struct SubtreeInfo {\n    using size_t = std::size_t;\n    template<class\
    \ U> using vector = std::vector<U>;\n    size_t n;\n    vector<size_t> parents,\
    \ sizes;\n    vector<T> depths;\n    SubtreeInfo(const vector<vector<size_t>>&\
    \ tree, size_t root): n(size(tree)), parents(n, -1), sizes(n, -1), depths(n, -1)\
    \ {\n        parents[root] = -1;\n        depths[root] = 0;\n        auto dfs\
    \ = [&](auto&& self, size_t v, size_t prev) -> void {\n            if (size(tree[v])\
    \ == 1) sizes[v] = 1;\n            for (const auto u: tree[v])\n             \
    \   if (u != prev) {\n                    parents[u] = v;\n                  \
    \  depths[u] = depths[v] + 1;\n                    if (sizes[u] == -1) self(self,\
    \ u, v);\n                    sizes[v] += sizes[u];\n                }\n     \
    \       sizes[v]++;\n        };\n        dfs(dfs, root, -1);\n    }\n    SubtreeInfo(const\
    \ vector<vector<std::pair<size_t, T>>>& tree, size_t root): n(size(tree)), parents(n,\
    \ -1), sizes(n, -1), depths(n, -1) {\n        parents[root] = -1;\n        depths[root]\
    \ = 0;\n        auto dfs = [&](auto&& self, size_t v, size_t prev) -> void {\n\
    \            if (size(tree[v]) == 1) sizes[v] = 1;\n            for (const auto&\
    \ [u, w]: tree[v])\n                if (u != prev) {\n                    parents[u]\
    \ = v;\n                    depths[u] = depths[v] + w;\n                    if\
    \ (sizes[u] == -1) self(self, u, v);\n                    sizes[v] += sizes[u];\n\
    \                }\n            sizes[v]++;\n        };\n        dfs(dfs, root,\
    \ -1);\n    }\n    size_t parent(size_t u) { return parents[u]; }\n    size_t\
    \ size(size_t u) { return sizes[u]; }\n    int depth(size_t u) { return depths[u];\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/subtree_info.hpp
  requiredBy: []
  timestamp: '2021-10-03 22:09:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/subtree_info.hpp
layout: document
title: "Subtree Info / \u90E8\u5206\u6728\u306E\u60C5\u5831"
---

## 概要

木グラフについて、各頂点についての深さ、親、部分木の大きさをまとめて求める。

## 使い方

- `SubtreeInfo info(tree, root)`: 根を`root`、として木`tree`について構築する。木は重み付き・重みなしに対応している。
- `info.parent(u)`: 頂点$u$の親。`root`の親は`-1`である。
- `info.size(u)`: 頂点$u$を根とした部分木の大きさ。
- `info.depth(u)`: 頂点$u$の深さ。

## 計算量

構築には$\mathcal{O}(N)$。クエリ$\mathcal{O}(1)$。
