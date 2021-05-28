---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: lib/test/yukicoder/1140.test.cpp
    title: lib/test/yukicoder/1140.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Eratosthenes's sieve($O(NloglogN)$)
    links: []
  bundledCode: "#line 2 \"lib/math/eratosthenes.hpp\"\n\n#include <vector>\n#include\
    \ <numeric>\n#include <cassert>\n#include <map>\n\nusing namespace std;\n\n/**\n\
    \ *@brief Eratosthenes's sieve($O(NloglogN)$)\n */\n\nclass Sieve {\n    int size;\n\
    \    vector<int> min_factor;\n\n    void init() {\n        assert(size >= 0);\n\
    \        iota(begin(min_factor), end(min_factor), 0);\n        for (int i = 2;\
    \ i <= size; i++) {\n            if (min_factor[i] != i) {\n                prime_list.emplace_back(i);\n\
    \                continue;\n            }\n            for (int mul = i * 2; mul\
    \ <= size; mul += i) {\n                if (min_factor[mul] == mul) min_factor[mul]\
    \ = i;\n            }\n        }\n    }\n\n   public:\n    vector<int> prime_list;\n\
    \n    Sieve(const int size_) : size(size_), min_factor(size_ + 1) { init(); };\n\
    \n    bool is_prime(const int n) { return min_factor[n] == n and n >= 2; }\n\n\
    \    map<int, int> prime_factorize(const int n) {\n        assert(1 <= n and n\
    \ <= size);\n        if (n == 1) return {};\n        map<int, int> factor;\n \
    \       int cur = n;\n        while (cur != 1) {\n            factor[min_factor[cur]]++;\n\
    \            cur /= min_factor[cur];\n        }\n        return factor;\n    }\n\
    \n    int count_divisor(const int n) {\n        assert(1 <= n and n <= size);\n\
    \        int ret = 1;\n        map<int, int> factor = prime_factorize(n);\n  \
    \      for (auto [p, ex] : factor) ret *= (ex + 1);\n        return ret;\n   \
    \ }\n};\n"
  code: "#pragma once\n\n#include <vector>\n#include <numeric>\n#include <cassert>\n\
    #include <map>\n\nusing namespace std;\n\n/**\n *@brief Eratosthenes's sieve($O(NloglogN)$)\n\
    \ */\n\nclass Sieve {\n    int size;\n    vector<int> min_factor;\n\n    void\
    \ init() {\n        assert(size >= 0);\n        iota(begin(min_factor), end(min_factor),\
    \ 0);\n        for (int i = 2; i <= size; i++) {\n            if (min_factor[i]\
    \ != i) {\n                prime_list.emplace_back(i);\n                continue;\n\
    \            }\n            for (int mul = i * 2; mul <= size; mul += i) {\n \
    \               if (min_factor[mul] == mul) min_factor[mul] = i;\n           \
    \ }\n        }\n    }\n\n   public:\n    vector<int> prime_list;\n\n    Sieve(const\
    \ int size_) : size(size_), min_factor(size_ + 1) { init(); };\n\n    bool is_prime(const\
    \ int n) { return min_factor[n] == n and n >= 2; }\n\n    map<int, int> prime_factorize(const\
    \ int n) {\n        assert(1 <= n and n <= size);\n        if (n == 1) return\
    \ {};\n        map<int, int> factor;\n        int cur = n;\n        while (cur\
    \ != 1) {\n            factor[min_factor[cur]]++;\n            cur /= min_factor[cur];\n\
    \        }\n        return factor;\n    }\n\n    int count_divisor(const int n)\
    \ {\n        assert(1 <= n and n <= size);\n        int ret = 1;\n        map<int,\
    \ int> factor = prime_factorize(n);\n        for (auto [p, ex] : factor) ret *=\
    \ (ex + 1);\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/eratosthenes.hpp
  requiredBy: []
  timestamp: '2021-05-28 15:42:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - lib/test/yukicoder/1140.test.cpp
documentation_of: lib/math/eratosthenes.hpp
layout: document
redirect_from:
- /library/lib/math/eratosthenes.hpp
- /library/lib/math/eratosthenes.hpp.html
title: Eratosthenes's sieve($O(NloglogN)$)
---
