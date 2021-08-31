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
    links: []
  bundledCode: "#line 2 \"lib/math/power.hpp\"\n\n#include <type_traits>\n\n#line\
    \ 2 \"lib/include.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n#define\
    \ overload3(_1, _2, _3, name, ...) name\n#define rep1(n) for (decltype(n) _tmp\
    \ = 0; _tmp < (n); _tmp++)\n#define rep2(i, n) for (decltype(n) i = 0; i < (n);\
    \ i++)\n#define rep3(i, a, b) for (decltype(b) i = a; i < (b); i++)\n#define rep(...)\
    \ overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\nstruct IOSetup {\n  \
    \  IOSetup() noexcept {\n        ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n\
    \        cout << fixed << setprecision(10);\n        cerr << fixed << setprecision(10);\n\
    \    }\n} iosetup;\ntemplate<class T> bool chmax(T &a, const T &b) { return a\
    \ < b and (a = b, true); }\ntemplate<class T> bool chmin(T &a, const T &b) { return\
    \ a > b and (a = b, true); }\nusing i64 = long long;\nusing f64 = long double;\n\
    #line 6 \"lib/math/power.hpp\"\n\ntemplate<typename T> T power(T a, T b) {\n \
    \   static_assert(is_integral<T>::value, \"T must be integer!\");\n    T ret =\
    \ 1;\n    while (b > 0) {\n        if (b & 1) ret *= a;\n        b >>= 1;\n  \
    \      a *= a;\n    }\n    return ret;\n}\n"
  code: "#pragma once\n\n#include <type_traits>\n\n#include \"../include.hpp\"\n\n\
    template<typename T> T power(T a, T b) {\n    static_assert(is_integral<T>::value,\
    \ \"T must be integer!\");\n    T ret = 1;\n    while (b > 0) {\n        if (b\
    \ & 1) ret *= a;\n        b >>= 1;\n        a *= a;\n    }\n    return ret;\n\
    }\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/math/power.hpp
  requiredBy: []
  timestamp: '2021-08-31 17:00:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/power.hpp
layout: document
redirect_from:
- /library/lib/math/power.hpp
- /library/lib/math/power.hpp.html
title: lib/math/power.hpp
---
