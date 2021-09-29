---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/data_structure/union_find.hpp
    title: Union Find
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
  bundledCode: "#line 1 \"test/aoj/DSL_1_A.test.cpp\"\n#include <cassert>\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A\"\
    \n\n#line 2 \"lib/data_structure/union_find.hpp\"\n\n#line 2 \"lib/include.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_NULL, _2,\
    \ _3, name, ...) name\n#define rep1(i, n) for (remove_const_t<remove_reference_t<decltype(n)>>\
    \ i = 0; i < (n); i++)\n#define rep2(i, a, b) for (remove_const_t<remove_reference_t<decltype(b)>>\
    \ i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)\n\
    using size_type = size_t;\n#line 4 \"lib/data_structure/union_find.hpp\"\n\n/**\n\
    \ * @brief Union Find\n * @docs docs/union_find.md\n */\n\nstruct UnionFind {\n\
    \    size_type n;\n    vector<int> node;\n    explicit UnionFind(const size_type\
    \ n):\n        n(n), node(n, -1) {}\n    bool unite(size_type u, size_type v)\
    \ {\n        u = root(u), v = root(v);\n        if (u == v) return false;\n  \
    \      if (node[u] > node[v]) swap(u, v);\n        node[u] += node[v];\n     \
    \   node[v] = (int)u;\n        return true;\n    }\n    size_type root(size_type\
    \ v) { return node[v] < 0 ? v : node[v] = (int)root(node[v]); }\n    size_type\
    \ size(size_type v) { return (size_type)-node[root(v)]; }\n    bool same(size_type\
    \ u, size_type v) { return root(u) == root(v); }\n    vector<vector<size_type>>\
    \ group() {\n        vector ret(n, vector<size_type>{});\n        rep(i, n) ret[root(i)].push_back(i);\n\
    \        ret.erase(remove_if(begin(ret), end(ret), [&](const auto &ri) { return\
    \ empty(ri); }));\n        return ret;\n    }\n};\n#line 5 \"test/aoj/DSL_1_A.test.cpp\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    UnionFind uf(n);\n  \
    \  while (q--) {\n        int com, x, y;\n        cin >> com >> x >> y;\n    \
    \    if (com == 0) {\n            uf.unite(x, y);\n        } else if (com == 1)\
    \ {\n            cout << (uf.same(x, y) ? 1 : 0) << \"\\n\";\n        } else {\n\
    \            assert(false);\n        }\n    }\n}\n"
  code: "#include <cassert>\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A\"\
    \n\n#include \"lib/data_structure/union_find.hpp\"\n\nint main() {\n    int n,\
    \ q;\n    cin >> n >> q;\n    UnionFind uf(n);\n    while (q--) {\n        int\
    \ com, x, y;\n        cin >> com >> x >> y;\n        if (com == 0) {\n       \
    \     uf.unite(x, y);\n        } else if (com == 1) {\n            cout << (uf.same(x,\
    \ y) ? 1 : 0) << \"\\n\";\n        } else {\n            assert(false);\n    \
    \    }\n    }\n}\n"
  dependsOn:
  - lib/data_structure/union_find.hpp
  - lib/include.hpp
  isVerificationFile: true
  path: test/aoj/DSL_1_A.test.cpp
  requiredBy: []
  timestamp: '2021-09-29 20:09:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_1_A.test.cpp
- /verify/test/aoj/DSL_1_A.test.cpp.html
title: test/aoj/DSL_1_A.test.cpp
---
