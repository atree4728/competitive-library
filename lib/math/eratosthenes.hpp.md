---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1140.test.cpp
    title: test/yukicoder/1140.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Eratosthenes's Sieve
    links: []
  bundledCode: "#line 2 \"lib/math/eratosthenes.hpp\"\n\n#line 2 \"lib/include.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_NULL, _2,\
    \ _3, name, ...) name\n#define rep1(i, n) for (remove_const_t<remove_reference_t<decltype(n)>>\
    \ i = 0; i < (n); i++)\n#define rep2(i, a, b) for (remove_const_t<remove_reference_t<decltype(b)>>\
    \ i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)\n\
    using size_type = size_t;\n#line 4 \"lib/math/eratosthenes.hpp\"\n\n/**\n * @brief\
    \ Eratosthenes's Sieve\n * @note construct in $O(NloglogN)$, return prime determination\
    \ in $O(1)$ and number of constants and prime factorization fastly(<-?).\n */\n\
    \nstruct Sieve {\n    int size;\n    vector<int> min_factor, prime_list;\n   \
    \ explicit Sieve(const int size_):\n        size(size_), min_factor(size_ + 1)\
    \ {\n        iota(begin(min_factor), end(min_factor), 0);\n        for (int i\
    \ = 2; i <= size; i++) {\n            if (min_factor[i] != i) {\n            \
    \    prime_list.emplace_back(i);\n                continue;\n            }\n \
    \           for (int mul = i * 2; mul <= size; mul += i)\n                if (min_factor[mul]\
    \ == mul) min_factor[mul] = i;\n        }\n    };\n    bool is_prime(const int\
    \ n) { return n >= 2 and (int) min_factor[n] == n; }\n    map<int, int> prime_factorize(const\
    \ int n) {\n        assert(1 <= n and n <= (int)size);\n        if (n == 1) return\
    \ {};\n        map<int, int> factor{};\n        int cur = n;\n        while (cur\
    \ != 1) {\n            factor[min_factor[cur]]++;\n            cur /= min_factor[cur];\n\
    \        }\n        return factor;\n    }\n    int count_divisor(const int n)\
    \ {\n        assert(1 <= n and n <= (int)size);\n        int ret = 1;\n      \
    \  map<int, int> factor = prime_factorize(n);\n        for (auto [_, ex]: factor)\
    \ ret *= (ex + 1);\n        return ret;\n    }\n};\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief Eratosthenes's\
    \ Sieve\n * @note construct in $O(NloglogN)$, return prime determination in $O(1)$\
    \ and number of constants and prime factorization fastly(<-?).\n */\n\nstruct\
    \ Sieve {\n    int size;\n    vector<int> min_factor, prime_list;\n    explicit\
    \ Sieve(const int size_):\n        size(size_), min_factor(size_ + 1) {\n    \
    \    iota(begin(min_factor), end(min_factor), 0);\n        for (int i = 2; i <=\
    \ size; i++) {\n            if (min_factor[i] != i) {\n                prime_list.emplace_back(i);\n\
    \                continue;\n            }\n            for (int mul = i * 2; mul\
    \ <= size; mul += i)\n                if (min_factor[mul] == mul) min_factor[mul]\
    \ = i;\n        }\n    };\n    bool is_prime(const int n) { return n >= 2 and\
    \ (int) min_factor[n] == n; }\n    map<int, int> prime_factorize(const int n)\
    \ {\n        assert(1 <= n and n <= (int)size);\n        if (n == 1) return {};\n\
    \        map<int, int> factor{};\n        int cur = n;\n        while (cur !=\
    \ 1) {\n            factor[min_factor[cur]]++;\n            cur /= min_factor[cur];\n\
    \        }\n        return factor;\n    }\n    int count_divisor(const int n)\
    \ {\n        assert(1 <= n and n <= (int)size);\n        int ret = 1;\n      \
    \  map<int, int> factor = prime_factorize(n);\n        for (auto [_, ex]: factor)\
    \ ret *= (ex + 1);\n        return ret;\n    }\n};\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/math/eratosthenes.hpp
  requiredBy: []
  timestamp: '2021-09-29 20:09:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1140.test.cpp
documentation_of: lib/math/eratosthenes.hpp
layout: document
redirect_from:
- /library/lib/math/eratosthenes.hpp
- /library/lib/math/eratosthenes.hpp.html
title: Eratosthenes's Sieve
---