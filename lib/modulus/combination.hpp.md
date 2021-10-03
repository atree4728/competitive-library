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
    document_title: Combination on mod
    links: []
  bundledCode: "#line 2 \"lib/modulus/combination.hpp\"\n\n#include <cassert>\n#include\
    \ <vector>\n\n/**\n * @brief Combination on mod\n * @note construct in $O(N)$,\
    \ return $nCr$, $nHr$, $nPr$ in $O(1)$.\n */\n\ntemplate<class Modint> struct\
    \ CombTable {\n    std::vector<Modint> fact, ifact;\n    CombTable(int n): fact(n\
    \ + 1), ifact(n + 1) {\n        assert(1 <= n);\n        fact[0] = 1;\n      \
    \  for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;\n        ifact[n] =\
    \ fact[n].inv();\n        for (int i = n; i >= 1; i--) ifact[i - 1] = ifact[i]\
    \ * i;\n    }\n    Modint operator()(int n, int r) { return r < 0 or r > n ? 0\
    \ : fact[n] * ifact[r] * ifact[n - r]; }\n    Modint H(int n, int r) { return\
    \ operator()(n + r - 1, r); }\n    Modint P(int n, int r) { return r < 0 or r\
    \ > n ? 0 : fact[n] * ifact[n - r]; }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n/**\n * @brief Combination\
    \ on mod\n * @note construct in $O(N)$, return $nCr$, $nHr$, $nPr$ in $O(1)$.\n\
    \ */\n\ntemplate<class Modint> struct CombTable {\n    std::vector<Modint> fact,\
    \ ifact;\n    CombTable(int n): fact(n + 1), ifact(n + 1) {\n        assert(1\
    \ <= n);\n        fact[0] = 1;\n        for (int i = 1; i <= n; i++) fact[i] =\
    \ fact[i - 1] * i;\n        ifact[n] = fact[n].inv();\n        for (int i = n;\
    \ i >= 1; i--) ifact[i - 1] = ifact[i] * i;\n    }\n    Modint operator()(int\
    \ n, int r) { return r < 0 or r > n ? 0 : fact[n] * ifact[r] * ifact[n - r]; }\n\
    \    Modint H(int n, int r) { return operator()(n + r - 1, r); }\n    Modint P(int\
    \ n, int r) { return r < 0 or r > n ? 0 : fact[n] * ifact[n - r]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/modulus/combination.hpp
  requiredBy: []
  timestamp: '2021-10-03 22:04:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_5_B.test.cpp
  - test/aoj/DPL_5_D.test.cpp
  - test/aoj/DPL_5_E.test.cpp
documentation_of: lib/modulus/combination.hpp
layout: document
redirect_from:
- /library/lib/modulus/combination.hpp
- /library/lib/modulus/combination.hpp.html
title: Combination on mod
---
