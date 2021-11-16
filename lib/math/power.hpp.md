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
  bundledCode: "#line 2 \"lib/math/power.hpp\"\n\n#include <cstdint>\n\nconstexpr\
    \ intmax_t power(intmax_t a, intmax_t b) {\n    intmax_t ans = 1;\n    for (;\
    \ b; b >>= 1) {\n        if (b & 1) ans *= a;\n        a *= a;\n    }\n    return\
    \ ans;\n}\n\n"
  code: "#pragma once\n\n#include <cstdint>\n\nconstexpr intmax_t power(intmax_t a,\
    \ intmax_t b) {\n    intmax_t ans = 1;\n    for (; b; b >>= 1) {\n        if (b\
    \ & 1) ans *= a;\n        a *= a;\n    }\n    return ans;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/power.hpp
  requiredBy: []
  timestamp: '2021-11-16 21:49:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/power.hpp
layout: document
redirect_from:
- /library/lib/math/power.hpp
- /library/lib/math/power.hpp.html
title: lib/math/power.hpp
---
