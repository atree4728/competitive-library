---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/modulus/combination.hpp
    title: Combination on mod
  - icon: ':heavy_check_mark:'
    path: lib/modulus/modint.hpp
    title: "Finite Field / \u6709\u9650\u4F53"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_B
  bundledCode: "#line 1 \"test/aoj/DPL_5_B.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_B\"\
    \n\n#line 2 \"lib/modulus/combination.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    \n/**\n * @brief Combination on mod\n * @note construct in $O(N)$, return $nCr$,\
    \ $nHr$, $nPr$ in $O(1)$.\n */\n\ntemplate<class Modint> struct CombTable {\n\
    \    std::vector<Modint> fact, ifact;\n    CombTable(int n): fact(n + 1), ifact(n\
    \ + 1) {\n        assert(1 <= n);\n        fact[0] = 1;\n        for (int i =\
    \ 1; i <= n; i++) fact[i] = fact[i - 1] * i;\n        ifact[n] = fact[n].inv();\n\
    \        for (int i = n; i >= 1; i--) ifact[i - 1] = ifact[i] * i;\n    }\n  \
    \  Modint operator()(int n, int r) { return r < 0 or r > n ? 0 : fact[n] * ifact[r]\
    \ * ifact[n - r]; }\n    Modint H(int n, int r) { return operator()(n + r - 1,\
    \ r); }\n    Modint P(int n, int r) { return r < 0 or r > n ? 0 : fact[n] * ifact[n\
    \ - r]; }\n};\n#line 2 \"lib/modulus/modint.hpp\"\n\n/**\n * @brief Finite Field\
    \ / \u6709\u9650\u4F53\n */\n\n#include <iostream>\n\ntemplate<int MOD> struct\
    \ Modint {\n    using mint = Modint<MOD>;\n    int value;\n    Modint(long long\
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
    \ / a; }\n    friend std::ostream& operator<<(std::ostream& os, Modint<MOD> a)\
    \ { return os << a.value; }\n};\n\nusing Modint1000000007 = Modint<1000000007>;\n\
    using Modint998244353 = Modint<998244353>;\n#line 5 \"test/aoj/DPL_5_B.test.cpp\"\
    \n\nint main() {\n    int n, k;\n    std::cin >> n >> k;\n\n    constexpr int\
    \ MOD = 1000000007;\n    using mint = Modint<MOD>;\n    CombTable<mint> ct(1100);\n\
    \    std::cout << ct.P(k, n) << \"\\n\";\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_B\"\
    \n\n#include \"lib/modulus/combination.hpp\"\n#include \"lib/modulus/modint.hpp\"\
    \n\nint main() {\n    int n, k;\n    std::cin >> n >> k;\n\n    constexpr int\
    \ MOD = 1000000007;\n    using mint = Modint<MOD>;\n    CombTable<mint> ct(1100);\n\
    \    std::cout << ct.P(k, n) << \"\\n\";\n    return 0;\n}\n"
  dependsOn:
  - lib/modulus/combination.hpp
  - lib/modulus/modint.hpp
  isVerificationFile: true
  path: test/aoj/DPL_5_B.test.cpp
  requiredBy: []
  timestamp: '2021-10-13 18:08:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DPL_5_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_5_B.test.cpp
- /verify/test/aoj/DPL_5_B.test.cpp.html
title: test/aoj/DPL_5_B.test.cpp
---
