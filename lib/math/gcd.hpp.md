---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_C.test.cpp
    title: test/aoj/NTL_1_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/math/gcd.hpp\"\n\n#include <type_traits>\n\n#line 2\
    \ \"lib/include.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n#define\
    \ overload3(_1, _2, _3, name, ...) name\n#define rep1(n) for (auto _tmp = 0; _tmp\
    \ < (n); _tmp++)\n#define rep2(i, n) for (auto i = 0; i < (n); i++)\n#define rep3(i,\
    \ a, b) for (auto i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\ntemplate<class T> bool chmax(T &a, const T &b)\
    \ { return a < b and (a = b, true); }\ntemplate<class T> bool chmin(T &a, const\
    \ T &b) { return a > b and (a = b, true); }\nusing i64 = long long;\nusing f64\
    \ = long double;\n#line 6 \"lib/math/gcd.hpp\"\n\ntemplate<typename T> T mygcd(T\
    \ a, T b) {\n    static_assert(is_integral<T>::value);\n    while (a % b != 0)\
    \ {\n        T u = a % b;\n        a = b;\n        b = u;\n    }\n    return b;\n\
    }\n\ntemplate<typename T> T mylcm(T a, T b) { return a / mygcd(a, b) * b; }\n"
  code: "#pragma once\n\n#include <type_traits>\n\n#include \"../include.hpp\"\n\n\
    template<typename T> T mygcd(T a, T b) {\n    static_assert(is_integral<T>::value);\n\
    \    while (a % b != 0) {\n        T u = a % b;\n        a = b;\n        b = u;\n\
    \    }\n    return b;\n}\n\ntemplate<typename T> T mylcm(T a, T b) { return a\
    \ / mygcd(a, b) * b; }\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/math/gcd.hpp
  requiredBy: []
  timestamp: '2021-09-14 22:20:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/NTL_1_C.test.cpp
documentation_of: lib/math/gcd.hpp
layout: document
redirect_from:
- /library/lib/math/gcd.hpp
- /library/lib/math/gcd.hpp.html
title: lib/math/gcd.hpp
---
