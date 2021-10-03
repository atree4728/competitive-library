---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/power.hpp
    title: lib/math/power.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A
  bundledCode: "#line 1 \"test/aoj/DPL_5_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A\"\
    \n\n#include <iostream>\n#line 2 \"lib/math/power.hpp\"\n\nlong long power(long\
    \ long a, long long b) {\n    long long ans = 1;\n    for (; b; b >>= 1) {\n \
    \       if (b & 1) ans *= a;\n        a *= a;\n    }\n    return ans;\n}\n\nlong\
    \ long power(long long a, long long b, int m) {\n    a %= m;\n    long long ans\
    \ = 1;\n    for (; b; b >>= 1) {\n        if (b & 1) (ans *= a) %= m;\n      \
    \  (a *= a) %= m;\n    }\n    return ans;\n}\n#line 5 \"test/aoj/DPL_5_A.test.cpp\"\
    \n\nconstexpr int MOD = 1000000007;\n\nint main() {\n    using namespace std;\n\
    \    int n, k;\n    cin >> n >> k;\n    cout << power(k, n, MOD) << \"\\n\";\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A\"\
    \n\n#include <iostream>\n#include \"lib/math/power.hpp\"\n\nconstexpr int MOD\
    \ = 1000000007;\n\nint main() {\n    using namespace std;\n    int n, k;\n   \
    \ cin >> n >> k;\n    cout << power(k, n, MOD) << \"\\n\";\n    return 0;\n}\n"
  dependsOn:
  - lib/math/power.hpp
  isVerificationFile: true
  path: test/aoj/DPL_5_A.test.cpp
  requiredBy: []
  timestamp: '2021-10-03 22:04:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DPL_5_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_5_A.test.cpp
- /verify/test/aoj/DPL_5_A.test.cpp.html
title: test/aoj/DPL_5_A.test.cpp
---
