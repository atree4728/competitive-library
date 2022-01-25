---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/utility/template.hpp
    title: lib/utility/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1595.test.cpp
    title: test/aoj/1595.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/utility/assign.hpp\"\n\n#include <utility>\n\ntemplate<class\
    \ T, class U = T> constexpr inline auto chmin(T& a, U&& b) -> bool {\n    return\
    \ b < a ? a = std::forward<U>(b), true : false;\n}\ntemplate<class T, class U\
    \ = T> constexpr inline auto chmax(T& a, U&& b) -> bool {\n    return a < b ?\
    \ a = std::forward<U>(b), true : false;\n}\n"
  code: "#pragma once\n\n#include <utility>\n\ntemplate<class T, class U = T> constexpr\
    \ inline auto chmin(T& a, U&& b) -> bool {\n    return b < a ? a = std::forward<U>(b),\
    \ true : false;\n}\ntemplate<class T, class U = T> constexpr inline auto chmax(T&\
    \ a, U&& b) -> bool {\n    return a < b ? a = std::forward<U>(b), true : false;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/utility/assign.hpp
  requiredBy:
  - lib/utility/template.hpp
  timestamp: '2022-01-16 21:32:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1595.test.cpp
documentation_of: lib/utility/assign.hpp
layout: document
redirect_from:
- /library/lib/utility/assign.hpp
- /library/lib/utility/assign.hpp.html
title: lib/utility/assign.hpp
---
