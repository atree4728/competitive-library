---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_D.test.cpp
    title: test/aoj/NTL_1_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/math/euler_phi.hpp\"\n\n#include <cassert>\n\ntemplate<typename\
    \ T> T euler_phi(T n) {\n    assert(n > 0);\n    T ret = n;\n    for (T i = 2;\
    \ i * i <= n; i++) {\n        if (n % i == 0) {\n            ret -= ret / i;\n\
    \            while (n % i == 0) n /= i;\n        }\n    }\n    if (n > 1) ret\
    \ -= ret / n;\n    return ret;\n}\n"
  code: "#pragma once\n\n#include <cassert>\n\ntemplate<typename T> T euler_phi(T\
    \ n) {\n    assert(n > 0);\n    T ret = n;\n    for (T i = 2; i * i <= n; i++)\
    \ {\n        if (n % i == 0) {\n            ret -= ret / i;\n            while\
    \ (n % i == 0) n /= i;\n        }\n    }\n    if (n > 1) ret -= ret / n;\n   \
    \ return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/euler_phi.hpp
  requiredBy: []
  timestamp: '2021-10-03 22:09:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/NTL_1_D.test.cpp
documentation_of: lib/math/euler_phi.hpp
layout: document
title: Euler's totient function / $\varphi(n)$
---

## 概要
オイラーのトーシェント関数$\varphi(n)$は、正整数$n$に対して、 $n$と互いに素である$1$以上$n$以下の自然数の個数を与える数論的関数である。
$$\varphi(n)=\sum_{m \in [1, n] \cup{\mathbb{Z}}, gcd(n,m)=1}1$$
である。また、$\varphi(n)$は乗法的関数であることでも知られる。

## 使い方
- `euler_phi(n)`: $\varphi(n)$。

## 計算量
$\mathcal{O}(\sqrt{n})$。
