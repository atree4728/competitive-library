---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/cumulative_sum.hpp
    title: Partial Sum
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
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
  bundledCode: "#line 1 \"test/library-checker/static_range_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#line 2 \"lib/data_structure/cumulative_sum.hpp\"\
    \n\n#line 2 \"lib/include.hpp\"\n\n#include <bits/stdc++.h>\n#include <experimental/iterator>\n\
    using namespace std;\n#define overload3(_1, _2, _3, name, ...) name\n#define rep1(n)\
    \ for (decltype(n) _tmp = 0; _tmp < n; _tmp++)\n#define rep2(i, n) for (decltype(n)\
    \ i = 0; i < n; i++)\n#define rep3(i, a, b) for (decltype(b) i = a; i < b; i++)\n\
    #define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\nstruct\
    \ IOSetup { IOSetup() noexcept { ios::sync_with_stdio(false); cin.tie(nullptr);\
    \ cout << fixed << setprecision(10); cerr << fixed << setprecision(10); } } iosetup;\n\
    template <class T> bool chmax(T &a, const T &b) { return a < b and (a = b, true);\
    \ }\ntemplate <class T> bool chmin(T &a, const T &b) { return a > b and (a = b,\
    \ true); }\nusing i64 = long long;\nusing u64 = unsigned long long;\nusing f64\
    \ = long double;\n#line 4 \"lib/data_structure/cumulative_sum.hpp\"\n\n/**\n *\
    \ @brief Partial Sum\n * @note construct in $O(N)$, query in $O(1)$ to return\
    \ partial sum\n */\n\ntemplate<class T> struct CumSum {\n    vector<T> v;\n  \
    \  CumSum(vector<T> a):\n        v(size(a) + 1, 0) {\n        copy(begin(a), end(a),\
    \ begin(v) + 1);\n        rep(i, 1, size(v)) v[i] += v[i - 1];\n    }\n    T operator()(int\
    \ r) { return v[r]; }\n    T operator()(int l, int r) { return v[r] - v[l]; }\n\
    };\n#line 4 \"test/library-checker/static_range_sum.test.cpp\"\n\nint main() {\n\
    \    int n, q;\n    cin >> n >> q;\n    vector<i64> a(n);\n    for (auto &&elem:\
    \ a) cin >> elem;\n    CumSum<i64> cs(a);\n    while (q--) {\n        int l, r;\n\
    \        cin >> l >> r;\n        cout << cs(l, r) << \"\\n\";\n    }\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include \"../../lib/data_structure/cumulative_sum.hpp\"\n\nint main() {\n   \
    \ int n, q;\n    cin >> n >> q;\n    vector<i64> a(n);\n    for (auto &&elem:\
    \ a) cin >> elem;\n    CumSum<i64> cs(a);\n    while (q--) {\n        int l, r;\n\
    \        cin >> l >> r;\n        cout << cs(l, r) << \"\\n\";\n    }\n    return\
    \ 0;\n}\n"
  dependsOn:
  - lib/data_structure/cumulative_sum.hpp
  - lib/include.hpp
  isVerificationFile: true
  path: test/library-checker/static_range_sum.test.cpp
  requiredBy: []
  timestamp: '2021-07-21 10:45:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/static_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/static_range_sum.test.cpp
- /verify/test/library-checker/static_range_sum.test.cpp.html
title: test/library-checker/static_range_sum.test.cpp
---
