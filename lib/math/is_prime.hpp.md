---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: prime determination
    links: []
  bundledCode: "#line 2 \"lib/math/is_prime.hpp\"\n\n#line 2 \"lib/include.hpp\"\n\
    #include <bits/stdc++.h>\n#include <experimental/iterator>\nusing namespace std;\n\
    #define overload3(_1, _2, _3, name, ...) name\n#define rep1(n) for (auto _i =\
    \ 0; _i < n; _i++)\n#define rep2(i, n) for (auto i = 0; i < n; i++)\n#define rep3(i,\
    \ a, b) for (auto i = a; i < b; i++)\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\ntemplate <class T> bool chmax(T &a, const T\
    \ &b) { return a < b ? a = b, true : false; }\ntemplate <class T> bool chmin(T\
    \ &a, const T &b) { return a > b ? a = b, true : false; }\nusing i64 = long long;\n\
    using f64 = long double;\n#line 4 \"lib/math/is_prime.hpp\"\n\n/**\n *@brief prime\
    \ determination\n * @note $O(\u221AN)$\n */\n\nauto is_prime(auto n) -> bool {\n\
    \    if (n <= 1) return false;\n    if (n == 2) return true;\n    for (auto i\
    \ = 2; i * i <= n; i++) {\n        if (n % i == 0) return false;\n    }\n    return\
    \ true;\n}\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n *@brief prime determination\n\
    \ * @note $O(\u221AN)$\n */\n\nauto is_prime(auto n) -> bool {\n    if (n <= 1)\
    \ return false;\n    if (n == 2) return true;\n    for (auto i = 2; i * i <= n;\
    \ i++) {\n        if (n % i == 0) return false;\n    }\n    return true;\n}"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/math/is_prime.hpp
  requiredBy: []
  timestamp: '2021-07-10 14:38:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/is_prime.hpp
layout: document
redirect_from:
- /library/lib/math/is_prime.hpp
- /library/lib/math/is_prime.hpp.html
title: prime determination
---
