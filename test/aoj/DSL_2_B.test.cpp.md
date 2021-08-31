---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/monoid.hpp
    title: lib/data_structure/monoid.hpp
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/segment_tree.hpp
    title: Segment Tree
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
  bundledCode: "#line 1 \"test/aoj/DSL_2_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n\n#line 2 \"lib/data_structure/monoid.hpp\"\n\n#line 2 \"lib/include.hpp\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_1, _2, _3,\
    \ name, ...) name\n#define rep1(n) for (decltype(n) _tmp = 0; _tmp < (n); _tmp++)\n\
    #define rep2(i, n) for (decltype(n) i = 0; i < (n); i++)\n#define rep3(i, a, b)\
    \ for (decltype(b) i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\nstruct IOSetup {\n    IOSetup() noexcept {\n\
    \        ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n        cout\
    \ << fixed << setprecision(10);\n        cerr << fixed << setprecision(10);\n\
    \    }\n} iosetup;\ntemplate<class T> bool chmax(T &a, const T &b) { return a\
    \ < b and (a = b, true); }\ntemplate<class T> bool chmin(T &a, const T &b) { return\
    \ a > b and (a = b, true); }\nusing i64 = long long;\nusing f64 = long double;\n\
    #line 4 \"lib/data_structure/monoid.hpp\"\n\nstruct Add {\n    using T = int;\n\
    \    static T op(T a, T b) { return a + b; }\n    static inline T id = 0;\n};\n\
    \nstruct Mul {\n    using T = int;\n    static T op(T a, T b) { return a * b;\
    \ }\n    static inline T id = 1;\n};\n\nstruct Xor {\n    using T = int;\n   \
    \ static T op(T a, T b) { return a xor b; }\n    static inline T id = 0;\n};\n\
    \nstruct Min {\n    using T = int;\n    static T op(T a, T b) { return min(a,\
    \ b); }\n    static inline T id = numeric_limits<T>::max();\n};\n\nstruct Max\
    \ {\n    using T = int;\n    static T op(T a, T b) { return max(a, b); }\n   \
    \ static inline T id = numeric_limits<T>::min();\n};\n\nstruct Gcd {\n    using\
    \ T = int;\n    static T op(T a, T b) { return gcd(a, b); }\n    static inline\
    \ T id = 0;\n};\n\nstruct Lcm {\n    using T = int;\n    static T op(T a, T b)\
    \ { return lcm(a, b); }\n    static inline T id = 0;\n};\n#line 2 \"lib/data_structure/segment_tree.hpp\"\
    \n\n#line 4 \"lib/data_structure/segment_tree.hpp\"\n\n/**\n * @brief Segment\
    \ Tree\n * @note Class ```Monoid``` must have one binary operation that satisfies\
    \ the associativity, a set to be defined, and the identify element.\n * ref: https://noshi91.hatenablog.com/entry/2020/04/22/212649\n\
    \ * @note\n *\n * @example\n * struct Add {\n *     using T = int;\n *     static\
    \ T op(int l, int r) { return l + r; }\n *     static inline T id = 0;\n * };\n\
    \ */\n\ntemplate<class Monoid> struct SegmentTree {\n    using T = typename Monoid::T;\n\
    \    int n;\n    vector<T> node;\n    explicit SegmentTree(const int n):\n   \
    \     n(n), node(n * 2, Monoid::id) {}\n    explicit SegmentTree(const vector<T>\
    \ &a):\n        n(size(a)), node(n * 2, Monoid::id) {\n        copy(begin(a),\
    \ end(a), begin(node) + n);\n        for (int i = n - 1; i >= 0; i--) node[i]\
    \ = Monoid::op(node[i * 2], node[i * 2 + 1]);\n    };\n    void update(int i,\
    \ T val) { set(i, Monoid::op(node[i + n], val)); }\n    void set(int i, T val)\
    \ {\n        i += n;\n        node[i] = val;\n        while ((i /= 2) >= 1) node[i]\
    \ = Monoid::op(node[i * 2], node[i * 2 + 1]);\n    }\n    T fold(int l, int r)\
    \ {\n        T ret = Monoid::id;\n        l += n;\n        r += n;\n        while\
    \ (l < r) {\n            if (l % 2 == 1) ret = Monoid::op(ret, node[l++]);\n \
    \           if (r % 2 == 1) ret = Monoid::op(ret, node[--r]);\n            l /=\
    \ 2;\n            r /= 2;\n        }\n        return ret;\n    }\n    T operator[](int\
    \ i) { return node[i + n]; }\n};\n#line 5 \"test/aoj/DSL_2_B.test.cpp\"\n\nint\
    \ main() {\n    int n, q;\n    cin >> n >> q;\n    SegmentTree<Add> segtree(n);\n\
    \    while (q--) {\n        int com, x, y;\n        cin >> com >> x >> y;\n  \
    \      if (com == 0) {\n            segtree.update(--x, y);\n        } else if\
    \ (com == 1) {\n            cout << segtree.fold(--x, y) << \"\\n\";\n       \
    \ } else {\n            assert(false);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n\n#include \"lib/data_structure/monoid.hpp\"\n#include \"lib/data_structure/segment_tree.hpp\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    SegmentTree<Add> segtree(n);\n\
    \    while (q--) {\n        int com, x, y;\n        cin >> com >> x >> y;\n  \
    \      if (com == 0) {\n            segtree.update(--x, y);\n        } else if\
    \ (com == 1) {\n            cout << segtree.fold(--x, y) << \"\\n\";\n       \
    \ } else {\n            assert(false);\n        }\n    }\n}\n"
  dependsOn:
  - lib/data_structure/monoid.hpp
  - lib/include.hpp
  - lib/data_structure/segment_tree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_B.test.cpp
  requiredBy: []
  timestamp: '2021-08-31 17:33:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_B.test.cpp
- /verify/test/aoj/DSL_2_B.test.cpp.html
title: test/aoj/DSL_2_B.test.cpp
---
