---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/strongly_connected_components.hpp
    title: "Strongly Connected Components / \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/library-checker/scc.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/scc\"\n\n#include <iostream>\n#line 2 \"lib/graph/strongly_connected_components.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\n/**\n * @brief\
    \ Strongly Connected Components / \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n\
    \ * @docs docs/strongly_connected_components.md\n */\n\nstruct StronglyConnectedComponents\
    \ {\n    template<class T> using vector = std::vector<T>;\n    using usize = std::size_t;\n\
    \n    usize n;\n    vector<vector<usize>> rev_graph;\n    vector<vector<usize>>\
    \ contracted;\n    vector<usize> component;\n    vector<usize> post_order;\n\n\
    \    StronglyConnectedComponents(const vector<vector<usize>>& graph): n(std::size(graph)),\
    \ rev_graph(n, vector<usize>{}), component(n, -1), seen(n, false) {\n        for\
    \ (usize v = 0; v < n; v++) {\n            for (const auto& u: graph[v]) {\n \
    \               rev_graph[u].push_back(v);\n            }\n        }\n       \
    \ for (usize v = 0; v < n; v++) dfs(v, graph);\n        usize index = 0;\n   \
    \     std::reverse(std::begin(post_order), std::end(post_order));\n        for\
    \ (const auto& v: post_order)\n            if (component[v] == (usize) -1) rev_dfs(v,\
    \ index++);\n        contracted.resize(index);\n        for (usize i = 0; i <\
    \ n; i++) {\n            for (const auto& j: graph[i]) {\n                const\
    \ auto& [u, v] = std::pair{ component[i], component[j] };\n                if\
    \ (u != v) contracted[u].push_back(v);\n            }\n        }\n    }\n    usize&\
    \ operator[](usize v) {\n        return component[v];\n    }\n\n  private:\n \
    \   vector<bool> seen;\n    void dfs(usize v, const vector<vector<usize>>& graph)\
    \ {\n        if (seen[v]) return;\n        seen[v] = true;\n        for (const\
    \ auto& u: graph[v]) dfs(u, graph);\n        post_order.push_back(v);\n    }\n\
    \    void rev_dfs(usize v, usize index) {\n        if (component[v] != (usize)\
    \ -1) return;\n        component[v] = index;\n        for (const auto& u: rev_graph[v])\
    \ rev_dfs(u, index);\n    }\n};\n#line 5 \"test/library-checker/scc.test.cpp\"\
    \n\nint main() {\n    using namespace std;\n    size_t n, m;\n    cin >> n >>\
    \ m;\n    vector graph(n, vector<size_t>{});\n    while (m--) {\n        size_t\
    \ a, b;\n        cin >> a >> b;\n        graph[a].push_back(b);\n    }\n    auto\
    \ scc = StronglyConnectedComponents(graph);\n    vector ans(size(scc.contracted),\
    \ vector<size_t>{});\n    for (size_t v = 0; v < n; v++) ans[scc[v]].push_back(v);\n\
    \    cout << size(scc.contracted) << \"\\n\";\n    for (size_t i = 0; i < size(scc.contracted);\
    \ i++) {\n        cout << size(ans[i]);\n        for (const auto& ai: ans[i])\
    \ cout << \" \" << ai;\n        cout << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include <iostream>\n\
    #include \"lib/graph/strongly_connected_components.hpp\"\n\nint main() {\n   \
    \ using namespace std;\n    size_t n, m;\n    cin >> n >> m;\n    vector graph(n,\
    \ vector<size_t>{});\n    while (m--) {\n        size_t a, b;\n        cin >>\
    \ a >> b;\n        graph[a].push_back(b);\n    }\n    auto scc = StronglyConnectedComponents(graph);\n\
    \    vector ans(size(scc.contracted), vector<size_t>{});\n    for (size_t v =\
    \ 0; v < n; v++) ans[scc[v]].push_back(v);\n    cout << size(scc.contracted) <<\
    \ \"\\n\";\n    for (size_t i = 0; i < size(scc.contracted); i++) {\n        cout\
    \ << size(ans[i]);\n        for (const auto& ai: ans[i]) cout << \" \" << ai;\n\
    \        cout << \"\\n\";\n    }\n}\n"
  dependsOn:
  - lib/graph/strongly_connected_components.hpp
  isVerificationFile: true
  path: test/library-checker/scc.test.cpp
  requiredBy: []
  timestamp: '2021-10-02 00:32:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/scc.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/scc.test.cpp
- /verify/test/library-checker/scc.test.cpp.html
title: test/library-checker/scc.test.cpp
---
