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
    \n\n#include <bits/stdc++.h>\n#include <experimental/iterator>\nusing namespace\
    \ std;\n#define overload3(_1, _2, _3, name, ...) name\n#define rep1(n) for (decltype(n)\
    \ _tmp = 0; _tmp < n; _tmp++)\n#define rep2(i, n) for (decltype(n) i = 0; i <\
    \ n; i++)\n#define rep3(i, a, b) for (decltype(b) i = a; i < b; i++)\n#define\
    \ rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\nstruct IOSetup\
    \ { IOSetup() noexcept { ios::sync_with_stdio(false); cin.tie(nullptr); cout <<\
    \ fixed << setprecision(10); cerr << fixed << setprecision(10); } } iosetup;\n\
    template <class T> bool chmax(T &a, const T &b) { return a < b and (a = b, true);\
    \ }\ntemplate <class T> bool chmin(T &a, const T &b) { return a > b and (a = b,\
    \ true); }\nusing i64 = long long;\nusing u64 = unsigned long long;\nusing f64\
    \ = long double;\n#line 4 \"lib/math/eratosthenes.hpp\"\n\n/**\n * @brief Eratosthenes's\
    \ Sieve\n * @note construct in $O(NloglogN)$, return prime determination in $O(1)$\
    \ and number of constants and prime factorization fastly(<-?).\n */\n\nstruct\
    \ Sieve {\n    size_t size;\n    vector<size_t> min_factor;\n    vector<int> prime_list;\n\
    \    Sieve(const size_t size_):\n        size(size_), min_factor(size_ + 1) {\n\
    \        iota(begin(min_factor), end(min_factor), 0);\n        for (size_t i =\
    \ 2; i <= size; i++) {\n            if (min_factor[i] != i) {\n              \
    \  prime_list.emplace_back(i);\n                continue;\n            }\n   \
    \         for (size_t mul = i * 2; mul <= size; mul += i)\n                if\
    \ (min_factor[mul] == mul) min_factor[mul] = i;\n        }\n    };\n    bool is_prime(const\
    \ int n) { return n >= 2 and (int) min_factor[n] == n; }\n    map<int, int> prime_factorize(const\
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
    \ Sieve {\n    size_t size;\n    vector<size_t> min_factor;\n    vector<int> prime_list;\n\
    \    Sieve(const size_t size_):\n        size(size_), min_factor(size_ + 1) {\n\
    \        iota(begin(min_factor), end(min_factor), 0);\n        for (size_t i =\
    \ 2; i <= size; i++) {\n            if (min_factor[i] != i) {\n              \
    \  prime_list.emplace_back(i);\n                continue;\n            }\n   \
    \         for (size_t mul = i * 2; mul <= size; mul += i)\n                if\
    \ (min_factor[mul] == mul) min_factor[mul] = i;\n        }\n    };\n    bool is_prime(const\
    \ int n) { return n >= 2 and (int) min_factor[n] == n; }\n    map<int, int> prime_factorize(const\
    \ int n) {\n        assert(1 <= n and n <= (int)size);\n        if (n == 1) return\
    \ {};\n        map<int, int> factor{};\n        int cur = n;\n        while (cur\
    \ != 1) {\n            factor[min_factor[cur]]++;\n            cur /= min_factor[cur];\n\
    \        }\n        return factor;\n    }\n    int count_divisor(const int n)\
    \ {\n        assert(1 <= n and n <= (int)size);\n        int ret = 1;\n      \
    \  map<int, int> factor = prime_factorize(n);\n        for (auto [_, ex]: factor)\
    \ ret *= (ex + 1);\n        return ret;\n    }\n};\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/math/eratosthenes.hpp
  requiredBy: []
  timestamp: '2021-07-21 10:45:19+09:00'
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
