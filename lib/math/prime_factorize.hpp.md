---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc110d.test.cpp
    title: test/atcoder/abc110d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Prime Factorize($O(\u221AN)$)"
    links: []
  bundledCode: "#line 2 \"lib/math/prime_factorize.hpp\"\n\n#line 2 \"lib/include.hpp\"\
    \n\n#include <bits/stdc++.h>\n#include <experimental/iterator>\nusing namespace\
    \ std;\n#define overload3(_1, _2, _3, name, ...) name\n#define rep1(n) for (decltype(n)\
    \ _tmp = 0; _tmp < n; _tmp++)\n#define rep2(i, n) for (decltype(n) i = 0; i <\
    \ n; i++)\n#define rep3(i, a, b) for (decltype(b) i = a; i < b; i++)\n#define\
    \ rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\nstruct IOSetup\
    \ { IOSetup() noexcept { ios::sync_with_stdio(false); cin.tie(nullptr); cout <<\
    \ fixed << setprecision(10); cerr << fixed << setprecision(10); } } iosetup;\n\
    template <class T> bool chmax(T &a, const T &b) { return a < b and (a = b, true);\
    \ }\ntemplate <class T> bool chmin(T &a, const T &b) { return a > b and (a = b,\
    \ true); }\nusing i64 = long long;\nusing u64 = unsigned long long;\nusing f64\
    \ = long double;\n#line 4 \"lib/math/prime_factorize.hpp\"\n\n/**\n * @brief Prime\
    \ Factorize($O(\u221AN)$)\n */\n\ntemplate<class T = u64> map<T, int> prime_factorize(T\
    \ n) {\n    map<T, int> factor;\n    for (auto p = 2; p * p <= n; p++) {\n   \
    \     if (n % p != 0) continue;\n        int ex = 0;\n        while (n % p ==\
    \ 0) {\n            ex++;\n            n /= p;\n        }\n        factor[p] =\
    \ ex;\n    }\n    if (n != 1) factor[n] = 1;\n    return factor;\n}\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief Prime Factorize($O(\u221A\
    N)$)\n */\n\ntemplate<class T = u64> map<T, int> prime_factorize(T n) {\n    map<T,\
    \ int> factor;\n    for (auto p = 2; p * p <= n; p++) {\n        if (n % p !=\
    \ 0) continue;\n        int ex = 0;\n        while (n % p == 0) {\n          \
    \  ex++;\n            n /= p;\n        }\n        factor[p] = ex;\n    }\n   \
    \ if (n != 1) factor[n] = 1;\n    return factor;\n}"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/math/prime_factorize.hpp
  requiredBy: []
  timestamp: '2021-07-21 10:45:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/abc110d.test.cpp
documentation_of: lib/math/prime_factorize.hpp
layout: document
redirect_from:
- /library/lib/math/prime_factorize.hpp
- /library/lib/math/prime_factorize.hpp.html
title: "Prime Factorize($O(\u221AN)$)"
---