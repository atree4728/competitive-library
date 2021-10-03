---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/union_find.hpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/library-checker/unionfind.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include <cassert>\n#include\
    \ <iostream>\n#line 2 \"lib/data_structure/union_find.hpp\"\n\n#include <algorithm>\n\
    #include <vector>\n\nstruct UnionFind {\n    std::size_t n;\n    std::vector<int>\
    \ node;\n    explicit UnionFind(const std::size_t n): n(n), node(n, -1) {}\n \
    \   bool unite(std::size_t u, std::size_t v) {\n        u = root(u), v = root(v);\n\
    \        if (u == v) return false;\n        if (node[u] > node[v]) std::swap(u,\
    \ v);\n        node[u] += node[v];\n        node[v] = (int) u;\n        return\
    \ true;\n    }\n    std::size_t root(const std::size_t &v) { return node[v] <\
    \ 0 ? v : node[v] = (int) root(node[v]); }\n    std::size_t size(const std::size_t\
    \ &v) { return (std::size_t) -node[root(v)]; }\n    bool same(const std::size_t\
    \ &u, const std::size_t &v) { return root(u) == root(v); }\n    std::vector<std::vector<std::size_t>>\
    \ group() {\n        std::vector ret(n, std::vector<std::size_t>{});\n       \
    \ for (std::size_t i = 0; i < n; i++) ret[root(i)].push_back(i);\n        ret.erase(std::remove_if(begin(ret),\
    \ end(ret), [&](const auto &ri) { return empty(ri); }));\n        return ret;\n\
    \    }\n};\n#line 6 \"test/library-checker/unionfind.test.cpp\"\n\nint main()\
    \ {\n    using namespace std;\n    size_t n, q;\n    cin >> n >> q;\n    UnionFind\
    \ uf(n);\n    while (q--) {\n        size_t t, u, v;\n        cin >> t >> u >>\
    \ v;\n        switch (t) {\n            case 0: uf.unite(u, v); break;\n     \
    \       case 1: cout << uf.same(u, v) << \"\\n\"; break;\n            default:\
    \ assert(false);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <cassert>\n#include <iostream>\n#include \"lib/data_structure/union_find.hpp\"\
    \n\nint main() {\n    using namespace std;\n    size_t n, q;\n    cin >> n >>\
    \ q;\n    UnionFind uf(n);\n    while (q--) {\n        size_t t, u, v;\n     \
    \   cin >> t >> u >> v;\n        switch (t) {\n            case 0: uf.unite(u,\
    \ v); break;\n            case 1: cout << uf.same(u, v) << \"\\n\"; break;\n \
    \           default: assert(false);\n        }\n    }\n}\n"
  dependsOn:
  - lib/data_structure/union_find.hpp
  isVerificationFile: true
  path: test/library-checker/unionfind.test.cpp
  requiredBy: []
  timestamp: '2021-10-03 22:09:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/unionfind.test.cpp
- /verify/test/library-checker/unionfind.test.cpp.html
title: test/library-checker/unionfind.test.cpp
---
