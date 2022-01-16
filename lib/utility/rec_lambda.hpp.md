---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: lib/graph/lowest_common_ancestor.hpp
    title: "Lowest Common Ancestor(Doubling, Binary Search) / \u6700\u8FD1\u5171\u901A\
      \u7956\u5148"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_5_C.test.cpp
    title: test/aoj/GRL_5_C.test.cpp
  - icon: ':x:'
    path: test/library-checker/lca.test.cpp
    title: test/library-checker/lca.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
  requiredBy:
  - lib/graph/lowest_common_ancestor.hpp
  timestamp: '2022-01-16 21:32:47+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL_5_C.test.cpp
  - test/library-checker/lca.test.cpp
documentation_of: lib/utility/rec_lambda.hpp
layout: document
redirect_from:
- /library/lib/utility/rec_lambda.hpp
- /library/lib/utility/rec_lambda.hpp.html
title: lib/utility/rec_lambda.hpp
---
