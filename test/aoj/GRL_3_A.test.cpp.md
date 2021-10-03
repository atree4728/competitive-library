---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/lowlink.hpp
    title: "Lowlink / \u6A4B\u30FB\u95A2\u7BC0\u70B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_A
  bundledCode: "#line 1 \"test/aoj/GRL_3_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_A\"\
    \n\n#include <iostream>\n#line 2 \"lib/graph/lowlink.hpp\"\n\n#include <algorithm>\n\
    #include <vector>\n\nstruct Lowlink {\n    using usize = std::size_t;\n    template<class\
    \ T> using vector = std::vector<T>;\n    using edge_t = std::pair<usize, usize>;\n\
    \n    usize n;\n    vector<usize> order, lowlink, articulation;\n    vector<edge_t>\
    \ bridge;\n    Lowlink(const vector<vector<usize>> &graph): n(size(graph)), order(n,\
    \ 0), lowlink(n, 0), seen(n, false) {\n        usize time = 0;\n        for (usize\
    \ i = 0; i < n; i++)\n            if (not seen[i]) time = dfs(i, i, time, graph);\n\
    \        // When you comment below two lines out, the complexity is $\\mathcal{O}(N\
    \ \\log N)$.\n        // std::sort(articulation.begin(), articulation.end());\n\
    \        // std::sort(bridge.begin(), bridge.end());\n    }\n\n  private:\n  \
    \  vector<bool> seen;\n    usize dfs(const usize &v, const usize &prev, usize\
    \ &time, const vector<vector<usize>> &graph) {\n        seen[v] = true;\n    \
    \    order[v] = time++;\n        lowlink[v] = order[v];\n        bool is_aps =\
    \ false;\n        int count = 0;\n        for (const auto &u: graph[v]) {\n  \
    \          if (not seen[u]) {\n                count++;\n                time\
    \ = dfs(u, v, time, graph);\n                lowlink[v] = std::min(lowlink[v],\
    \ lowlink[u]);\n                if (prev != v && order[v] <= lowlink[u]) is_aps\
    \ = true;\n                if (order[v] < lowlink[u]) bridge.emplace_back(std::minmax(u,\
    \ v));\n            } else if (u != prev) {\n                lowlink[v] = std::min(lowlink[v],\
    \ order[u]);\n            }\n        }\n        if (prev == v && count >= 2) is_aps\
    \ = true;\n        if (is_aps) articulation.push_back(v);\n        return time;\n\
    \    }\n};\n#line 5 \"test/aoj/GRL_3_A.test.cpp\"\n\nint main() {\n    using namespace\
    \ std;\n    size_t v, e;\n    cin >> v >> e;\n    vector graph(v, vector<size_t>{});\n\
    \    while (e--) {\n        size_t s, t;\n        cin >> s >> t;\n        graph[s].push_back(t);\n\
    \        graph[t].push_back(s);\n    }\n    auto articulation = Lowlink(graph).articulation;\n\
    \    sort(begin(articulation), end(articulation));\n    for (const auto &u: articulation)\
    \ {\n        cout << u << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_A\"\n\n\
    #include <iostream>\n#include \"lib/graph/lowlink.hpp\"\n\nint main() {\n    using\
    \ namespace std;\n    size_t v, e;\n    cin >> v >> e;\n    vector graph(v, vector<size_t>{});\n\
    \    while (e--) {\n        size_t s, t;\n        cin >> s >> t;\n        graph[s].push_back(t);\n\
    \        graph[t].push_back(s);\n    }\n    auto articulation = Lowlink(graph).articulation;\n\
    \    sort(begin(articulation), end(articulation));\n    for (const auto &u: articulation)\
    \ {\n        cout << u << \"\\n\";\n    }\n}\n"
  dependsOn:
  - lib/graph/lowlink.hpp
  isVerificationFile: true
  path: test/aoj/GRL_3_A.test.cpp
  requiredBy: []
  timestamp: '2021-10-03 22:09:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_3_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_3_A.test.cpp
- /verify/test/aoj/GRL_3_A.test.cpp.html
title: test/aoj/GRL_3_A.test.cpp
---
