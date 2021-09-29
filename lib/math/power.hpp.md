---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/NTL_1_B.test.cpp
    title: test/aoj/NTL_1_B.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/math/power.hpp\"\n\n#line 2 \"lib/include.hpp\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_NULL, _2, _3,\
    \ name, ...) name\n#define rep1(i, n) for (remove_const_t<remove_reference_t<decltype(n)>>\
    \ i = 0; i < (n); i++)\n#define rep2(i, a, b) for (remove_const_t<remove_reference_t<decltype(b)>>\
    \ i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)\n\
    using size_type = size_t;\n#line 4 \"lib/math/power.hpp\"\n\ni64 power(i64 a,\
    \ i64 b) {\n    i64 ans = 1;\n    for (; b; b >>= 1) {\n        if (b & 1) ans\
    \ *= a;\n        a *= a;\n    }\n    return ans;\n}\n\ni64 power(i64 a, i64 b,\
    \ int m) {\n    a %= m;\n    i64 ans = 1;\n    for (; b; b >>= 1) {\n        if\
    \ (b & 1) (ans *= a) %= m;\n        (a *= a) %= m;\n    }\n    return ans;\n}\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\ni64 power(i64 a, i64 b) {\n\
    \    i64 ans = 1;\n    for (; b; b >>= 1) {\n        if (b & 1) ans *= a;\n  \
    \      a *= a;\n    }\n    return ans;\n}\n\ni64 power(i64 a, i64 b, int m) {\n\
    \    a %= m;\n    i64 ans = 1;\n    for (; b; b >>= 1) {\n        if (b & 1) (ans\
    \ *= a) %= m;\n        (a *= a) %= m;\n    }\n    return ans;\n}\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/math/power.hpp
  requiredBy: []
  timestamp: '2021-09-29 20:09:01+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/NTL_1_B.test.cpp
documentation_of: lib/math/power.hpp
layout: document
redirect_from:
- /library/lib/math/power.hpp
- /library/lib/math/power.hpp.html
title: lib/math/power.hpp
---
