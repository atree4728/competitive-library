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
    document_title: Combination without mod
    links: []
  bundledCode: "#line 2 \"lib/math/simple_combination.hpp\"\n\n#line 2 \"lib/include.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_1, _2,\
    \ _3, name, ...) name\n#define rep1(n) for (decltype(n) _tmp = 0; _tmp < (n);\
    \ _tmp++)\n#define rep2(i, n) for (decltype(n) i = 0; i < (n); i++)\n#define rep3(i,\
    \ a, b) for (decltype(b) i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\nstruct IOSetup {\n    IOSetup() noexcept {\n\
    \        ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n        cout\
    \ << fixed << setprecision(10);\n        cerr << fixed << setprecision(10);\n\
    \    }\n} iosetup;\ntemplate<class T> bool chmax(T &a, const T &b) { return a\
    \ < b and (a = b, true); }\ntemplate<class T> bool chmin(T &a, const T &b) { return\
    \ a > b and (a = b, true); }\nusing i64 = long long;\nusing f64 = long double;\n\
    #line 4 \"lib/math/simple_combination.hpp\"\n\n/**\n * @brief Combination without\
    \ mod\n * @note construct in $O(N^2)$, return nCr / nHr in $O(1)$.\n */\n\ntemplate<typename\
    \ T> struct SimpleCombinationTable {\n    vector<vector<T>> table;\n    SimpleCombinationTable(size_t\
    \ size):\n        table(size + 1, vector<T>(size + 1, 0)) {\n        for (size_t\
    \ i = 0; i <= size; i++) {\n            table[i][0] = 1;\n            table[i][i]\
    \ = 1;\n        }\n        for (size_t i = 1; i <= size; i++) {\n            for\
    \ (size_t j = 1; j < i; j++) {\n                table[i][j] = (table[i - 1][j\
    \ - 1] + table[i - 1][j]);\n            }\n        }\n    }\n    T operator()(int\
    \ n, int r) {\n        if (r < 0 or r > n) return 0;\n        return table[n][min(n,\
    \ n - r)];\n    }\n    T H(int n, int r) const { return table[n + r - 1][min(r,\
    \ n - 1)]; }\n};\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief Combination\
    \ without mod\n * @note construct in $O(N^2)$, return nCr / nHr in $O(1)$.\n */\n\
    \ntemplate<typename T> struct SimpleCombinationTable {\n    vector<vector<T>>\
    \ table;\n    SimpleCombinationTable(size_t size):\n        table(size + 1, vector<T>(size\
    \ + 1, 0)) {\n        for (size_t i = 0; i <= size; i++) {\n            table[i][0]\
    \ = 1;\n            table[i][i] = 1;\n        }\n        for (size_t i = 1; i\
    \ <= size; i++) {\n            for (size_t j = 1; j < i; j++) {\n            \
    \    table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]);\n            }\n \
    \       }\n    }\n    T operator()(int n, int r) {\n        if (r < 0 or r > n)\
    \ return 0;\n        return table[n][min(n, n - r)];\n    }\n    T H(int n, int\
    \ r) const { return table[n + r - 1][min(r, n - 1)]; }\n};\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/math/simple_combination.hpp
  requiredBy: []
  timestamp: '2021-08-31 17:00:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/simple_combination.hpp
layout: document
redirect_from:
- /library/lib/math/simple_combination.hpp
- /library/lib/math/simple_combination.hpp.html
title: Combination without mod
---
