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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
  bundledCode: "#line 1 \"test/aoj/NTL_1_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B\"\
    \n\n#include <iostream>\n#line 2 \"lib/math/power.hpp\"\n\nlong long power(long\
    \ long a, long long b) {\n    long long ans = 1;\n    for (; b; b >>= 1) {\n \
    \       if (b & 1) ans *= a;\n        a *= a;\n    }\n    return ans;\n}\n\nlong\
    \ long power(long long a, long long b, int m) {\n    a %= m;\n    long long ans\
    \ = 1;\n    for (; b; b >>= 1) {\n        if (b & 1) (ans *= a) %= m;\n      \
    \  (a *= a) %= m;\n    }\n    return ans;\n}\n#line 5 \"test/aoj/NTL_1_B.test.cpp\"\
    \n\nint main() {\n    using namespace std;\n    int m, n;\n    cin >> m >> n;\n\
    \    const int MOD = 1'000'000'007;\n    int ans = power(m, n, MOD);\n    cout\
    \ << ans << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B\"\
    \n\n#include <iostream>\n#include \"lib/math/power.hpp\"\n\nint main() {\n   \
    \ using namespace std;\n    int m, n;\n    cin >> m >> n;\n    const int MOD =\
    \ 1'000'000'007;\n    int ans = power(m, n, MOD);\n    cout << ans << \"\\n\"\
    ;\n}\n"
  dependsOn:
  - lib/math/power.hpp
  isVerificationFile: true
  path: test/aoj/NTL_1_B.test.cpp
  requiredBy: []
  timestamp: '2021-10-03 22:04:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_B.test.cpp
- /verify/test/aoj/NTL_1_B.test.cpp.html
title: test/aoj/NTL_1_B.test.cpp
---
