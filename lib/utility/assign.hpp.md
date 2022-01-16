---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  requiredBy: []
  timestamp: '2022-01-16 21:32:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/utility/assign.hpp
layout: document
redirect_from:
- /library/lib/utility/assign.hpp
- /library/lib/utility/assign.hpp.html
title: lib/utility/assign.hpp
---
