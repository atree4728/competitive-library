---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Extended Euclid's Algorithm
    links:
    - https://noshi91.hatenablog.com/entry/2019/04/01/184957
  bundledCode: "#line 2 \"lib/math/extgcd.hpp\"\n\n#include <cassert>\n\n#line 2 \"\
    lib/include.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_1,\
    \ _2, _3, name, ...) name\n#define rep1(n) for (decltype(n) _tmp = 0; _tmp < (n);\
    \ _tmp++)\n#define rep2(i, n) for (decltype(n) i = 0; i < (n); i++)\n#define rep3(i,\
    \ a, b) for (decltype(b) i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\nstruct IOSetup {\n    IOSetup() noexcept {\n\
    \        ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n        cout\
    \ << fixed << setprecision(10);\n        cerr << fixed << setprecision(10);\n\
    \    }\n} iosetup;\ntemplate<class T> bool chmax(T &a, const T &b) { return a\
    \ < b and (a = b, true); }\ntemplate<class T> bool chmin(T &a, const T &b) { return\
    \ a > b and (a = b, true); }\nusing i64 = long long;\nusing f64 = long double;\n\
    #line 6 \"lib/math/extgcd.hpp\"\n\n/**\n * @brief Extended Euclid's Algorithm\n\
    \ * @note return pair of minimum x, y s.t. ax + by = gcd(x, y)\n * @ref https://noshi91.hatenablog.com/entry/2019/04/01/184957\n\
    \ */\n\ntemplate<typename T> pair<T, T> extgcd(T a, T b) {\n    static_assert(is_integral<T>::value);\n\
    \    T s = a, xs = 1, ys = 0, t = b, xt = 0, yt = 1;\n    while (s % t != 0) {\n\
    \        T tmp = s / t,\n          u = s - t * tmp,\n          xu = xs - xt *\
    \ tmp,\n          yu = ys - yt * tmp;\n        s = t, xs = xt, ys = yt;\n    \
    \    t = u, xt = xu, yt = yu;\n    }\n    assert(t == gcd(a, b));\n    return\
    \ {xt, yt};\n}\n"
  code: "#pragma once\n\n#include <cassert>\n\n#include \"../include.hpp\"\n\n/**\n\
    \ * @brief Extended Euclid's Algorithm\n * @note return pair of minimum x, y s.t.\
    \ ax + by = gcd(x, y)\n * @ref https://noshi91.hatenablog.com/entry/2019/04/01/184957\n\
    \ */\n\ntemplate<typename T> pair<T, T> extgcd(T a, T b) {\n    static_assert(is_integral<T>::value);\n\
    \    T s = a, xs = 1, ys = 0, t = b, xt = 0, yt = 1;\n    while (s % t != 0) {\n\
    \        T tmp = s / t,\n          u = s - t * tmp,\n          xu = xs - xt *\
    \ tmp,\n          yu = ys - yt * tmp;\n        s = t, xs = xt, ys = yt;\n    \
    \    t = u, xt = xu, yt = yu;\n    }\n    assert(t == gcd(a, b));\n    return\
    \ {xt, yt};\n}\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/math/extgcd.hpp
  requiredBy: []
  timestamp: '2021-08-31 17:00:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/extgcd.hpp
layout: document
redirect_from:
- /library/lib/math/extgcd.hpp
- /library/lib/math/extgcd.hpp.html
title: Extended Euclid's Algorithm
---
