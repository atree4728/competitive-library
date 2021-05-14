---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: lib/math/eratosthenes.aoj.test.cpp
    title: lib/math/eratosthenes.aoj.test.cpp
  - icon: ':x:'
    path: lib/math/eratosthenes.yukicoder-1140.test.cpp
    title: lib/math/eratosthenes.yukicoder-1140.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Eratosthenes's sieve
    links: []
  bundledCode: "#line 2 \"lib/math/eratosthenes.hpp\"\n\n#include <vector>\n#include\
    \ <numeric>\n#include <cassert>\n#include <map>\n\nusing namespace std;\n\n/**\n\
    \ *@brief Eratosthenes's sieve\n */\n\nclass Eratosthenes {\n    int size;\n \
    \   vector<int> min_factor;\n    vector<int> prime_list;\n\n    void init() {\n\
    \        assert(size >= 0);\n        iota(begin(min_factor), end(min_factor),\
    \ 0);\n        for (int i = 2; i * i <= size; i++) {\n            if (min_factor[i]\
    \ != i) {\n                prime_list.emplace_back(i);\n                continue;\n\
    \            }\n            for (int mul = i * 2; mul <= size; mul += i) {\n \
    \               if (min_factor[mul] == mul) min_factor[mul] = i;\n           \
    \ }\n        }\n    }\n\n   public:\n    Eratosthenes(const int size_) : size(size_),\
    \ min_factor(size_ + 1) {\n        init();\n    };\n\n    bool is_prime(const\
    \ int n) { return min_factor[n] == n and n >= 2; }\n\n    map<long long, int>\
    \ prime_factorize(const long long n) {\n        assert(1 <= n and n < (long long)size\
    \ * size);\n        if (n == 1) return {};\n        map<long long, int> factor;\n\
    \        long long cur = n;\n        while (cur != 1) {\n            factor[min_factor[cur]]++;\n\
    \            cur /= min_factor[cur];\n        }\n        return factor;\n    }\n\
    \n    int count_divisor(const long long n) {\n        assert(1 <= n and n < (long\
    \ long)size * size);\n        long long ret = 1;\n        map<long long, int>\
    \ factor = prime_factorize(n);\n        for (auto [p, ex] : factor) ret *= (ex\
    \ + 1);\n        return ret;\n    }\n};\n"
  code: "#pragma once\n\n#include <vector>\n#include <numeric>\n#include <cassert>\n\
    #include <map>\n\nusing namespace std;\n\n/**\n *@brief Eratosthenes's sieve\n\
    \ */\n\nclass Eratosthenes {\n    int size;\n    vector<int> min_factor;\n   \
    \ vector<int> prime_list;\n\n    void init() {\n        assert(size >= 0);\n \
    \       iota(begin(min_factor), end(min_factor), 0);\n        for (int i = 2;\
    \ i * i <= size; i++) {\n            if (min_factor[i] != i) {\n             \
    \   prime_list.emplace_back(i);\n                continue;\n            }\n  \
    \          for (int mul = i * 2; mul <= size; mul += i) {\n                if\
    \ (min_factor[mul] == mul) min_factor[mul] = i;\n            }\n        }\n  \
    \  }\n\n   public:\n    Eratosthenes(const int size_) : size(size_), min_factor(size_\
    \ + 1) {\n        init();\n    };\n\n    bool is_prime(const int n) { return min_factor[n]\
    \ == n and n >= 2; }\n\n    map<long long, int> prime_factorize(const long long\
    \ n) {\n        assert(1 <= n and n < (long long)size * size);\n        if (n\
    \ == 1) return {};\n        map<long long, int> factor;\n        long long cur\
    \ = n;\n        while (cur != 1) {\n            factor[min_factor[cur]]++;\n \
    \           cur /= min_factor[cur];\n        }\n        return factor;\n    }\n\
    \n    int count_divisor(const long long n) {\n        assert(1 <= n and n < (long\
    \ long)size * size);\n        long long ret = 1;\n        map<long long, int>\
    \ factor = prime_factorize(n);\n        for (auto [p, ex] : factor) ret *= (ex\
    \ + 1);\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/eratosthenes.hpp
  requiredBy: []
  timestamp: '2021-05-14 22:14:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - lib/math/eratosthenes.yukicoder-1140.test.cpp
  - lib/math/eratosthenes.aoj.test.cpp
documentation_of: lib/math/eratosthenes.hpp
layout: document
redirect_from:
- /library/lib/math/eratosthenes.hpp
- /library/lib/math/eratosthenes.hpp.html
title: Eratosthenes's sieve
---
