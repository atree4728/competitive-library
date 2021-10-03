---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/euler_phi.hpp
    title: Euler's totient function / $\varphi(n)$
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_D
  bundledCode: "#line 1 \"test/aoj/NTL_1_D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_D\"\
    \n\n#include <iostream>\n#line 2 \"lib/math/euler_phi.hpp\"\n\n#include <cassert>\n\
    \ntemplate<typename T> T euler_phi(T n) {\n    assert(n > 0);\n    T ret = n;\n\
    \    for (T i = 2; i * i <= n; i++) {\n        if (n % i == 0) {\n           \
    \ ret -= ret / i;\n            while (n % i == 0) n /= i;\n        }\n    }\n\
    \    if (n > 1) ret -= ret / n;\n    return ret;\n}\n#line 5 \"test/aoj/NTL_1_D.test.cpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n    std::cout << euler_phi(n)\
    \ << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_D\"\n\n\
    #include <iostream>\n#include \"lib/math/euler_phi.hpp\"\n\nint main() {\n   \
    \ int n;\n    std::cin >> n;\n    std::cout << euler_phi(n) << \"\\n\";\n}\n"
  dependsOn:
  - lib/math/euler_phi.hpp
  isVerificationFile: true
  path: test/aoj/NTL_1_D.test.cpp
  requiredBy: []
  timestamp: '2021-10-03 22:09:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL_1_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_D.test.cpp
- /verify/test/aoj/NTL_1_D.test.cpp.html
title: test/aoj/NTL_1_D.test.cpp
---
