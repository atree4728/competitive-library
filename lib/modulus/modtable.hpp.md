---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_B.test.cpp
    title: test/aoj/DPL_5_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_D.test.cpp
    title: test/aoj/DPL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_E.test.cpp
    title: test/aoj/DPL_5_E.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/modulus/modtable.hpp\"\n\n#include <cassert>\n#include\
    \ <vector>\n\ntemplate<typename Modint> class ModTable {\n    std::vector<Modint>\
    \ factorials, factorials_inv;\n\n  public:\n    constexpr ModTable() = default;\n\
    \    constexpr ModTable(const int n): factorials(n + 1), factorials_inv(n + 1)\
    \ {\n        factorials[0] = 1;\n        for (size_t i = 0; i < n; i++) factorials[i\
    \ + 1] = factorials[i] * Modint{ i + 1 };\n        factorials_inv[n] = factorials[n].inv();\n\
    \        for (size_t i = n; i--;) factorials_inv[i] = factorials_inv[i + 1] *\
    \ Modint{ i + 1 };\n    }\n    constexpr auto fact(const int i) const { return\
    \ factorials[i]; }\n    constexpr auto fact_inv(const int i) const { return factorials_inv[i];\
    \ }\n    constexpr auto perm(const int i, const int j) const { return i >= j ?\
    \ fact(i) * fact_inv(i - j) : 0; }\n    constexpr auto binom(const int i, const\
    \ int j) const {\n        if (i < 0 or j < 0 or i < j) return Modint{ 0 };\n \
    \       return factorials[i] * factorials_inv[j] * factorials_inv[i - j];\n  \
    \  }\n    constexpr auto homo(const int i, const int j) const { return binom(i\
    \ + j - 1, j); }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\ntemplate<typename\
    \ Modint> class ModTable {\n    std::vector<Modint> factorials, factorials_inv;\n\
    \n  public:\n    constexpr ModTable() = default;\n    constexpr ModTable(const\
    \ int n): factorials(n + 1), factorials_inv(n + 1) {\n        factorials[0] =\
    \ 1;\n        for (size_t i = 0; i < n; i++) factorials[i + 1] = factorials[i]\
    \ * Modint{ i + 1 };\n        factorials_inv[n] = factorials[n].inv();\n     \
    \   for (size_t i = n; i--;) factorials_inv[i] = factorials_inv[i + 1] * Modint{\
    \ i + 1 };\n    }\n    constexpr auto fact(const int i) const { return factorials[i];\
    \ }\n    constexpr auto fact_inv(const int i) const { return factorials_inv[i];\
    \ }\n    constexpr auto perm(const int i, const int j) const { return i >= j ?\
    \ fact(i) * fact_inv(i - j) : 0; }\n    constexpr auto binom(const int i, const\
    \ int j) const {\n        if (i < 0 or j < 0 or i < j) return Modint{ 0 };\n \
    \       return factorials[i] * factorials_inv[j] * factorials_inv[i - j];\n  \
    \  }\n    constexpr auto homo(const int i, const int j) const { return binom(i\
    \ + j - 1, j); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/modulus/modtable.hpp
  requiredBy: []
  timestamp: '2021-11-23 21:36:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_5_B.test.cpp
  - test/aoj/DPL_5_D.test.cpp
  - test/aoj/DPL_5_E.test.cpp
documentation_of: lib/modulus/modtable.hpp
layout: document
redirect_from:
- /library/lib/modulus/modtable.hpp
- /library/lib/modulus/modtable.hpp.html
title: lib/modulus/modtable.hpp
---
