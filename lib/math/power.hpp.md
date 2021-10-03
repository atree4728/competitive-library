---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_A.test.cpp
    title: test/aoj/DPL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_B.test.cpp
    title: test/aoj/NTL_1_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/math/power.hpp\"\n\nlong long power(long long a, long\
    \ long b) {\n    long long ans = 1;\n    for (; b; b >>= 1) {\n        if (b &\
    \ 1) ans *= a;\n        a *= a;\n    }\n    return ans;\n}\n\nlong long power(long\
    \ long a, long long b, int m) {\n    a %= m;\n    long long ans = 1;\n    for\
    \ (; b; b >>= 1) {\n        if (b & 1) (ans *= a) %= m;\n        (a *= a) %= m;\n\
    \    }\n    return ans;\n}\n"
  code: "#pragma once\n\nlong long power(long long a, long long b) {\n    long long\
    \ ans = 1;\n    for (; b; b >>= 1) {\n        if (b & 1) ans *= a;\n        a\
    \ *= a;\n    }\n    return ans;\n}\n\nlong long power(long long a, long long b,\
    \ int m) {\n    a %= m;\n    long long ans = 1;\n    for (; b; b >>= 1) {\n  \
    \      if (b & 1) (ans *= a) %= m;\n        (a *= a) %= m;\n    }\n    return\
    \ ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/power.hpp
  requiredBy: []
  timestamp: '2021-10-03 22:04:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_5_A.test.cpp
  - test/aoj/NTL_1_B.test.cpp
documentation_of: lib/math/power.hpp
layout: document
redirect_from:
- /library/lib/math/power.hpp
- /library/lib/math/power.hpp.html
title: lib/math/power.hpp
---
