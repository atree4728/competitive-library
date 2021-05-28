---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/math/eratosthenes.hpp
    title: Eratosthenes's sieve($O(NloglogN)$)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
  bundledCode: "#line 1 \"lib/test/aoj/ALDS1_1_C.test.cpp\"\n#define PROBLEM \\\n\
    \    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\n\
    #line 2 \"lib/math/eratosthenes.hpp\"\n\n#include <vector>\n#include <numeric>\n\
    #include <cassert>\n#include <map>\n\nusing namespace std;\n\n/**\n *@brief Eratosthenes's\
    \ sieve($O(NloglogN)$)\n */\n\nclass Sieve {\n    int size;\n    vector<int> min_factor;\n\
    \n    void init() {\n        assert(size >= 0);\n        iota(begin(min_factor),\
    \ end(min_factor), 0);\n        for (int i = 2; i <= size; i++) {\n          \
    \  if (min_factor[i] != i) {\n                prime_list.emplace_back(i);\n  \
    \              continue;\n            }\n            for (int mul = i * 2; mul\
    \ <= size; mul += i) {\n                if (min_factor[mul] == mul) min_factor[mul]\
    \ = i;\n            }\n        }\n    }\n\n   public:\n    vector<int> prime_list;\n\
    \n    Sieve(const int size_) : size(size_), min_factor(size_ + 1) { init(); };\n\
    \n    bool is_prime(const int n) { return min_factor[n] == n and n >= 2; }\n\n\
    \    map<int, int> prime_factorize(const int n) {\n        assert(1 <= n and n\
    \ <= size);\n        if (n == 1) return {};\n        map<int, int> factor;\n \
    \       int cur = n;\n        while (cur != 1) {\n            factor[min_factor[cur]]++;\n\
    \            cur /= min_factor[cur];\n        }\n        return factor;\n    }\n\
    \n    int count_divisor(const int n) {\n        assert(1 <= n and n <= size);\n\
    \        int ret = 1;\n        map<int, int> factor = prime_factorize(n);\n  \
    \      for (auto [p, ex] : factor) ret *= (ex + 1);\n        return ret;\n   \
    \ }\n};\n#line 4 \"lib/test/aoj/ALDS1_1_C.test.cpp\"\n#include <iostream>\n\n\
    const int M = 100000003;\n\nint main() {\n    int n;\n    cin >> n;\n    Sieve\
    \ sieve(M);\n    int cnt = 0;\n    for (int i = 0; i < n; i++) {\n        int\
    \ a;\n        cin >> a;\n        cnt += sieve.is_prime(a);\n    }\n    cout <<\
    \ cnt << \"\\n\";\n    return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \n#include \"lib/math/eratosthenes.hpp\"\n#include <iostream>\n\nconst int M =\
    \ 100000003;\n\nint main() {\n    int n;\n    cin >> n;\n    Sieve sieve(M);\n\
    \    int cnt = 0;\n    for (int i = 0; i < n; i++) {\n        int a;\n       \
    \ cin >> a;\n        cnt += sieve.is_prime(a);\n    }\n    cout << cnt << \"\\\
    n\";\n    return 0;\n}\n"
  dependsOn:
  - lib/math/eratosthenes.hpp
  isVerificationFile: true
  path: lib/test/aoj/ALDS1_1_C.test.cpp
  requiredBy: []
  timestamp: '2021-05-28 15:42:00+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: lib/test/aoj/ALDS1_1_C.test.cpp
layout: document
redirect_from:
- /verify/lib/test/aoj/ALDS1_1_C.test.cpp
- /verify/lib/test/aoj/ALDS1_1_C.test.cpp.html
title: lib/test/aoj/ALDS1_1_C.test.cpp
---
