---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/ford_fulkerson.hpp
    title: "Max flow(with Ford-Fulkerson) / \u6700\u5927\u8CBB\u7528\u6D41"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
  bundledCode: "#line 1 \"test/aoj/GRL_6_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \n\n#include <iostream>\n#line 2 \"lib/graph/ford_fulkerson.hpp\"\n\n#include\
    \ <limits>\n#include <vector>\n\nstruct FordFulkerson {\n    using size_t = std::size_t;\n\
    \    using flow_t = int;\n\n  private:\n    struct Edge {\n        size_t to,\
    \ from, rev_ind;\n        flow_t cap;\n        Edge(size_t to, size_t from, size_t\
    \ rev_ind, flow_t cap): to(to), from(from), rev_ind(rev_ind), cap(cap) {}\n  \
    \  };\n    std::vector<std::vector<Edge>> data;\n    Edge &rev(const Edge &e)\
    \ { return data[e.to][e.rev_ind]; }\n    void run_flow(Edge &e, flow_t f) {\n\
    \        e.cap -= f;\n        rev(e).cap += f;\n    }\n    flow_t find(const size_t\
    \ &v, const size_t &t, const flow_t &f, std::vector<bool> &seen) {\n        if\
    \ (v == t) return f;\n        seen[v] = true;\n        for (auto &&e: data[v])\
    \ {\n            if (seen[e.to] or e.cap <= 0) continue;\n            flow_t flow\
    \ = find(e.to, t, std::min(f, e.cap), seen);\n            if (flow == 0) continue;\n\
    \            run_flow(e, flow);\n            return flow;\n        }\n       \
    \ return 0;\n    }\n\n  public:\n    explicit FordFulkerson(const size_t n = 0):\
    \ data(n) {}\n    [[nodiscard]] size_t size() const { return std::size(data);\
    \ }\n    std::vector<Edge> &operator[](size_t i) { return data[i]; }\n    void\
    \ add_edge(size_t from, size_t to, flow_t cap) {\n        size_t reg_ind = data[from].size();\n\
    \        size_t rev_ind = data[to].size();\n        data[from].emplace_back(Edge{\
    \ to, from, rev_ind, cap });\n        data[to].emplace_back(Edge{ from, to, reg_ind,\
    \ 0 });\n    }\n    flow_t max_flow(size_t s, size_t t) {\n        flow_t res\
    \ = 0;\n        while (true) {\n            std::vector<bool> seen(data.size(),\
    \ false);\n            flow_t flow = find(s, t, std::numeric_limits<int>::max(),\
    \ seen);\n            if (flow == 0) return res;\n            res += flow;\n \
    \       }\n    }\n};\n#line 5 \"test/aoj/GRL_6_A.test.cpp\"\n\nint main() {\n\
    \    using namespace std;\n    size_t v, e;\n    cin >> v >> e;\n    FordFulkerson\
    \ graph(v);\n    while (e--) {\n        size_t ui, vi;\n        int ci;\n    \
    \    cin >> ui >> vi >> ci;\n        graph.add_edge(ui, vi, ci);\n    }\n    int\
    \ ans = graph.max_flow(0, v - 1);\n    cout << ans << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \n\n#include <iostream>\n#include \"lib/graph/ford_fulkerson.hpp\"\n\nint main()\
    \ {\n    using namespace std;\n    size_t v, e;\n    cin >> v >> e;\n    FordFulkerson\
    \ graph(v);\n    while (e--) {\n        size_t ui, vi;\n        int ci;\n    \
    \    cin >> ui >> vi >> ci;\n        graph.add_edge(ui, vi, ci);\n    }\n    int\
    \ ans = graph.max_flow(0, v - 1);\n    cout << ans << \"\\n\";\n}\n"
  dependsOn:
  - lib/graph/ford_fulkerson.hpp
  isVerificationFile: true
  path: test/aoj/GRL_6_A.test.cpp
  requiredBy: []
  timestamp: '2021-10-03 22:09:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_6_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_6_A.test.cpp
- /verify/test/aoj/GRL_6_A.test.cpp.html
title: test/aoj/GRL_6_A.test.cpp
---
