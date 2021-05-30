---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/modulus/combination.hpp
    title: combination on mod including nCk, nHr, nPr
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: lib/test/aoj/DPL_5_A.test.cpp
    title: lib/test/aoj/DPL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: lib/test/aoj/DPL_5_B.test.cpp
    title: lib/test/aoj/DPL_5_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: lib/test/aoj/DPL_5_D.test.cpp
    title: lib/test/aoj/DPL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: lib/test/aoj/DPL_5_E.test.cpp
    title: lib/test/aoj/DPL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: lib/test/atcoder/abc110d.test.cpp
    title: lib/test/atcoder/abc110d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Modint
    links: []
  bundledCode: "#line 2 \"lib/modulus/modint.hpp\"\n\n#include <iostream>\n\nusing\
    \ namespace std;\n\n/**\n *@brief Modint\n */\n\ntemplate <int MOD>\nclass Modint\
    \ {\n    using mint = Modint<MOD>;\n\n   public:\n    int value;\n    Modint(long\
    \ long value_ = 0) : value((value_ % MOD + MOD) % MOD) {}\n\n    static constexpr\
    \ int mod() { return MOD; }\n    mint val() const { return *this; }\n\n    inline\
    \ mint operator-() const { return mint(-value); }\n\n    inline mint operator++()\
    \ const { return *this += 1; }\n    inline mint operator--() const { return *this\
    \ -= 1; }\n\n    inline mint operator+(mint arg) const { return mint(*this) +=\
    \ arg; }\n    inline mint operator-(mint arg) const { return mint(*this) -= arg;\
    \ }\n    inline mint operator*(mint arg) const { return mint(*this) *= arg; }\n\
    \n    inline mint& operator+=(mint arg) {\n        value += arg.value;\n     \
    \   if (value >= MOD) value -= MOD;\n        return *this;\n    }\n    inline\
    \ mint& operator-=(mint arg) {\n        value -= arg.value;\n        if (value\
    \ < 0) value += MOD;\n        return *this;\n    }\n    inline mint& operator*=(mint\
    \ arg) {\n        value = (long long)value * arg.value % MOD;\n        return\
    \ *this;\n    }\n\n    inline bool operator==(mint arg) const { return value ==\
    \ arg.value; }\n    inline bool operator!=(mint arg) const { return value != arg.value;\
    \ }\n\n    inline mint pow(long long k) const {\n        Modint ret = 1, a(*this);\n\
    \        while (k > 0) {\n            if (k & 1) ret *= a;\n            k >>=\
    \ 1;\n            a *= a;\n        }\n        return ret;\n    }\n    inline mint\
    \ inv() const { return pow(MOD - 2); }\n\n    inline mint operator/(mint arg)\
    \ const { return *this * arg.inv(); }\n    inline mint& operator/=(mint arg) {\
    \ return *this *= arg.inv(); }\n};\n\ntemplate <int MOD>\nModint<MOD> operator+(long\
    \ long value, Modint<MOD> a) {\n    return Modint<MOD>(value) + a;\n}\ntemplate\
    \ <int MOD>\nModint<MOD> operator-(long long value, Modint<MOD> a) {\n    return\
    \ Modint<MOD>(value) - a;\n}\ntemplate <int MOD>\nModint<MOD> operator*(long long\
    \ value, Modint<MOD> a) {\n    return Modint<MOD>(value) * a;\n}\ntemplate <int\
    \ MOD>\nModint<MOD> operator/(long long value, Modint<MOD> a) {\n    return Modint<MOD>(value)\
    \ / a;\n}\ntemplate <int MOD>\nostream& operator<<(ostream& os, Modint<MOD> a)\
    \ {\n    return os << a.value;\n}\n"
  code: "#pragma once\n\n#include <iostream>\n\nusing namespace std;\n\n/**\n *@brief\
    \ Modint\n */\n\ntemplate <int MOD>\nclass Modint {\n    using mint = Modint<MOD>;\n\
    \n   public:\n    int value;\n    Modint(long long value_ = 0) : value((value_\
    \ % MOD + MOD) % MOD) {}\n\n    static constexpr int mod() { return MOD; }\n \
    \   mint val() const { return *this; }\n\n    inline mint operator-() const {\
    \ return mint(-value); }\n\n    inline mint operator++() const { return *this\
    \ += 1; }\n    inline mint operator--() const { return *this -= 1; }\n\n    inline\
    \ mint operator+(mint arg) const { return mint(*this) += arg; }\n    inline mint\
    \ operator-(mint arg) const { return mint(*this) -= arg; }\n    inline mint operator*(mint\
    \ arg) const { return mint(*this) *= arg; }\n\n    inline mint& operator+=(mint\
    \ arg) {\n        value += arg.value;\n        if (value >= MOD) value -= MOD;\n\
    \        return *this;\n    }\n    inline mint& operator-=(mint arg) {\n     \
    \   value -= arg.value;\n        if (value < 0) value += MOD;\n        return\
    \ *this;\n    }\n    inline mint& operator*=(mint arg) {\n        value = (long\
    \ long)value * arg.value % MOD;\n        return *this;\n    }\n\n    inline bool\
    \ operator==(mint arg) const { return value == arg.value; }\n    inline bool operator!=(mint\
    \ arg) const { return value != arg.value; }\n\n    inline mint pow(long long k)\
    \ const {\n        Modint ret = 1, a(*this);\n        while (k > 0) {\n      \
    \      if (k & 1) ret *= a;\n            k >>= 1;\n            a *= a;\n     \
    \   }\n        return ret;\n    }\n    inline mint inv() const { return pow(MOD\
    \ - 2); }\n\n    inline mint operator/(mint arg) const { return *this * arg.inv();\
    \ }\n    inline mint& operator/=(mint arg) { return *this *= arg.inv(); }\n};\n\
    \ntemplate <int MOD>\nModint<MOD> operator+(long long value, Modint<MOD> a) {\n\
    \    return Modint<MOD>(value) + a;\n}\ntemplate <int MOD>\nModint<MOD> operator-(long\
    \ long value, Modint<MOD> a) {\n    return Modint<MOD>(value) - a;\n}\ntemplate\
    \ <int MOD>\nModint<MOD> operator*(long long value, Modint<MOD> a) {\n    return\
    \ Modint<MOD>(value) * a;\n}\ntemplate <int MOD>\nModint<MOD> operator/(long long\
    \ value, Modint<MOD> a) {\n    return Modint<MOD>(value) / a;\n}\ntemplate <int\
    \ MOD>\nostream& operator<<(ostream& os, Modint<MOD> a) {\n    return os << a.value;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/modulus/modint.hpp
  requiredBy:
  - lib/modulus/combination.hpp
  timestamp: '2021-05-29 23:05:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - lib/test/aoj/DPL_5_A.test.cpp
  - lib/test/aoj/DPL_5_B.test.cpp
  - lib/test/aoj/DPL_5_E.test.cpp
  - lib/test/aoj/DPL_5_D.test.cpp
  - lib/test/atcoder/abc110d.test.cpp
documentation_of: lib/modulus/modint.hpp
layout: document
redirect_from:
- /library/lib/modulus/modint.hpp
- /library/lib/modulus/modint.hpp.html
title: Modint
---
