---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/math/convert_base.hpp
    title: Base conversion
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: lib/test/atcoder/abc110d.test.cpp
    title: lib/test/atcoder/abc110d.test.cpp
  - icon: ':heavy_check_mark:'
    path: lib/test/my_stress_test/convert_base.test.cpp
    title: lib/test/my_stress_test/convert_base.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: math utility
    links: []
  bundledCode: "#line 2 \"lib/math/utility.hpp\"\n\n#include <string>\n#include <algorithm>\n\
    #include <map>\n\nusing namespace std;\n\n/**\n * @brief math utility\n */\n\n\
    constexpr long long ceil(long long a, long long b) { return (a + b - 1) / b; }\n\
    \nlong long digit_sum(long long n) {\n    if (n < 10) return n;\n    return digit_sum(n\
    \ / 10) + n % 10;\n}\n\nlong long mypow(long long a, int e) {\n    long long ret\
    \ = 1;\n    while (e--) ret *= a;\n    return ret;\n}\n\nbool is_prime(long long\
    \ n) {\n    if (n <= 1) return false;\n    if (n == 2) return true;\n    for (long\
    \ long i = 2; i * i <= n; i++) {\n        if (n % i == 0) return false;\n    }\n\
    \    return true;\n}\n\nmap<long long, int> prime_factorize(long long n) {\n \
    \   map<long long, int> factor;\n    for (long long p = 2; p * p <= n; p++) {\n\
    \        if (n % p != 0) continue;\n        int ex = 0;\n        while (n % p\
    \ == 0) {\n            ex++;\n            n /= p;\n        }\n        factor[p]\
    \ = ex;\n    }\n    if (n != 1) factor[n] = 1;\n    return factor;\n}\n\nvector<long\
    \ long> divisor(long long n) {\n    vector<long long> ret;\n    for (long long\
    \ p = 1; p * p <= n; p++) {\n        if (n % p == 0) {\n            ret.push_back(p);\n\
    \            if (p * p != n) ret.push_back(n / p);\n        }\n    }\n    sort(begin(ret),\
    \ end(ret));\n    return ret;\n}\n"
  code: "#pragma once\n\n#include <string>\n#include <algorithm>\n#include <map>\n\
    \nusing namespace std;\n\n/**\n * @brief math utility\n */\n\nconstexpr long long\
    \ ceil(long long a, long long b) { return (a + b - 1) / b; }\n\nlong long digit_sum(long\
    \ long n) {\n    if (n < 10) return n;\n    return digit_sum(n / 10) + n % 10;\n\
    }\n\nlong long mypow(long long a, int e) {\n    long long ret = 1;\n    while\
    \ (e--) ret *= a;\n    return ret;\n}\n\nbool is_prime(long long n) {\n    if\
    \ (n <= 1) return false;\n    if (n == 2) return true;\n    for (long long i =\
    \ 2; i * i <= n; i++) {\n        if (n % i == 0) return false;\n    }\n    return\
    \ true;\n}\n\nmap<long long, int> prime_factorize(long long n) {\n    map<long\
    \ long, int> factor;\n    for (long long p = 2; p * p <= n; p++) {\n        if\
    \ (n % p != 0) continue;\n        int ex = 0;\n        while (n % p == 0) {\n\
    \            ex++;\n            n /= p;\n        }\n        factor[p] = ex;\n\
    \    }\n    if (n != 1) factor[n] = 1;\n    return factor;\n}\n\nvector<long long>\
    \ divisor(long long n) {\n    vector<long long> ret;\n    for (long long p = 1;\
    \ p * p <= n; p++) {\n        if (n % p == 0) {\n            ret.push_back(p);\n\
    \            if (p * p != n) ret.push_back(n / p);\n        }\n    }\n    sort(begin(ret),\
    \ end(ret));\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/utility.hpp
  requiredBy:
  - lib/math/convert_base.hpp
  timestamp: '2021-05-29 21:52:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - lib/test/my_stress_test/convert_base.test.cpp
  - lib/test/atcoder/abc110d.test.cpp
documentation_of: lib/math/utility.hpp
layout: document
redirect_from:
- /library/lib/math/utility.hpp
- /library/lib/math/utility.hpp.html
title: math utility
---
