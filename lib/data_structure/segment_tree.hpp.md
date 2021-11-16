---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.test.cpp
    title: test/aoj/DSL_2_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/segment_tree.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\ntemplate<class Monoid> struct SegmentTree {\n    using operand_type\
    \ = typename Monoid::operand_type;\n    size_t n;\n    std::vector<operand_type>\
    \ node;\n    SegmentTree(const size_t n): n(n), node(n * 2, Monoid::identity())\
    \ {}\n    template<typename InputIterator> SegmentTree(InputIterator first, InputIterator\
    \ last): n(last - first), node(n * 2, Monoid::identity()) {\n        copy(first,\
    \ last, begin(node) + n);\n        for (size_t i = n - 1; i--;) node[i] = Monoid::operaton(node[i\
    \ * 2], node[i * 2 + 1]);\n    };\n    void update(size_t i, operand_type val)\
    \ { set(i, Monoid::operation(node[i + n], val)); }\n    void set(size_t i, operand_type\
    \ val) {\n        assert(i < n);\n        i += n;\n        node[i] = val;\n  \
    \      while ((i /= 2) >= 1) node[i] = Monoid::operation(node[i * 2], node[i *\
    \ 2 + 1]);\n    }\n    operand_type fold(size_t l, size_t r) {\n        assert(l\
    \ <= n and r <= n);\n        if (l == 0 and r == n) return node[1];\n        operand_type\
    \ ret = Monoid::identity();\n        l += n;\n        r += n;\n        while (l\
    \ < r) {\n            if (l % 2 == 1) ret = Monoid::operation(ret, node[l++]);\n\
    \            if (r % 2 == 1) ret = Monoid::operation(ret, node[--r]);\n      \
    \      l /= 2;\n            r /= 2;\n        }\n        return ret;\n    }\n \
    \   operand_type& operator[](size_t i) {\n        assert(i < n);\n        return\
    \ &node[i + n];\n    }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\ntemplate<class Monoid>\
    \ struct SegmentTree {\n    using operand_type = typename Monoid::operand_type;\n\
    \    size_t n;\n    std::vector<operand_type> node;\n    SegmentTree(const size_t\
    \ n): n(n), node(n * 2, Monoid::identity()) {}\n    template<typename InputIterator>\
    \ SegmentTree(InputIterator first, InputIterator last): n(last - first), node(n\
    \ * 2, Monoid::identity()) {\n        copy(first, last, begin(node) + n);\n  \
    \      for (size_t i = n - 1; i--;) node[i] = Monoid::operaton(node[i * 2], node[i\
    \ * 2 + 1]);\n    };\n    void update(size_t i, operand_type val) { set(i, Monoid::operation(node[i\
    \ + n], val)); }\n    void set(size_t i, operand_type val) {\n        assert(i\
    \ < n);\n        i += n;\n        node[i] = val;\n        while ((i /= 2) >= 1)\
    \ node[i] = Monoid::operation(node[i * 2], node[i * 2 + 1]);\n    }\n    operand_type\
    \ fold(size_t l, size_t r) {\n        assert(l <= n and r <= n);\n        if (l\
    \ == 0 and r == n) return node[1];\n        operand_type ret = Monoid::identity();\n\
    \        l += n;\n        r += n;\n        while (l < r) {\n            if (l\
    \ % 2 == 1) ret = Monoid::operation(ret, node[l++]);\n            if (r % 2 ==\
    \ 1) ret = Monoid::operation(ret, node[--r]);\n            l /= 2;\n         \
    \   r /= 2;\n        }\n        return ret;\n    }\n    operand_type& operator[](size_t\
    \ i) {\n        assert(i < n);\n        return &node[i + n];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/segment_tree.hpp
  requiredBy: []
  timestamp: '2021-11-16 23:22:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_A.test.cpp
documentation_of: lib/data_structure/segment_tree.hpp
layout: document
title: Segment Tree
---

Segment Tree は Monoid の列に関する一点変更と区間積を高速に処理するデータ構造である。

## Usage

まず、クラス`Monoid`を定義する必要がある。 Monoid とは、単位元$e$を持つ集合$S$と、写像$op:S\times S\rightarrow S$の組$(S, op, e)$のことである。 ただし、$\forall(
a,b,c)\in S^3. op(op(a,b),c)=op(a,op(b,c))$が満たされる必要がある。  

```c++
// $({i | -2^31\leq<2^31},+,0)$を例とする。
struct Add {
    using operand_type = int; // operand の型
    static operand_type opearaion(operand_type lhs, operand_type rhs) { return lhs + rhs; } // fucntion<operand_type(operand_type, operand_type)> の二項演算
    static operand_type identity { return 0; } // 単位元
};
```

ref: https://noshi91.hatenablog.com/entry/2020/04/22/212649

以下、上の`Monoid`を前提とする。

- `SegmentTree<Monoid>(size_t n)`: 長さ$n$の`identity()`から成る列で Segment Tree を構築する。$\mathcal{O}(n\log n)$.
- `SegmentTree<Monoid>(InputIterator first, InputIterator last)`: iterator による constructor. $\mathcal{O}(n\log n)$.
- `void set(size_t i, operand_type val)`: $a_i$を$val$にする。
- `void update(size_t i, operand_type val)`: $a_i$を$\mathrm{operation}(a_i,val)$にする。$\mathcal{O}(\log n)$.
- `operand_type fold(size_t l, size_t r)`: $\bigodot_{i\in[l,r)}a_i. $\mathcal{O}(\log n)$.
- `operator[]`

