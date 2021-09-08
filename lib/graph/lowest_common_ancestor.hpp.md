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
    document_title: Lowest Common Ancestor
    links: []
  bundledCode: "#line 2 \"lib/graph/lowest_common_ancestor.hpp\"\n\n#line 2 \"lib/include.hpp\"\
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
    #line 4 \"lib/graph/lowest_common_ancestor.hpp\"\n\n/**\n * @brief Lowest Common\
    \ Ancestor\n * @note with doubling\n*/\n\nstruct LCA {\n    vector<int> parent,\
    \ depth;\n    vector<vector<int>> dp;\n    explicit LCA(const vector<vector<int>>\
    \ tree, int root):\n        parent(size(tree), -1), depth(size(tree), -1) {\n\
    \        depth[root] = 0;\n        auto init = [&](auto&& dfs, int v, int prev)\
    \ {\n            assert(parent[v] == -1 and depth[v] == -1);\n            parent[v]\
    \ = prev;\n            depth[v] = depth[prev] + 1;\n            for (const auto&\
    \ u: tree[u])\n                if (u != prev) self(self, u, v);\n        };\n\
    \        init(init, root, -1);\n        int max_depth = *max_element(begin(depth),\
    \ end(depth));\n    }\n};\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief Lowest Common\
    \ Ancestor\n * @note with doubling\n*/\n\nstruct LCA {\n    vector<int> parent,\
    \ depth;\n    vector<vector<int>> dp;\n    explicit LCA(const vector<vector<int>>\
    \ tree, int root):\n        parent(size(tree), -1), depth(size(tree), -1) {\n\
    \        depth[root] = 0;\n        auto init = [&](auto&& dfs, int v, int prev)\
    \ {\n            assert(parent[v] == -1 and depth[v] == -1);\n            parent[v]\
    \ = prev;\n            depth[v] = depth[prev] + 1;\n            for (const auto&\
    \ u: tree[u])\n                if (u != prev) self(self, u, v);\n        };\n\
    \        init(init, root, -1);\n        int max_depth = *max_element(begin(depth),\
    \ end(depth));\n    }\n};"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/graph/lowest_common_ancestor.hpp
  requiredBy: []
  timestamp: '2021-09-08 23:15:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/lowest_common_ancestor.hpp
layout: document
redirect_from:
- /library/lib/graph/lowest_common_ancestor.hpp
- /library/lib/graph/lowest_common_ancestor.hpp.html
title: Lowest Common Ancestor
---
