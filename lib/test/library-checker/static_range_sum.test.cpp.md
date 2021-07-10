---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
  - icon: ':heavy_check_mark:'
    path: lib/utility/cumulative_sum.hpp
    title: Partial Sum
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
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#line 2 \"lib/include.hpp\"\
    \n#include <bits/stdc++.h>\n#include <experimental/iterator>\nusing namespace\
    \ std;\n#define overload3(_1, _2, _3, name, ...) name\n#define rep1(n) for (auto\
    \ _i = 0; _i < n; _i++)\n#define rep2(i, n) for (auto i = 0; i < n; i++)\n#define\
    \ rep3(i, a, b) for (auto i = a; i < b; i++)\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\ntemplate <class T> bool chmax(T &a, const T\
    \ &b) { return a < b ? a = b, true : false; }\ntemplate <class T> bool chmin(T\
    \ &a, const T &b) { return a > b ? a = b, true : false; }\nusing i64 = long long;\n\
    using f64 = long double;\n#line 2 \"lib/utility/cumulative_sum.hpp\"\n\n#line\
    \ 4 \"lib/utility/cumulative_sum.hpp\"\n\n/**\n * @brief Partial Sum\n * @note\
    \ construct in $O(N)$, query in $O(1)$ to return partial sum\n */\n\ntemplate<class\
    \ T> class CumulativeSum1D {\n    vector<T> v;\n\n  public:\n    CumulativeSum1D(vector<T>\
    \ a):\n        v(a.size() + 1, 0) {\n        copy(begin(a), end(a), begin(v) +\
    \ 1);\n        for (size_t i = 1; i < v.size(); i++) v[i] += v[i - 1];\n    }\n\
    \    T operator()(int r) { return v[r]; }\n    T operator()(int l, int r) { return\
    \ v[r] - v[l]; }\n    vector<T> raw() { return v; }\n};\n#line 5 \"lib/test/library-checker/static_range_sum.test.cpp\"\
    \n\nstruct IOSetup {\n    IOSetup() noexcept {\n        ios::sync_with_stdio(false);\n\
    \        cin.tie(nullptr);\n        cout << fixed << setprecision(10);\n     \
    \   cerr << fixed << setprecision(10);\n    }\n} IOSetup;\n\nint main() {\n  \
    \  int n, q;\n    cin >> n >> q;\n    vector<i64> a(n);\n    for (auto &&elem\
    \ : a) cin >> elem;\n    CumulativeSum1D<i64> cs(a);\n    while (q--) {\n    \
    \    int l, r;\n        cin >> l >> r;\n        cout << cs(l, r) << \"\\n\";\n\
    \    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include \"../../include.hpp\"\n#include \"../../utility/cumulative_sum.hpp\"\n\
    \nstruct IOSetup {\n    IOSetup() noexcept {\n        ios::sync_with_stdio(false);\n\
    \        cin.tie(nullptr);\n        cout << fixed << setprecision(10);\n     \
    \   cerr << fixed << setprecision(10);\n    }\n} IOSetup;\n\nint main() {\n  \
    \  int n, q;\n    cin >> n >> q;\n    vector<i64> a(n);\n    for (auto &&elem\
    \ : a) cin >> elem;\n    CumulativeSum1D<i64> cs(a);\n    while (q--) {\n    \
    \    int l, r;\n        cin >> l >> r;\n        cout << cs(l, r) << \"\\n\";\n\
    \    }\n    return 0;\n}\n"
  dependsOn:
  - lib/include.hpp
  - lib/utility/cumulative_sum.hpp
  isVerificationFile: true
  path: lib/test/library-checker/static_range_sum.test.cpp
  requiredBy: []
  timestamp: '2021-07-10 14:38:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: lib/test/library-checker/static_range_sum.test.cpp
layout: document
redirect_from:
- /verify/lib/test/library-checker/static_range_sum.test.cpp
- /verify/lib/test/library-checker/static_range_sum.test.cpp.html
title: lib/test/library-checker/static_range_sum.test.cpp
---
