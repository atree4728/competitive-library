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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Monoids
    links: []
  bundledCode: "#line 2 \"lib/data_structure/monoid.hpp\"\n\n#line 2 \"lib/include.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_NULL, _2,\
    \ _3, name, ...) name\n#define rep1(i, n) for (remove_const_t<remove_reference_t<decltype(n)>>\
    \ i = 0; i < (n); i++)\n#define rep2(i, a, b) for (remove_const_t<remove_reference_t<decltype(b)>>\
    \ i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)\n\
    using size_type = size_t;\n#line 4 \"lib/data_structure/monoid.hpp\"\n\n/**\n\
    \ * @brief Monoids\n * @note Monoid \u96C6\n */\n\nstruct Add {\n    using T =\
    \ int;\n    static T op(T a, T b) { return a + b; }\n    static inline T id =\
    \ 0;\n};\n\nstruct Mul {\n    using T = int;\n    static T op(T a, T b) { return\
    \ a * b; }\n    static inline T id = 1;\n};\n\nstruct Xor {\n    using T = int;\n\
    \    static T op(T a, T b) { return a xor b; }\n    static inline T id = 0;\n\
    };\n\nstruct Min {\n    using T = int;\n    static T op(T a, T b) { return min(a,\
    \ b); }\n    static inline T id = numeric_limits<T>::max();\n};\n\nstruct Max\
    \ {\n    using T = int;\n    static T op(T a, T b) { return max(a, b); }\n   \
    \ static inline T id = numeric_limits<T>::min();\n};\n\nstruct Gcd {\n    using\
    \ T = int;\n    static T op(T a, T b) { return gcd(a, b); }\n    static inline\
    \ T id = 0;\n};\n\nstruct Lcm {\n    using T = int;\n    static T op(T a, T b)\
    \ { return lcm(a, b); }\n    static inline T id = 1;\n};\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief Monoids\n *\
    \ @note Monoid \u96C6\n */\n\nstruct Add {\n    using T = int;\n    static T op(T\
    \ a, T b) { return a + b; }\n    static inline T id = 0;\n};\n\nstruct Mul {\n\
    \    using T = int;\n    static T op(T a, T b) { return a * b; }\n    static inline\
    \ T id = 1;\n};\n\nstruct Xor {\n    using T = int;\n    static T op(T a, T b)\
    \ { return a xor b; }\n    static inline T id = 0;\n};\n\nstruct Min {\n    using\
    \ T = int;\n    static T op(T a, T b) { return min(a, b); }\n    static inline\
    \ T id = numeric_limits<T>::max();\n};\n\nstruct Max {\n    using T = int;\n \
    \   static T op(T a, T b) { return max(a, b); }\n    static inline T id = numeric_limits<T>::min();\n\
    };\n\nstruct Gcd {\n    using T = int;\n    static T op(T a, T b) { return gcd(a,\
    \ b); }\n    static inline T id = 0;\n};\n\nstruct Lcm {\n    using T = int;\n\
    \    static T op(T a, T b) { return lcm(a, b); }\n    static inline T id = 1;\n\
    };\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/data_structure/monoid.hpp
  requiredBy: []
  timestamp: '2021-09-29 20:09:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_A.test.cpp
documentation_of: lib/data_structure/monoid.hpp
layout: document
redirect_from:
- /library/lib/data_structure/monoid.hpp
- /library/lib/data_structure/monoid.hpp.html
title: Monoids
---
