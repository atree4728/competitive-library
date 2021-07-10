---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: lib/test/aoj/0560.test.cpp
    title: lib/test/aoj/0560.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Partial Sum(2D)
    links: []
  bundledCode: "#line 2 \"lib/utility/cumulative_sum_2D.hpp\"\n\n#line 2 \"lib/include.hpp\"\
    \n#include <bits/stdc++.h>\n#include <experimental/iterator>\nusing namespace\
    \ std;\n#define overload3(_1, _2, _3, name, ...) name\n#define rep1(n) for (auto\
    \ _i = 0; _i < n; _i++)\n#define rep2(i, n) for (auto i = 0; i < n; i++)\n#define\
    \ rep3(i, a, b) for (auto i = a; i < b; i++)\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\ntemplate <class T> bool chmax(T &a, const T\
    \ &b) { return a < b ? a = b, true : false; }\ntemplate <class T> bool chmin(T\
    \ &a, const T &b) { return a > b ? a = b, true : false; }\nusing i64 = long long;\n\
    using f64 = long double;\n#line 4 \"lib/utility/cumulative_sum_2D.hpp\"\n\n/**\n\
    \ * @brief Partial Sum(2D)\n * @note construct in $O(N^2)$, query in $O(1)$ to\
    \ return partial sum(2D)\n */\n\ntemplate<class T> class CumulativeSum2D {\n \
    \   vector<vector<T>> vv;\n\n  public:\n    CumulativeSum2D(vector<vector<T>>\
    \ a):\n        vv(a.size() + 1, vector<int>(a[0].size() + 1, 0)) {\n        for\
    \ (size_t i = 0; i + 1 < vv.size(); i++) copy(begin(a[i]), end(a[i]), begin(vv[i\
    \ + 1]) + 1);\n        for (size_t i = 1; i < vv.size(); i++) {\n            for\
    \ (size_t j = 1; j < vv[i].size(); j++)\n                vv[i][j] += vv[i][j -\
    \ 1] + vv[i - 1][j] - vv[i - 1][j - 1];\n        }\n    }\n    T operator()(size_t\
    \ sx, size_t sy, size_t gx, size_t gy) { return vv[gx][gy] - vv[sx][gy] - vv[gx][sy]\
    \ + vv[sx][sy]; }\n    vector<vector<T>> raw() { return vv; }\n};\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief Partial Sum(2D)\n\
    \ * @note construct in $O(N^2)$, query in $O(1)$ to return partial sum(2D)\n */\n\
    \ntemplate<class T> class CumulativeSum2D {\n    vector<vector<T>> vv;\n\n  public:\n\
    \    CumulativeSum2D(vector<vector<T>> a):\n        vv(a.size() + 1, vector<int>(a[0].size()\
    \ + 1, 0)) {\n        for (size_t i = 0; i + 1 < vv.size(); i++) copy(begin(a[i]),\
    \ end(a[i]), begin(vv[i + 1]) + 1);\n        for (size_t i = 1; i < vv.size();\
    \ i++) {\n            for (size_t j = 1; j < vv[i].size(); j++)\n            \
    \    vv[i][j] += vv[i][j - 1] + vv[i - 1][j] - vv[i - 1][j - 1];\n        }\n\
    \    }\n    T operator()(size_t sx, size_t sy, size_t gx, size_t gy) { return\
    \ vv[gx][gy] - vv[sx][gy] - vv[gx][sy] + vv[sx][sy]; }\n    vector<vector<T>>\
    \ raw() { return vv; }\n};\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/utility/cumulative_sum_2D.hpp
  requiredBy: []
  timestamp: '2021-07-10 14:38:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - lib/test/aoj/0560.test.cpp
documentation_of: lib/utility/cumulative_sum_2D.hpp
layout: document
redirect_from:
- /library/lib/utility/cumulative_sum_2D.hpp
- /library/lib/utility/cumulative_sum_2D.hpp.html
title: Partial Sum(2D)
---
