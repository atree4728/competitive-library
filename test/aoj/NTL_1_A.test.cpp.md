---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/include.hpp
    title: lib/include.hpp
  - icon: ':x:'
    path: lib/math/prime_factorize.hpp
    title: "Prime Factorize($O(\u221AN)$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
  bundledCode: "#line 1 \"test/aoj/NTL_1_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n\n#line 2 \"lib/math/prime_factorize.hpp\"\n\n#line 2 \"lib/include.hpp\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_NULL, _2, _3,\
    \ name, ...) name\n#define rep1(i, n) for (remove_const_t<remove_reference_t<decltype(n)>>\
    \ i = 0; i < (n); i++)\n#define rep2(i, a, b) for (remove_const_t<remove_reference_t<decltype(b)>>\
    \ i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)\n\
    using size_type = size_t;\n#line 4 \"lib/math/prime_factorize.hpp\"\n\n/**\n *\
    \ @brief Prime Factorize($O(\u221AN)$)\n */\n\ntemplate<class T> map<T, int> prime_factorize(T\
    \ n) {\n    map<T, int> factor;\n    for (auto p = 2; p * p <= n; p++) {\n   \
    \     if (n % p != 0) continue;\n        int ex = 0;\n        while (n % p ==\
    \ 0) {\n            ex++;\n            n /= p;\n        }\n        factor[p] =\
    \ ex;\n    }\n    if (n != 1) factor[n] = 1;\n    return factor;\n}\n#line 4 \"\
    test/aoj/NTL_1_A.test.cpp\"\n\nint main() {\n    int n;\n    cin >> n;\n    auto\
    \ pf = prime_factorize(n);\n    cout << n << \":\";\n    for (auto [p, e]: pf)\
    \ {\n        while (e--) cout << \" \" << p;\n    }\n    cout << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n\n#include \"lib/math/prime_factorize.hpp\"\n\nint main() {\n    int n;\n  \
    \  cin >> n;\n    auto pf = prime_factorize(n);\n    cout << n << \":\";\n   \
    \ for (auto [p, e]: pf) {\n        while (e--) cout << \" \" << p;\n    }\n  \
    \  cout << \"\\n\";\n}\n"
  dependsOn:
  - lib/math/prime_factorize.hpp
  - lib/include.hpp
  isVerificationFile: true
  path: test/aoj/NTL_1_A.test.cpp
  requiredBy: []
  timestamp: '2021-09-29 20:09:01+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/NTL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_A.test.cpp
- /verify/test/aoj/NTL_1_A.test.cpp.html
title: test/aoj/NTL_1_A.test.cpp
---
