---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/modulus/modint.hpp
    title: Modint
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: lib/test/aoj/DPL_5_B.test.cpp
    title: lib/test/aoj/DPL_5_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: lib/test/aoj/DPL_5_D.test.cpp
    title: lib/test/aoj/DPL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: lib/test/aoj/DPL_5_E.test.cpp
    title: lib/test/aoj/DPL_5_E.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: combination on mod including nCk, nHr, nPr
    links: []
  bundledCode: "#line 2 \"lib/modulus/combination.hpp\"\n\n#include <cassert>\n#include\
    \ <vector>\n\nusing namespace std;\n\n#line 2 \"lib/modulus/modint.hpp\"\n\n#include\
    \ <iostream>\n\nusing namespace std;\n\n/**\n *@brief Modint\n */\n\ntemplate\
    \ <int MOD>\nclass Modint {\n    using mint = Modint<MOD>;\n\n   public:\n   \
    \ int value;\n    Modint(long long value_ = 0) : value((value_ % MOD + MOD) %\
    \ MOD) {}\n\n    static constexpr int mod() { return MOD; }\n    int val() const\
    \ { return *this; }\n\n    inline mint operator-() const { return mint(-value);\
    \ }\n\n    inline mint operator++() const { return *this += 1; }\n    inline mint\
    \ operator--() const { return *this -= 1; }\n\n    inline mint operator+(mint\
    \ arg) const { return mint(*this) += arg; }\n    inline mint operator-(mint arg)\
    \ const { return mint(*this) -= arg; }\n    inline mint operator*(mint arg) const\
    \ { return mint(*this) *= arg; }\n\n    inline mint& operator+=(mint arg) {\n\
    \        value += arg.value;\n        if (value >= MOD) value -= MOD;\n      \
    \  return *this;\n    }\n    inline mint& operator-=(mint arg) {\n        value\
    \ -= arg.value;\n        if (value < 0) value += MOD;\n        return *this;\n\
    \    }\n    inline mint& operator*=(mint arg) {\n        value = (long long)value\
    \ * arg.value % MOD;\n        return *this;\n    }\n\n    inline bool operator==(mint\
    \ arg) const { return value == arg.value; }\n    inline bool operator!=(mint arg)\
    \ const { return value != arg.value; }\n\n    inline mint pow(long long k) const\
    \ {\n        Modint ret = 1, a(*this);\n        while (k > 0) {\n            if\
    \ (k & 1) ret *= a;\n            k >>= 1;\n            a *= a;\n        }\n  \
    \      return ret;\n    }\n    inline mint inv() const { return pow(MOD - 2);\
    \ }\n\n    inline mint operator/(mint arg) const { return *this * arg.inv(); }\n\
    \    inline mint& operator/=(mint arg) { return *this *= arg.inv(); }\n};\n\n\
    template <int MOD>\nModint<MOD> operator+(long long value, Modint<MOD> a) {\n\
    \    return Modint<MOD>(value) + a;\n}\ntemplate <int MOD>\nModint<MOD> operator-(long\
    \ long value, Modint<MOD> a) {\n    return Modint<MOD>(value) - a;\n}\ntemplate\
    \ <int MOD>\nModint<MOD> operator*(long long value, Modint<MOD> a) {\n    return\
    \ Modint<MOD>(value) * a;\n}\ntemplate <int MOD>\nModint<MOD> operator/(long long\
    \ value, Modint<MOD> a) {\n    return Modint<MOD>(value) / a;\n}\ntemplate <int\
    \ MOD>\nostream& operator<<(ostream& os, Modint<MOD> a) {\n    return os << a.value;\n\
    }\n#line 9 \"lib/modulus/combination.hpp\"\n\n/**\n *@brief combination on mod\
    \ including nCk, nHr, nPr\n */\n\ntemplate <int MOD>\nclass CombinationTable {\n\
    \    vector<Modint<MOD>> fact, ifact;\n\n   public:\n    CombinationTable<MOD>(int\
    \ n) : fact(n + 1), ifact(n + 1) {\n        assert(1 <= n and n < MOD);\n    \
    \    fact[0] = 1;\n        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1]\
    \ * i;\n        ifact[n] = fact[n].inv();\n        for (int i = n; i >= 1; i--)\
    \ ifact[i - 1] = ifact[i] * i;\n    }\n\n    Modint<MOD> c(int n, int r) {\n \
    \       if (r < 0 or r > n) return 0;\n        return fact[n] * ifact[r] * ifact[n\
    \ - r];\n    }\n\n    Modint<MOD> h(int n, int r) { return c(n + r - 1, r); }\n\
    \n    Modint<MOD> p(int n, int r) {\n        if (r < 0 or r > n) return 0;\n \
    \       return fact[n] * ifact[n - r];\n    }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\nusing namespace\
    \ std;\n\n#include \"lib/modulus/modint.hpp\"\n\n/**\n *@brief combination on\
    \ mod including nCk, nHr, nPr\n */\n\ntemplate <int MOD>\nclass CombinationTable\
    \ {\n    vector<Modint<MOD>> fact, ifact;\n\n   public:\n    CombinationTable<MOD>(int\
    \ n) : fact(n + 1), ifact(n + 1) {\n        assert(1 <= n and n < MOD);\n    \
    \    fact[0] = 1;\n        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1]\
    \ * i;\n        ifact[n] = fact[n].inv();\n        for (int i = n; i >= 1; i--)\
    \ ifact[i - 1] = ifact[i] * i;\n    }\n\n    Modint<MOD> c(int n, int r) {\n \
    \       if (r < 0 or r > n) return 0;\n        return fact[n] * ifact[r] * ifact[n\
    \ - r];\n    }\n\n    Modint<MOD> h(int n, int r) { return c(n + r - 1, r); }\n\
    \n    Modint<MOD> p(int n, int r) {\n        if (r < 0 or r > n) return 0;\n \
    \       return fact[n] * ifact[n - r];\n    }\n};\n"
  dependsOn:
  - lib/modulus/modint.hpp
  isVerificationFile: false
  path: lib/modulus/combination.hpp
  requiredBy: []
  timestamp: '2021-05-28 15:42:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - lib/test/aoj/DPL_5_B.test.cpp
  - lib/test/aoj/DPL_5_E.test.cpp
  - lib/test/aoj/DPL_5_D.test.cpp
documentation_of: lib/modulus/combination.hpp
layout: document
redirect_from:
- /library/lib/modulus/combination.hpp
- /library/lib/modulus/combination.hpp.html
title: combination on mod including nCk, nHr, nPr
---
