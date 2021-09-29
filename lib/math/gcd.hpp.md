---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/NTL_1_C.test.cpp
    title: test/aoj/NTL_1_C.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/math/gcd.hpp\"\n\n#include <type_traits>\n\n#line 2\
    \ \"lib/include.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n#define\
    \ overload3(_NULL, _2, _3, name, ...) name\n#define rep1(i, n) for (remove_const_t<remove_reference_t<decltype(n)>>\
    \ i = 0; i < (n); i++)\n#define rep2(i, a, b) for (remove_const_t<remove_reference_t<decltype(b)>>\
    \ i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)\n\
    using size_type = size_t;\n#line 6 \"lib/math/gcd.hpp\"\n\ntemplate<typename T>\
    \ T mygcd(T a, T b) {\n    static_assert(is_integral<T>::value);\n    while (a\
    \ % b != 0) {\n        T u = a % b;\n        a = b;\n        b = u;\n    }\n \
    \   return b;\n}\n\ntemplate<typename T> T mylcm(T a, T b) { return a / mygcd(a,\
    \ b) * b; }\n"
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
  timestamp: '2021-09-29 20:09:01+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/NTL_1_C.test.cpp
documentation_of: lib/math/gcd.hpp
layout: document
redirect_from:
- /library/lib/math/gcd.hpp
- /library/lib/math/gcd.hpp.html
title: lib/math/gcd.hpp
---
