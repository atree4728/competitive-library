---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/cumulative_sum.hpp
    title: Partial Sum
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/cumulative_sum_2D.hpp
    title: Partial Sum(2D)
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/union_find.hpp
    title: Union Find
  - icon: ':heavy_check_mark:'
    path: lib/graph/bellman_ford.hpp
    title: Bellman-Ford's Algorithm
  - icon: ':heavy_check_mark:'
    path: lib/graph/dijkstra.hpp
    title: Dijkstra's Algorithm
  - icon: ':heavy_check_mark:'
    path: lib/graph/floyd_warshall.hpp
    title: Floyd Warshall's Algorithm
  - icon: ':heavy_check_mark:'
    path: lib/graph/kruskal.hpp
    title: Kruskal's Algorithm
  - icon: ':heavy_check_mark:'
    path: lib/graph/topological_sort.hpp
    title: Topological Sort
  - icon: ':heavy_check_mark:'
    path: lib/math/convert_base.hpp
    title: Convert Base
  - icon: ':warning:'
    path: lib/math/divisor.hpp
    title: Multiple Enumeration
  - icon: ':heavy_check_mark:'
    path: lib/math/eratosthenes.hpp
    title: Eratosthenes's Sieve
  - icon: ':warning:'
    path: lib/math/is_prime.hpp
    title: "Prime Determination($O(\u221AN)$)"
  - icon: ':heavy_check_mark:'
    path: lib/math/prime_factorize.hpp
    title: "Prime Factorize($O(\u221AN)$)"
  - icon: ':warning:'
    path: lib/math/simple_combination.hpp
    title: Combination without mod
  - icon: ':heavy_check_mark:'
    path: lib/modulus/combination.hpp
    title: Combination on mod
  - icon: ':heavy_check_mark:'
    path: lib/modulus/modint.hpp
    title: Finite Field
  - icon: ':warning:'
    path: lib/utility/print.hpp
    title: Print
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0560.test.cpp
    title: test/aoj/0560.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_A.test.cpp
    title: test/aoj/DPL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_B.test.cpp
    title: test/aoj/DPL_5_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_D.test.cpp
    title: test/aoj/DPL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_E.test.cpp
    title: test/aoj/DPL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_A.test.cpp
    title: test/aoj/GRL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_B.test.cpp
    title: test/aoj/GRL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_C.test.cpp
    title: test/aoj/GRL_1_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.test.cpp
    title: test/aoj/GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_4_A.test.cpp
    title: test/aoj/GRL_4_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc110d.test.cpp
    title: test/atcoder/abc110d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/static_range_sum.test.cpp
    title: test/library-checker/static_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/unionfind.test.cpp
    title: test/library-checker/unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/my_stress_test/convert_base.test.cpp
    title: test/my_stress_test/convert_base.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/my_stress_test/topological_sort.test.cpp
    title: test/my_stress_test/topological_sort.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1140.test.cpp
    title: test/yukicoder/1140.test.cpp
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

    #define rep1(n) for (decltype(n) _tmp = 0; _tmp < n; _tmp++)

    #define rep2(i, n) for (decltype(n) i = 0; i < n; i++)

    #define rep3(i, a, b) for (decltype(b) i = a; i < b; i++)

    #define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

    struct IOSetup { IOSetup() noexcept { ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed << setprecision(10); cerr << fixed << setprecision(10); } } iosetup;

    template <class T> bool chmax(T &a, const T &b) { return a < b and (a = b, true);
    }

    template <class T> bool chmin(T &a, const T &b) { return a > b and (a = b, true);
    }

    using i64 = long long;

    using u64 = unsigned long long;

    using f64 = long double;

    '
  code: '#pragma once


    #include <bits/stdc++.h>

    #include <experimental/iterator>

    using namespace std;

    #define overload3(_1, _2, _3, name, ...) name

    #define rep1(n) for (decltype(n) _tmp = 0; _tmp < n; _tmp++)

    #define rep2(i, n) for (decltype(n) i = 0; i < n; i++)

    #define rep3(i, a, b) for (decltype(b) i = a; i < b; i++)

    #define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

    struct IOSetup { IOSetup() noexcept { ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed << setprecision(10); cerr << fixed << setprecision(10); } } iosetup;

    template <class T> bool chmax(T &a, const T &b) { return a < b and (a = b, true);
    }

    template <class T> bool chmin(T &a, const T &b) { return a > b and (a = b, true);
    }

    using i64 = long long;

    using u64 = unsigned long long;

    using f64 = long double;

    '
  dependsOn: []
  isVerificationFile: false
  path: lib/include.hpp
  requiredBy:
  - lib/graph/dijkstra.hpp
  - lib/graph/kruskal.hpp
  - lib/graph/floyd_warshall.hpp
  - lib/graph/topological_sort.hpp
  - lib/graph/bellman_ford.hpp
  - lib/data_structure/cumulative_sum_2D.hpp
  - lib/data_structure/union_find.hpp
  - lib/data_structure/cumulative_sum.hpp
  - lib/modulus/modint.hpp
  - lib/modulus/combination.hpp
  - lib/utility/print.hpp
  - lib/math/divisor.hpp
  - lib/math/simple_combination.hpp
  - lib/math/convert_base.hpp
  - lib/math/is_prime.hpp
  - lib/math/eratosthenes.hpp
  - lib/math/prime_factorize.hpp
  timestamp: '2021-07-21 10:45:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/static_range_sum.test.cpp
  - test/library-checker/unionfind.test.cpp
  - test/atcoder/abc110d.test.cpp
  - test/my_stress_test/topological_sort.test.cpp
  - test/my_stress_test/convert_base.test.cpp
  - test/yukicoder/1140.test.cpp
  - test/aoj/GRL_1_C.test.cpp
  - test/aoj/GRL_1_B.test.cpp
  - test/aoj/DPL_5_A.test.cpp
  - test/aoj/DPL_5_D.test.cpp
  - test/aoj/GRL_2_A.test.cpp
  - test/aoj/DPL_5_B.test.cpp
  - test/aoj/GRL_4_A.test.cpp
  - test/aoj/0560.test.cpp
  - test/aoj/GRL_1_A.test.cpp
  - test/aoj/DPL_5_E.test.cpp
documentation_of: lib/include.hpp
layout: document
redirect_from:
- /library/lib/include.hpp
- /library/lib/include.hpp.html
title: lib/include.hpp
---
