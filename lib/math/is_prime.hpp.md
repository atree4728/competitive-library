---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Prime Determination($O(\u221AN)$)"
    links: []
  bundledCode: "#line 2 \"lib/math/is_prime.hpp\"\n\n#line 2 \"lib/include.hpp\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_1, _2, _3,\
    \ name, ...) name\n#define rep1(n) for (decltype(n) _tmp = 0; _tmp < (n); _tmp++)\n\
    #define rep2(i, n) for (decltype(n) i = 0; i < (n); i++)\n#define rep3(i, a, b)\
    \ for (decltype(b) i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\nstruct IOSetup {\n    IOSetup() noexcept {\n\
    \        ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n        cout\
    \ << fixed << setprecision(10);\n        cerr << fixed << setprecision(10);\n\
    \    }\n} iosetup;\ntemplate<class T> bool chmax(T &a, const T &b) { return a\
    \ < b and (a = b, true); }\ntemplate<class T> bool chmin(T &a, const T &b) { return\
    \ a > b and (a = b, true); }\nusing i64 = long long;\nusing f64 = long double;\n\
    #line 4 \"lib/math/is_prime.hpp\"\n\n/**\n * @brief Prime Determination($O(\u221A\
    N)$)\n */\n\ntemplate<typename T = i64> bool is_prime(T n) {\n    if (n <= 1)\
    \ return false;\n    if (n == 2) return true;\n    for (T i = 2; i * i <= n; i++)\n\
    \        if (n % i == 0) return false;\n    return true;\n}\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief Prime Determination($O(\u221A\
    N)$)\n */\n\ntemplate<typename T = i64> bool is_prime(T n) {\n    if (n <= 1)\
    \ return false;\n    if (n == 2) return true;\n    for (T i = 2; i * i <= n; i++)\n\
    \        if (n % i == 0) return false;\n    return true;\n}"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/math/is_prime.hpp
  requiredBy: []
  timestamp: '2021-08-31 17:00:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/is_prime.hpp
layout: document
redirect_from:
- /library/lib/math/is_prime.hpp
- /library/lib/math/is_prime.hpp.html
title: "Prime Determination($O(\u221AN)$)"
---
