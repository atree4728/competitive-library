---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: lib/test/library-checker/static_range_sum.test.cpp
    title: lib/test/library-checker/static_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Partial Sum
    links: []
  bundledCode: "#line 2 \"lib/utility/cumulative_sum.hpp\"\n\n#line 2 \"lib/include.hpp\"\
    \n#include <bits/stdc++.h>\n#include <experimental/iterator>\nusing namespace\
    \ std;\n#define overload3(_1, _2, _3, name, ...) name\n#define rep1(n) for (auto\
    \ _i = 0; _i < n; _i++)\n#define rep2(i, n) for (auto i = 0; i < n; i++)\n#define\
    \ rep3(i, a, b) for (auto i = a; i < b; i++)\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\ntemplate <class T> bool chmax(T &a, const T\
    \ &b) { return a < b ? a = b, true : false; }\ntemplate <class T> bool chmin(T\
    \ &a, const T &b) { return a > b ? a = b, true : false; }\nusing i64 = long long;\n\
    using f64 = long double;\n#line 4 \"lib/utility/cumulative_sum.hpp\"\n\n/**\n\
    \ * @brief Partial Sum\n * @note construct in $O(N)$, query in $O(1)$ to return\
    \ partial sum\n */\n\ntemplate<class T> class CumulativeSum1D {\n    vector<T>\
    \ v;\n\n  public:\n    CumulativeSum1D(vector<T> a):\n        v(a.size() + 1,\
    \ 0) {\n        copy(begin(a), end(a), begin(v) + 1);\n        for (size_t i =\
    \ 1; i < v.size(); i++) v[i] += v[i - 1];\n    }\n    T operator()(int r) { return\
    \ v[r]; }\n    T operator()(int l, int r) { return v[r] - v[l]; }\n    vector<T>\
    \ raw() { return v; }\n};\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief Partial Sum\n\
    \ * @note construct in $O(N)$, query in $O(1)$ to return partial sum\n */\n\n\
    template<class T> class CumulativeSum1D {\n    vector<T> v;\n\n  public:\n   \
    \ CumulativeSum1D(vector<T> a):\n        v(a.size() + 1, 0) {\n        copy(begin(a),\
    \ end(a), begin(v) + 1);\n        for (size_t i = 1; i < v.size(); i++) v[i] +=\
    \ v[i - 1];\n    }\n    T operator()(int r) { return v[r]; }\n    T operator()(int\
    \ l, int r) { return v[r] - v[l]; }\n    vector<T> raw() { return v; }\n};\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/utility/cumulative_sum.hpp
  requiredBy: []
  timestamp: '2021-07-10 14:38:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - lib/test/library-checker/static_range_sum.test.cpp
documentation_of: lib/utility/cumulative_sum.hpp
layout: document
redirect_from:
- /library/lib/utility/cumulative_sum.hpp
- /library/lib/utility/cumulative_sum.hpp.html
title: Partial Sum
---
