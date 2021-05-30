---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/utility.hpp
    title: math utility
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
    PROBLEM: https://atcoder.jp/contests/abc110/tasks/abc110_d
    links:
    - https://atcoder.jp/contests/abc110/tasks/abc110_d
  bundledCode: "#line 1 \"lib/test/atcoder/abc110d.test.cpp\"\n#define PROBLEM \"\
    https://atcoder.jp/contests/abc110/tasks/abc110_d\"\n\n#include <bits/stdc++.h>\n\
    #line 2 \"lib/modulus/modint.hpp\"\n\n#line 4 \"lib/modulus/modint.hpp\"\n\nusing\
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
    \ {\n    return os << a.value;\n}\n#line 2 \"lib/modulus/combination.hpp\"\n\n\
    #line 5 \"lib/modulus/combination.hpp\"\n\nusing namespace std;\n\n#line 9 \"\
    lib/modulus/combination.hpp\"\n\n/**\n *@brief combination on mod including nCk,\
    \ nHr, nPr\n */\n\ntemplate <int MOD>\nclass CombinationTable {\n    vector<Modint<MOD>>\
    \ fact, ifact;\n\n   public:\n    CombinationTable<MOD>(int n) : fact(n + 1),\
    \ ifact(n + 1) {\n        assert(1 <= n and n < MOD);\n        fact[0] = 1;\n\
    \        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;\n        ifact[n]\
    \ = fact[n].inv();\n        for (int i = n; i >= 1; i--) ifact[i - 1] = ifact[i]\
    \ * i;\n    }\n    Modint<MOD> C(int n, int r) {\n        if (r < 0 or r > n)\
    \ return 0;\n        return fact[n] * ifact[r] * ifact[n - r];\n    }\n    Modint<MOD>\
    \ H(int n, int r) { return C(n + r - 1, r); }\n    Modint<MOD> P(int n, int r)\
    \ {\n        if (r < 0 or r > n) return 0;\n        return fact[n] * ifact[n -\
    \ r];\n    }\n};\n#line 2 \"lib/math/utility.hpp\"\n\n#line 6 \"lib/math/utility.hpp\"\
    \n\nusing namespace std;\n\n/**\n * @brief math utility\n */\n\nconstexpr long\
    \ long ceil(long long a, long long b) { return (a + b - 1) / b; }\n\nlong long\
    \ digit_sum(long long n) {\n    if (n < 10) return n;\n    return digit_sum(n\
    \ / 10) + n % 10;\n}\n\nlong long mypow(long long a, int e) {\n    long long ret\
    \ = 1;\n    while (e--) ret *= a;\n    return ret;\n}\n\nbool is_prime(long long\
    \ n) {\n    if (n <= 1) return false;\n    if (n == 2) return true;\n    for (long\
    \ long i = 2; i * i <= n; i++) {\n        if (n % i == 0) return false;\n    }\n\
    \    return true;\n}\n\nmap<long long, int> prime_factorize(long long n) {\n \
    \   map<long long, int> factor;\n    for (long long p = 2; p * p <= n; p++) {\n\
    \        if (n % p != 0) continue;\n        int ex = 0;\n        while (n % p\
    \ == 0) {\n            ex++;\n            n /= p;\n        }\n        factor[p]\
    \ = ex;\n    }\n    if (n != 1) factor[n] = 1;\n    return factor;\n}\n\nvector<long\
    \ long> divisor(long long n) {\n    vector<long long> ret;\n    for (long long\
    \ p = 1; p * p <= n; p++) {\n        if (n % p == 0) {\n            ret.push_back(p);\n\
    \            if (p * p != n) ret.push_back(n / p);\n        }\n    }\n    sort(begin(ret),\
    \ end(ret));\n    return ret;\n}\n#line 7 \"lib/test/atcoder/abc110d.test.cpp\"\
    \nusing namespace std;\n\nconstexpr int MOD = 1000000007;\nconstexpr int M = 200000;\n\
    using mint = Modint<MOD>;\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    long long n, m;\n    cin >> n >> m;\n    map<long\
    \ long, int> factor = prime_factorize(m);\n    mint ans = 1;\n    CombinationTable<MOD>\
    \ ct(M);\n    for (auto [_, ex] : factor) ans *= ct.H(n, ex);\n    cout << ans.val()\
    \ << \"\\n\";\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc110/tasks/abc110_d\"\n\n\
    #include <bits/stdc++.h>\n#include \"lib/modulus/modint.hpp\"\n#include \"lib/modulus/combination.hpp\"\
    \n#include \"lib/math/utility.hpp\"\nusing namespace std;\n\nconstexpr int MOD\
    \ = 1000000007;\nconstexpr int M = 200000;\nusing mint = Modint<MOD>;\n\nint main()\
    \ {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    long long n,\
    \ m;\n    cin >> n >> m;\n    map<long long, int> factor = prime_factorize(m);\n\
    \    mint ans = 1;\n    CombinationTable<MOD> ct(M);\n    for (auto [_, ex] :\
    \ factor) ans *= ct.H(n, ex);\n    cout << ans.val() << \"\\n\";\n    return 0;\n\
    }\n"
  dependsOn:
  - lib/modulus/modint.hpp
  - lib/modulus/combination.hpp
  - lib/math/utility.hpp
  isVerificationFile: true
  path: lib/test/atcoder/abc110d.test.cpp
  requiredBy: []
  timestamp: '2021-05-29 23:05:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: lib/test/atcoder/abc110d.test.cpp
layout: document
redirect_from:
- /verify/lib/test/atcoder/abc110d.test.cpp
- /verify/lib/test/atcoder/abc110d.test.cpp.html
title: lib/test/atcoder/abc110d.test.cpp
---
