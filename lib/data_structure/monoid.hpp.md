---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.test.cpp
    title: test/aoj/DSL_2_A.test.cpp
  - icon: ':x:'
    path: test/aoj/DSL_2_B.test.cpp
    title: test/aoj/DSL_2_B.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/monoid.hpp\"\n\n#include <limits>\n\n\
    #line 2 \"lib/include.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #define overload3(_1, _2, _3, name, ...) name\n#define rep1(n) for (decltype(n)\
    \ _tmp = 0; _tmp < (n); _tmp++)\n#define rep2(i, n) for (decltype(n) i = 0; i\
    \ < (n); i++)\n#define rep3(i, a, b) for (decltype(b) i = a; i < (b); i++)\n#define\
    \ rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\nstruct IOSetup\
    \ {\n    IOSetup() noexcept {\n        ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n\
    \        cout << fixed << setprecision(10);\n        cerr << fixed << setprecision(10);\n\
    \    }\n} iosetup;\ntemplate<class T> bool chmax(T &a, const T &b) { return a\
    \ < b and (a = b, true); }\ntemplate<class T> bool chmin(T &a, const T &b) { return\
    \ a > b and (a = b, true); }\nusing i64 = long long;\nusing f64 = long double;\n\
    #line 6 \"lib/data_structure/monoid.hpp\"\n\nstruct Add {\n    using T = int;\n\
    \    static T op(T a, T b) { return a + b; }\n    static inline T id = 0;\n};\n\
    \nstruct Mul {\n    using T = int;\n    static T op(T a, T b) { return a * b;\
    \ }\n    static inline T id = 1;\n};\n\nstruct Xor {\n    using T = int;\n   \
    \ static T op(T a, T b) { return a xor b; }\n    static inline T id = 0;\n};\n\
    \nstruct Min {\n    using T = int;\n    static T op(T a, T b) { return min(a,\
    \ b); }\n    static inline T id = numeric_limits<T>::max();\n};\n\nstruct Max\
    \ {\n    using T = int;\n    static T op(T a, T b) { return max(a, b); }\n   \
    \ static inline T id = numeric_limits<T>::min();\n};\n"
  code: "#pragma once\n\n#include <limits>\n\n#include \"../include.hpp\"\n\nstruct\
    \ Add {\n    using T = int;\n    static T op(T a, T b) { return a + b; }\n   \
    \ static inline T id = 0;\n};\n\nstruct Mul {\n    using T = int;\n    static\
    \ T op(T a, T b) { return a * b; }\n    static inline T id = 1;\n};\n\nstruct\
    \ Xor {\n    using T = int;\n    static T op(T a, T b) { return a xor b; }\n \
    \   static inline T id = 0;\n};\n\nstruct Min {\n    using T = int;\n    static\
    \ T op(T a, T b) { return min(a, b); }\n    static inline T id = numeric_limits<T>::max();\n\
    };\n\nstruct Max {\n    using T = int;\n    static T op(T a, T b) { return max(a,\
    \ b); }\n    static inline T id = numeric_limits<T>::min();\n};\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/data_structure/monoid.hpp
  requiredBy: []
  timestamp: '2021-08-31 17:00:15+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/DSL_2_A.test.cpp
  - test/aoj/DSL_2_B.test.cpp
documentation_of: lib/data_structure/monoid.hpp
layout: document
redirect_from:
- /library/lib/data_structure/monoid.hpp
- /library/lib/data_structure/monoid.hpp.html
title: lib/data_structure/monoid.hpp
---
