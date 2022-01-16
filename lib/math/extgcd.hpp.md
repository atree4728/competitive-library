---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: lib/modulus/modint.hpp
    title: Modint
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_A.test.cpp
    title: test/aoj/DPL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_B.test.cpp
    title: test/aoj/DPL_5_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_D.test.cpp
    title: test/aoj/DPL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_E.test.cpp
    title: test/aoj/DPL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_B.test.cpp
    title: test/aoj/NTL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_E.test.cpp
    title: test/aoj/NTL_1_E.test.cpp
  - icon: ':x:'
    path: test/yukicoder/117.test.cpp
    title: test/yukicoder/117.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Extended Euclid's Algorithm
    links:
    - https://noshi91.hatenablog.com/entry/2019/04/01/184957
  bundledCode: "#line 2 \"lib/math/extgcd.hpp\"\n\n#include <cassert>\n#include <numeric>\n\
    #include <utility>\n\n/**\n * @brief Extended Euclid's Algorithm\n * @note return\
    \ pair of minimum x, y s.t. ax + by = gcd(x, y)\n * @ref https://noshi91.hatenablog.com/entry/2019/04/01/184957\n\
    \ */\n\nconstexpr std::pair<intmax_t, intmax_t> extgcd(intmax_t a, intmax_t b)\
    \ {\n    intmax_t s = a, xs = 1, ys = 0, t = b, xt = 0, yt = 1;\n    while (s\
    \ % t != 0) {\n        const intmax_t tmp = s / t,\n                       u =\
    \ s - t * tmp,\n                       xu = xs - xt * tmp,\n                 \
    \      yu = ys - yt * tmp;\n        s = t, xs = xt, ys = yt;\n        t = u, xt\
    \ = xu, yt = yu;\n    }\n    assert(t == std::gcd(a, b));\n    return { xt, yt\
    \ };\n}\n"
  code: "#pragma once\n\n#include <cassert>\n#include <numeric>\n#include <utility>\n\
    \n/**\n * @brief Extended Euclid's Algorithm\n * @note return pair of minimum\
    \ x, y s.t. ax + by = gcd(x, y)\n * @ref https://noshi91.hatenablog.com/entry/2019/04/01/184957\n\
    \ */\n\nconstexpr std::pair<intmax_t, intmax_t> extgcd(intmax_t a, intmax_t b)\
    \ {\n    intmax_t s = a, xs = 1, ys = 0, t = b, xt = 0, yt = 1;\n    while (s\
    \ % t != 0) {\n        const intmax_t tmp = s / t,\n                       u =\
    \ s - t * tmp,\n                       xu = xs - xt * tmp,\n                 \
    \      yu = ys - yt * tmp;\n        s = t, xs = xt, ys = yt;\n        t = u, xt\
    \ = xu, yt = yu;\n    }\n    assert(t == std::gcd(a, b));\n    return { xt, yt\
    \ };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/extgcd.hpp
  requiredBy:
  - lib/modulus/modint.hpp
  timestamp: '2021-11-16 17:42:48+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/NTL_1_B.test.cpp
  - test/aoj/DPL_5_E.test.cpp
  - test/aoj/NTL_1_E.test.cpp
  - test/aoj/DPL_5_D.test.cpp
  - test/aoj/DPL_5_B.test.cpp
  - test/aoj/DPL_5_A.test.cpp
  - test/yukicoder/117.test.cpp
documentation_of: lib/math/extgcd.hpp
layout: document
title: "Extended Euclidean algorithm / \u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5"
---

## 概要
$(a,b)\in\mathbb{Z}^2$ について、$ax+by=d$を満たす$(x,y)\in\mathbb{Z}^2$は、$\gcd(a,b)| d$のときのみに存在する。
この実装では、Euclid の互除法を用いて$\gcd(a,b)$を求めると同時に$(x,y)$を持つことで、$(x,y)\in\mathbb{Z}^2\mathrm{s.t.}ax+by=\gcd(a,b)$を求める。

## 使い方
- `extgcd(a, b)`: $(x,y)\in\mathbb{Z}^2\mathrm{s.t.}ax+by=\gcd(a,b)$ を`pair`として返す。

## 計算量
Euclid の互除法と同じく$\mathcal{O}(\log \max(a,b))$。
