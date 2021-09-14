---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/subtree_info.md
    document_title: "Subtree Info / \u90E8\u5206\u6728\u306E\u60C5\u5831"
    links: []
  bundledCode: "#line 2 \"lib/graph/subtree_info.hpp\"\n\n#line 2 \"lib/include.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_1, _2,\
    \ _3, name, ...) name\n#define rep1(n) for (auto _tmp = 0; _tmp < (n); _tmp++)\n\
    #define rep2(i, n) for (auto i = 0; i < (n); i++)\n#define rep3(i, a, b) for (auto\
    \ i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n\
    template<class T> bool chmax(T &a, const T &b) { return a < b and (a = b, true);\
    \ }\ntemplate<class T> bool chmin(T &a, const T &b) { return a > b and (a = b,\
    \ true); }\nusing i64 = long long;\nusing f64 = long double;\n#line 4 \"lib/graph/subtree_info.hpp\"\
    \n\n/**\n * @brief Subtree Info / \u90E8\u5206\u6728\u306E\u60C5\u5831\n * @docs\
    \ docs/subtree_info.md\n */\n\ntemplate<typename T> struct SubtreeInfo {\n   \
    \ int n;\n    vector<int> parents, sizes;\n    vector<T> depths;\n    SubtreeInfo(const\
    \ vector<vector<int>>& tree, int root):\n        n(size(tree)), parents(n, -1),\
    \ sizes(n, -1), depths(n, -1) {\n        parents[root] = -1;\n        depths[root]\
    \ = 0;\n        auto dfs = [&](auto&& self, int v, int prev) -> void {\n     \
    \       if (size(tree[v]) == 1) sizes[v] = 1;\n            for (const auto& u:\
    \ tree[v])\n                if (u != prev) {\n                    parents[u] =\
    \ v;\n                    depths[u] = depths[v] + 1;\n                    if (sizes[u]\
    \ == -1) self(self, u, v);\n                    sizes[v] += sizes[u];\n      \
    \          }\n            sizes[v]++;\n        };\n        dfs(dfs, root, -1);\n\
    \    }\n    SubtreeInfo(const vector<vector<pair<int, T>>>& tree, int root):\n\
    \        n(size(tree)), parents(n, -1), sizes(n, -1), depths(n, -1) {\n      \
    \  parents[root] = -1;\n        depths[root] = 0;\n        auto dfs = [&](auto&&\
    \ self, int v, int prev) -> void {\n            if (size(tree[v]) == 1) sizes[v]\
    \ = 1;\n            for (const auto& [u, w]: tree[v])\n                if (u !=\
    \ prev) {\n                    parents[u] = v;\n                    depths[u]\
    \ = depths[v] + w;\n                    if (sizes[u] == -1) self(self, u, v);\n\
    \                    sizes[v] += sizes[u];\n                }\n            sizes[v]++;\n\
    \        };\n        dfs(dfs, root, -1);\n    }\n    int parent(int u) { return\
    \ parents[u]; }\n    int size(int u) { return sizes[u]; }\n    int depth(int u)\
    \ { return depths[u]; }\n};\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief Subtree Info\
    \ / \u90E8\u5206\u6728\u306E\u60C5\u5831\n * @docs docs/subtree_info.md\n */\n\
    \ntemplate<typename T> struct SubtreeInfo {\n    int n;\n    vector<int> parents,\
    \ sizes;\n    vector<T> depths;\n    SubtreeInfo(const vector<vector<int>>& tree,\
    \ int root):\n        n(size(tree)), parents(n, -1), sizes(n, -1), depths(n, -1)\
    \ {\n        parents[root] = -1;\n        depths[root] = 0;\n        auto dfs\
    \ = [&](auto&& self, int v, int prev) -> void {\n            if (size(tree[v])\
    \ == 1) sizes[v] = 1;\n            for (const auto& u: tree[v])\n            \
    \    if (u != prev) {\n                    parents[u] = v;\n                 \
    \   depths[u] = depths[v] + 1;\n                    if (sizes[u] == -1) self(self,\
    \ u, v);\n                    sizes[v] += sizes[u];\n                }\n     \
    \       sizes[v]++;\n        };\n        dfs(dfs, root, -1);\n    }\n    SubtreeInfo(const\
    \ vector<vector<pair<int, T>>>& tree, int root):\n        n(size(tree)), parents(n,\
    \ -1), sizes(n, -1), depths(n, -1) {\n        parents[root] = -1;\n        depths[root]\
    \ = 0;\n        auto dfs = [&](auto&& self, int v, int prev) -> void {\n     \
    \       if (size(tree[v]) == 1) sizes[v] = 1;\n            for (const auto& [u,\
    \ w]: tree[v])\n                if (u != prev) {\n                    parents[u]\
    \ = v;\n                    depths[u] = depths[v] + w;\n                    if\
    \ (sizes[u] == -1) self(self, u, v);\n                    sizes[v] += sizes[u];\n\
    \                }\n            sizes[v]++;\n        };\n        dfs(dfs, root,\
    \ -1);\n    }\n    int parent(int u) { return parents[u]; }\n    int size(int\
    \ u) { return sizes[u]; }\n    int depth(int u) { return depths[u]; }\n};\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/graph/subtree_info.hpp
  requiredBy: []
  timestamp: '2021-09-14 22:20:52+09:00'
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