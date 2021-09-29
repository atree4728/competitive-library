---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/tree_diameter.hpp
    title: "Diameter of a Tree / \u6728\u306E\u76F4\u5F84"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A
  bundledCode: "#line 1 \"test/aoj/GRL_5_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A\"\
    \n\n#include <iostream>\n#line 2 \"lib/graph/tree_diameter.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <limits>\n#include <vector>\nusing namespace std;\n\
    \n/**\n * @brief Diameter of a Tree / \u6728\u306E\u76F4\u5F84\n * @docs docs/tree_diameter.md\n\
    \ */\n\ntemplate<typename T> T tree_diameter(const vector<vector<pair<size_t,\
    \ T>>> &tree) {\n    const size_t n = size(tree);\n    const T INF = numeric_limits<T>::max();\n\
    \    vector<T> dist(n, INF);\n    auto dfs = [&](auto &&self, size_t v, size_t\
    \ prev) -> void {\n        for (const auto &[u, w]: tree[v]) {\n            if\
    \ (u == prev) continue;\n            assert(dist[u] == INF);  // graph must be\
    \ a tree\n            dist[u] = dist[v] + w;\n            self(self, u, v);\n\
    \        }\n    };\n    dist[0] = 0;\n    dfs(dfs, 0, 0);\n    size_t farthest\
    \ = distance(begin(dist), max_element(begin(dist), end(dist)));\n    assert(dist[farthest]\
    \ != INF);  // graph must be a tree\n    fill(begin(dist), end(dist), INF);\n\
    \    dist[farthest] = 0;\n    dfs(dfs, farthest, 0);\n    T ans = *max_element(begin(dist),\
    \ end(dist));\n    return ans;\n}\n#line 5 \"test/aoj/GRL_5_A.test.cpp\"\n\nint\
    \ main() {\n    size_t n;\n    cin >> n;\n    using Edge = pair<size_t, int>;\n\
    \    vector tree(n, vector<Edge>{});\n    for (size_t _ = 0; _ < n - 1; _++) {\n\
    \        size_t s, t;\n        int w;\n        cin >> s >> t >> w;\n        tree[s].emplace_back(t,\
    \ w);\n        tree[t].emplace_back(s, w);\n    }\n    const auto ans = tree_diameter(tree);\n\
    \    cout << ans << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A\"\n\n\
    #include <iostream>\n#include \"lib/graph/tree_diameter.hpp\"\n\nint main() {\n\
    \    size_t n;\n    cin >> n;\n    using Edge = pair<size_t, int>;\n    vector\
    \ tree(n, vector<Edge>{});\n    for (size_t _ = 0; _ < n - 1; _++) {\n       \
    \ size_t s, t;\n        int w;\n        cin >> s >> t >> w;\n        tree[s].emplace_back(t,\
    \ w);\n        tree[t].emplace_back(s, w);\n    }\n    const auto ans = tree_diameter(tree);\n\
    \    cout << ans << \"\\n\";\n}\n"
  dependsOn:
  - lib/graph/tree_diameter.hpp
  isVerificationFile: true
  path: test/aoj/GRL_5_A.test.cpp
  requiredBy: []
  timestamp: '2021-09-29 22:27:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_5_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_A.test.cpp
- /verify/test/aoj/GRL_5_A.test.cpp.html
title: test/aoj/GRL_5_A.test.cpp
---
