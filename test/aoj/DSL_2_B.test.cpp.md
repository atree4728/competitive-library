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
    \ namespace std;\n\n/**\n * @brief Fenwick Tree / Binary Indexed Tree\n * @docs\
    \ docs/fenwick_tree.md\n */\n\ntemplate<class T> struct FenwickTree {\n    size_t\
    \ n;\n    vector<T> data;\n\n    FenwickTree(const size_t n): n(n), data(n, 0)\
    \ {}\n    FenwickTree(const vector<T>& a): n(size(a)), data(n, 0) {\n        for\
    \ (size_t i = 0; i < n; i++) set(i, a[i]);\n    }\n    T prefix_sum(size_t i)\
    \ {\n        T ret = 0;\n        while (i > 0) {\n            ret += data[i -\
    \ 1];\n            i -= i & -i;\n        }\n        return ret;\n    }\n    T\
    \ sum(size_t l, size_t r) {\n        assert(l <= r and r <= n);\n        return\
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
  timestamp: '2021-09-29 20:09:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_B.test.cpp
- /verify/test/aoj/DSL_2_B.test.cpp.html
title: test/aoj/DSL_2_B.test.cpp
---