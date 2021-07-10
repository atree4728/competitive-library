---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: lib/test/library-checker/unionfind.test.cpp
    title: lib/test/library-checker/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Union-Find
    links: []
  bundledCode: "#line 2 \"lib/data_structure/union_find.hpp\"\n\n#line 2 \"lib/include.hpp\"\
    \n#include <bits/stdc++.h>\n#include <experimental/iterator>\nusing namespace\
    \ std;\n#define overload3(_1, _2, _3, name, ...) name\n#define rep1(n) for (auto\
    \ _i = 0; _i < n; _i++)\n#define rep2(i, n) for (auto i = 0; i < n; i++)\n#define\
    \ rep3(i, a, b) for (auto i = a; i < b; i++)\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\ntemplate <class T> bool chmax(T &a, const T\
    \ &b) { return a < b ? a = b, true : false; }\ntemplate <class T> bool chmin(T\
    \ &a, const T &b) { return a > b ? a = b, true : false; }\nusing i64 = long long;\n\
    using f64 = long double;\n#line 4 \"lib/data_structure/union_find.hpp\"\n\n/**\n\
    \ * @brief Union-Find\n */\nstruct UnionFind {\n    vector<int> parents_or_size;\n\
    \    UnionFind(int size_):\n        parents_or_size(size_, -1) {}\n    bool unite(int\
    \ u, int v) {\n        u = root(u), v = root(v);\n        if (u == v) return false;\n\
    \        if (parents_or_size[u] > parents_or_size[v]) swap(u, v);\n        parents_or_size[u]\
    \ += parents_or_size[v];\n        parents_or_size[v] = u;\n        return true;\n\
    \    }\n    int root(int k) { return parents_or_size[k] < 0 ? k : parents_or_size[k]\
    \ = root(parents_or_size[k]); }\n    int size(int k) { return -parents_or_size[root(k)];\
    \ }\n    bool same(int u, int v) { return root(u) == root(v); }\n    vector<vector<int>>\
    \ groups() {\n        size_t n = parents_or_size.size();\n        vector<vector<int>>\
    \ ret(n);\n        rep(i, n) ret[root(i)].emplace_back(i);\n        ret.erase(remove_if(begin(ret),\
    \ end(ret), [&](const vector<int> &v) { return v.empty(); }));\n        return\
    \ ret;\n    }\n};\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief Union-Find\n\
    \ */\nstruct UnionFind {\n    vector<int> parents_or_size;\n    UnionFind(int\
    \ size_):\n        parents_or_size(size_, -1) {}\n    bool unite(int u, int v)\
    \ {\n        u = root(u), v = root(v);\n        if (u == v) return false;\n  \
    \      if (parents_or_size[u] > parents_or_size[v]) swap(u, v);\n        parents_or_size[u]\
    \ += parents_or_size[v];\n        parents_or_size[v] = u;\n        return true;\n\
    \    }\n    int root(int k) { return parents_or_size[k] < 0 ? k : parents_or_size[k]\
    \ = root(parents_or_size[k]); }\n    int size(int k) { return -parents_or_size[root(k)];\
    \ }\n    bool same(int u, int v) { return root(u) == root(v); }\n    vector<vector<int>>\
    \ groups() {\n        size_t n = parents_or_size.size();\n        vector<vector<int>>\
    \ ret(n);\n        rep(i, n) ret[root(i)].emplace_back(i);\n        ret.erase(remove_if(begin(ret),\
    \ end(ret), [&](const vector<int> &v) { return v.empty(); }));\n        return\
    \ ret;\n    }\n};\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/data_structure/union_find.hpp
  requiredBy: []
  timestamp: '2021-07-10 14:38:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - lib/test/library-checker/unionfind.test.cpp
documentation_of: lib/data_structure/union_find.hpp
layout: document
redirect_from:
- /library/lib/data_structure/union_find.hpp
- /library/lib/data_structure/union_find.hpp.html
title: Union-Find
---
