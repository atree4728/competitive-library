---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/math/simple_combination.hpp
    title: lib/math/simple_combination.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc202/tasks/abc202_d
    links:
    - https://atcoder.jp/contests/abc202/tasks/abc202_d
  bundledCode: "#line 1 \"lib/test/atcoder/abc202d.test.cpp\"\n#define PROBLEM \"\
    https://atcoder.jp/contests/abc202/tasks/abc202_d\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"lib/math/simple_combination.hpp\"\n\n#line 4\
    \ \"lib/math/simple_combination.hpp\"\n\nusing namespace std;\n\ntemplate <typename\
    \ T>\nclass SimpleCombinationTable {\n    vector<vector<T>> table;\n\n   public:\n\
    \    SimpleCombinationTable(int size) : table(size + 1, vector<T>(size + 1, 0))\
    \ {\n        for (size_t i = 0; i <= size; i++) {\n            table[i][0] = 1;\n\
    \            table[i][i] = 1;\n        }\n        for (size_t j = 1; j <= size;\
    \ j++) {\n            for (size_t k = 1; k < j; k++) {\n                table[j][k]\
    \ = (table[j - 1][k - 1] + table[j - 1][k]);\n            }\n        }\n    }\n\
    \    T inline C(int n, int r) const {\n        if (r < 0 or r > n) return 0;\n\
    \        return table[n][min(n, n - r)];\n    }\n    T inline H(int n, int r)\
    \ const { return table[n + r - 1][min(r, n - 1)]; }\n};\n#line 7 \"lib/test/atcoder/abc202d.test.cpp\"\
    \n\nint main() {\n    long long a, b, k;\n    cin >> a >> b >> k;\n    SimpleCombinationTable<long\
    \ long> ct(60);\n    auto dfs = [&ct](auto self, long long a, long long b, long\
    \ long k,\n                     string ans) {\n        if (a == 0 or b == 0) {\n\
    \            return ans + string((a == 0 ? 'b' : 'a'), (a == 0 ? b : a));\n  \
    \      }\n        long long c = ct.C(a + b - 1, b);\n        if (k <= c) {\n \
    \           ans.push_back('a');\n            a--;\n        } else {\n        \
    \    ans.push_back('b');\n            b--;\n            k -= c;\n        }\n \
    \       return self(self, a, b, k, ans);\n    };\n    cout << dfs(dfs, a, b, k,\
    \ \"\") << \"\\n\";\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc202/tasks/abc202_d\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"lib/math/simple_combination.hpp\"\
    \n\nint main() {\n    long long a, b, k;\n    cin >> a >> b >> k;\n    SimpleCombinationTable<long\
    \ long> ct(60);\n    auto dfs = [&ct](auto self, long long a, long long b, long\
    \ long k,\n                     string ans) {\n        if (a == 0 or b == 0) {\n\
    \            return ans + string((a == 0 ? 'b' : 'a'), (a == 0 ? b : a));\n  \
    \      }\n        long long c = ct.C(a + b - 1, b);\n        if (k <= c) {\n \
    \           ans.push_back('a');\n            a--;\n        } else {\n        \
    \    ans.push_back('b');\n            b--;\n            k -= c;\n        }\n \
    \       return self(self, a, b, k, ans);\n    };\n    cout << dfs(dfs, a, b, k,\
    \ \"\") << \"\\n\";\n    return 0;\n}\n"
  dependsOn:
  - lib/math/simple_combination.hpp
  isVerificationFile: true
  path: lib/test/atcoder/abc202d.test.cpp
  requiredBy: []
  timestamp: '2021-05-29 21:52:58+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: lib/test/atcoder/abc202d.test.cpp
layout: document
redirect_from:
- /verify/lib/test/atcoder/abc202d.test.cpp
- /verify/lib/test/atcoder/abc202d.test.cpp.html
title: lib/test/atcoder/abc202d.test.cpp
---
