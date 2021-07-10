---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/modulus/combination.hpp
    title: Combination on mod
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
    document_title: Finite Field
    links: []
  bundledCode: "#line 2 \"lib/modulus/modint.hpp\"\n\n#line 2 \"lib/include.hpp\"\n\
    #include <bits/stdc++.h>\n#include <experimental/iterator>\nusing namespace std;\n\
    #define overload3(_1, _2, _3, name, ...) name\n#define rep1(n) for (auto _i =\
    \ 0; _i < n; _i++)\n#define rep2(i, n) for (auto i = 0; i < n; i++)\n#define rep3(i,\
    \ a, b) for (auto i = a; i < b; i++)\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\ntemplate <class T> bool chmax(T &a, const T\
    \ &b) { return a < b ? a = b, true : false; }\ntemplate <class T> bool chmin(T\
    \ &a, const T &b) { return a > b ? a = b, true : false; }\nusing i64 = long long;\n\
    using f64 = long double;\n#line 4 \"lib/modulus/modint.hpp\"\n\n/**\n *@brief\
    \  Finite Field\n * @note Since Fermat's little theorem is used for division,\
    \ the modulo must be prime\n */\n\ntemplate<int MOD> class Modint {\n    using\
    \ mint = Modint<MOD>;\n\n  public:\n    int value;\n    Modint(long long value_\
    \ = 0):\n        value((value_ % MOD + MOD) % MOD) {}\n    static constexpr int\
    \ mod() { return MOD; }\n    mint val() const { return *this; }\n    inline mint\
    \ operator-() const { return mint(-value); }\n    inline mint operator++() const\
    \ { return *this += 1; }\n    inline mint operator--() const { return *this -=\
    \ 1; }\n    inline mint operator+(mint arg) const { return mint(*this) += arg;\
    \ }\n    inline mint operator-(mint arg) const { return mint(*this) -= arg; }\n\
    \    inline mint operator*(mint arg) const { return mint(*this) *= arg; }\n  \
    \  inline mint& operator+=(mint arg) {\n        value += arg.value;\n        if\
    \ (value >= MOD) value -= MOD;\n        return *this;\n    }\n    inline mint&\
    \ operator-=(mint arg) {\n        value -= arg.value;\n        if (value < 0)\
    \ value += MOD;\n        return *this;\n    }\n    inline mint& operator*=(mint\
    \ arg) {\n        value = (long long)value * arg.value % MOD;\n        return\
    \ *this;\n    }\n    inline bool operator==(mint arg) const { return value ==\
    \ arg.value; }\n    inline bool operator!=(mint arg) const { return value != arg.value;\
    \ }\n    inline mint pow(long long k) const {\n        Modint ret = 1, a(*this);\n\
    \        while (k > 0) {\n            if (k & 1) ret *= a;\n            k >>=\
    \ 1;\n            a *= a;\n        }\n        return ret;\n    }\n    inline mint\
    \ inv() const { return pow(MOD - 2); }\n    inline mint operator/(mint arg) const\
    \ { return *this * arg.inv(); }\n    inline mint& operator/=(mint arg) { return\
    \ *this *= arg.inv(); }\n};\ntemplate<int MOD> Modint<MOD> operator+(long long\
    \ value, Modint<MOD> a) { return Modint<MOD>(value) + a; }\ntemplate<int MOD>\
    \ Modint<MOD> operator-(long long value, Modint<MOD> a) { return Modint<MOD>(value)\
    \ - a; }\ntemplate<int MOD> Modint<MOD> operator*(long long value, Modint<MOD>\
    \ a) { return Modint<MOD>(value) * a; }\ntemplate<int MOD> Modint<MOD> operator/(long\
    \ long value, Modint<MOD> a) { return Modint<MOD>(value) / a; }\ntemplate<int\
    \ MOD> ostream& operator<<(ostream& os, Modint<MOD> a) { return os << a.value;\
    \ }\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n *@brief  Finite Field\n\
    \ * @note Since Fermat's little theorem is used for division, the modulo must\
    \ be prime\n */\n\ntemplate<int MOD> class Modint {\n    using mint = Modint<MOD>;\n\
    \n  public:\n    int value;\n    Modint(long long value_ = 0):\n        value((value_\
    \ % MOD + MOD) % MOD) {}\n    static constexpr int mod() { return MOD; }\n   \
    \ mint val() const { return *this; }\n    inline mint operator-() const { return\
    \ mint(-value); }\n    inline mint operator++() const { return *this += 1; }\n\
    \    inline mint operator--() const { return *this -= 1; }\n    inline mint operator+(mint\
    \ arg) const { return mint(*this) += arg; }\n    inline mint operator-(mint arg)\
    \ const { return mint(*this) -= arg; }\n    inline mint operator*(mint arg) const\
    \ { return mint(*this) *= arg; }\n    inline mint& operator+=(mint arg) {\n  \
    \      value += arg.value;\n        if (value >= MOD) value -= MOD;\n        return\
    \ *this;\n    }\n    inline mint& operator-=(mint arg) {\n        value -= arg.value;\n\
    \        if (value < 0) value += MOD;\n        return *this;\n    }\n    inline\
    \ mint& operator*=(mint arg) {\n        value = (long long)value * arg.value %\
    \ MOD;\n        return *this;\n    }\n    inline bool operator==(mint arg) const\
    \ { return value == arg.value; }\n    inline bool operator!=(mint arg) const {\
    \ return value != arg.value; }\n    inline mint pow(long long k) const {\n   \
    \     Modint ret = 1, a(*this);\n        while (k > 0) {\n            if (k &\
    \ 1) ret *= a;\n            k >>= 1;\n            a *= a;\n        }\n       \
    \ return ret;\n    }\n    inline mint inv() const { return pow(MOD - 2); }\n \
    \   inline mint operator/(mint arg) const { return *this * arg.inv(); }\n    inline\
    \ mint& operator/=(mint arg) { return *this *= arg.inv(); }\n};\ntemplate<int\
    \ MOD> Modint<MOD> operator+(long long value, Modint<MOD> a) { return Modint<MOD>(value)\
    \ + a; }\ntemplate<int MOD> Modint<MOD> operator-(long long value, Modint<MOD>\
    \ a) { return Modint<MOD>(value) - a; }\ntemplate<int MOD> Modint<MOD> operator*(long\
    \ long value, Modint<MOD> a) { return Modint<MOD>(value) * a; }\ntemplate<int\
    \ MOD> Modint<MOD> operator/(long long value, Modint<MOD> a) { return Modint<MOD>(value)\
    \ / a; }\ntemplate<int MOD> ostream& operator<<(ostream& os, Modint<MOD> a) {\
    \ return os << a.value; }\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/modulus/modint.hpp
  requiredBy:
  - lib/modulus/combination.hpp
  timestamp: '2021-07-10 14:38:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - lib/test/atcoder/abc110d.test.cpp
  - lib/test/aoj/DPL_5_A.test.cpp
  - lib/test/aoj/DPL_5_D.test.cpp
  - lib/test/aoj/DPL_5_B.test.cpp
  - lib/test/aoj/DPL_5_E.test.cpp
documentation_of: lib/modulus/modint.hpp
layout: document
redirect_from:
- /library/lib/modulus/modint.hpp
- /library/lib/modulus/modint.hpp.html
title: Finite Field
---
