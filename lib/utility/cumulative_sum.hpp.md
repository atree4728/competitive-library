---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Cumulative-Sum(1D)
    links: []
  bundledCode: "#line 2 \"lib/utility/cumulative_sum.hpp\"\n\n#include <vector>\n\n\
    using namespace std;\n\n/**\n * @brief Cumulative-Sum(1D)\n */\ntemplate <class\
    \ T>\nclass CumulativeSum1D {\n    vector<T> v;\n\n   public:\n    CumulativeSum1D(vector<T>\
    \ a) : v(size(a) + 1, 0) {\n        copy(begin(a), end(a), begin(v) + 1);\n  \
    \      for (size_t i = 1; i < size(v); i++) v[i] += v[i - 1];\n    }\n    inline\
    \ T operator()(int r) const { return v[r]; }\n    inline T operator()(int l, int\
    \ r) const { return v[r] - v[l]; }\n    vector<T> raw() { return v; }\n};\n\n\
    /**\n * @brief Cumulative-Sum(2D)\n */\ntemplate <class T>\nclass CumulativeSum2D\
    \ {\n    vector<vector<T>> vv;\n\n   public:\n    CumulativeSum2D(vector<vector<T>>\
    \ a)\n        : vv(size(a) + 1, vector<int>(size(a[0]) + 1, 0)) {\n        for\
    \ (int i = 0; i + 1 < size(vv); i++)\n            copy(begin(a[i]), end(a[i]),\
    \ begin(vv[i + 1]) + 1);\n        for (size_t i = 1; i < size(vv); i++) {\n  \
    \          for (size_t j = 1; j < size(vv[i]); j++)\n                vv[i][j]\
    \ += vv[i][j - 1] + vv[i - 1][j] - vv[i - 1][j - 1];\n        }\n    }\n    inline\
    \ T operator()(int sx, int sy, int gx, int gy) const {\n        return vv[gx][gy]\
    \ - vv[sx][gy] - vv[gx][sy] + vv[sx][sy];\n    }\n    vector<vector<T>> raw()\
    \ { return vv; }\n};\n"
  code: "#pragma once\n\n#include <vector>\n\nusing namespace std;\n\n/**\n * @brief\
    \ Cumulative-Sum(1D)\n */\ntemplate <class T>\nclass CumulativeSum1D {\n    vector<T>\
    \ v;\n\n   public:\n    CumulativeSum1D(vector<T> a) : v(size(a) + 1, 0) {\n \
    \       copy(begin(a), end(a), begin(v) + 1);\n        for (size_t i = 1; i <\
    \ size(v); i++) v[i] += v[i - 1];\n    }\n    inline T operator()(int r) const\
    \ { return v[r]; }\n    inline T operator()(int l, int r) const { return v[r]\
    \ - v[l]; }\n    vector<T> raw() { return v; }\n};\n\n/**\n * @brief Cumulative-Sum(2D)\n\
    \ */\ntemplate <class T>\nclass CumulativeSum2D {\n    vector<vector<T>> vv;\n\
    \n   public:\n    CumulativeSum2D(vector<vector<T>> a)\n        : vv(size(a) +\
    \ 1, vector<int>(size(a[0]) + 1, 0)) {\n        for (int i = 0; i + 1 < size(vv);\
    \ i++)\n            copy(begin(a[i]), end(a[i]), begin(vv[i + 1]) + 1);\n    \
    \    for (size_t i = 1; i < size(vv); i++) {\n            for (size_t j = 1; j\
    \ < size(vv[i]); j++)\n                vv[i][j] += vv[i][j - 1] + vv[i - 1][j]\
    \ - vv[i - 1][j - 1];\n        }\n    }\n    inline T operator()(int sx, int sy,\
    \ int gx, int gy) const {\n        return vv[gx][gy] - vv[sx][gy] - vv[gx][sy]\
    \ + vv[sx][sy];\n    }\n    vector<vector<T>> raw() { return vv; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/utility/cumulative_sum.hpp
  requiredBy: []
  timestamp: '2021-05-29 21:52:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/utility/cumulative_sum.hpp
layout: document
redirect_from:
- /library/lib/utility/cumulative_sum.hpp
- /library/lib/utility/cumulative_sum.hpp.html
title: Cumulative-Sum(1D)
---
