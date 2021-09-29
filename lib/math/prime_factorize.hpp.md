---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/NTL_1_A.test.cpp
    title: test/aoj/NTL_1_A.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc110d.test.cpp
    title: test/atcoder/abc110d.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Prime Factorize($O(\u221AN)$)"
    links: []
  bundledCode: "#line 2 \"lib/math/prime_factorize.hpp\"\n\n#line 2 \"lib/include.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_NULL, _2,\
    \ _3, name, ...) name\n#define rep1(i, n) for (remove_const_t<remove_reference_t<decltype(n)>>\
    \ i = 0; i < (n); i++)\n#define rep2(i, a, b) for (remove_const_t<remove_reference_t<decltype(b)>>\
    \ i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)\n\
    using size_type = size_t;\n#line 4 \"lib/math/prime_factorize.hpp\"\n\n/**\n *\
    \ @brief Prime Factorize($O(\u221AN)$)\n */\n\ntemplate<class T> map<T, int> prime_factorize(T\
    \ n) {\n    map<T, int> factor;\n    for (auto p = 2; p * p <= n; p++) {\n   \
    \     if (n % p != 0) continue;\n        int ex = 0;\n        while (n % p ==\
    \ 0) {\n            ex++;\n            n /= p;\n        }\n        factor[p] =\
    \ ex;\n    }\n    if (n != 1) factor[n] = 1;\n    return factor;\n}\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief Prime Factorize($O(\u221A\
    N)$)\n */\n\ntemplate<class T> map<T, int> prime_factorize(T n) {\n    map<T,\
    \ int> factor;\n    for (auto p = 2; p * p <= n; p++) {\n        if (n % p !=\
    \ 0) continue;\n        int ex = 0;\n        while (n % p == 0) {\n          \
    \  ex++;\n            n /= p;\n        }\n        factor[p] = ex;\n    }\n   \
    \ if (n != 1) factor[n] = 1;\n    return factor;\n}\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/math/prime_factorize.hpp
  requiredBy: []
  timestamp: '2021-09-29 20:09:01+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/atcoder/abc110d.test.cpp
  - test/aoj/NTL_1_A.test.cpp
documentation_of: lib/math/prime_factorize.hpp
layout: document
redirect_from:
- /library/lib/math/prime_factorize.hpp
- /library/lib/math/prime_factorize.hpp.html
title: "Prime Factorize($O(\u221AN)$)"
---
