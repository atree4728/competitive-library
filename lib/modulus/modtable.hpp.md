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
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/117.test.cpp
    title: test/yukicoder/117.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/modulus/modtable.hpp\"\n\n#include <cassert>\n#include\
    \ <vector>\n\ntemplate<typename M> class ModTable {\n    std::vector<M> m_fact,\
    \ m_fact_inv, m_inv;\n\n  public:\n    constexpr ModTable() = default;\n    constexpr\
    \ ModTable(const size_t n): m_fact(n + 1), m_fact_inv(n + 1), m_inv(n + 1) {\n\
    \        m_inv[1] = 1;\n        for (size_t i = 2; i <= n; ++i) m_inv[i] = -m_inv[M::mod()\
    \ % i] * (M::mod() / i);\n        m_fact[0] = 1;\n        for (size_t i = 0; i\
    \ < n; i++) m_fact[i + 1] = m_fact[i] * M{ i + 1 };\n        m_fact_inv[n] = m_fact[n].inv();\n\
    \        for (size_t i = n; i--;) m_fact_inv[i] = m_fact_inv[i + 1] * M{ i + 1\
    \ };\n    }\n    constexpr auto inv(const int i) const {\n        assert(i !=\
    \ 0);\n        return m_inv[i];\n    }\n    constexpr auto fact(const int i) const\
    \ { return m_fact[i]; }\n    constexpr auto fact_inv(const int i) const { return\
    \ m_fact_inv[i]; }\n    constexpr auto perm(const int i, const int j) const {\
    \ return i >= j ? fact(i) * fact_inv(i - j) : 0; }\n    constexpr auto binom(const\
    \ int i, const int j) const {\n        if (i < 0 or j < 0 or i < j) return M::raw(0);\n\
    \        return m_fact[i] * m_fact_inv[j] * m_fact_inv[i - j];\n    }\n    constexpr\
    \ auto homo(const int i, const int j) const {\n        if (i == 0 and j == 0)\
    \ return M::raw(1);\n        return binom(i + j - 1, j);\n    }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\ntemplate<typename\
    \ M> class ModTable {\n    std::vector<M> m_fact, m_fact_inv, m_inv;\n\n  public:\n\
    \    constexpr ModTable() = default;\n    constexpr ModTable(const size_t n):\
    \ m_fact(n + 1), m_fact_inv(n + 1), m_inv(n + 1) {\n        m_inv[1] = 1;\n  \
    \      for (size_t i = 2; i <= n; ++i) m_inv[i] = -m_inv[M::mod() % i] * (M::mod()\
    \ / i);\n        m_fact[0] = 1;\n        for (size_t i = 0; i < n; i++) m_fact[i\
    \ + 1] = m_fact[i] * M{ i + 1 };\n        m_fact_inv[n] = m_fact[n].inv();\n \
    \       for (size_t i = n; i--;) m_fact_inv[i] = m_fact_inv[i + 1] * M{ i + 1\
    \ };\n    }\n    constexpr auto inv(const int i) const {\n        assert(i !=\
    \ 0);\n        return m_inv[i];\n    }\n    constexpr auto fact(const int i) const\
    \ { return m_fact[i]; }\n    constexpr auto fact_inv(const int i) const { return\
    \ m_fact_inv[i]; }\n    constexpr auto perm(const int i, const int j) const {\
    \ return i >= j ? fact(i) * fact_inv(i - j) : 0; }\n    constexpr auto binom(const\
    \ int i, const int j) const {\n        if (i < 0 or j < 0 or i < j) return M::raw(0);\n\
    \        return m_fact[i] * m_fact_inv[j] * m_fact_inv[i - j];\n    }\n    constexpr\
    \ auto homo(const int i, const int j) const {\n        if (i == 0 and j == 0)\
    \ return M::raw(1);\n        return binom(i + j - 1, j);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/modulus/modtable.hpp
  requiredBy: []
  timestamp: '2022-01-29 19:35:55+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/117.test.cpp
  - test/aoj/DPL_5_D.test.cpp
  - test/aoj/DPL_5_B.test.cpp
  - test/aoj/DPL_5_E.test.cpp
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
