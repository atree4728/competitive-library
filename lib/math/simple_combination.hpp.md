---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Combination without mod
    links: []
  bundledCode: "#line 2 \"lib/math/simple_combination.hpp\"\n\n#include <vector>\n\
    \n/**\n * @brief Combination without mod\n * @note construct in $O(N^2)$, return\
    \ nCr / nHr in $O(1)$.\n */\n\ntemplate<typename T> struct SimpleCombinationTable\
    \ {\n    std::vector<std::vector<T>> table;\n    SimpleCombinationTable(std::size_t\
    \ size): table(size + 1, std::vector<T>(size + 1, 0)) {\n        for (size_t i\
    \ = 0; i <= size; i++) {\n            table[i][0] = 1;\n            table[i][i]\
    \ = 1;\n        }\n        for (size_t i = 1; i <= size; i++) {\n            for\
    \ (size_t j = 1; j < i; j++) {\n                table[i][j] = (table[i - 1][j\
    \ - 1] + table[i - 1][j]);\n            }\n        }\n    }\n    T operator()(int\
    \ n, int r) {\n        if (r < 0 or r > n) return 0;\n        return table[n][std::min(n,\
    \ n - r)];\n    }\n    T H(int n, int r) const { return table[n + r - 1][std::min(r,\
    \ n - 1)]; }\n};\n"
  code: "#pragma once\n\n#include <vector>\n\n/**\n * @brief Combination without mod\n\
    \ * @note construct in $O(N^2)$, return nCr / nHr in $O(1)$.\n */\n\ntemplate<typename\
    \ T> struct SimpleCombinationTable {\n    std::vector<std::vector<T>> table;\n\
    \    SimpleCombinationTable(std::size_t size): table(size + 1, std::vector<T>(size\
    \ + 1, 0)) {\n        for (size_t i = 0; i <= size; i++) {\n            table[i][0]\
    \ = 1;\n            table[i][i] = 1;\n        }\n        for (size_t i = 1; i\
    \ <= size; i++) {\n            for (size_t j = 1; j < i; j++) {\n            \
    \    table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]);\n            }\n \
    \       }\n    }\n    T operator()(int n, int r) {\n        if (r < 0 or r > n)\
    \ return 0;\n        return table[n][std::min(n, n - r)];\n    }\n    T H(int\
    \ n, int r) const { return table[n + r - 1][std::min(r, n - 1)]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/simple_combination.hpp
  requiredBy: []
  timestamp: '2021-10-03 22:04:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/simple_combination.hpp
layout: document
redirect_from:
- /library/lib/math/simple_combination.hpp
- /library/lib/math/simple_combination.hpp.html
title: Combination without mod
---
