---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
  - icon: ':heavy_check_mark:'
    path: lib/math/prime_factorize.hpp
    title: "Prime Factorize($O(\u221AN)$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
  bundledCode: "#line 1 \"test/aoj/NTL_1_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n\n#line 2 \"lib/math/prime_factorize.hpp\"\n\n#line 2 \"lib/include.hpp\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_1, _2, _3,\
    \ name, ...) name\n#define rep1(n) for (decltype(n) _tmp = 0; _tmp < (n); _tmp++)\n\
    #define rep2(i, n) for (decltype(n) i = 0; i < (n); i++)\n#define rep3(i, a, b)\
    \ for (decltype(b) i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\nstruct IOSetup {\n    IOSetup() noexcept {\n\
    \        ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n        cout\
    \ << fixed << setprecision(10);\n        cerr << fixed << setprecision(10);\n\
    \    }\n} iosetup;\ntemplate<class T> bool chmax(T &a, const T &b) { return a\
    \ < b and (a = b, true); }\ntemplate<class T> bool chmin(T &a, const T &b) { return\
    \ a > b and (a = b, true); }\nusing i64 = long long;\nusing f64 = long double;\n\
    #line 4 \"lib/math/prime_factorize.hpp\"\n\n/**\n * @brief Prime Factorize($O(\u221A\
    N)$)\n */\n\ntemplate<class T = i64> map<T, int> prime_factorize(T n) {\n    map<T,\
    \ int> factor;\n    for (auto p = 2; p * p <= n; p++) {\n        if (n % p !=\
    \ 0) continue;\n        int ex = 0;\n        while (n % p == 0) {\n          \
    \  ex++;\n            n /= p;\n        }\n        factor[p] = ex;\n    }\n   \
    \ if (n != 1) factor[n] = 1;\n    return factor;\n}\n#line 4 \"test/aoj/NTL_1_A.test.cpp\"\
    \n\nint main() {\n    int n;\n    cin >> n;\n    auto pf = prime_factorize(n);\n\
    \    cout << n << \":\";\n    for (auto [p, e]: pf) {\n        while (e--) cout\
    \ << \" \" << p;\n    }\n    cout << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n\n#include \"lib/math/prime_factorize.hpp\"\n\nint main() {\n    int n;\n  \
    \  cin >> n;\n    auto pf = prime_factorize(n);\n    cout << n << \":\";\n   \
    \ for (auto [p, e]: pf) {\n        while (e--) cout << \" \" << p;\n    }\n  \
    \  cout << \"\\n\";\n}\n"
  dependsOn:
  - lib/math/prime_factorize.hpp
  - lib/include.hpp
  isVerificationFile: true
  path: test/aoj/NTL_1_A.test.cpp
  requiredBy: []
  timestamp: '2021-09-08 23:15:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_A.test.cpp
- /verify/test/aoj/NTL_1_A.test.cpp.html
title: test/aoj/NTL_1_A.test.cpp
---