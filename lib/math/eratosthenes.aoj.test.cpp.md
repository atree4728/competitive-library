---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/math/eratosthenes.hpp
    title: Eratosthenes's sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
  bundledCode: "#line 1 \"lib/math/eratosthenes.aoj.test.cpp\"\n#define PROBLEM \\\
    \n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\n\
    #line 2 \"lib/math/eratosthenes.hpp\"\n\n#include <vector>\n#include <numeric>\n\
    #include <cassert>\n#include <map>\n\nusing namespace std;\n\n/**\n *@brief Eratosthenes's\
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
    \ + 1);\n        return ret;\n    }\n};\n#line 4 \"lib/math/eratosthenes.aoj.test.cpp\"\
    \n#include <iostream>\n\nconst int M = 100000003;\n\nint main() {\n    int n;\n\
    \    cin >> n;\n    Eratosthenes era(M);\n    int cnt = 0;\n    for (int i = 0;\
    \ i < n; i++) {\n        int a;\n        cin >> a;\n        cnt += era.is_prime(a);\n\
    \    }\n    cout << cnt << \"\\n\";\n    return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \n#include \"lib/math/eratosthenes.hpp\"\n#include <iostream>\n\nconst int M =\
    \ 100000003;\n\nint main() {\n    int n;\n    cin >> n;\n    Eratosthenes era(M);\n\
    \    int cnt = 0;\n    for (int i = 0; i < n; i++) {\n        int a;\n       \
    \ cin >> a;\n        cnt += era.is_prime(a);\n    }\n    cout << cnt << \"\\n\"\
    ;\n    return 0;\n}\n"
  dependsOn:
  - lib/math/eratosthenes.hpp
  isVerificationFile: true
  path: lib/math/eratosthenes.aoj.test.cpp
  requiredBy: []
  timestamp: '2021-05-14 22:14:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: lib/math/eratosthenes.aoj.test.cpp
layout: document
redirect_from:
- /verify/lib/math/eratosthenes.aoj.test.cpp
- /verify/lib/math/eratosthenes.aoj.test.cpp.html
title: lib/math/eratosthenes.aoj.test.cpp
---
