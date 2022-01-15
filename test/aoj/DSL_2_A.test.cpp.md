---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/monoids.hpp
    title: Monoids
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/segment_tree.hpp
    title: Segment Tree
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
  bundledCode: "#line 1 \"test/aoj/DSL_2_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n\n#include <iostream>\n#line 2 \"lib/data_structure/monoids.hpp\"\n\n/**\n *\
    \ @brief Monoids\n * @note Monoid \u96C6\n */\n\n#include <algorithm>\n#include\
    \ <limits>\n#include <numeric>\n\ntemplate<class T> struct Add {\n    using operand_type\
    \ = T;\n    static operand_type operation(operand_type a, operand_type b) { return\
    \ a + b; }\n    static operand_type identity() { return static_cast<operand_type>(0);\
    \ }\n};\n\ntemplate<class T> struct Mul {\n    using operand_type = T;\n    static\
    \ operand_type operation(operand_type a, operand_type b) { return a * b; }\n \
    \   static operand_type identity() { return static_cast<operand_type>(1); }\n\
    };\n\ntemplate<class T> struct Xor {\n    using operand_type = T;\n    static\
    \ operand_type operation(operand_type a, operand_type b) { return a xor b; }\n\
    \    static operand_type identity() { return static_cast<operand_type>(0); }\n\
    };\n\ntemplate<class T> struct Min {\n    using operand_type = T;\n    static\
    \ operand_type operation(operand_type a, operand_type b) { return std::min(a,\
    \ b); }\n    static operand_type identity() { return std::numeric_limits<operand_type>::max();\
    \ }\n};\n\ntemplate<class T> struct Max {\n    using operand_type = T;\n    static\
    \ operand_type operation(operand_type a, operand_type b) { return std::max(a,\
    \ b); }\n    static operand_type identity() { return std::numeric_limits<operand_type>::min();\
    \ }\n};\n\ntemplate<class T> struct Gcd {\n    using operand_type = T;\n    static\
    \ operand_type operation(operand_type a, operand_type b) { return std::gcd(a,\
    \ b); }\n    static operand_type identity() { return static_cast<operand_type>(0);\
    \ }\n};\n\ntemplate<class T> struct Lcm {\n    using operand_type = T;\n    static\
    \ operand_type operation(operand_type a, operand_type b) { return std::lcm(a,\
    \ b); }\n    static operand_type identity() { return static_cast<operand_type>(1);\
    \ }\n};\n#line 2 \"lib/data_structure/segment_tree.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\ntemplate<class Monoid> struct SegmentTree {\n    using operand_type\
    \ = typename Monoid::operand_type;\n    size_t n;\n    std::vector<operand_type>\
    \ node;\n    SegmentTree(const size_t n): n(n), node(n * 2, Monoid::identity())\
    \ {}\n    template<typename InputIterator> SegmentTree(InputIterator first, InputIterator\
    \ last)\n        : n(last - first), node(n * 2, Monoid::identity()) {\n      \
    \  copy(first, last, begin(node) + n);\n        for (size_t i = n - 1; i--;) node[i]\
    \ = Monoid::operation(node[i * 2], node[i * 2 + 1]);\n    };\n    void update(size_t\
    \ i, operand_type val) { set(i, Monoid::operation(node[i + n], val)); }\n    void\
    \ set(size_t i, operand_type val) {\n        assert(i < n);\n        i += n;\n\
    \        node[i] = val;\n        while ((i /= 2) >= 1) node[i] = Monoid::operation(node[i\
    \ * 2], node[i * 2 + 1]);\n    }\n    operand_type fold(size_t l, size_t r) {\n\
    \        assert(l <= n and r <= n);\n        if (l == 0 and r == n) return node[1];\n\
    \        operand_type ret = Monoid::identity();\n        l += n;\n        r +=\
    \ n;\n        while (l < r) {\n            if (l % 2 == 1) ret = Monoid::operation(ret,\
    \ node[l++]);\n            if (r % 2 == 1) ret = Monoid::operation(ret, node[--r]);\n\
    \            l /= 2;\n            r /= 2;\n        }\n        return ret;\n  \
    \  }\n    operand_type& operator[](size_t i) {\n        assert(i < n);\n     \
    \   return &node[i + n];\n    }\n};\n#line 6 \"test/aoj/DSL_2_A.test.cpp\"\n\n\
    int main() {\n    using namespace std;\n    size_t n, q;\n    cin >> n >> q;\n\
    \    SegmentTree<Min<int>> segtree(n);\n    while (q--) {\n        size_t com,\
    \ x, y;\n        cin >> com >> x >> y;\n        if (com == 0) {\n            segtree.set(x,\
    \ static_cast<int>(y));\n        } else if (com == 1) {\n            cout << segtree.fold(x,\
    \ ++y) << \"\\n\";\n        } else {\n            assert(false);\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n\n#include <iostream>\n#include \"lib/data_structure/monoids.hpp\"\n#include\
    \ \"lib/data_structure/segment_tree.hpp\"\n\nint main() {\n    using namespace\
    \ std;\n    size_t n, q;\n    cin >> n >> q;\n    SegmentTree<Min<int>> segtree(n);\n\
    \    while (q--) {\n        size_t com, x, y;\n        cin >> com >> x >> y;\n\
    \        if (com == 0) {\n            segtree.set(x, static_cast<int>(y));\n \
    \       } else if (com == 1) {\n            cout << segtree.fold(x, ++y) << \"\
    \\n\";\n        } else {\n            assert(false);\n        }\n    }\n}\n"
  dependsOn:
  - lib/data_structure/monoids.hpp
  - lib/data_structure/segment_tree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_A.test.cpp
  requiredBy: []
  timestamp: '2022-01-15 17:41:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_A.test.cpp
- /verify/test/aoj/DSL_2_A.test.cpp.html
title: test/aoj/DSL_2_A.test.cpp
---
