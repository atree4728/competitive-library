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
  bundledCode: "#line 2 \"lib/data_structure/monoids.hpp\"\n\n/**\n * @brief Monoids\n\
    \ * @note Monoid \u96C6\n */\n\n#include <algorithm>\n#include <limits>\n#include\
    \ <numeric>\n\ntemplate<class T> struct Add {\n    using operand_type = T;\n \
    \   static operand_type operation(operand_type a, operand_type b) { return a +\
    \ b; }\n    static operand_type identity() { return static_cast<operand_type>(0);\
    \ }\n};\n\ntemplate<class T> struct Mul {\n    using operand_type = T;\n    static\
    \ operand_type operation(operand_type a, operand_type b) { return a * b; }\n \
    \   static operand_type identity() { return static_cast<operand_type>(1); }\n\
    };\n\ntemplate<class T> struct Xor {\n    using operand_type = T;\n    static\
    \ operand_type operation(operand_type a, operand_type b) { return a xor b; }\n\
    \    static operand_type identity() { return static_cast<operand_type>(0); }\n\
    };\n\ntemplate<class T> struct Min {\n    using operand_type = T;\n    static\
    \ operand_type operation(operand_type a, operand_type b) { return std::min(a,\
    \ b); }\n    static operand_type identity() { return std::numeric_limits<operand_type>::max();\
    \ }\n};\n\ntemplate<class T> struct Max {\n    using operand_type = T;\n    static\
    \ operand_type operation(operand_type a, operand_type b) { return std::max(a,\
    \ b); }\n    static operand_type identity() { return std::numeric_limits<operand_type>::min();\
    \ }\n};\n\ntemplate<class T> struct Gcd {\n    using operand_type = T;\n    static\
    \ operand_type operation(operand_type a, operand_type b) { return std::gcd(a,\
    \ b); }\n    static operand_type identity() { return static_cast<operand_type>(0);\
    \ }\n};\n\ntemplate<class T> struct Lcm {\n    using operand_type = T;\n    static\
    \ operand_type operation(operand_type a, operand_type b) { return std::lcm(a,\
    \ b); }\n    static operand_type identity() { return static_cast<operand_type>(1);\
    \ }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Monoids\n * @note Monoid \u96C6\n */\n\n#include\
    \ <algorithm>\n#include <limits>\n#include <numeric>\n\ntemplate<class T> struct\
    \ Add {\n    using operand_type = T;\n    static operand_type operation(operand_type\
    \ a, operand_type b) { return a + b; }\n    static operand_type identity() { return\
    \ static_cast<operand_type>(0); }\n};\n\ntemplate<class T> struct Mul {\n    using\
    \ operand_type = T;\n    static operand_type operation(operand_type a, operand_type\
    \ b) { return a * b; }\n    static operand_type identity() { return static_cast<operand_type>(1);\
    \ }\n};\n\ntemplate<class T> struct Xor {\n    using operand_type = T;\n    static\
    \ operand_type operation(operand_type a, operand_type b) { return a xor b; }\n\
    \    static operand_type identity() { return static_cast<operand_type>(0); }\n\
    };\n\ntemplate<class T> struct Min {\n    using operand_type = T;\n    static\
    \ operand_type operation(operand_type a, operand_type b) { return std::min(a,\
    \ b); }\n    static operand_type identity() { return std::numeric_limits<operand_type>::max();\
    \ }\n};\n\ntemplate<class T> struct Max {\n    using operand_type = T;\n    static\
    \ operand_type operation(operand_type a, operand_type b) { return std::max(a,\
    \ b); }\n    static operand_type identity() { return std::numeric_limits<operand_type>::min();\
    \ }\n};\n\ntemplate<class T> struct Gcd {\n    using operand_type = T;\n    static\
    \ operand_type operation(operand_type a, operand_type b) { return std::gcd(a,\
    \ b); }\n    static operand_type identity() { return static_cast<operand_type>(0);\
    \ }\n};\n\ntemplate<class T> struct Lcm {\n    using operand_type = T;\n    static\
    \ operand_type operation(operand_type a, operand_type b) { return std::lcm(a,\
    \ b); }\n    static operand_type identity() { return static_cast<operand_type>(1);\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/monoids.hpp
  requiredBy: []
  timestamp: '2021-11-16 23:22:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_A.test.cpp
documentation_of: lib/data_structure/monoids.hpp
layout: document
redirect_from:
- /library/lib/data_structure/monoids.hpp
- /library/lib/data_structure/monoids.hpp.html
title: Monoids
---
