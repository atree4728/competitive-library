---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
  - icon: ':heavy_check_mark:'
    path: lib/modulus/combination.hpp
    title: Combination on mod
  - icon: ':heavy_check_mark:'
    path: lib/modulus/modint.hpp
    title: Finite Field
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D
  bundledCode: "#line 1 \"lib/test/aoj/DPL_5_D.test.cpp\"\n#define PROBLEM \\\n  \
    \  \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D\"\n#line\
    \ 2 \"lib/include.hpp\"\n#include <bits/stdc++.h>\n#include <experimental/iterator>\n\
    using namespace std;\n#define overload3(_1, _2, _3, name, ...) name\n#define rep1(n)\
    \ for (auto _i = 0; _i < n; _i++)\n#define rep2(i, n) for (auto i = 0; i < n;\
    \ i++)\n#define rep3(i, a, b) for (auto i = a; i < b; i++)\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\ntemplate <class T> bool chmax(T &a, const T\
    \ &b) { return a < b ? a = b, true : false; }\ntemplate <class T> bool chmin(T\
    \ &a, const T &b) { return a > b ? a = b, true : false; }\nusing i64 = long long;\n\
    using f64 = long double;\n#line 2 \"lib/modulus/combination.hpp\"\n\n#line 2 \"\
    lib/modulus/modint.hpp\"\n\n#line 4 \"lib/modulus/modint.hpp\"\n\n/**\n *@brief\
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
    \ }\n#line 5 \"lib/modulus/combination.hpp\"\n\n/**\n *@brief Combination on mod\n\
    \ * @note construct in $O(N)$, return $nCr$, $nHr$, $nPr$ in $O(1)$\n */\n\ntemplate<int\
    \ MOD> class CombinationTable {\n    vector<Modint<MOD>> fact, ifact;\n\n  public:\n\
    \    CombinationTable<MOD>(int n):\n        fact(n + 1), ifact(n + 1) {\n    \
    \    assert(1 <= n and n < MOD);\n        fact[0] = 1;\n        for (int i = 1;\
    \ i <= n; i++) fact[i] = fact[i - 1] * i;\n        ifact[n] = fact[n].inv();\n\
    \        for (int i = n; i >= 1; i--) ifact[i - 1] = ifact[i] * i;\n    }\n  \
    \  Modint<MOD> operator()(int n, int r) { return r < 0 or r > n ? 0 : fact[n]\
    \ * ifact[r] * ifact[n - r]; }\n    Modint<MOD> H(int n, int r) { return operator()(n\
    \ + r - 1, r); }\n    Modint<MOD> P(int n, int r) { return r < 0 or r > n ? 0\
    \ : fact[n] * ifact[n - r]; }\n};\n#line 5 \"lib/test/aoj/DPL_5_D.test.cpp\"\n\
    \nconstexpr int MOD = 1000000007;\n\nint main() {\n    int n, k;\n    cin >> n\
    \ >> k;\n    CombinationTable<MOD> ct(2100);\n    cout << ct.H(k, n) << endl;\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D\"\
    \n#include \"../../include.hpp\"\n#include \"../../modulus/combination.hpp\"\n\
    \nconstexpr int MOD = 1000000007;\n\nint main() {\n    int n, k;\n    cin >> n\
    \ >> k;\n    CombinationTable<MOD> ct(2100);\n    cout << ct.H(k, n) << endl;\n\
    \    return 0;\n}\n"
  dependsOn:
  - lib/include.hpp
  - lib/modulus/combination.hpp
  - lib/modulus/modint.hpp
  isVerificationFile: true
  path: lib/test/aoj/DPL_5_D.test.cpp
  requiredBy: []
  timestamp: '2021-07-10 14:38:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: lib/test/aoj/DPL_5_D.test.cpp
layout: document
redirect_from:
- /verify/lib/test/aoj/DPL_5_D.test.cpp
- /verify/lib/test/aoj/DPL_5_D.test.cpp.html
title: lib/test/aoj/DPL_5_D.test.cpp
---
