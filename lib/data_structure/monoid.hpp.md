---
data:
  _extendedDependsOn: []
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
  bundledCode: "#line 2 \"lib/data_structure/monoid.hpp\"\n\n/**\n * @brief Monoids\n\
    \ * @note Monoid \u96C6\n */\n\n#include <algorithm>\n#include <limits>\n#include\
    \ <numeric>\n\nstruct Add {\n    using T = int;\n    static T op(T a, T b) { return\
    \ a + b; }\n    static inline T id = 0;\n};\n\nstruct Mul {\n    using T = int;\n\
    \    static T op(T a, T b) { return a * b; }\n    static inline T id = 1;\n};\n\
    \nstruct Xor {\n    using T = int;\n    static T op(T a, T b) { return a xor b;\
    \ }\n    static inline T id = 0;\n};\n\nstruct Min {\n    using T = int;\n   \
    \ static T op(T a, T b) { return std::min(a, b); }\n    static inline T id = std::numeric_limits<T>::max();\n\
    };\n\nstruct Max {\n    using T = int;\n    static T op(T a, T b) { return std::max(a,\
    \ b); }\n    static inline T id = std::numeric_limits<T>::min();\n};\n\nstruct\
    \ Gcd {\n    using T = int;\n    static T op(T a, T b) { return std::gcd(a, b);\
    \ }\n    static inline T id = 0;\n};\n\nstruct Lcm {\n    using T = int;\n   \
    \ static T op(T a, T b) { return std::lcm(a, b); }\n    static inline T id = 1;\n\
    };\n"
  code: "#pragma once\n\n/**\n * @brief Monoids\n * @note Monoid \u96C6\n */\n\n#include\
    \ <algorithm>\n#include <limits>\n#include <numeric>\n\nstruct Add {\n    using\
    \ T = int;\n    static T op(T a, T b) { return a + b; }\n    static inline T id\
    \ = 0;\n};\n\nstruct Mul {\n    using T = int;\n    static T op(T a, T b) { return\
    \ a * b; }\n    static inline T id = 1;\n};\n\nstruct Xor {\n    using T = int;\n\
    \    static T op(T a, T b) { return a xor b; }\n    static inline T id = 0;\n\
    };\n\nstruct Min {\n    using T = int;\n    static T op(T a, T b) { return std::min(a,\
    \ b); }\n    static inline T id = std::numeric_limits<T>::max();\n};\n\nstruct\
    \ Max {\n    using T = int;\n    static T op(T a, T b) { return std::max(a, b);\
    \ }\n    static inline T id = std::numeric_limits<T>::min();\n};\n\nstruct Gcd\
    \ {\n    using T = int;\n    static T op(T a, T b) { return std::gcd(a, b); }\n\
    \    static inline T id = 0;\n};\n\nstruct Lcm {\n    using T = int;\n    static\
    \ T op(T a, T b) { return std::lcm(a, b); }\n    static inline T id = 1;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/monoid.hpp
  requiredBy: []
  timestamp: '2021-10-03 22:04:20+09:00'
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
