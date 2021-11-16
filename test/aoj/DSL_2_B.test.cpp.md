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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
  bundledCode: "#line 1 \"test/aoj/DSL_2_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n\n#include <cassert>\n#include <iostream>\n#line 2 \"lib/data_structure/fenwick_tree.hpp\"\
    \n\n#line 4 \"lib/data_structure/fenwick_tree.hpp\"\n#include <vector>\nusing\
    \ namespace std;\n\ntemplate<class T> struct FenwickTree {\n    size_t n;\n  \
    \  vector<T> data;\n\n    FenwickTree() = default;\n    FenwickTree(const size_t\
    \ n): n(n), data(n, T{}) {}\n    template<typename InputIterator> FenwickTree(InputIterator\
    \ first, InputIterator last): n(last - first), data(n, T{}) {\n        for (auto\
    \ it = first; it != last; it++) this->add(it - first, *it);\n    }\n    T prefix_sum(size_t\
    \ i) {\n        T ret = 0;\n        while (i > 0) {\n            ret += data[i\
    \ - 1];\n            i -= i & -i;\n        }\n        return ret;\n    }\n   \
    \ T sum(size_t l, size_t r) {\n        assert(l <= r and r <= n);\n        return\
    \ prefix_sum(r) - prefix_sum(l);\n    }\n    void add(size_t i, T v) {\n     \
    \   assert(i < n);\n        i++;\n        while (i <= n) {\n            data[i\
    \ - 1] += v;\n            i += i & -i;\n        }\n    }\n};\n#line 6 \"test/aoj/DSL_2_B.test.cpp\"\
    \n\nint main() {\n    using namespace std;\n    size_t n, q;\n    cin >> n >>\
    \ q;\n    FenwickTree<int> bit(n);\n    while (q--) {\n        size_t com, x;\n\
    \        int y;\n        cin >> com >> x >> y;\n        if (com == 0) {\n    \
    \        bit.add(--x, y);\n        } else if (com == 1) {\n            cout <<\
    \ bit.sum(--x, y) << \"\\n\";\n        } else {\n            assert(false);\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n\n#include <cassert>\n#include <iostream>\n#include \"lib/data_structure/fenwick_tree.hpp\"\
    \n\nint main() {\n    using namespace std;\n    size_t n, q;\n    cin >> n >>\
    \ q;\n    FenwickTree<int> bit(n);\n    while (q--) {\n        size_t com, x;\n\
    \        int y;\n        cin >> com >> x >> y;\n        if (com == 0) {\n    \
    \        bit.add(--x, y);\n        } else if (com == 1) {\n            cout <<\
    \ bit.sum(--x, y) << \"\\n\";\n        } else {\n            assert(false);\n\
    \        }\n    }\n}\n"
  dependsOn:
  - lib/data_structure/fenwick_tree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_B.test.cpp
  requiredBy: []
  timestamp: '2021-11-16 22:42:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_B.test.cpp
- /verify/test/aoj/DSL_2_B.test.cpp.html
title: test/aoj/DSL_2_B.test.cpp
---
