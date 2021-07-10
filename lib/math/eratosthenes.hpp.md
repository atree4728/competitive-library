---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: lib/test/yukicoder/1140.test.cpp
    title: lib/test/yukicoder/1140.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Eratosthenes's Sieve
    links: []
  bundledCode: "#line 2 \"lib/math/eratosthenes.hpp\"\n\n#line 2 \"lib/include.hpp\"\
    \n#include <bits/stdc++.h>\n#include <experimental/iterator>\nusing namespace\
    \ std;\n#define overload3(_1, _2, _3, name, ...) name\n#define rep1(n) for (auto\
    \ _i = 0; _i < n; _i++)\n#define rep2(i, n) for (auto i = 0; i < n; i++)\n#define\
    \ rep3(i, a, b) for (auto i = a; i < b; i++)\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\ntemplate <class T> bool chmax(T &a, const T\
    \ &b) { return a < b ? a = b, true : false; }\ntemplate <class T> bool chmin(T\
    \ &a, const T &b) { return a > b ? a = b, true : false; }\nusing i64 = long long;\n\
    using f64 = long double;\n#line 4 \"lib/math/eratosthenes.hpp\"\n\n/**\n * @brief\
    \ Eratosthenes's Sieve\n * @note construct in $O(NloglogN)$, return prime determination\
    \ in $O(1)$ and number of constants and prime factorization fastly(<-!?)\n */\n\
    \nclass Sieve {\n    size_t size;\n    vector<int> min_factor;\n\n  public:\n\
    \    vector<int> prime_list;\n\n    Sieve(const int size_):\n        size(size_),\
    \ min_factor(size_ + 1) {\n        assert(size >= 0);\n        iota(begin(min_factor),\
    \ end(min_factor), 0);\n        for (int i = 2; i <= size; i++) {\n          \
    \  if (min_factor[i] != i) {\n                prime_list.emplace_back(i);\n  \
    \              continue;\n            }\n            for (int mul = i * 2; mul\
    \ <= size; mul += i) {\n                if (min_factor[mul] == mul) min_factor[mul]\
    \ = i;\n            }\n        }\n    };\n    bool is_prime(const int n) { return\
    \ min_factor[n] == n and n >= 2; }\n    map<int, int> prime_factorize(const int\
    \ n) {\n        assert(1 <= n and n <= size);\n        if (n == 1) return {};\n\
    \        map<int, int> factor;\n        int cur = n;\n        while (cur != 1)\
    \ {\n            factor[min_factor[cur]]++;\n            cur /= min_factor[cur];\n\
    \        }\n        return factor;\n    }\n    int count_divisor(const int n)\
    \ {\n        assert(1 <= n and n <= size);\n        int ret = 1;\n        map<int,\
    \ int> factor = prime_factorize(n);\n        for (auto [p, ex]: factor) ret *=\
    \ (ex + 1);\n        return ret;\n    }\n};\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief Eratosthenes's\
    \ Sieve\n * @note construct in $O(NloglogN)$, return prime determination in $O(1)$\
    \ and number of constants and prime factorization fastly(<-!?)\n */\n\nclass Sieve\
    \ {\n    size_t size;\n    vector<int> min_factor;\n\n  public:\n    vector<int>\
    \ prime_list;\n\n    Sieve(const int size_):\n        size(size_), min_factor(size_\
    \ + 1) {\n        assert(size >= 0);\n        iota(begin(min_factor), end(min_factor),\
    \ 0);\n        for (int i = 2; i <= size; i++) {\n            if (min_factor[i]\
    \ != i) {\n                prime_list.emplace_back(i);\n                continue;\n\
    \            }\n            for (int mul = i * 2; mul <= size; mul += i) {\n \
    \               if (min_factor[mul] == mul) min_factor[mul] = i;\n           \
    \ }\n        }\n    };\n    bool is_prime(const int n) { return min_factor[n]\
    \ == n and n >= 2; }\n    map<int, int> prime_factorize(const int n) {\n     \
    \   assert(1 <= n and n <= size);\n        if (n == 1) return {};\n        map<int,\
    \ int> factor;\n        int cur = n;\n        while (cur != 1) {\n           \
    \ factor[min_factor[cur]]++;\n            cur /= min_factor[cur];\n        }\n\
    \        return factor;\n    }\n    int count_divisor(const int n) {\n       \
    \ assert(1 <= n and n <= size);\n        int ret = 1;\n        map<int, int> factor\
    \ = prime_factorize(n);\n        for (auto [p, ex]: factor) ret *= (ex + 1);\n\
    \        return ret;\n    }\n};\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/math/eratosthenes.hpp
  requiredBy: []
  timestamp: '2021-07-10 14:38:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - lib/test/yukicoder/1140.test.cpp
documentation_of: lib/math/eratosthenes.hpp
layout: document
redirect_from:
- /library/lib/math/eratosthenes.hpp
- /library/lib/math/eratosthenes.hpp.html
title: Eratosthenes's Sieve
---
