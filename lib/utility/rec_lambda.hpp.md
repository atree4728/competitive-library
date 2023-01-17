---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/graph/lowest_common_ancestor.hpp
    title: "Lowest Common Ancestor(Doubling, Binary Search) / \u6700\u8FD1\u5171\u901A\
      \u7956\u5148"
  - icon: ':heavy_check_mark:'
    path: lib/graph/rerooting_dp.hpp
    title: "Rerooting DP / \u5168\u65B9\u4F4D\u6728 DP"
  - icon: ':heavy_check_mark:'
    path: lib/utility/io.hpp
    title: lib/utility/io.hpp
  - icon: ':heavy_check_mark:'
    path: lib/utility/make_vector.hpp
    title: lib/utility/make_vector.hpp
  - icon: ':heavy_check_mark:'
    path: lib/utility/scanner.hpp
    title: lib/utility/scanner.hpp
  - icon: ':heavy_check_mark:'
    path: lib/utility/template.hpp
    title: lib/utility/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1595.test.cpp
    title: test/aoj/1595.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_C.test.cpp
    title: test/aoj/GRL_5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/lca.test.cpp
    title: test/library-checker/lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  - lib/graph/rerooting_dp.hpp
  - lib/graph/lowest_common_ancestor.hpp
  - lib/utility/make_vector.hpp
  - lib/utility/scanner.hpp
  - lib/utility/io.hpp
  - lib/utility/template.hpp
  timestamp: '2022-01-16 21:32:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1595.test.cpp
  - test/aoj/GRL_5_C.test.cpp
  - test/library-checker/lca.test.cpp
documentation_of: lib/utility/rec_lambda.hpp
layout: document
redirect_from:
- /library/lib/utility/rec_lambda.hpp
- /library/lib/utility/rec_lambda.hpp.html
title: lib/utility/rec_lambda.hpp
---
