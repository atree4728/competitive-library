---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/lowest_common_ancestor.hpp
    title: "Lowest Common Ancestor(Doubling, Binary Search) / \u6700\u8FD1\u5171\u901A\
      \u7956\u5148"
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
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/library-checker/lca.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/lca\"\n\n#line 2 \"lib/graph/lowest_common_ancestor.hpp\"\
    \n\n#line 2 \"lib/include.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #define overload3(_1, _2, _3, name, ...) name\n#define rep1(n) for (auto _tmp\
    \ = 0; _tmp < (n); _tmp++)\n#define rep2(i, n) for (auto i = 0; i < (n); i++)\n\
    #define rep3(i, a, b) for (auto i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\ntemplate<class T> bool chmax(T &a, const T &b)\
    \ { return a < b and (a = b, true); }\ntemplate<class T> bool chmin(T &a, const\
    \ T &b) { return a > b and (a = b, true); }\nusing i64 = long long;\nusing f64\
    \ = long double;\n#line 4 \"lib/graph/lowest_common_ancestor.hpp\"\n\n/**\n *\
    \ @brief Lowest Common Ancestor(Doubling, Binary Search) / \u6700\u8FD1\u5171\u901A\
    \u7956\u5148\n * @docs docs/lowest_common_ancestor.md\n*/\n\nstruct LCA {\n  \
    \  int n, height;\n    vector<int> depth;\n    vector<vector<int>> dp;\n    explicit\
    \ LCA(const vector<vector<int>>& tree, int root):\n        n((int)size(tree)),\n\
    \        height(32 - __builtin_clz(n)),\n        depth(n, -1),\n        dp(height,\
    \ vector<int>(n, -1)) {\n        depth[root] = 0;\n        dfs(tree, root, -1);\n\
    \        rep(k, height - 1) rep(v, n) {\n            if (dp[k][v] == -1) dp[k\
    \ + 1][v] = -1;\n            else\n                dp[k + 1][v] = dp[k][dp[k][v]];\n\
    \        }\n    }\n    int operator()(int u, int v) {\n        assert(0 <= u and\
    \ u < n and 0 <= v and v < n);\n        if (depth[u] < depth[v]) swap(u, v);\n\
    \        for (int k = height - 1; k >= 0; k--)\n            if (((depth[u] - depth[v])\
    \ >> k) & 1) u = dp[k][u];\n        if (u == v) return u;\n        for (int k\
    \ = height - 1; k >= 0; k--)\n            if (dp[k][u] != dp[k][v]) {\n      \
    \          u = dp[k][u];\n                v = dp[k][v];\n            }\n     \
    \   return dp[0][u];\n    }\n    int dist(int u, int v) { return depth[u] + depth[v]\
    \ - depth[(*this)(u, v)] * 2; }\n\n  private:\n    void dfs(const vector<vector<int>>&\
    \ tree, int v, int prev) {\n        for (const auto& u: tree[v])\n           \
    \ if (u != prev) {\n                assert(depth[u] == -1 and dp[0][u] == -1);\
    \ // The graph may not be a tree Graph.\n                dp[0][u] = v;\n     \
    \           depth[u] = depth[v] + 1;\n                dfs(tree, u, v);\n     \
    \       }\n    }\n};\n#line 4 \"test/library-checker/lca.test.cpp\"\n\nint main()\
    \ {\n    int n, q;\n    cin >> n >> q;\n    vector graph(n, vector<int>{});\n\
    \    rep(i, 1, n) {\n        int p;\n        cin >> p;\n        graph[p].push_back(i);\n\
    \    }\n    LCA lca(graph, 0);\n    while (q--) {\n        int u, v;\n       \
    \ cin >> u >> v;\n        cout << lca(u, v) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"lib/graph/lowest_common_ancestor.hpp\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    vector graph(n, vector<int>{});\n\
    \    rep(i, 1, n) {\n        int p;\n        cin >> p;\n        graph[p].push_back(i);\n\
    \    }\n    LCA lca(graph, 0);\n    while (q--) {\n        int u, v;\n       \
    \ cin >> u >> v;\n        cout << lca(u, v) << \"\\n\";\n    }\n}"
  dependsOn:
  - lib/graph/lowest_common_ancestor.hpp
  - lib/include.hpp
  isVerificationFile: true
  path: test/library-checker/lca.test.cpp
  requiredBy: []
  timestamp: '2021-09-14 22:20:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/lca.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/lca.test.cpp
- /verify/test/library-checker/lca.test.cpp.html
title: test/library-checker/lca.test.cpp
---
