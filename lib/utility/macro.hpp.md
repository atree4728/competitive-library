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
  bundledCode: '#line 2 "lib/utility/macro.hpp"


    #define overload2(_NULL, _1, _2, name, ...) name

    #define rep1(i, n) for (std::decay_t<decltype(n)> i = 0; i < (n); i++)

    #define rep2(i, a, b) for (std::decay_t<decltype(b)> i = (a); i < (b); i++)

    #define rep(...) overload2(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)

    #define LAMBDA(...) [&]([[maybe_unused]] const auto& _) { return __VA_ARGS__;
    }

    #define LAMBDA2(...) [&](const auto& _1, const auto& _2) { return __VA_ARGS__;
    }

    '
  code: '#pragma once


    #define overload2(_NULL, _1, _2, name, ...) name

    #define rep1(i, n) for (std::decay_t<decltype(n)> i = 0; i < (n); i++)

    #define rep2(i, a, b) for (std::decay_t<decltype(b)> i = (a); i < (b); i++)

    #define rep(...) overload2(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)

    #define LAMBDA(...) [&]([[maybe_unused]] const auto& _) { return __VA_ARGS__;
    }

    #define LAMBDA2(...) [&](const auto& _1, const auto& _2) { return __VA_ARGS__;
    }

    '
  dependsOn: []
  isVerificationFile: false
  path: lib/utility/macro.hpp
  requiredBy:
  - lib/utility/template.hpp
  timestamp: '2022-01-16 21:32:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1595.test.cpp
documentation_of: lib/utility/macro.hpp
layout: document
redirect_from:
- /library/lib/utility/macro.hpp
- /library/lib/utility/macro.hpp.html
title: lib/utility/macro.hpp
---
