---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/include.hpp
    title: lib/include.hpp
  - icon: ':x:'
    path: lib/math/power.hpp
    title: lib/math/power.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
  bundledCode: "#line 1 \"test/aoj/NTL_1_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B\"\
    \n\n#line 2 \"lib/math/power.hpp\"\n\n#line 2 \"lib/include.hpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#define overload3(_1, _2, _3, name, ...)\
    \ name\n#define rep1(n) for (decltype(n) _tmp = 0; _tmp < (n); _tmp++)\n#define\
    \ rep2(i, n) for (decltype(n) i = 0; i < (n); i++)\n#define rep3(i, a, b) for\
    \ (decltype(b) i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep3,\
    \ rep2, rep1)(__VA_ARGS__)\nstruct IOSetup {\n    IOSetup() noexcept {\n     \
    \   ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n        cout << fixed\
    \ << setprecision(10);\n        cerr << fixed << setprecision(10);\n    }\n} iosetup;\n\
    template<class T> bool chmax(T &a, const T &b) { return a < b and (a = b, true);\
    \ }\ntemplate<class T> bool chmin(T &a, const T &b) { return a > b and (a = b,\
    \ true); }\nusing i64 = long long;\nusing f64 = long double;\n#line 4 \"lib/math/power.hpp\"\
    \n\ntemplate<typename T> i64 power(T a, T b) {\n    static_assert(is_integral<T>::value,\
    \ \"T must be integer!\");\n    assert(0 <= b);\n    i64 ret = 1;\n    while (b\
    \ > 0) {\n        if (b & 1) ret *= a;\n        b >>= 1;\n        a *= a;\n  \
    \  }\n    return ret;\n}\n\ntemplate<typename T> i64 power(T a, T b, T m) {\n\
    \    static_assert(is_integral<T>::value, \"T must be integer!\");\n    assert(0\
    \ <= b && 1 <= m);\n    i64 ret = 1;\n    while (b > 0) {\n        if (b & 1)\
    \ (ret *= a) %= m;\n        b >>= 1;\n        (a *= a) %= m;\n    }\n    return\
    \ ret;\n}\n#line 4 \"test/aoj/NTL_1_B.test.cpp\"\n\nconst int MOD = 1'000'000'007;\n\
    \nint main() {\n    int m, n;\n    cin >> m >> n;\n    int ans = power(m, n, MOD);\n\
    \    cout << ans << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B\"\
    \n\n#include \"lib/math/power.hpp\"\n\nconst int MOD = 1'000'000'007;\n\nint main()\
    \ {\n    int m, n;\n    cin >> m >> n;\n    int ans = power(m, n, MOD);\n    cout\
    \ << ans << \"\\n\";\n}\n"
  dependsOn:
  - lib/math/power.hpp
  - lib/include.hpp
  isVerificationFile: true
  path: test/aoj/NTL_1_B.test.cpp
  requiredBy: []
  timestamp: '2021-09-08 23:15:27+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/NTL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_B.test.cpp
- /verify/test/aoj/NTL_1_B.test.cpp.html
title: test/aoj/NTL_1_B.test.cpp
---
