---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
  - icon: ':heavy_check_mark:'
    path: lib/math/extgcd.hpp
    title: Extended Euclid's Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
  bundledCode: "#line 1 \"test/aoj/NTL_1_E.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
    \n\n#line 2 \"lib/math/extgcd.hpp\"\n\n#include <cassert>\n\n#line 2 \"lib/include.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_NULL, _2,\
    \ _3, name, ...) name\n#define rep1(i, n) for (remove_const_t<remove_reference_t<decltype(n)>>\
    \ i = 0; i < (n); i++)\n#define rep2(i, a, b) for (remove_const_t<remove_reference_t<decltype(b)>>\
    \ i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)\n\
    using size_type = size_t;\n#line 6 \"lib/math/extgcd.hpp\"\n\n/**\n * @brief Extended\
    \ Euclid's Algorithm\n * @note return pair of minimum x, y s.t. ax + by = gcd(x,\
    \ y)\n * @ref https://noshi91.hatenablog.com/entry/2019/04/01/184957\n */\n\n\
    template<typename T> pair<T, T> extgcd(T a, T b) {\n    static_assert(is_integral<T>::value);\n\
    \    T s = a, xs = 1, ys = 0, t = b, xt = 0, yt = 1;\n    while (s % t != 0) {\n\
    \        T tmp = s / t,\n          u = s - t * tmp,\n          xu = xs - xt *\
    \ tmp,\n          yu = ys - yt * tmp;\n        s = t, xs = xt, ys = yt;\n    \
    \    t = u, xt = xu, yt = yu;\n    }\n    assert(t == gcd(a, b));\n    return\
    \ {xt, yt};\n}\n#line 4 \"test/aoj/NTL_1_E.test.cpp\"\n\nint main() {\n    int\
    \ a, b;\n    cin >> a >> b;\n    const auto& [x, y] = extgcd(a, b);\n    cout\
    \ << x << \" \" << y << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
    \n\n#include \"lib/math/extgcd.hpp\"\n\nint main() {\n    int a, b;\n    cin >>\
    \ a >> b;\n    const auto& [x, y] = extgcd(a, b);\n    cout << x << \" \" << y\
    \ << \"\\n\";\n}\n"
  dependsOn:
  - lib/math/extgcd.hpp
  - lib/include.hpp
  isVerificationFile: true
  path: test/aoj/NTL_1_E.test.cpp
  requiredBy: []
  timestamp: '2021-09-29 20:09:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL_1_E.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_E.test.cpp
- /verify/test/aoj/NTL_1_E.test.cpp.html
title: test/aoj/NTL_1_E.test.cpp
---
