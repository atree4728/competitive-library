---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/graph/tree_diameter.hpp
    title: "Diameter of a Tree / \u6728\u306E\u76F4\u5F84"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A
  bundledCode: "#line 1 \"test/aoj/GRL_5_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A\"\
    \n\n#line 2 \"lib/graph/tree_diameter.hpp\"\n\n#line 2 \"lib/include.hpp\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_NULL, _2, _3,\
    \ name, ...) name\n#define rep1(i, n) for (remove_const_t<remove_reference_t<decltype(n)>>\
    \ i = 0; i < (n); i++)\n#define rep2(i, a, b) for (remove_const_t<remove_reference_t<decltype(b)>>\
    \ i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)\n\
    using size_type = size_t;\n#line 4 \"lib/graph/tree_diameter.hpp\"\n\n/**\n *\
    \ @brief Diameter of a Tree / \u6728\u306E\u76F4\u5F84\n * @docs docs/tree_diameter.md\n\
    \ */\n\ntemplate<typename T> T tree_diameter(const vector<vector<pair<size_type,\
    \ T>>> &tree) {\n    const size_type n = size(tree);\n    const T INF = numeric_limits<T>::max();\n\
    \    vector<T> dist(n, INF);\n    auto dfs = [&](auto &&self, size_type v, size_type\
    \ prev) -> void {\n        for (const auto [u, w]: tree[v])\n            if (u\
    \ != prev) {\n                assert(dist[u] == INF); // graph must be a tree\n\
    \                dist[u] = dist[v] + w;\n                self(self, u, v);\n \
    \           }\n    };\n    dist[0] = 0;\n    dfs(dfs, 0, 0);\n    size_type farthest\
    \ = distance(begin(dist), max_element(begin(dist), end(dist)));\n    assert(dist[farthest]\
    \ != INF); // graph must be a tree\n    fill(begin(dist), end(dist), INF);\n \
    \   dist[farthest] = 0;\n    dfs(dfs, farthest, 0);\n    T ans = *max_element(begin(dist),\
    \ end(dist));\n    return ans;\n}\n#line 4 \"test/aoj/GRL_5_A.test.cpp\"\n\nint\
    \ main() {\n    int n;\n    cin >> n;\n    using Edge = pair<int, int>;\n    vector\
    \ tree(n, vector<Edge>{});\n    rep(i, n - 1) {\n        int s, t, w;\n      \
    \  cin >> s >> t >> w;\n        tree[s].emplace_back(t, w);\n        tree[t].emplace_back(s,\
    \ w);\n    }\n    const auto ans = tree_diameter(tree);\n    cout << ans << \"\
    \\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A\"\n\n\
    #include \"lib/graph/tree_diameter.hpp\"\n\nint main() {\n    int n;\n    cin\
    \ >> n;\n    using Edge = pair<int, int>;\n    vector tree(n, vector<Edge>{});\n\
    \    rep(i, n - 1) {\n        int s, t, w;\n        cin >> s >> t >> w;\n    \
    \    tree[s].emplace_back(t, w);\n        tree[t].emplace_back(s, w);\n    }\n\
    \    const auto ans = tree_diameter(tree);\n    cout << ans << \"\\n\";\n}"
  dependsOn:
  - lib/graph/tree_diameter.hpp
  - lib/include.hpp
  isVerificationFile: true
  path: test/aoj/GRL_5_A.test.cpp
  requiredBy: []
  timestamp: '2021-09-29 20:09:01+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_5_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_A.test.cpp
- /verify/test/aoj/GRL_5_A.test.cpp.html
title: test/aoj/GRL_5_A.test.cpp
---
