---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0560.test.cpp
    title: test/aoj/0560.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Partial Sum(2D)
    links: []
  bundledCode: "#line 2 \"lib/data_structure/cumulative_sum_2D.hpp\"\n\n#line 2 \"\
    lib/include.hpp\"\n\n#include <bits/stdc++.h>\n#include <experimental/iterator>\n\
    using namespace std;\n#define overload3(_1, _2, _3, name, ...) name\n#define rep1(n)\
    \ for (decltype(n) _tmp = 0; _tmp < n; _tmp++)\n#define rep2(i, n) for (decltype(n)\
    \ i = 0; i < n; i++)\n#define rep3(i, a, b) for (decltype(b) i = a; i < b; i++)\n\
    #define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\nstruct\
    \ IOSetup { IOSetup() noexcept { ios::sync_with_stdio(false); cin.tie(nullptr);\
    \ cout << fixed << setprecision(10); cerr << fixed << setprecision(10); } } iosetup;\n\
    template <class T> bool chmax(T &a, const T &b) { return a < b and (a = b, true);\
    \ }\ntemplate <class T> bool chmin(T &a, const T &b) { return a > b and (a = b,\
    \ true); }\nusing i64 = long long;\nusing u64 = unsigned long long;\nusing f64\
    \ = long double;\n#line 4 \"lib/data_structure/cumulative_sum_2D.hpp\"\n\n/**\n\
    \ * @brief Partial Sum(2D)\n * @note construct in $O(N^2)$, query in $O(1)$ to\
    \ return partial sum(2D)\n */\n\ntemplate<class T> struct CumSum2D {\n    vector<vector<T>>\
    \ vv;\n    CumSum2D(vector<vector<T>> a):\n        vv(size(a) + 1, vector<T>(size(a[0])\
    \ + 1, 0)) {\n        rep(i, size(vv) - 1) copy(begin(a[i]), end(a[i]), begin(vv[i\
    \ + 1]) + 1);\n        rep(i, 1, size(vv)) rep(j, 1, size(vv[i])) vv[i][j] +=\
    \ vv[i][j - 1] + vv[i - 1][j] - vv[i - 1][j - 1];\n    }\n    T operator()(size_t\
    \ sx, size_t sy, size_t gx, size_t gy) { return vv[gx][gy] - vv[sx][gy] - vv[gx][sy]\
    \ + vv[sx][sy]; }\n};\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief Partial Sum(2D)\n\
    \ * @note construct in $O(N^2)$, query in $O(1)$ to return partial sum(2D)\n */\n\
    \ntemplate<class T> struct CumSum2D {\n    vector<vector<T>> vv;\n    CumSum2D(vector<vector<T>>\
    \ a):\n        vv(size(a) + 1, vector<T>(size(a[0]) + 1, 0)) {\n        rep(i,\
    \ size(vv) - 1) copy(begin(a[i]), end(a[i]), begin(vv[i + 1]) + 1);\n        rep(i,\
    \ 1, size(vv)) rep(j, 1, size(vv[i])) vv[i][j] += vv[i][j - 1] + vv[i - 1][j]\
    \ - vv[i - 1][j - 1];\n    }\n    T operator()(size_t sx, size_t sy, size_t gx,\
    \ size_t gy) { return vv[gx][gy] - vv[sx][gy] - vv[gx][sy] + vv[sx][sy]; }\n};\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/data_structure/cumulative_sum_2D.hpp
  requiredBy: []
  timestamp: '2021-07-21 10:45:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0560.test.cpp
documentation_of: lib/data_structure/cumulative_sum_2D.hpp
layout: document
redirect_from:
- /library/lib/data_structure/cumulative_sum_2D.hpp
- /library/lib/data_structure/cumulative_sum_2D.hpp.html
title: Partial Sum(2D)
---
