---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/math/eratosthenes.hpp
    title: Eratosthenes's sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1140
    links:
    - https://yukicoder.me/problems/no/1140
  bundledCode: "#line 1 \"lib/math/eratosthenes.yukicoder-1140.test.cpp\"\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/1140\"\n#include <iostream>\n#line\
    \ 2 \"lib/math/eratosthenes.hpp\"\n\n#include <vector>\n#include <numeric>\n#include\
    \ <cassert>\n#include <map>\n\nusing namespace std;\n\n/**\n *@brief Eratosthenes's\
    \ sieve\n */\n\nclass Eratosthenes {\n    int size;\n    vector<int> min_factor;\n\
    \    vector<int> prime_list;\n\n    void init() {\n        assert(size >= 0);\n\
    \        iota(begin(min_factor), end(min_factor), 0);\n        for (int i = 2;\
    \ i * i <= size; i++) {\n            if (min_factor[i] != i) {\n             \
    \   prime_list.emplace_back(i);\n                continue;\n            }\n  \
    \          for (int mul = i * 2; mul <= size; mul += i) {\n                if\
    \ (min_factor[mul] == mul) min_factor[mul] = i;\n            }\n        }\n  \
    \  }\n\n   public:\n    Eratosthenes(const int size_) : size(size_), min_factor(size_\
    \ + 1) {\n        init();\n    };\n\n    bool is_prime(const int n) { return min_factor[n]\
    \ == n and n >= 2; }\n\n    map<long long, int> prime_factorize(const long long\
    \ n) {\n        assert(1 <= n and n < (long long)size * size);\n        if (n\
    \ == 1) return {};\n        map<long long, int> factor;\n        long long cur\
    \ = n;\n        while (cur != 1) {\n            factor[min_factor[cur]]++;\n \
    \           cur /= min_factor[cur];\n        }\n        return factor;\n    }\n\
    \n    int count_divisor(const long long n) {\n        assert(1 <= n and n < (long\
    \ long)size * size);\n        long long ret = 1;\n        map<long long, int>\
    \ factor = prime_factorize(n);\n        for (auto [p, ex] : factor) ret *= (ex\
    \ + 1);\n        return ret;\n    }\n};\n#line 4 \"lib/math/eratosthenes.yukicoder-1140.test.cpp\"\
    \n\nstruct IOSetup {\n    IOSetup() noexcept {\n        ios::sync_with_stdio(false);\n\
    \        cin.tie(nullptr);\n    }\n} IOSetup;\n\nconst int M = 5000005;\n\nEratosthenes\
    \ era(M);\n\nint solve(long long a, int p) {\n    if (not era.is_prime(p)) return\
    \ -1;\n    if (a % p == 0) return 0;\n    return 1;\n}\n\nint main() {\n    int\
    \ t;\n    cin >> t;\n    while (t--) {\n        long long a;\n        int p;\n\
    \        cin >> a >> p;\n        cout << solve(a, p) << \"\\n\";\n    }\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1140\"\n#include <iostream>\n\
    #include \"lib/math/eratosthenes.hpp\"\n\nstruct IOSetup {\n    IOSetup() noexcept\
    \ {\n        ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n    }\n\
    } IOSetup;\n\nconst int M = 5000005;\n\nEratosthenes era(M);\n\nint solve(long\
    \ long a, int p) {\n    if (not era.is_prime(p)) return -1;\n    if (a % p ==\
    \ 0) return 0;\n    return 1;\n}\n\nint main() {\n    int t;\n    cin >> t;\n\
    \    while (t--) {\n        long long a;\n        int p;\n        cin >> a >>\
    \ p;\n        cout << solve(a, p) << \"\\n\";\n    }\n    return 0;\n}\n"
  dependsOn:
  - lib/math/eratosthenes.hpp
  isVerificationFile: true
  path: lib/math/eratosthenes.yukicoder-1140.test.cpp
  requiredBy: []
  timestamp: '2021-05-14 22:14:56+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: lib/math/eratosthenes.yukicoder-1140.test.cpp
layout: document
redirect_from:
- /verify/lib/math/eratosthenes.yukicoder-1140.test.cpp
- /verify/lib/math/eratosthenes.yukicoder-1140.test.cpp.html
title: lib/math/eratosthenes.yukicoder-1140.test.cpp
---
