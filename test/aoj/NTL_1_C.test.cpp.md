---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/include.hpp
    title: lib/include.hpp
  - icon: ':x:'
    path: lib/math/gcd.hpp
    title: lib/math/gcd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C
  bundledCode: "#line 1 \"test/aoj/NTL_1_C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C\"\
    \n\n#line 2 \"lib/math/gcd.hpp\"\n\n#include <type_traits>\n\n#line 2 \"lib/include.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_NULL, _2,\
    \ _3, name, ...) name\n#define rep1(i, n) for (remove_const_t<remove_reference_t<decltype(n)>>\
    \ i = 0; i < (n); i++)\n#define rep2(i, a, b) for (remove_const_t<remove_reference_t<decltype(b)>>\
    \ i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)\n\
    using size_type = size_t;\n#line 6 \"lib/math/gcd.hpp\"\n\ntemplate<typename T>\
    \ T mygcd(T a, T b) {\n    static_assert(is_integral<T>::value);\n    while (a\
    \ % b != 0) {\n        T u = a % b;\n        a = b;\n        b = u;\n    }\n \
    \   return b;\n}\n\ntemplate<typename T> T mylcm(T a, T b) { return a / mygcd(a,\
    \ b) * b; }\n#line 4 \"test/aoj/NTL_1_C.test.cpp\"\n\nint main() {\n    int n;\n\
    \    cin >> n;\n    vector<int> a(n);\n    for (auto&& ai: a) cin >> ai;\n   \
    \ int ans = reduce(cbegin(a), cend(a), 1, [](int p, int q) { return mylcm(p, q);\
    \ });\n    cout << ans << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C\"\
    \n\n#include \"lib/math/gcd.hpp\"\n\nint main() {\n    int n;\n    cin >> n;\n\
    \    vector<int> a(n);\n    for (auto&& ai: a) cin >> ai;\n    int ans = reduce(cbegin(a),\
    \ cend(a), 1, [](int p, int q) { return mylcm(p, q); });\n    cout << ans << \"\
    \\n\";\n}\n"
  dependsOn:
  - lib/math/gcd.hpp
  - lib/include.hpp
  isVerificationFile: true
  path: test/aoj/NTL_1_C.test.cpp
  requiredBy: []
  timestamp: '2021-09-29 20:09:01+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/NTL_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_C.test.cpp
- /verify/test/aoj/NTL_1_C.test.cpp.html
title: test/aoj/NTL_1_C.test.cpp
---
