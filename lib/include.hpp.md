---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/union_find.hpp
    title: Union-Find
  - icon: ':heavy_check_mark:'
    path: lib/graph/dijkstra.hpp
    title: Dijkstra's Algorithm
  - icon: ':heavy_check_mark:'
    path: lib/math/convert_base.hpp
    title: Convert base
  - icon: ':warning:'
    path: lib/math/divisor.hpp
    title: multiple enumeration
  - icon: ':heavy_check_mark:'
    path: lib/math/eratosthenes.hpp
    title: Eratosthenes's Sieve
  - icon: ':warning:'
    path: lib/math/is_prime.hpp
    title: prime determination
  - icon: ':heavy_check_mark:'
    path: lib/math/prime_factorize.hpp
    title: prime factorize
  - icon: ':warning:'
    path: lib/math/simple_combination.hpp
    title: Combination without mod
  - icon: ':heavy_check_mark:'
    path: lib/modulus/combination.hpp
    title: Combination on mod
  - icon: ':heavy_check_mark:'
    path: lib/modulus/modint.hpp
    title: Finite Field
  - icon: ':heavy_check_mark:'
    path: lib/utility/cumulative_sum.hpp
    title: Partial Sum
  - icon: ':heavy_check_mark:'
    path: lib/utility/cumulative_sum_2D.hpp
    title: Partial Sum(2D)
  - icon: ':warning:'
    path: lib/utility/print.hpp
    title: Print
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: lib/test/aoj/0560.test.cpp
    title: lib/test/aoj/0560.test.cpp
  - icon: ':heavy_check_mark:'
    path: lib/test/aoj/DPL_5_A.test.cpp
    title: lib/test/aoj/DPL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: lib/test/aoj/DPL_5_B.test.cpp
    title: lib/test/aoj/DPL_5_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: lib/test/aoj/DPL_5_D.test.cpp
    title: lib/test/aoj/DPL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: lib/test/aoj/DPL_5_E.test.cpp
    title: lib/test/aoj/DPL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: lib/test/aoj/GRL_1_A.test.cpp
    title: lib/test/aoj/GRL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: lib/test/atcoder/abc110d.test.cpp
    title: lib/test/atcoder/abc110d.test.cpp
  - icon: ':heavy_check_mark:'
    path: lib/test/library-checker/static_range_sum.test.cpp
    title: lib/test/library-checker/static_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: lib/test/library-checker/unionfind.test.cpp
    title: lib/test/library-checker/unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: lib/test/my_stress_test/convert_base.test.cpp
    title: lib/test/my_stress_test/convert_base.test.cpp
  - icon: ':heavy_check_mark:'
    path: lib/test/yukicoder/1140.test.cpp
    title: lib/test/yukicoder/1140.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 2 "lib/include.hpp"

    #include <bits/stdc++.h>

    #include <experimental/iterator>

    using namespace std;

    #define overload3(_1, _2, _3, name, ...) name

    #define rep1(n) for (auto _i = 0; _i < n; _i++)

    #define rep2(i, n) for (auto i = 0; i < n; i++)

    #define rep3(i, a, b) for (auto i = a; i < b; i++)

    #define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

    template <class T> bool chmax(T &a, const T &b) { return a < b ? a = b, true :
    false; }

    template <class T> bool chmin(T &a, const T &b) { return a > b ? a = b, true :
    false; }

    using i64 = long long;

    using f64 = long double;

    '
  code: '#pragma once

    #include <bits/stdc++.h>

    #include <experimental/iterator>

    using namespace std;

    #define overload3(_1, _2, _3, name, ...) name

    #define rep1(n) for (auto _i = 0; _i < n; _i++)

    #define rep2(i, n) for (auto i = 0; i < n; i++)

    #define rep3(i, a, b) for (auto i = a; i < b; i++)

    #define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

    template <class T> bool chmax(T &a, const T &b) { return a < b ? a = b, true :
    false; }

    template <class T> bool chmin(T &a, const T &b) { return a > b ? a = b, true :
    false; }

    using i64 = long long;

    using f64 = long double;'
  dependsOn: []
  isVerificationFile: false
  path: lib/include.hpp
  requiredBy:
  - lib/graph/dijkstra.hpp
  - lib/data_structure/union_find.hpp
  - lib/modulus/modint.hpp
  - lib/modulus/combination.hpp
  - lib/utility/print.hpp
  - lib/utility/cumulative_sum_2D.hpp
  - lib/utility/cumulative_sum.hpp
  - lib/math/divisor.hpp
  - lib/math/simple_combination.hpp
  - lib/math/convert_base.hpp
  - lib/math/is_prime.hpp
  - lib/math/eratosthenes.hpp
  - lib/math/prime_factorize.hpp
  timestamp: '2021-07-10 14:38:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - lib/test/library-checker/static_range_sum.test.cpp
  - lib/test/library-checker/unionfind.test.cpp
  - lib/test/atcoder/abc110d.test.cpp
  - lib/test/my_stress_test/convert_base.test.cpp
  - lib/test/yukicoder/1140.test.cpp
  - lib/test/aoj/DPL_5_A.test.cpp
  - lib/test/aoj/DPL_5_D.test.cpp
  - lib/test/aoj/DPL_5_B.test.cpp
  - lib/test/aoj/0560.test.cpp
  - lib/test/aoj/GRL_1_A.test.cpp
  - lib/test/aoj/DPL_5_E.test.cpp
documentation_of: lib/include.hpp
layout: document
redirect_from:
- /library/lib/include.hpp
- /library/lib/include.hpp.html
title: lib/include.hpp
---
