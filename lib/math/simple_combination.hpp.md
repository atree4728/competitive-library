---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/math/simple_combination.hpp\"\n\n#include <vector>\n\
    \nusing namespace std;\n\ntemplate <typename T>\nclass SimpleCombinationTable\
    \ {\n    vector<vector<T>> table;\n\n   public:\n    SimpleCombinationTable(int\
    \ size) : table(size + 1, vector<T>(size + 1, 0)) {\n        for (size_t i = 0;\
    \ i <= size; i++) {\n            table[i][0] = 1;\n            table[i][i] = 1;\n\
    \        }\n        for (size_t j = 1; j <= size; j++) {\n            for (size_t\
    \ k = 1; k < j; k++) {\n                table[j][k] = (table[j - 1][k - 1] + table[j\
    \ - 1][k]);\n            }\n        }\n    }\n    T inline C(int n, int r) const\
    \ {\n        if (r < 0 or r > n) return 0;\n        return table[n][min(n, n -\
    \ r)];\n    }\n    T inline H(int n, int r) const { return table[n + r - 1][min(r,\
    \ n - 1)]; }\n};\n"
  code: "#pragma once\n\n#include <vector>\n\nusing namespace std;\n\ntemplate <typename\
    \ T>\nclass SimpleCombinationTable {\n    vector<vector<T>> table;\n\n   public:\n\
    \    SimpleCombinationTable(int size) : table(size + 1, vector<T>(size + 1, 0))\
    \ {\n        for (size_t i = 0; i <= size; i++) {\n            table[i][0] = 1;\n\
    \            table[i][i] = 1;\n        }\n        for (size_t j = 1; j <= size;\
    \ j++) {\n            for (size_t k = 1; k < j; k++) {\n                table[j][k]\
    \ = (table[j - 1][k - 1] + table[j - 1][k]);\n            }\n        }\n    }\n\
    \    T inline C(int n, int r) const {\n        if (r < 0 or r > n) return 0;\n\
    \        return table[n][min(n, n - r)];\n    }\n    T inline H(int n, int r)\
    \ const { return table[n + r - 1][min(r, n - 1)]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/simple_combination.hpp
  requiredBy: []
  timestamp: '2021-05-29 21:52:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/simple_combination.hpp
layout: document
redirect_from:
- /library/lib/math/simple_combination.hpp
- /library/lib/math/simple_combination.hpp.html
title: lib/math/simple_combination.hpp
---
