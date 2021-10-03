---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_E.test.cpp
    title: test/aoj/NTL_1_E.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Extended Euclid's Algorithm
    links:
    - https://noshi91.hatenablog.com/entry/2019/04/01/184957
  bundledCode: "#line 2 \"lib/math/extgcd.hpp\"\n\n#include <cassert>\n#include <numeric>\n\
    #include <utility>\n\n/**\n * @brief Extended Euclid's Algorithm\n * @note return\
    \ pair of minimum x, y s.t. ax + by = gcd(x, y)\n * @ref https://noshi91.hatenablog.com/entry/2019/04/01/184957\n\
    \ */\n\ntemplate<typename T> std::pair<T, T> extgcd(T a, T b) {\n    static_assert(std::is_integral<T>::value);\n\
    \    T s = a, xs = 1, ys = 0, t = b, xt = 0, yt = 1;\n    while (s % t != 0) {\n\
    \        T tmp = s / t,\n          u = s - t * tmp,\n          xu = xs - xt *\
    \ tmp,\n          yu = ys - yt * tmp;\n        s = t, xs = xt, ys = yt;\n    \
    \    t = u, xt = xu, yt = yu;\n    }\n    assert(t == std::gcd(a, b));\n    return\
    \ { xt, yt };\n}\n"
  code: "#pragma once\n\n#include <cassert>\n#include <numeric>\n#include <utility>\n\
    \n/**\n * @brief Extended Euclid's Algorithm\n * @note return pair of minimum\
    \ x, y s.t. ax + by = gcd(x, y)\n * @ref https://noshi91.hatenablog.com/entry/2019/04/01/184957\n\
    \ */\n\ntemplate<typename T> std::pair<T, T> extgcd(T a, T b) {\n    static_assert(std::is_integral<T>::value);\n\
    \    T s = a, xs = 1, ys = 0, t = b, xt = 0, yt = 1;\n    while (s % t != 0) {\n\
    \        T tmp = s / t,\n          u = s - t * tmp,\n          xu = xs - xt *\
    \ tmp,\n          yu = ys - yt * tmp;\n        s = t, xs = xt, ys = yt;\n    \
    \    t = u, xt = xu, yt = yu;\n    }\n    assert(t == std::gcd(a, b));\n    return\
    \ { xt, yt };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/extgcd.hpp
  requiredBy: []
  timestamp: '2021-10-03 22:04:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/NTL_1_E.test.cpp
documentation_of: lib/math/extgcd.hpp
layout: document
redirect_from:
- /library/lib/math/extgcd.hpp
- /library/lib/math/extgcd.hpp.html
title: Extended Euclid's Algorithm
---
