---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
  - icon: ':heavy_check_mark:'
    path: lib/modulus/modint.hpp
    title: Finite Field
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
  bundledCode: "#line 2 \"lib/modulus/combination.hpp\"\n\n#line 2 \"lib/include.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_NULL, _2,\
    \ _3, name, ...) name\n#define rep1(i, n) for (remove_const_t<remove_reference_t<decltype(n)>>\
    \ i = 0; i < (n); i++)\n#define rep2(i, a, b) for (remove_const_t<remove_reference_t<decltype(b)>>\
    \ i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)\n\
    using size_type = size_t;\n#line 2 \"lib/modulus/modint.hpp\"\n\n#line 4 \"lib/modulus/modint.hpp\"\
    \n\n/**\n * @brief  Finite Field\n * @note Since Fermat's little theorem is used\
    \ for division, the modulo must be prime.\n */\n\ntemplate<int MOD> struct Modint\
    \ {\n    using mint = Modint<MOD>;\n    unsigned int value;\n    Modint(long long\
    \ value_ = 0): value((value_ % MOD + MOD) % MOD) {}\n    mint val() const { return\
    \ *this; }\n    mint operator-() const { return mint(-value); }\n    mint operator++()\
    \ const { return *this += 1; }\n    mint operator--() const { return *this -=\
    \ 1; }\n    mint operator+(mint arg) const { return mint(*this) += arg; }\n  \
    \  mint operator-(mint arg) const { return mint(*this) -= arg; }\n    mint operator*(mint\
    \ arg) const { return mint(*this) *= arg; }\n    mint& operator+=(mint arg) {\n\
    \        value += arg.value;\n        if (value >= MOD) value -= MOD;\n      \
    \  return *this;\n    }\n    mint& operator-=(mint arg) {\n        value -= arg.value;\n\
    \        if (value < 0) value += MOD;\n        return *this;\n    }\n    mint&\
    \ operator*=(mint arg) {\n        value = (long long) value * arg.value % MOD;\n\
    \        return *this;\n    }\n    bool operator==(mint arg) const { return value\
    \ == arg.value; }\n    bool operator!=(mint arg) const { return value != arg.value;\
    \ }\n    mint pow(long long k) const {\n        Modint ret = 1, a(*this);\n  \
    \      while (k > 0) {\n            if (k & 1) ret *= a;\n            k >>= 1;\n\
    \            a *= a;\n        }\n        return ret;\n    }\n    mint inv() const\
    \ { return pow(MOD - 2); }\n    mint operator/(mint arg) const { return *this\
    \ * arg.inv(); }\n    mint& operator/=(mint arg) { return *this *= arg.inv();\
    \ }\n    friend mint operator+(long long value, Modint<MOD> a) { return Modint<MOD>(value)\
    \ + a; }\n    friend mint operator-(long long value, Modint<MOD> a) { return Modint<MOD>(value)\
    \ - a; }\n    friend mint operator*(long long value, Modint<MOD> a) { return Modint<MOD>(value)\
    \ * a; }\n    friend mint operator/(long long value, Modint<MOD> a) { return Modint<MOD>(value)\
    \ / a; }\n    friend ostream& operator<<(ostream& os, Modint<MOD> a) { return\
    \ os << a.value; }\n};\n#line 5 \"lib/modulus/combination.hpp\"\n\n/**\n * @brief\
    \ Combination on mod\n * @note construct in $O(N)$, return $nCr$, $nHr$, $nPr$\
    \ in $O(1)$.\n */\n\ntemplate<int MOD> struct CombTable {\n    vector<Modint<MOD>>\
    \ fact, ifact;\n    CombTable<MOD>(int n):\n        fact(n + 1), ifact(n + 1)\
    \ {\n        assert(1 <= n and n < MOD);\n        fact[0] = 1;\n        for (int\
    \ i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;\n        ifact[n] = fact[n].inv();\n\
    \        for (int i = n; i >= 1; i--) ifact[i - 1] = ifact[i] * i;\n    }\n  \
    \  Modint<MOD> operator()(int n, int r) { return r < 0 or r > n ? 0 : fact[n]\
    \ * ifact[r] * ifact[n - r]; }\n    Modint<MOD> H(int n, int r) { return operator()(n\
    \ + r - 1, r); }\n    Modint<MOD> P(int n, int r) { return r < 0 or r > n ? 0\
    \ : fact[n] * ifact[n - r]; }\n};\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n#include \"lib/modulus/modint.hpp\"\
    \n\n/**\n * @brief Combination on mod\n * @note construct in $O(N)$, return $nCr$,\
    \ $nHr$, $nPr$ in $O(1)$.\n */\n\ntemplate<int MOD> struct CombTable {\n    vector<Modint<MOD>>\
    \ fact, ifact;\n    CombTable<MOD>(int n):\n        fact(n + 1), ifact(n + 1)\
    \ {\n        assert(1 <= n and n < MOD);\n        fact[0] = 1;\n        for (int\
    \ i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;\n        ifact[n] = fact[n].inv();\n\
    \        for (int i = n; i >= 1; i--) ifact[i - 1] = ifact[i] * i;\n    }\n  \
    \  Modint<MOD> operator()(int n, int r) { return r < 0 or r > n ? 0 : fact[n]\
    \ * ifact[r] * ifact[n - r]; }\n    Modint<MOD> H(int n, int r) { return operator()(n\
    \ + r - 1, r); }\n    Modint<MOD> P(int n, int r) { return r < 0 or r > n ? 0\
    \ : fact[n] * ifact[n - r]; }\n};\n"
  dependsOn:
  - lib/include.hpp
  - lib/modulus/modint.hpp
  isVerificationFile: false
  path: lib/modulus/combination.hpp
  requiredBy: []
  timestamp: '2021-09-29 20:09:01+09:00'
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