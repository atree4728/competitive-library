---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_B.test.cpp
    title: test/aoj/DPL_5_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_D.test.cpp
    title: test/aoj/DPL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_E.test.cpp
    title: test/aoj/DPL_5_E.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Finite Field / \u6709\u9650\u4F53"
    links: []
  bundledCode: "#line 2 \"lib/modulus/modint.hpp\"\n\n/**\n * @brief Finite Field\
    \ / \u6709\u9650\u4F53\n */\n\n#include <iostream>\n\ntemplate<int MOD> struct\
    \ Modint {\n    using mint = Modint<MOD>;\n    int value;\n    Modint(long long\
    \ value_ = 0): value((value_ % MOD + MOD) % MOD) {}\n    mint val() const { return\
    \ *this; }\n    mint operator-() const { return mint(-value); }\n    mint operator++()\
    \ const { return *this += 1; }\n    mint operator--() const { return *this -=\
    \ 1; }\n    mint operator+(mint arg) const { return mint(*this) += arg; }\n  \
    \  mint operator-(mint arg) const { return mint(*this) -= arg; }\n    mint operator*(mint\
    \ arg) const { return mint(*this) *= arg; }\n    mint& operator+=(mint arg) {\n\
    \        value += arg.value;\n        if (value >= MOD) value -= MOD;\n      \
    \  return *this;\n    }\n    mint& operator-=(mint arg) {\n        value -= arg.value;\n\
    \        if (value < 0) value += MOD;\n        return *this;\n    }\n    mint&\
    \ operator*=(mint arg) {\n        value = (long long) value * arg.value % MOD;\n\
    \        return *this;\n    }\n    bool operator==(mint arg) const { return value\
    \ == arg.value; }\n    bool operator!=(mint arg) const { return value != arg.value;\
    \ }\n    mint pow(long long k) const {\n        Modint ret = 1, a(*this);\n  \
    \      while (k > 0) {\n            if (k & 1) ret *= a;\n            k >>= 1;\n\
    \            a *= a;\n        }\n        return ret;\n    }\n    mint inv() const\
    \ { return pow(MOD - 2); }\n    mint operator/(mint arg) const { return *this\
    \ * arg.inv(); }\n    mint& operator/=(mint arg) { return *this *= arg.inv();\
    \ }\n    friend mint operator+(long long value, Modint<MOD> a) { return Modint<MOD>(value)\
    \ + a; }\n    friend mint operator-(long long value, Modint<MOD> a) { return Modint<MOD>(value)\
    \ - a; }\n    friend mint operator*(long long value, Modint<MOD> a) { return Modint<MOD>(value)\
    \ * a; }\n    friend mint operator/(long long value, Modint<MOD> a) { return Modint<MOD>(value)\
    \ / a; }\n    friend std::ostream& operator<<(std::ostream& os, Modint<MOD> a)\
    \ { return os << a.value; }\n};\n\nusing Modint1000000007 = Modint<1000000007>;\n\
    using Modint998244353 = Modint<998244353>;\n"
  code: "#pragma once\n\n/**\n * @brief Finite Field / \u6709\u9650\u4F53\n */\n\n\
    #include <iostream>\n\ntemplate<int MOD> struct Modint {\n    using mint = Modint<MOD>;\n\
    \    int value;\n    Modint(long long value_ = 0): value((value_ % MOD + MOD)\
    \ % MOD) {}\n    mint val() const { return *this; }\n    mint operator-() const\
    \ { return mint(-value); }\n    mint operator++() const { return *this += 1; }\n\
    \    mint operator--() const { return *this -= 1; }\n    mint operator+(mint arg)\
    \ const { return mint(*this) += arg; }\n    mint operator-(mint arg) const { return\
    \ mint(*this) -= arg; }\n    mint operator*(mint arg) const { return mint(*this)\
    \ *= arg; }\n    mint& operator+=(mint arg) {\n        value += arg.value;\n \
    \       if (value >= MOD) value -= MOD;\n        return *this;\n    }\n    mint&\
    \ operator-=(mint arg) {\n        value -= arg.value;\n        if (value < 0)\
    \ value += MOD;\n        return *this;\n    }\n    mint& operator*=(mint arg)\
    \ {\n        value = (long long) value * arg.value % MOD;\n        return *this;\n\
    \    }\n    bool operator==(mint arg) const { return value == arg.value; }\n \
    \   bool operator!=(mint arg) const { return value != arg.value; }\n    mint pow(long\
    \ long k) const {\n        Modint ret = 1, a(*this);\n        while (k > 0) {\n\
    \            if (k & 1) ret *= a;\n            k >>= 1;\n            a *= a;\n\
    \        }\n        return ret;\n    }\n    mint inv() const { return pow(MOD\
    \ - 2); }\n    mint operator/(mint arg) const { return *this * arg.inv(); }\n\
    \    mint& operator/=(mint arg) { return *this *= arg.inv(); }\n    friend mint\
    \ operator+(long long value, Modint<MOD> a) { return Modint<MOD>(value) + a; }\n\
    \    friend mint operator-(long long value, Modint<MOD> a) { return Modint<MOD>(value)\
    \ - a; }\n    friend mint operator*(long long value, Modint<MOD> a) { return Modint<MOD>(value)\
    \ * a; }\n    friend mint operator/(long long value, Modint<MOD> a) { return Modint<MOD>(value)\
    \ / a; }\n    friend std::ostream& operator<<(std::ostream& os, Modint<MOD> a)\
    \ { return os << a.value; }\n};\n\nusing Modint1000000007 = Modint<1000000007>;\n\
    using Modint998244353 = Modint<998244353>;\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/modulus/modint.hpp
  requiredBy: []
  timestamp: '2021-10-13 18:08:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_5_E.test.cpp
  - test/aoj/DPL_5_B.test.cpp
  - test/aoj/DPL_5_D.test.cpp
documentation_of: lib/modulus/modint.hpp
layout: document
redirect_from:
- /library/lib/modulus/modint.hpp
- /library/lib/modulus/modint.hpp.html
title: "Finite Field / \u6709\u9650\u4F53"
---
