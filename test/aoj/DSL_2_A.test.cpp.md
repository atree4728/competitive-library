---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/monoid.hpp
    title: Monoids
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/segment_tree.hpp
    title: Segment Tree
  - icon: ':question:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
  bundledCode: "#line 1 \"test/aoj/DSL_2_A.test.cpp\"\n#include <cassert>\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n\n#line 2 \"lib/data_structure/monoid.hpp\"\n\n#line 2 \"lib/include.hpp\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_NULL, _2,\
    \ _3, name, ...) name\n#define rep1(i, n) for (remove_const_t<remove_reference_t<decltype(n)>>\
    \ i = 0; i < (n); i++)\n#define rep2(i, a, b) for (remove_const_t<remove_reference_t<decltype(b)>>\
    \ i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)\n\
    using size_type = size_t;\n#line 4 \"lib/data_structure/monoid.hpp\"\n\n/**\n\
    \ * @brief Monoids\n * @note Monoid \u96C6\n */\n\nstruct Add {\n    using T =\
    \ int;\n    static T op(T a, T b) { return a + b; }\n    static inline T id =\
    \ 0;\n};\n\nstruct Mul {\n    using T = int;\n    static T op(T a, T b) { return\
    \ a * b; }\n    static inline T id = 1;\n};\n\nstruct Xor {\n    using T = int;\n\
    \    static T op(T a, T b) { return a xor b; }\n    static inline T id = 0;\n\
    };\n\nstruct Min {\n    using T = int;\n    static T op(T a, T b) { return min(a,\
    \ b); }\n    static inline T id = numeric_limits<T>::max();\n};\n\nstruct Max\
    \ {\n    using T = int;\n    static T op(T a, T b) { return max(a, b); }\n   \
    \ static inline T id = numeric_limits<T>::min();\n};\n\nstruct Gcd {\n    using\
    \ T = int;\n    static T op(T a, T b) { return gcd(a, b); }\n    static inline\
    \ T id = 0;\n};\n\nstruct Lcm {\n    using T = int;\n    static T op(T a, T b)\
    \ { return lcm(a, b); }\n    static inline T id = 1;\n};\n#line 2 \"lib/data_structure/segment_tree.hpp\"\
    \n\n#line 4 \"lib/data_structure/segment_tree.hpp\"\n\n/**\n * @brief Segment\
    \ Tree\n * @docs docs/segment_tree.md\n */\n\ntemplate<class Monoid> struct SegmentTree\
    \ {\n    using T = typename Monoid::T;\n    size_type n;\n    vector<T> node;\n\
    \    explicit SegmentTree(const size_type n):\n        n(n), node(n * 2, Monoid::id)\
    \ {}\n    explicit SegmentTree(const vector<T>& a):\n        n(size(a)), node(n\
    \ * 2, Monoid::id) {\n        copy(begin(a), end(a), begin(node) + n);\n     \
    \   for (size_type i = n - 1; i--;) node[i] = Monoid::op(node[i * 2], node[i *\
    \ 2 + 1]);\n    };\n    void update(size_type i, T val) { set(i, Monoid::op(node[i\
    \ + n], val)); }\n    void set(size_type i, T val) {\n        assert(i < n);\n\
    \        i += n;\n        node[i] = val;\n        while ((i /= 2) >= 1) node[i]\
    \ = Monoid::op(node[i * 2], node[i * 2 + 1]);\n    }\n    T fold(size_type l,\
    \ size_type r) {\n        assert(l <= n and r <= n);\n        if (l == 0 and r\
    \ == n) return node[1];\n        T ret = Monoid::id;\n        l += n;\n      \
    \  r += n;\n        while (l < r) {\n            if (l % 2 == 1) ret = Monoid::op(ret,\
    \ node[l++]);\n            if (r % 2 == 1) ret = Monoid::op(ret, node[--r]);\n\
    \            l /= 2;\n            r /= 2;\n        }\n        return ret;\n  \
    \  }\n    T& operator[](size_type i) {\n        assert(i < n);\n        return\
    \ &node[i + n];\n    }\n};\n#line 6 \"test/aoj/DSL_2_A.test.cpp\"\n\nint main()\
    \ {\n    int n, q;\n    cin >> n >> q;\n    SegmentTree<Min> segtree(n);\n   \
    \ while (q--) {\n        int com, x, y;\n        cin >> com >> x >> y;\n     \
    \   if (com == 0) {\n            segtree.set(x, y);\n        } else if (com ==\
    \ 1) {\n            cout << segtree.fold(x, ++y) << \"\\n\";\n        } else {\n\
    \            assert(false);\n        }\n    }\n}\n"
  code: "#include <cassert>\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n\n#include \"lib/data_structure/monoid.hpp\"\n#include \"lib/data_structure/segment_tree.hpp\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    SegmentTree<Min> segtree(n);\n\
    \    while (q--) {\n        int com, x, y;\n        cin >> com >> x >> y;\n  \
    \      if (com == 0) {\n            segtree.set(x, y);\n        } else if (com\
    \ == 1) {\n            cout << segtree.fold(x, ++y) << \"\\n\";\n        } else\
    \ {\n            assert(false);\n        }\n    }\n}\n"
  dependsOn:
  - lib/data_structure/monoid.hpp
  - lib/include.hpp
  - lib/data_structure/segment_tree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_A.test.cpp
  requiredBy: []
  timestamp: '2021-09-29 20:09:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_A.test.cpp
- /verify/test/aoj/DSL_2_A.test.cpp.html
title: test/aoj/DSL_2_A.test.cpp
---
