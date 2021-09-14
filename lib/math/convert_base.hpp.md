---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/my_stress_test/convert_base.test.cpp
    title: test/my_stress_test/convert_base.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Convert Base
    links: []
  bundledCode: "#line 2 \"lib/math/convert_base.hpp\"\n\n#line 2 \"lib/include.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_1, _2,\
    \ _3, name, ...) name\n#define rep1(n) for (auto _tmp = 0; _tmp < (n); _tmp++)\n\
    #define rep2(i, n) for (auto i = 0; i < (n); i++)\n#define rep3(i, a, b) for (auto\
    \ i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n\
    template<class T> bool chmax(T &a, const T &b) { return a < b and (a = b, true);\
    \ }\ntemplate<class T> bool chmin(T &a, const T &b) { return a > b and (a = b,\
    \ true); }\nusing i64 = long long;\nusing f64 = long double;\n#line 4 \"lib/math/convert_base.hpp\"\
    \n\n/**\n * @brief Convert Base\n * @note when base > 10, it will be used lower\
    \ case letters.\n */\ni64 to_base10(string n, int base) {\n    i64 ret = 0;\n\
    \    int s = (n[0] == '-' ? 1 : 0);\n    reverse(begin(n), end(n));\n    rep(i,\
    \ s, size(n)) {\n        int d = (isdigit(n[i]) ? (n[i] - '0') : (n[i] - 'a' +\
    \ 10));\n        ret += pow(base, i) * d;\n    }\n    return ret * (s == 1 ? -1\
    \ : 1);\n}\n\nstring from_base10(i64 n, int base) {\n    assert(2 <= base and\
    \ base <= 36);\n    const string table = \"0123456789abcdefghijklmnopqrstuvwxyz\"\
    ;\n    bool is_negative = (n < 0);\n    if (is_negative) n *= -1;\n    string\
    \ ret;\n    while (n >= base) {\n        ret.push_back(table[n % base]);\n   \
    \     n /= base;\n    }\n    ret.push_back(table[n]);\n    reverse(begin(ret),\
    \ end(ret));\n    return (is_negative ? \"-\" : \"\") + ret;\n}\n\nstring convert_base(string\
    \ n, int from_base, int to_base) {\n    return from_base10((to_base10(n, from_base)),\
    \ to_base);\n}\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief Convert Base\n\
    \ * @note when base > 10, it will be used lower case letters.\n */\ni64 to_base10(string\
    \ n, int base) {\n    i64 ret = 0;\n    int s = (n[0] == '-' ? 1 : 0);\n    reverse(begin(n),\
    \ end(n));\n    rep(i, s, size(n)) {\n        int d = (isdigit(n[i]) ? (n[i] -\
    \ '0') : (n[i] - 'a' + 10));\n        ret += pow(base, i) * d;\n    }\n    return\
    \ ret * (s == 1 ? -1 : 1);\n}\n\nstring from_base10(i64 n, int base) {\n    assert(2\
    \ <= base and base <= 36);\n    const string table = \"0123456789abcdefghijklmnopqrstuvwxyz\"\
    ;\n    bool is_negative = (n < 0);\n    if (is_negative) n *= -1;\n    string\
    \ ret;\n    while (n >= base) {\n        ret.push_back(table[n % base]);\n   \
    \     n /= base;\n    }\n    ret.push_back(table[n]);\n    reverse(begin(ret),\
    \ end(ret));\n    return (is_negative ? \"-\" : \"\") + ret;\n}\n\nstring convert_base(string\
    \ n, int from_base, int to_base) {\n    return from_base10((to_base10(n, from_base)),\
    \ to_base);\n}\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/math/convert_base.hpp
  requiredBy: []
  timestamp: '2021-09-14 22:20:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/my_stress_test/convert_base.test.cpp
documentation_of: lib/math/convert_base.hpp
layout: document
redirect_from:
- /library/lib/math/convert_base.hpp
- /library/lib/math/convert_base.hpp.html
title: Convert Base
---
