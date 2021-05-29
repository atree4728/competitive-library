---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/utility/cumulative_sum.hpp
    title: Cumulative-Sum(1D)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"lib/test/library-checker/static_range_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"lib/utility/cumulative_sum.hpp\"\n\n#line 4\
    \ \"lib/utility/cumulative_sum.hpp\"\n\nusing namespace std;\n\n/**\n * @brief\
    \ Cumulative-Sum(1D)\n */\ntemplate <class T>\nclass CumulativeSum1D {\n    vector<T>\
    \ v;\n\n   public:\n    CumulativeSum1D(vector<T> a) : v(size(a) + 1, 0) {\n \
    \       copy(begin(a), end(a), begin(v) + 1);\n        for (size_t i = 1; i <\
    \ size(v); i++) v[i] += v[i - 1];\n    }\n    inline T operator()(int r) const\
    \ { return v[r]; }\n    inline T operator()(int l, int r) const { return v[r]\
    \ - v[l]; }\n    vector<T> raw() { return v; }\n};\n\n/**\n * @brief Cumulative-Sum(2D)\n\
    \ */\ntemplate <class T>\nclass CumulativeSum2D {\n    vector<vector<T>> vv;\n\
    \n   public:\n    CumulativeSum2D(vector<vector<T>> a)\n        : vv(size(a) +\
    \ 1, vector<int>(size(a[0]) + 1, 0)) {\n        for (size_t i = 0; i + 1 < size(vv);\
    \ i++)\n            copy(begin(a[i]), end(a[i]), begin(vv[i + 1]) + 1);\n    \
    \    for (size_t i = 1; i < size(vv); i++) {\n            for (size_t j = 1; j\
    \ < size(vv[i]); j++)\n                vv[i][j] += vv[i][j - 1] + vv[i - 1][j]\
    \ - vv[i - 1][j - 1];\n        }\n    }\n    inline T operator()(int sx, int sy,\
    \ int gx, int gy) const {\n        return vv[gx][gy] - vv[sx][gy] - vv[gx][sy]\
    \ + vv[sx][sy];\n    }\n    vector<vector<T>> raw() { return vv; }\n};\n#line\
    \ 7 \"lib/test/library-checker/static_range_sum.test.cpp\"\n\nstruct IOSetup {\n\
    \    IOSetup() noexcept {\n        ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n\
    \        cout << fixed << setprecision(10);\n        cerr << fixed << setprecision(10);\n\
    \    }\n} IOSetup;\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    vector<long\
    \ long> a(n);\n    for (auto &&elem : a) cin >> elem;\n    CumulativeSum1D cs(a);\n\
    \    while (q--) {\n        int l, r;\n        cin >> l >> r;\n        cout <<\
    \ cs(l, r) << \"\\n\";\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"lib/utility/cumulative_sum.hpp\"\
    \n\nstruct IOSetup {\n    IOSetup() noexcept {\n        ios::sync_with_stdio(false);\n\
    \        cin.tie(nullptr);\n        cout << fixed << setprecision(10);\n     \
    \   cerr << fixed << setprecision(10);\n    }\n} IOSetup;\n\nint main() {\n  \
    \  int n, q;\n    cin >> n >> q;\n    vector<long long> a(n);\n    for (auto &&elem\
    \ : a) cin >> elem;\n    CumulativeSum1D cs(a);\n    while (q--) {\n        int\
    \ l, r;\n        cin >> l >> r;\n        cout << cs(l, r) << \"\\n\";\n    }\n\
    \    return 0;\n}\n"
  dependsOn:
  - lib/utility/cumulative_sum.hpp
  isVerificationFile: true
  path: lib/test/library-checker/static_range_sum.test.cpp
  requiredBy: []
  timestamp: '2021-05-29 23:05:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: lib/test/library-checker/static_range_sum.test.cpp
layout: document
redirect_from:
- /verify/lib/test/library-checker/static_range_sum.test.cpp
- /verify/lib/test/library-checker/static_range_sum.test.cpp.html
title: lib/test/library-checker/static_range_sum.test.cpp
---
