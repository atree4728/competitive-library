---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/fenwick_tree.hpp
    title: Fenwick Tree / Binary Indexed Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/library-checker/point_add_range_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#include\
    \ <iostream>\n#line 2 \"lib/data_structure/fenwick_tree.hpp\"\n\n#include <cassert>\n\
    #include <vector>\nusing namespace std;\n\ntemplate<class T> struct FenwickTree\
    \ {\n    size_t n;\n    vector<T> data;\n\n    FenwickTree() = default;\n    FenwickTree(const\
    \ size_t n): n(n), data(n, T{}) {}\n    template<typename InputIterator> FenwickTree(InputIterator\
    \ first, InputIterator last): n(last - first), data(n, T{}) {\n        for (auto\
    \ it = first; it != last; it++) this->add(it - first, *it);\n    }\n    T prefix_sum(size_t\
    \ i) {\n        T ret = 0;\n        while (i > 0) {\n            ret += data[i\
    \ - 1];\n            i -= i & -i;\n        }\n        return ret;\n    }\n   \
    \ T sum(size_t l, size_t r) {\n        assert(l <= r and r <= n);\n        return\
    \ prefix_sum(r) - prefix_sum(l);\n    }\n    void add(size_t i, T v) {\n     \
    \   assert(i < n);\n        i++;\n        while (i <= n) {\n            data[i\
    \ - 1] += v;\n            i += i & -i;\n        }\n    }\n};\n#line 5 \"test/library-checker/point_add_range_sum.test.cpp\"\
    \n\nint main() {\n    using namespace std;\n    size_t n, q;\n    cin >> n >>\
    \ q;\n    vector<unsigned long long> a(n);\n    for (auto&& ai: a) cin >> ai;\n\
    \    FenwickTree<unsigned long long> bit(cbegin(a), cend(a));\n    while (q--)\
    \ {\n        int t;\n        cin >> t;\n        if (t == 0) {\n            size_t\
    \ p;\n            unsigned long long x;\n            cin >> p >> x;\n        \
    \    bit.add(p, x);\n        }\n        if (t == 1) {\n            size_t l, r;\n\
    \            cin >> l >> r;\n            cout << bit.sum(l, r) << \"\\n\";\n \
    \       }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <iostream>\n#include \"lib/data_structure/fenwick_tree.hpp\"\n\nint\
    \ main() {\n    using namespace std;\n    size_t n, q;\n    cin >> n >> q;\n \
    \   vector<unsigned long long> a(n);\n    for (auto&& ai: a) cin >> ai;\n    FenwickTree<unsigned\
    \ long long> bit(cbegin(a), cend(a));\n    while (q--) {\n        int t;\n   \
    \     cin >> t;\n        if (t == 0) {\n            size_t p;\n            unsigned\
    \ long long x;\n            cin >> p >> x;\n            bit.add(p, x);\n     \
    \   }\n        if (t == 1) {\n            size_t l, r;\n            cin >> l >>\
    \ r;\n            cout << bit.sum(l, r) << \"\\n\";\n        }\n    }\n}\n"
  dependsOn:
  - lib/data_structure/fenwick_tree.hpp
  isVerificationFile: true
  path: test/library-checker/point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2021-11-16 22:42:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/point_add_range_sum.test.cpp
- /verify/test/library-checker/point_add_range_sum.test.cpp.html
title: test/library-checker/point_add_range_sum.test.cpp
---
