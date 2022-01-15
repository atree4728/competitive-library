---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/lowest_common_ancestor.hpp
    title: "Lowest Common Ancestor(Doubling, Binary Search) / \u6700\u8FD1\u5171\u901A\
      \u7956\u5148"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C
  bundledCode: "#line 1 \"test/aoj/GRL_5_C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C\"\
    \n\n#include <iostream>\n#line 2 \"lib/graph/lowest_common_ancestor.hpp\"\n\n\
    #include <cassert>\n#include <vector>\n\nstruct LowestCommonAncestor {\n    std::size_t\
    \ n, height;\n    std::vector<int> depth;\n    std::vector<std::vector<int>> dp;\n\
    \    LowestCommonAncestor(const std::vector<std::vector<std::size_t>>& tree, std::size_t\
    \ root): n(size(tree)), height(32 - __builtin_clz(n)), depth(n, -1), dp(height,\
    \ std::vector<int>(n, -1)) {\n        depth[root] = 0;\n        dfs(tree, root,\
    \ root);\n        for (std::size_t k = 0; k + 1 < height; k++)\n            for\
    \ (std::size_t v = 0; v < n; v++) {\n                if (dp[k][v] == -1) dp[k\
    \ + 1][v] = -1;\n                else\n                    dp[k + 1][v] = dp[k][dp[k][v]];\n\
    \            }\n    }\n    std::size_t operator()(std::size_t u, std::size_t v)\
    \ {\n        assert(u < n and v < n);\n        if (depth[u] < depth[v]) std::swap(u,\
    \ v);\n        for (std::size_t k = height - 1; k--;)\n            if (((depth[u]\
    \ - depth[v]) >> k) & 1) u = dp[k][u];\n        if (u == v) return u;\n      \
    \  for (size_t k = height - 1; k--;)\n            if (dp[k][u] != dp[k][v]) {\n\
    \                u = dp[k][u];\n                v = dp[k][v];\n            }\n\
    \        return dp[0][u];\n    }\n    int dist(size_t u, size_t v) { return depth[u]\
    \ + depth[v] - depth[(*this)(u, v)] * 2; }\n\n  private:\n    void dfs(const std::vector<std::vector<std::size_t>>&\
    \ tree, std::size_t v, std::size_t prev) {\n        for (const auto u: tree[v])\n\
    \            if (u != prev) {\n                assert(depth[u] == -1 and dp[0][u]\
    \ == -1);  // The graph may not be a tree Graph.\n                dp[0][u] = (int)\
    \ v;\n                depth[u] = depth[v] + 1;\n                dfs(tree, u, v);\n\
    \            }\n    }\n};\n#line 5 \"test/aoj/GRL_5_C.test.cpp\"\n\nint main()\
    \ {\n    using namespace std;\n    size_t n;\n    cin >> n;\n    vector graph(n,\
    \ vector<size_t>{});\n    for (size_t i = 0; i < n; i++) {\n        size_t k;\n\
    \        cin >> k;\n        while (k--) {\n            size_t c;\n           \
    \ cin >> c;\n            graph[i].push_back(c);\n        }\n    }\n    auto lca\
    \ = LowestCommonAncestor(graph, 0);\n    size_t q;\n    cin >> q;\n    while (q--)\
    \ {\n        size_t u, v;\n        cin >> u >> v;\n        size_t ans = lca(u,\
    \ v);\n        cout << ans << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C\"\n\n\
    #include <iostream>\n#include \"lib/graph/lowest_common_ancestor.hpp\"\n\nint\
    \ main() {\n    using namespace std;\n    size_t n;\n    cin >> n;\n    vector\
    \ graph(n, vector<size_t>{});\n    for (size_t i = 0; i < n; i++) {\n        size_t\
    \ k;\n        cin >> k;\n        while (k--) {\n            size_t c;\n      \
    \      cin >> c;\n            graph[i].push_back(c);\n        }\n    }\n    auto\
    \ lca = LowestCommonAncestor(graph, 0);\n    size_t q;\n    cin >> q;\n    while\
    \ (q--) {\n        size_t u, v;\n        cin >> u >> v;\n        size_t ans =\
    \ lca(u, v);\n        cout << ans << \"\\n\";\n    }\n}\n"
  dependsOn:
  - lib/graph/lowest_common_ancestor.hpp
  isVerificationFile: true
  path: test/aoj/GRL_5_C.test.cpp
  requiredBy: []
  timestamp: '2021-11-16 17:03:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_5_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_C.test.cpp
- /verify/test/aoj/GRL_5_C.test.cpp.html
title: test/aoj/GRL_5_C.test.cpp
---