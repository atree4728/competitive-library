---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: lib/test/atcoder/abc110d.test.cpp
    title: lib/test/atcoder/abc110d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: prime factorize
    links: []
  bundledCode: "#line 2 \"lib/math/prime_factorize.hpp\"\n\n#line 2 \"lib/include.hpp\"\
    \n#include <bits/stdc++.h>\n#include <experimental/iterator>\nusing namespace\
    \ std;\n#define overload3(_1, _2, _3, name, ...) name\n#define rep1(n) for (auto\
    \ _i = 0; _i < n; _i++)\n#define rep2(i, n) for (auto i = 0; i < n; i++)\n#define\
    \ rep3(i, a, b) for (auto i = a; i < b; i++)\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\ntemplate <class T> bool chmax(T &a, const T\
    \ &b) { return a < b ? a = b, true : false; }\ntemplate <class T> bool chmin(T\
    \ &a, const T &b) { return a > b ? a = b, true : false; }\nusing i64 = long long;\n\
    using f64 = long double;\n#line 4 \"lib/math/prime_factorize.hpp\"\n\n/**\n *\
    \ @brief prime factorize\n * @note O(\u221AN)\n */\n\ntemplate<class T> map<T,\
    \ int> prime_factorize(T n) {\n    map<T, int> factor;\n    for (auto p = 2; p\
    \ * p <= n; p++) {\n        if (n % p != 0) continue;\n        int ex = 0;\n \
    \       while (n % p == 0) {\n            ex++;\n            n /= p;\n       \
    \ }\n        factor[p] = ex;\n    }\n    if (n != 1) factor[n] = 1;\n    return\
    \ factor;\n}\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief prime factorize\n\
    \ * @note O(\u221AN)\n */\n\ntemplate<class T> map<T, int> prime_factorize(T n)\
    \ {\n    map<T, int> factor;\n    for (auto p = 2; p * p <= n; p++) {\n      \
    \  if (n % p != 0) continue;\n        int ex = 0;\n        while (n % p == 0)\
    \ {\n            ex++;\n            n /= p;\n        }\n        factor[p] = ex;\n\
    \    }\n    if (n != 1) factor[n] = 1;\n    return factor;\n}"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/math/prime_factorize.hpp
  requiredBy: []
  timestamp: '2021-07-10 14:38:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - lib/test/atcoder/abc110d.test.cpp
documentation_of: lib/math/prime_factorize.hpp
layout: document
redirect_from:
- /library/lib/math/prime_factorize.hpp
- /library/lib/math/prime_factorize.hpp.html
title: prime factorize
---
