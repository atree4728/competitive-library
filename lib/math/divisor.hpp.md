---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: multiple enumeration
    links: []
  bundledCode: "#line 2 \"lib/math/divisor.hpp\"\n\n#line 2 \"lib/include.hpp\"\n\
    #include <bits/stdc++.h>\n#include <experimental/iterator>\nusing namespace std;\n\
    #define overload3(_1, _2, _3, name, ...) name\n#define rep1(n) for (auto _i =\
    \ 0; _i < n; _i++)\n#define rep2(i, n) for (auto i = 0; i < n; i++)\n#define rep3(i,\
    \ a, b) for (auto i = a; i < b; i++)\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\ntemplate <class T> bool chmax(T &a, const T\
    \ &b) { return a < b ? a = b, true : false; }\ntemplate <class T> bool chmin(T\
    \ &a, const T &b) { return a > b ? a = b, true : false; }\nusing i64 = long long;\n\
    using f64 = long double;\n#line 4 \"lib/math/divisor.hpp\"\n\n/**\n *@brief multiple\
    \ enumeration\n * @note $O(NlogN)$\n */\n\nvector<long long> divisor(long long\
    \ n) {\n    vector<long long> ret;\n    for (long long p = 1; p * p <= n; p++)\
    \ {\n        if (n % p == 0) {\n            ret.push_back(p);\n            if\
    \ (p * p != n) ret.push_back(n / p);\n        }\n    }\n    sort(begin(ret), end(ret));\n\
    \    return ret;\n}\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n *@brief multiple enumeration\n\
    \ * @note $O(NlogN)$\n */\n\nvector<long long> divisor(long long n) {\n    vector<long\
    \ long> ret;\n    for (long long p = 1; p * p <= n; p++) {\n        if (n % p\
    \ == 0) {\n            ret.push_back(p);\n            if (p * p != n) ret.push_back(n\
    \ / p);\n        }\n    }\n    sort(begin(ret), end(ret));\n    return ret;\n\
    }\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/math/divisor.hpp
  requiredBy: []
  timestamp: '2021-07-10 14:38:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/divisor.hpp
layout: document
redirect_from:
- /library/lib/math/divisor.hpp
- /library/lib/math/divisor.hpp.html
title: multiple enumeration
---
