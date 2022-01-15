---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1140.test.cpp
    title: test/yukicoder/1140.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/math/sieve.hpp\"\n\n#include <cassert>\n#include <numeric>\n\
    #include <unordered_map>\n#include <vector>\n\ntemplate<class T = std::uint32_t>\
    \ struct Sieve {\n  private:\n    T n;\n    std::vector<T> min_factor;\n    std::vector<int>\
    \ m_mobius;\n\n  public:\n    explicit Sieve(const T n): n(n), min_factor(n +\
    \ 1), m_mobius(n + 1, 1) {\n        std::iota(begin(min_factor), end(min_factor),\
    \ 0);\n        for (T p = 2; p <= n; ++p) {\n            if (min_factor[p] !=\
    \ p) continue;\n            m_mobius[p] = -1;\n            for (T m = p * 2; m\
    \ <= n; m += p) {\n                if (min_factor[m] == m) min_factor[m] = p;\n\
    \                if (m / p % p == 0) m_mobius[m] = 0;\n                else m_mobius[m]\
    \ *= -1;\n            }\n        }\n    };\n    bool is_prime(const T n) const\
    \ {\n        assert(1 <= n and n <= n);\n        return n >= 2 and min_factor[n]\
    \ == n;\n    }\n    int mobius(const T n) const {\n        assert(1 <= n and n\
    \ <= n);\n        return m_mobius[n];\n    }\n    std::vector<T> factor(T n) const\
    \ {\n        assert(1 <= n and n <= n);\n        if (n == 1) return {};\n    \
    \    std::vector<T> factor{};\n        while (n != 1) {\n            factor.emplace_back(min_factor[n]);\n\
    \            n /= min_factor[n];\n        }\n        return factor;\n    }\n \
    \   T count_divisor(const T n) const {\n        assert(1 <= n and n <= n);\n \
    \       std::unordered_map<T, T> factor_map{};\n        for (const auto& p: this->factor(n))\
    \ factor_map[p]++;\n        return std::transform_reduce(cbegin(factor_map), cend(factor_map),\
    \ static_cast<T>(1), std::multiplies<>{},\n                                  \
    \   [](const auto p_e) { return p_e.second + 1; });\n    }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <numeric>\n#include <unordered_map>\n\
    #include <vector>\n\ntemplate<class T = std::uint32_t> struct Sieve {\n  private:\n\
    \    T n;\n    std::vector<T> min_factor;\n    std::vector<int> m_mobius;\n\n\
    \  public:\n    explicit Sieve(const T n): n(n), min_factor(n + 1), m_mobius(n\
    \ + 1, 1) {\n        std::iota(begin(min_factor), end(min_factor), 0);\n     \
    \   for (T p = 2; p <= n; ++p) {\n            if (min_factor[p] != p) continue;\n\
    \            m_mobius[p] = -1;\n            for (T m = p * 2; m <= n; m += p)\
    \ {\n                if (min_factor[m] == m) min_factor[m] = p;\n            \
    \    if (m / p % p == 0) m_mobius[m] = 0;\n                else m_mobius[m] *=\
    \ -1;\n            }\n        }\n    };\n    bool is_prime(const T n) const {\n\
    \        assert(1 <= n and n <= n);\n        return n >= 2 and min_factor[n] ==\
    \ n;\n    }\n    int mobius(const T n) const {\n        assert(1 <= n and n <=\
    \ n);\n        return m_mobius[n];\n    }\n    std::vector<T> factor(T n) const\
    \ {\n        assert(1 <= n and n <= n);\n        if (n == 1) return {};\n    \
    \    std::vector<T> factor{};\n        while (n != 1) {\n            factor.emplace_back(min_factor[n]);\n\
    \            n /= min_factor[n];\n        }\n        return factor;\n    }\n \
    \   T count_divisor(const T n) const {\n        assert(1 <= n and n <= n);\n \
    \       std::unordered_map<T, T> factor_map{};\n        for (const auto& p: this->factor(n))\
    \ factor_map[p]++;\n        return std::transform_reduce(cbegin(factor_map), cend(factor_map),\
    \ static_cast<T>(1), std::multiplies<>{},\n                                  \
    \   [](const auto p_e) { return p_e.second + 1; });\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/sieve.hpp
  requiredBy: []
  timestamp: '2022-01-16 00:36:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1140.test.cpp
documentation_of: lib/math/sieve.hpp
layout: document
title: "Eratosthenes's Sieve / \u7D20\u6570\u5224\u5B9A\u30FB\u5217\u6319"
---

Eratosthenes の篩。

## Usage
- `Sieve(const intmax_t n)`: constructor. $\mathcal{O}(n \log \log n)$.
- `bool is_prime(const intmax_t n)`: `n` の素数判定。$\mathcal{O}(\log n)$.
- `std::vector<intmax_t> factor(intmax_t n)`: `n` の素因数分解。sorted とは限らない。$\mathcal{O}(\log n)$.
- `intmax_t count_divisor(const intmax_t n)`: `n` の正の約数の個数。$\mathcal{O}(\log n)$.
