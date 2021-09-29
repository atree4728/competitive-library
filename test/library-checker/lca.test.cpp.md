---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/graph/lowest_common_ancestor.hpp
    title: "Lowest Common Ancestor(Doubling, Binary Search) / \u6700\u8FD1\u5171\u901A\
      \u7956\u5148"
  - icon: ':question:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/library-checker/lca.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/lca\"\n\n#line 2 \"lib/graph/lowest_common_ancestor.hpp\"\
    \n\n#line 2 \"lib/include.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #define overload3(_NULL, _2, _3, name, ...) name\n#define rep1(i, n) for (remove_const_t<remove_reference_t<decltype(n)>>\
    \ i = 0; i < (n); i++)\n#define rep2(i, a, b) for (remove_const_t<remove_reference_t<decltype(b)>>\
    \ i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)\n\
    using size_type = size_t;\n#line 4 \"lib/graph/lowest_common_ancestor.hpp\"\n\n\
    /**\n * @brief Lowest Common Ancestor(Doubling, Binary Search) / \u6700\u8FD1\u5171\
    \u901A\u7956\u5148\n * @docs docs/lowest_common_ancestor.md\n*/\n\nstruct LCA\
    \ {\n    size_t n, height;\n    vector<int> depth;\n    vector<vector<int>> dp;\n\
    \    explicit LCA(const vector<vector<size_t>>& tree, size_t root): n(size(tree)),\n\
    \                                                                   height(32\
    \ - __builtin_clz(n)),\n                                                     \
    \              depth(n, -1),\n                                               \
    \                    dp(height, vector<int>(n, -1)) {\n        depth[root] = 0;\n\
    \        dfs(tree, root, -1);\n        rep(k, height - 1) rep(v, n) {\n      \
    \      if (dp[k][v] == -1) dp[k + 1][v] = -1;\n            else\n            \
    \    dp[k + 1][v] = dp[k][dp[k][v]];\n        }\n    }\n    size_t operator()(size_t\
    \ u, size_t v) {\n        assert(u < n and v < n);\n        if (depth[u] < depth[v])\
    \ swap(u, v);\n        for (size_t k = height - 1; k--;)\n            if (((depth[u]\
    \ - depth[v]) >> k) & 1) u = dp[k][u];\n        if (u == v) return u;\n      \
    \  for (size_t k = height - 1; k--;)\n            if (dp[k][u] != dp[k][v]) {\n\
    \                u = dp[k][u];\n                v = dp[k][v];\n            }\n\
    \        return dp[0][u];\n    }\n    int dist(size_t u, size_t v) { return depth[u]\
    \ + depth[v] - depth[(*this)(u, v)] * 2; }\n\n  private:\n    void dfs(const vector<vector<size_t>>&\
    \ tree, size_t v, size_t prev) {\n        for (const auto u: tree[v])\n      \
    \      if (u != prev) {\n                assert(depth[u] == -1 and dp[0][u] ==\
    \ -1);  // The graph may not be a tree Graph.\n                dp[0][u] = (int)\
    \ v;\n                depth[u] = depth[v] + 1;\n                dfs(tree, u, v);\n\
    \            }\n    }\n};\n#line 4 \"test/library-checker/lca.test.cpp\"\n\nint\
    \ main() {\n    size_t n, q;\n    cin >> n >> q;\n    vector graph(n, vector<size_t>{});\n\
    \    rep(i, 1, n) {\n        size_t p;\n        cin >> p;\n        graph[p].push_back(i);\n\
    \    }\n    LCA lca(graph, 0);\n    while (q--) {\n        size_t u, v;\n    \
    \    cin >> u >> v;\n        cout << lca(u, v) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"lib/graph/lowest_common_ancestor.hpp\"\
    \n\nint main() {\n    size_t n, q;\n    cin >> n >> q;\n    vector graph(n, vector<size_t>{});\n\
    \    rep(i, 1, n) {\n        size_t p;\n        cin >> p;\n        graph[p].push_back(i);\n\
    \    }\n    LCA lca(graph, 0);\n    while (q--) {\n        size_t u, v;\n    \
    \    cin >> u >> v;\n        cout << lca(u, v) << \"\\n\";\n    }\n}\n"
  dependsOn:
  - lib/graph/lowest_common_ancestor.hpp
  - lib/include.hpp
  isVerificationFile: true
  path: test/library-checker/lca.test.cpp
  requiredBy: []
  timestamp: '2021-09-29 20:09:01+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/lca.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/lca.test.cpp
- /verify/test/library-checker/lca.test.cpp.html
title: test/library-checker/lca.test.cpp
---
