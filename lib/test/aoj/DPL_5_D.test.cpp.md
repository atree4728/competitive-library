---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/modulus/combination.hpp
    title: combination on mod including nCk, nHr, nPr
  - icon: ':heavy_check_mark:'
    path: lib/modulus/modint.hpp
    title: Modint
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
    \  \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D\"\n#include\
    \ <iostream>\n#line 2 \"lib/modulus/combination.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\nusing namespace std;\n\n#line 2 \"lib/modulus/modint.hpp\"\
    \n\n#line 4 \"lib/modulus/modint.hpp\"\n\nusing namespace std;\n\n/**\n *@brief\
    \ Modint\n */\n\ntemplate <int MOD>\nclass Modint {\n    using mint = Modint<MOD>;\n\
    \n   public:\n    int value;\n    Modint(long long value_ = 0) : value((value_\
    \ % MOD + MOD) % MOD) {}\n\n    static constexpr int mod() { return MOD; }\n \
    \   int val() const { return *this; }\n\n    inline mint operator-() const { return\
    \ mint(-value); }\n\n    inline mint operator++() const { return *this += 1; }\n\
    \    inline mint operator--() const { return *this -= 1; }\n\n    inline mint\
    \ operator+(mint arg) const { return mint(*this) += arg; }\n    inline mint operator-(mint\
    \ arg) const { return mint(*this) -= arg; }\n    inline mint operator*(mint arg)\
    \ const { return mint(*this) *= arg; }\n\n    inline mint& operator+=(mint arg)\
    \ {\n        value += arg.value;\n        if (value >= MOD) value -= MOD;\n  \
    \      return *this;\n    }\n    inline mint& operator-=(mint arg) {\n       \
    \ value -= arg.value;\n        if (value < 0) value += MOD;\n        return *this;\n\
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
    \ ifact[i - 1] = ifact[i] * i;\n    }\n    Modint<MOD> C(int n, int r) {\n   \
    \     if (r < 0 or r > n) return 0;\n        return fact[n] * ifact[r] * ifact[n\
    \ - r];\n    }\n    Modint<MOD> H(int n, int r) { return C(n + r - 1, r); }\n\
    \    Modint<MOD> P(int n, int r) {\n        if (r < 0 or r > n) return 0;\n  \
    \      return fact[n] * ifact[n - r];\n    }\n};\n#line 5 \"lib/test/aoj/DPL_5_D.test.cpp\"\
    \n\nusing namespace std;\n\nconstexpr int MOD = 1000000007;\n\nint main() {\n\
    \    int n, k;\n    cin >> n >> k;\n    CombinationTable<MOD> ct(2100);\n    cout\
    \ << ct.H(k, n) << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D\"\
    \n#include <iostream>\n#include \"lib/modulus/combination.hpp\"\n\nusing namespace\
    \ std;\n\nconstexpr int MOD = 1000000007;\n\nint main() {\n    int n, k;\n   \
    \ cin >> n >> k;\n    CombinationTable<MOD> ct(2100);\n    cout << ct.H(k, n)\
    \ << endl;\n    return 0;\n}\n"
  dependsOn:
  - lib/modulus/combination.hpp
  - lib/modulus/modint.hpp
  isVerificationFile: true
  path: lib/test/aoj/DPL_5_D.test.cpp
  requiredBy: []
  timestamp: '2021-05-29 21:52:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: lib/test/aoj/DPL_5_D.test.cpp
layout: document
redirect_from:
- /verify/lib/test/aoj/DPL_5_D.test.cpp
- /verify/lib/test/aoj/DPL_5_D.test.cpp.html
title: lib/test/aoj/DPL_5_D.test.cpp
---
