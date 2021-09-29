---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
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
    \n\n#line 2 \"lib/math/power.hpp\"\n\n#line 2 \"lib/include.hpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#define overload3(_NULL, _2, _3, name,\
    \ ...) name\n#define rep1(i, n) for (remove_const_t<remove_reference_t<decltype(n)>>\
    \ i = 0; i < (n); i++)\n#define rep2(i, a, b) for (remove_const_t<remove_reference_t<decltype(b)>>\
    \ i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)\n\
    using size_type = size_t;\n#line 4 \"lib/math/power.hpp\"\n\nlong long power(long\
    \ long a, long long b) {\n    long long ans = 1;\n    for (; b; b >>= 1) {\n \
    \       if (b & 1) ans *= a;\n        a *= a;\n    }\n    return ans;\n}\n\nlong\
    \ long power(long long a, long long b, int m) {\n    a %= m;\n    long long ans\
    \ = 1;\n    for (; b; b >>= 1) {\n        if (b & 1) (ans *= a) %= m;\n      \
    \  (a *= a) %= m;\n    }\n    return ans;\n}\n#line 4 \"test/aoj/NTL_1_B.test.cpp\"\
    \n\nconst int MOD = 1'000'000'007;\n\nint main() {\n    int m, n;\n    cin >>\
    \ m >> n;\n    int ans = power(m, n, MOD);\n    cout << ans << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B\"\
    \n\n#include \"lib/math/power.hpp\"\n\nconst int MOD = 1'000'000'007;\n\nint main()\
    \ {\n    int m, n;\n    cin >> m >> n;\n    int ans = power(m, n, MOD);\n    cout\
    \ << ans << \"\\n\";\n}\n"
  dependsOn:
  - lib/math/power.hpp
  - lib/include.hpp
  isVerificationFile: true
  path: test/aoj/NTL_1_B.test.cpp
  requiredBy: []
  timestamp: '2021-09-29 22:27:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_B.test.cpp
- /verify/test/aoj/NTL_1_B.test.cpp.html
title: test/aoj/NTL_1_B.test.cpp
---
