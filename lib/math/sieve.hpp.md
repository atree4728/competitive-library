---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1140.test.cpp
    title: test/yukicoder/1140.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/math/sieve.hpp\"\n\n#include <cassert>\n#include <numeric>\n\
    #include <unordered_map>\n#include <vector>\n\nstruct Sieve {\n    intmax_t n;\n\
    \    std::vector<intmax_t> min_factor;\n    explicit Sieve(const intmax_t n):\
    \ n(n), min_factor(n + 1) {\n        std::iota(begin(min_factor), end(min_factor),\
    \ 0);\n        for (intmax_t i = 2; i * i <= n; i++) {\n            if (min_factor[i]\
    \ != i) continue;\n            for (intmax_t mul = i * i; mul <= n; mul += i)\
    \ {\n                if (min_factor[mul] == mul) min_factor[mul] = i;\n      \
    \      }\n        }\n    };\n    bool is_prime(const intmax_t n) {\n        assert(1\
    \ <= n and n <= n);\n        return n >= 2 and min_factor[n] == n;\n    }\n  \
    \  std::vector<intmax_t> factor(intmax_t n) {\n        assert(1 <= n and n <=\
    \ n);\n        if (n == 1) return {};\n        std::vector<intmax_t> factor{};\n\
    \        while (n != 1) {\n            factor.emplace_back(min_factor[n]);\n \
    \           n /= min_factor[n];\n        }\n        return factor;\n    }\n  \
    \  intmax_t count_divisor(const intmax_t n) {\n        assert(1 <= n and n <=\
    \ n);\n        std::unordered_map<intmax_t, intmax_t> factor_map{};\n        for\
    \ (const auto& p: this->factor(n)) factor_map[p]++;\n        return std::transform_reduce(cbegin(factor_map),\
    \ cend(factor_map), static_cast<intmax_t>(1), std::multiplies<>{},\n         \
    \                            [](const auto p_e) { return p_e.second + 1; });\n\
    \    }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <numeric>\n#include <unordered_map>\n\
    #include <vector>\n\nstruct Sieve {\n    intmax_t n;\n    std::vector<intmax_t>\
    \ min_factor;\n    explicit Sieve(const intmax_t n): n(n), min_factor(n + 1) {\n\
    \        std::iota(begin(min_factor), end(min_factor), 0);\n        for (intmax_t\
    \ i = 2; i * i <= n; i++) {\n            if (min_factor[i] != i) continue;\n \
    \           for (intmax_t mul = i * i; mul <= n; mul += i) {\n               \
    \ if (min_factor[mul] == mul) min_factor[mul] = i;\n            }\n        }\n\
    \    };\n    bool is_prime(const intmax_t n) {\n        assert(1 <= n and n <=\
    \ n);\n        return n >= 2 and min_factor[n] == n;\n    }\n    std::vector<intmax_t>\
    \ factor(intmax_t n) {\n        assert(1 <= n and n <= n);\n        if (n == 1)\
    \ return {};\n        std::vector<intmax_t> factor{};\n        while (n != 1)\
    \ {\n            factor.emplace_back(min_factor[n]);\n            n /= min_factor[n];\n\
    \        }\n        return factor;\n    }\n    intmax_t count_divisor(const intmax_t\
    \ n) {\n        assert(1 <= n and n <= n);\n        std::unordered_map<intmax_t,\
    \ intmax_t> factor_map{};\n        for (const auto& p: this->factor(n)) factor_map[p]++;\n\
    \        return std::transform_reduce(cbegin(factor_map), cend(factor_map), static_cast<intmax_t>(1),\
    \ std::multiplies<>{},\n                                     [](const auto p_e)\
    \ { return p_e.second + 1; });\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/sieve.hpp
  requiredBy: []
  timestamp: '2021-11-15 23:15:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1140.test.cpp
documentation_of: lib/math/sieve.hpp
layout: document
redirect_from:
- /library/lib/math/sieve.hpp
- /library/lib/math/sieve.hpp.html
title: lib/math/sieve.hpp
---
