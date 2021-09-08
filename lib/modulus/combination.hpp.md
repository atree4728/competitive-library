---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc110d.test.cpp
    title: test/atcoder/abc110d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Combination on mod
    links: []
  bundledCode: "#line 2 \"lib/modulus/combination.hpp\"\n\n#line 2 \"lib/include.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_1, _2,\
    \ _3, name, ...) name\n#define rep1(n) for (decltype(n) _tmp = 0; _tmp < (n);\
    \ _tmp++)\n#define rep2(i, n) for (decltype(n) i = 0; i < (n); i++)\n#define rep3(i,\
    \ a, b) for (decltype(b) i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\nstruct IOSetup {\n    IOSetup() noexcept {\n\
    \        ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n        cout\
    \ << fixed << setprecision(10);\n        cerr << fixed << setprecision(10);\n\
    \    }\n} iosetup;\ntemplate<class T> bool chmax(T &a, const T &b) { return a\
    \ < b and (a = b, true); }\ntemplate<class T> bool chmin(T &a, const T &b) { return\
    \ a > b and (a = b, true); }\nusing i64 = long long;\nusing f64 = long double;\n\
    #line 2 \"lib/modulus/modint.hpp\"\n\n#line 4 \"lib/modulus/modint.hpp\"\n\n/**\n\
    \ * @brief  Finite Field\n * @note Since Fermat's little theorem is used for division,\
    \ the modulo must be prime.\n */\n\ntemplate<int MOD> struct Modint {\n    using\
    \ mint = Modint<MOD>;\n    int value;\n    Modint(i64 value_ = 0):\n        value((value_\
    \ % MOD + MOD) % MOD) {}\n    mint val() const { return *this; }\n    mint operator-()\
    \ const { return mint(-value); }\n    mint operator++() const { return *this +=\
    \ 1; }\n    mint operator--() const { return *this -= 1; }\n    mint operator+(mint\
    \ arg) const { return mint(*this) += arg; }\n    mint operator-(mint arg) const\
    \ { return mint(*this) -= arg; }\n    mint operator*(mint arg) const { return\
    \ mint(*this) *= arg; }\n    mint& operator+=(mint arg) {\n        value += arg.value;\n\
    \        if (value >= MOD) value -= MOD;\n        return *this;\n    }\n    mint&\
    \ operator-=(mint arg) {\n        value -= arg.value;\n        if (value < 0)\
    \ value += MOD;\n        return *this;\n    }\n    mint& operator*=(mint arg)\
    \ {\n        value = (long long)value * arg.value % MOD;\n        return *this;\n\
    \    }\n    bool operator==(mint arg) const { return value == arg.value; }\n \
    \   bool operator!=(mint arg) const { return value != arg.value; }\n    mint pow(long\
    \ long k) const {\n        Modint ret = 1, a(*this);\n        while (k > 0) {\n\
    \            if (k & 1) ret *= a;\n            k >>= 1;\n            a *= a;\n\
    \        }\n        return ret;\n    }\n    mint inv() const { return pow(MOD\
    \ - 2); }\n    mint operator/(mint arg) const { return *this * arg.inv(); }\n\
    \    mint& operator/=(mint arg) { return *this *= arg.inv(); }\n    friend mint\
    \ operator+(i64 value, Modint<MOD> a) { return Modint<MOD>(value) + a; }\n   \
    \ friend mint operator-(i64 value, Modint<MOD> a) { return Modint<MOD>(value)\
    \ - a; }\n    friend mint operator*(i64 value, Modint<MOD> a) { return Modint<MOD>(value)\
    \ * a; }\n    friend mint operator/(i64 value, Modint<MOD> a) { return Modint<MOD>(value)\
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
  timestamp: '2021-08-31 17:00:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/abc110d.test.cpp
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
