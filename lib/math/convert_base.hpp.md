---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/utility.hpp
    title: math utility
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: lib/test/my_stress_test/convert_base.test.cpp
    title: lib/test/my_stress_test/convert_base.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Base conversion
    links: []
  bundledCode: "#line 2 \"lib/math/convert_base.hpp\"\n\n#include <string>\n#include\
    \ <algorithm>\n#include <cassert>\n\n#line 2 \"lib/math/utility.hpp\"\n\n#line\
    \ 5 \"lib/math/utility.hpp\"\n#include <map>\n\nusing namespace std;\n\n/**\n\
    \ * @brief math utility\n */\n\nconstexpr long long ceil(long long a, long long\
    \ b) { return (a + b - 1) / b; }\n\nlong long digit_sum(long long n) {\n    if\
    \ (n < 10) return n;\n    return digit_sum(n / 10) + n % 10;\n}\n\nlong long mypow(long\
    \ long a, int e) {\n    long long ret = 1;\n    while (e--) ret *= a;\n    return\
    \ ret;\n}\n\nbool is_prime(long long n) {\n    if (n <= 1) return false;\n   \
    \ if (n == 2) return true;\n    for (long long i = 2; i * i <= n; i++) {\n   \
    \     if (n % i == 0) return false;\n    }\n    return true;\n}\n\nmap<long long,\
    \ int> prime_factorize(long long n) {\n    map<long long, int> factor;\n    for\
    \ (long long p = 2; p * p <= n; p++) {\n        if (n % p != 0) continue;\n  \
    \      int ex = 0;\n        while (n % p == 0) {\n            ex++;\n        \
    \    n /= p;\n        }\n        factor[p] = ex;\n    }\n    if (n != 1) factor[n]\
    \ = 1;\n    return factor;\n}\n\nvector<long long> divisor(long long n) {\n  \
    \  vector<long long> ret;\n    for (long long p = 1; p * p <= n; p++) {\n    \
    \    if (n % p == 0) {\n            ret.push_back(p);\n            if (p * p !=\
    \ n) ret.push_back(n / p);\n        }\n    }\n    sort(begin(ret), end(ret));\n\
    \    return ret;\n}\n#line 8 \"lib/math/convert_base.hpp\"\n\nusing namespace\
    \ std;\n\n/**\n * @brief Base conversion\n * @detail when base > 10, it will be\
    \ used lower case letters\n */\nlong long to_base10(string n, int base) {\n  \
    \  long long ret = 0;\n    int s = (n[0] == '-' ? 1 : 0);\n    reverse(begin(n),\
    \ end(n));\n    for (int i = s; (size_t)i < size(n); i++) {\n        int d = (isdigit(n[i])\
    \ ? (n[i] - '0') : (n[i] - 'a' + 10));\n        ret += mypow(base, i) * d;\n \
    \   }\n    return ret * (s == 1 ? -1 : 1);\n}\n\nstring from_base10(long long\
    \ n, int base) {\n    assert(2 <= base and base <= 36);\n    const string table\
    \ = \"0123456789abcdefghijklmnopqrstuvwxyz\";\n    bool is_negative = (n < 0);\n\
    \    if (is_negative) n *= -1;\n    assert(n >= 0);\n    string ret;\n    while\
    \ (n >= base) {\n        ret.push_back(table[n % base]);\n        n /= base;\n\
    \    }\n    ret.push_back(table[n]);\n    reverse(begin(ret), end(ret));\n   \
    \ return (is_negative ? \"-\" : \"\") + ret;\n}\n\nstring convert_base(string\
    \ n, int from_base, int to_base) {\n    return from_base10((to_base10(n, from_base)),\
    \ to_base);\n}\n"
  code: "#pragma once\n\n#include <string>\n#include <algorithm>\n#include <cassert>\n\
    \n#include \"lib/math/utility.hpp\"\n\nusing namespace std;\n\n/**\n * @brief\
    \ Base conversion\n * @detail when base > 10, it will be used lower case letters\n\
    \ */\nlong long to_base10(string n, int base) {\n    long long ret = 0;\n    int\
    \ s = (n[0] == '-' ? 1 : 0);\n    reverse(begin(n), end(n));\n    for (int i =\
    \ s; (size_t)i < size(n); i++) {\n        int d = (isdigit(n[i]) ? (n[i] - '0')\
    \ : (n[i] - 'a' + 10));\n        ret += mypow(base, i) * d;\n    }\n    return\
    \ ret * (s == 1 ? -1 : 1);\n}\n\nstring from_base10(long long n, int base) {\n\
    \    assert(2 <= base and base <= 36);\n    const string table = \"0123456789abcdefghijklmnopqrstuvwxyz\"\
    ;\n    bool is_negative = (n < 0);\n    if (is_negative) n *= -1;\n    assert(n\
    \ >= 0);\n    string ret;\n    while (n >= base) {\n        ret.push_back(table[n\
    \ % base]);\n        n /= base;\n    }\n    ret.push_back(table[n]);\n    reverse(begin(ret),\
    \ end(ret));\n    return (is_negative ? \"-\" : \"\") + ret;\n}\n\nstring convert_base(string\
    \ n, int from_base, int to_base) {\n    return from_base10((to_base10(n, from_base)),\
    \ to_base);\n}\n"
  dependsOn:
  - lib/math/utility.hpp
  isVerificationFile: false
  path: lib/math/convert_base.hpp
  requiredBy: []
  timestamp: '2021-05-29 23:05:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - lib/test/my_stress_test/convert_base.test.cpp
documentation_of: lib/math/convert_base.hpp
layout: document
redirect_from:
- /library/lib/math/convert_base.hpp
- /library/lib/math/convert_base.hpp.html
title: Base conversion
---
