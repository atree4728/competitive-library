---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/math/extgcd.hpp
    title: "Extended Euclidean algorithm / \u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
  bundledCode: "#line 1 \"test/aoj/NTL_1_E.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
    \n\n#include <iostream>\n#line 2 \"lib/math/extgcd.hpp\"\n\n#include <cassert>\n\
    #include <numeric>\n#include <utility>\n\n/**\n * @brief Extended Euclid's Algorithm\n\
    \ * @note return pair of minimum x, y s.t. ax + by = gcd(x, y)\n * @ref https://noshi91.hatenablog.com/entry/2019/04/01/184957\n\
    \ */\n\nconstexpr std::pair<intmax_t, intmax_t> extgcd(intmax_t a, intmax_t b)\
    \ {\n    intmax_t s = a, xs = 1, ys = 0, t = b, xt = 0, yt = 1;\n    while (s\
    \ % t != 0) {\n        const intmax_t tmp = s / t,\n                       u =\
    \ s - t * tmp,\n                       xu = xs - xt * tmp,\n                 \
    \      yu = ys - yt * tmp;\n        s = t, xs = xt, ys = yt;\n        t = u, xt\
    \ = xu, yt = yu;\n    }\n    assert(t == std::gcd(a, b));\n    return { xt, yt\
    \ };\n}\n#line 5 \"test/aoj/NTL_1_E.test.cpp\"\n\nint main() {\n    int a, b;\n\
    \    std::cin >> a >> b;\n    const auto& [x, y] = extgcd(a, b);\n    std::cout\
    \ << x << \" \" << y << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
    \n\n#include <iostream>\n#include \"lib/math/extgcd.hpp\"\n\nint main() {\n  \
    \  int a, b;\n    std::cin >> a >> b;\n    const auto& [x, y] = extgcd(a, b);\n\
    \    std::cout << x << \" \" << y << \"\\n\";\n}\n"
  dependsOn:
  - lib/math/extgcd.hpp
  isVerificationFile: true
  path: test/aoj/NTL_1_E.test.cpp
  requiredBy: []
  timestamp: '2021-11-16 17:42:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL_1_E.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_E.test.cpp
- /verify/test/aoj/NTL_1_E.test.cpp.html
title: test/aoj/NTL_1_E.test.cpp
---
