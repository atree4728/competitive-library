---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Multiple Enumeration($O(\u221AN)$)"
    links: []
  bundledCode: "#line 2 \"lib/math/divisor.hpp\"\n\n#line 2 \"lib/include.hpp\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_NULL, _2, _3,\
    \ name, ...) name\n#define rep1(i, n) for (remove_const_t<remove_reference_t<decltype(n)>>\
    \ i = 0; i < (n); i++)\n#define rep2(i, a, b) for (remove_const_t<remove_reference_t<decltype(b)>>\
    \ i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)\n\
    using size_type = size_t;\n#line 4 \"lib/math/divisor.hpp\"\n\n/**\n * @brief\
    \ Multiple Enumeration($O(\u221AN)$)\n */\n\ntemplate<class T> vector<T> divisor(T\
    \ n) {\n    vector<T> ret{};\n    for (T p = 1; p * p <= n; p++) {\n        if\
    \ (n % p == 0) {\n            ret.push_back(p);\n            if (p * p != n) ret.push_back(n\
    \ / p);\n        }\n    }\n    sort(begin(ret), end(ret));\n    return ret;\n\
    }\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief Multiple Enumeration($O(\u221A\
    N)$)\n */\n\ntemplate<class T> vector<T> divisor(T n) {\n    vector<T> ret{};\n\
    \    for (T p = 1; p * p <= n; p++) {\n        if (n % p == 0) {\n           \
    \ ret.push_back(p);\n            if (p * p != n) ret.push_back(n / p);\n     \
    \   }\n    }\n    sort(begin(ret), end(ret));\n    return ret;\n}\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/math/divisor.hpp
  requiredBy: []
  timestamp: '2021-09-29 20:09:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/divisor.hpp
layout: document
redirect_from:
- /library/lib/math/divisor.hpp
- /library/lib/math/divisor.hpp.html
title: "Multiple Enumeration($O(\u221AN)$)"
---
