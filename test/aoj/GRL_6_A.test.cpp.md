---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/graph/ford_fulkerson.hpp
    title: "Max flow(with Ford-Fulkerson) / \u6700\u5927\u8CBB\u7528\u6D41"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
  bundledCode: "#line 1 \"test/aoj/GRL_6_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \n\n#line 2 \"lib/graph/ford_fulkerson.hpp\"\n\n#line 2 \"lib/include.hpp\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_NULL, _2, _3,\
    \ name, ...) name\n#define rep1(i, n) for (remove_const_t<remove_reference_t<decltype(n)>>\
    \ i = 0; i < (n); i++)\n#define rep2(i, a, b) for (remove_const_t<remove_reference_t<decltype(b)>>\
    \ i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)\n\
    using size_type = size_t;\n#line 4 \"lib/graph/ford_fulkerson.hpp\"\n\n/**\n *\
    \ @brief MaxFlow(Ford-Fulkerson) / \u6700\u5927\u8CBB\u7528\u6D41\n * @docs docs/ford_fulkerson.md\n\
    */\n\nstruct FordFulkerson {\n    using flow_t = int;\n\n  private:\n    struct\
    \ Edge {\n        size_type to, from, rev_ind;\n        flow_t cap;\n        Edge(size_type\
    \ to, size_type from, size_type rev_ind, flow_t cap):\n            to(to), from(from),\
    \ rev_ind(rev_ind), cap(cap) {}\n    };\n    vector<vector<Edge>> data;\n    Edge\
    \ &rev(const Edge e) { return data[e.to][e.rev_ind]; }\n    void run_flow(Edge\
    \ e, flow_t f) {\n        e.cap -= f;\n        rev(e).cap += f;\n    }\n    flow_t\
    \ find(size_type v, const size_type t, flow_t f, vector<bool> &seen) {\n     \
    \   if (v == t) return f;\n        seen[v] = true;\n        for (auto &&e: data[v])\n\
    \            if (not seen[e.to] and e.cap > 0) {\n                flow_t flow\
    \ = find(e.to, t, min(f, e.cap), seen);\n                if (flow == 0) continue;\n\
    \                run_flow(e, flow);\n                return flow;\n          \
    \  }\n        return 0;\n    }\n\n  public:\n    explicit FordFulkerson(const\
    \ size_type n = 0):\n        data(n) {}\n    [[nodiscard]] size_t size() const\
    \ { return std::size(data); }\n    vector<Edge> &operator[](size_type i) { return\
    \ data[i]; }\n    void add_edge(size_type from, size_type to, flow_t cap) {\n\
    \        size_type reg_ind = data[from].size();\n        size_type rev_ind = data[to].size();\n\
    \        data[from].emplace_back(Edge{to, from, rev_ind, cap});\n        data[to].emplace_back(Edge{from,\
    \ to, reg_ind, 0});\n    }\n    flow_t max_flow(size_type s, size_type t) {\n\
    \        flow_t res = 0;\n        while (true) {\n            vector<bool> seen(data.size(),\
    \ false);\n            flow_t flow = find(s, t, numeric_limits<int>::max(), seen);\n\
    \            if (flow == 0) return res;\n            res += flow;\n        }\n\
    \    }\n};\n#line 4 \"test/aoj/GRL_6_A.test.cpp\"\n\nint main() {\n    int v,\
    \ e;\n    cin >> v >> e;\n    FordFulkerson graph(v);\n    while (e--) {\n   \
    \     int ui, vi, ci;\n        cin >> ui >> vi >> ci;\n        graph.add_edge(ui,\
    \ vi, ci);\n    }\n    int ans = graph.max_flow(0, v - 1);\n    cout << ans <<\
    \ \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \n\n#include \"lib/graph/ford_fulkerson.hpp\"\n\nint main() {\n    int v, e;\n\
    \    cin >> v >> e;\n    FordFulkerson graph(v);\n    while (e--) {\n        int\
    \ ui, vi, ci;\n        cin >> ui >> vi >> ci;\n        graph.add_edge(ui, vi,\
    \ ci);\n    }\n    int ans = graph.max_flow(0, v - 1);\n    cout << ans << \"\\\
    n\";\n}"
  dependsOn:
  - lib/graph/ford_fulkerson.hpp
  - lib/include.hpp
  isVerificationFile: true
  path: test/aoj/GRL_6_A.test.cpp
  requiredBy: []
  timestamp: '2021-09-29 20:09:01+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_6_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_6_A.test.cpp
- /verify/test/aoj/GRL_6_A.test.cpp.html
title: test/aoj/GRL_6_A.test.cpp
---
