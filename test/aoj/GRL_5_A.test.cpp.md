---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/graph/tree_diameter.hpp
    title: "Diameter of a Tree / \u6728\u306E\u76F4\u5F84"
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
    \n\n#include <iostream>\n#line 2 \"lib/graph/tree_diameter.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <limits>\n#include <queue>\n#include <vector>\n\n\
    template<class T> std::vector<T> tree_diameter(const std::vector<std::vector<T>>&\
    \ tree) {\n    const T n = size(tree);\n    const auto furthest = [&](T s) {\n\
    \        std::vector<T> dist(n, static_cast<T>(-1));\n        dist[s] = 0;\n \
    \       std::queue<T> que{ { s } };\n        while (not empty(que)) {\n      \
    \      const T u = que.front();\n            que.pop();\n            for (const\
    \ T& v: tree[u]) {\n                if (dist[v] != static_cast<T>(-1)) continue;\n\
    \                dist[v] = dist[u] + 1;\n                que.emplace(v);\n   \
    \         }\n        }\n        const T f = distance(cbegin(dist), max_element(cbegin(dist),\
    \ cend(dist)));\n        std::vector<T> path{ f };\n        while (dist[path.back()]\
    \ != 0) {\n            for (const T& u: tree[path.back()]) {\n               \
    \ if (dist[u] + 1 == dist[path.back()]) {\n                    path.emplace_back(u);\n\
    \                    break;\n                }\n            }\n        }\n   \
    \     reverse(begin(path), end(path));\n        return path;\n    };\n    return\
    \ furthest(furthest(0).back());\n}\n#line 5 \"test/aoj/GRL_5_A.test.cpp\"\n\n\
    int main() {\n    using namespace std;\n    size_t n;\n    cin >> n;\n    using\
    \ Edge = pair<size_t, int>;\n    vector tree(n, vector<Edge>{});\n    for (size_t\
    \ _ = 0; _ < n - 1; _++) {\n        size_t s, t;\n        int w;\n        cin\
    \ >> s >> t >> w;\n        tree[s].emplace_back(t, w);\n        tree[t].emplace_back(s,\
    \ w);\n    }\n    const auto ans = size(tree_diameter(tree));\n    cout << ans\
    \ << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A\"\n\n\
    #include <iostream>\n#include \"lib/graph/tree_diameter.hpp\"\n\nint main() {\n\
    \    using namespace std;\n    size_t n;\n    cin >> n;\n    using Edge = pair<size_t,\
    \ int>;\n    vector tree(n, vector<Edge>{});\n    for (size_t _ = 0; _ < n - 1;\
    \ _++) {\n        size_t s, t;\n        int w;\n        cin >> s >> t >> w;\n\
    \        tree[s].emplace_back(t, w);\n        tree[t].emplace_back(s, w);\n  \
    \  }\n    const auto ans = size(tree_diameter(tree));\n    cout << ans << \"\\\
    n\";\n}\n"
  dependsOn:
  - lib/graph/tree_diameter.hpp
  isVerificationFile: true
  path: test/aoj/GRL_5_A.test.cpp
  requiredBy: []
  timestamp: '2022-09-04 00:42:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_5_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_A.test.cpp
- /verify/test/aoj/GRL_5_A.test.cpp.html
title: test/aoj/GRL_5_A.test.cpp
---
