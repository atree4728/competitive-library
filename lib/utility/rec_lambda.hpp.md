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
  bundledCode: "#line 2 \"lib/utility/rec_lambda.hpp\"\n\n#include <utility>\n\ntemplate<class\
    \ F> struct rec_lambda {\n    F f;\n    explicit constexpr rec_lambda(F&& f):\
    \ f(std::forward<F>(f)) {}\n    template<class... Args> constexpr decltype(auto)\
    \ operator()(Args&&... args) const {\n        return f(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n"
  code: "#pragma once\n\n#include <utility>\n\ntemplate<class F> struct rec_lambda\
    \ {\n    F f;\n    explicit constexpr rec_lambda(F&& f): f(std::forward<F>(f))\
    \ {}\n    template<class... Args> constexpr decltype(auto) operator()(Args&&...\
    \ args) const {\n        return f(*this, std::forward<Args>(args)...);\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/utility/rec_lambda.hpp
  requiredBy: []
  timestamp: '2022-01-16 21:32:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/utility/rec_lambda.hpp
layout: document
redirect_from:
- /library/lib/utility/rec_lambda.hpp
- /library/lib/utility/rec_lambda.hpp.html
title: lib/utility/rec_lambda.hpp
---
