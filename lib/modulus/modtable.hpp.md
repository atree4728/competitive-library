---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DPL_5_B.test.cpp
    title: test/aoj/DPL_5_B.test.cpp
  - icon: ':x:'
    path: test/aoj/DPL_5_D.test.cpp
    title: test/aoj/DPL_5_D.test.cpp
  - icon: ':x:'
    path: test/aoj/DPL_5_E.test.cpp
    title: test/aoj/DPL_5_E.test.cpp
  - icon: ':x:'
    path: test/yukicoder/117.test.cpp
    title: test/yukicoder/117.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/modulus/modtable.hpp\"\n\n#include <cassert>\n#include\
    \ <vector>\n\ntemplate<typename Modint> class ModTable {\n    std::vector<Modint>\
    \ factorials, factorials_inv, inverse;\n\n  public:\n    constexpr ModTable()\
    \ = default;\n    constexpr ModTable(const size_t n): factorials(n + 1), factorials_inv(n\
    \ + 1), inverse(n + 1) {\n        inverse[1] = 1;\n        for (size_t i = 2;\
    \ i <= n; ++i) inverse[i] = -inverse[Modint::mod() % i] * (Modint::mod() / i);\n\
    \        factorials[0] = 1;\n        for (size_t i = 0; i < n; i++) factorials[i\
    \ + 1] = factorials[i] * Modint{ i + 1 };\n        factorials_inv[n] = factorials[n].inv();\n\
    \        for (size_t i = n; i--;) factorials_inv[i] = factorials_inv[i + 1] *\
    \ Modint{ i + 1 };\n    }\n    constexpr auto inv(const int i) const {\n     \
    \   assert(i != 0);\n        return inverse[i];\n    }\n    constexpr auto fact(const\
    \ int i) const { return factorials[i]; }\n    constexpr auto fact_inv(const int\
    \ i) const { return factorials_inv[i]; }\n    constexpr auto perm(const int i,\
    \ const int j) const { return i >= j ? fact(i) * fact_inv(i - j) : 0; }\n    constexpr\
    \ auto binom(const int i, const int j) const {\n        if (i < 0 or j < 0 or\
    \ i < j) return Modint::raw(0);\n        return factorials[i] * factorials_inv[j]\
    \ * factorials_inv[i - j];\n    }\n    constexpr auto homo(const int i, const\
    \ int j) const {\n        if (i == 0 and j == 0) return Modint::raw(1);\n    \
    \    return binom(i + j - 1, j);\n    }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\ntemplate<typename\
    \ Modint> class ModTable {\n    std::vector<Modint> factorials, factorials_inv,\
    \ inverse;\n\n  public:\n    constexpr ModTable() = default;\n    constexpr ModTable(const\
    \ size_t n): factorials(n + 1), factorials_inv(n + 1), inverse(n + 1) {\n    \
    \    inverse[1] = 1;\n        for (size_t i = 2; i <= n; ++i) inverse[i] = -inverse[Modint::mod()\
    \ % i] * (Modint::mod() / i);\n        factorials[0] = 1;\n        for (size_t\
    \ i = 0; i < n; i++) factorials[i + 1] = factorials[i] * Modint{ i + 1 };\n  \
    \      factorials_inv[n] = factorials[n].inv();\n        for (size_t i = n; i--;)\
    \ factorials_inv[i] = factorials_inv[i + 1] * Modint{ i + 1 };\n    }\n    constexpr\
    \ auto inv(const int i) const {\n        assert(i != 0);\n        return inverse[i];\n\
    \    }\n    constexpr auto fact(const int i) const { return factorials[i]; }\n\
    \    constexpr auto fact_inv(const int i) const { return factorials_inv[i]; }\n\
    \    constexpr auto perm(const int i, const int j) const { return i >= j ? fact(i)\
    \ * fact_inv(i - j) : 0; }\n    constexpr auto binom(const int i, const int j)\
    \ const {\n        if (i < 0 or j < 0 or i < j) return Modint::raw(0);\n     \
    \   return factorials[i] * factorials_inv[j] * factorials_inv[i - j];\n    }\n\
    \    constexpr auto homo(const int i, const int j) const {\n        if (i == 0\
    \ and j == 0) return Modint::raw(1);\n        return binom(i + j - 1, j);\n  \
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/modulus/modtable.hpp
  requiredBy: []
  timestamp: '2022-01-16 23:42:32+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DPL_5_E.test.cpp
  - test/aoj/DPL_5_D.test.cpp
  - test/aoj/DPL_5_B.test.cpp
  - test/yukicoder/117.test.cpp
documentation_of: lib/modulus/modtable.hpp
layout: document
title: Combinatorics Table on mod
---

前計算により二項係数などのクエリを高速に処理する。全てのメンバは`constexpr`化されている。
ref: https://noshi91.hatenablog.com/entry/2019/10/18/182935

## Usage
- `Modtable<Modint>(int n)`: クエリの最大値を$n$とした constructor. $\mathcal{O}(n)$.
- `constexpr Modint inv(const int n)`: $n^{-1}$. $\mathcal{O}(1)$.
- `constexpr Modint fact(const int n)`: $n!$. $\mathcal{O}(1)$.
- `constexpr Modint fact_inv(const int n)`: $n!^{-1}$. $\mathcal{O}(1)$.
- `constexpr Modint perm(const int n, const int r)`: $_nP_r$. $\mathcal{O}(1)$.
- `constexpr Modint binom(const int n, const int r)`: $_nC_r$. $\mathcal{O}(1)$.
- `constexpr Modint homo(const int n, const int r)`: $_nH_r$. $\mathcal{O}(1)$.
