---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/static_range_sum.test.cpp
    title: test/library-checker/static_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Partial Sum
    links: []
  bundledCode: "#line 2 \"lib/data_structure/cumulative_sum.hpp\"\n\n#line 2 \"lib/include.hpp\"\
    \n\n#include <bits/stdc++.h>\n#include <experimental/iterator>\nusing namespace\
    \ std;\n#define overload3(_1, _2, _3, name, ...) name\n#define rep1(n) for (decltype(n)\
    \ _tmp = 0; _tmp < n; _tmp++)\n#define rep2(i, n) for (decltype(n) i = 0; i <\
    \ n; i++)\n#define rep3(i, a, b) for (decltype(b) i = a; i < b; i++)\n#define\
    \ rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\nstruct IOSetup\
    \ { IOSetup() noexcept { ios::sync_with_stdio(false); cin.tie(nullptr); cout <<\
    \ fixed << setprecision(10); cerr << fixed << setprecision(10); } } iosetup;\n\
    template <class T> bool chmax(T &a, const T &b) { return a < b and (a = b, true);\
    \ }\ntemplate <class T> bool chmin(T &a, const T &b) { return a > b and (a = b,\
    \ true); }\nusing i64 = long long;\nusing u64 = unsigned long long;\nusing f64\
    \ = long double;\n#line 4 \"lib/data_structure/cumulative_sum.hpp\"\n\n/**\n *\
    \ @brief Partial Sum\n * @note construct in $O(N)$, query in $O(1)$ to return\
    \ partial sum\n */\n\ntemplate<class T> struct CumSum {\n    vector<T> v;\n  \
    \  CumSum(vector<T> a):\n        v(size(a) + 1, 0) {\n        copy(begin(a), end(a),\
    \ begin(v) + 1);\n        rep(i, 1, size(v)) v[i] += v[i - 1];\n    }\n    T operator()(int\
    \ r) { return v[r]; }\n    T operator()(int l, int r) { return v[r] - v[l]; }\n\
    };\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief Partial Sum\n\
    \ * @note construct in $O(N)$, query in $O(1)$ to return partial sum\n */\n\n\
    template<class T> struct CumSum {\n    vector<T> v;\n    CumSum(vector<T> a):\n\
    \        v(size(a) + 1, 0) {\n        copy(begin(a), end(a), begin(v) + 1);\n\
    \        rep(i, 1, size(v)) v[i] += v[i - 1];\n    }\n    T operator()(int r)\
    \ { return v[r]; }\n    T operator()(int l, int r) { return v[r] - v[l]; }\n};\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/data_structure/cumulative_sum.hpp
  requiredBy: []
  timestamp: '2021-07-21 10:45:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/static_range_sum.test.cpp
documentation_of: lib/data_structure/cumulative_sum.hpp
layout: document
redirect_from:
- /library/lib/data_structure/cumulative_sum.hpp
- /library/lib/data_structure/cumulative_sum.hpp.html
title: Partial Sum
---
