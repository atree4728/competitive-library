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
    #include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_1, _2, _3,\
    \ name, ...) name\n#define rep1(n) for (decltype(n) _tmp = 0; _tmp < (n); _tmp++)\n\
    #define rep2(i, n) for (decltype(n) i = 0; i < (n); i++)\n#define rep3(i, a, b)\
    \ for (decltype(b) i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\nstruct IOSetup {\n    IOSetup() noexcept {\n\
    \        ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n        cout\
    \ << fixed << setprecision(10);\n        cerr << fixed << setprecision(10);\n\
    \    }\n} iosetup;\ntemplate<class T> bool chmax(T &a, const T &b) { return a\
    \ < b and (a = b, true); }\ntemplate<class T> bool chmin(T &a, const T &b) { return\
    \ a > b and (a = b, true); }\nusing i64 = long long;\nusing f64 = long double;\n\
    #line 4 \"lib/graph/ford_fulkerson.hpp\"\n\n/**\n * @brief MaxFlow(Ford-Fulkerson)\
    \ / \u6700\u5927\u8CBB\u7528\u6D41\n * @docs docs/ford_fulkerson.md\n*/\n\nstruct\
    \ FordFulkerson {\n  private:\n    struct Edge {\n        int to, from, cap, rev_ind;\n\
    \        Edge(int to, int from, int cap, int rev_ind):\n            to(to), from(from),\
    \ cap(cap), rev_ind(rev_ind) {}\n    };\n    vector<vector<Edge>> data;\n    explicit\
    \ FordFulkerson(const int n = 0):\n        data(n) {}\n    Edge &rev(const Edge\
    \ &e) { return data[e.to][e.rev_ind]; }\n    void run_flow(Edge &e, int f) {\n\
    \        e.cap -= f;\n        rev(e).cap += f;\n    }\n    int find(int v, const\
    \ int &t, int f, vector<bool> &seen) {\n        if (v == t) return f;\n      \
    \  seen[v] = true;\n        for (auto &&e: data[v])\n            if (not seen[e.to]\
    \ and e.cap > 0) {\n                int flow = find(e.to, t, min(f, e.cap), seen);\n\
    \                if (flow == 0) continue;\n                run_flow(e, flow);\n\
    \                return flow;\n            }\n        return 0;\n    }\n\n  public:\n\
    \    [[nodiscard]] size_t size() const { return std::size(data); }\n    vector<Edge>\
    \ &operator[](int i) { return data[i]; }\n    void add_edge(int from, int to,\
    \ int cap) {\n        int reg_ind = (int)data[from].size();\n        int rev_ind\
    \ = (int)data[to].size();\n        data[from].emplace_back(Edge{to, from, cap,\
    \ rev_ind});\n        data[to].emplace_back(Edge{from, to, 0, reg_ind});\n   \
    \ }\n    int max_flow(int s, int t) {\n        int res = 0;\n        while (true)\
    \ {\n            vector<bool> seen(data.size(), false);\n            int flow\
    \ = find(s, t, numeric_limits<int>::max(), seen);\n            if (flow == 0)\
    \ return res;\n            res += flow;\n        }\n    }\n};\n#line 4 \"test/aoj/GRL_6_A.test.cpp\"\
    \n\nint main() {\n    int v, e;\n    cin >> v >> e;\n    FordFulkerson graph(v);\n\
    \    while (e--) {\n        int ui, vi, ci;\n        cin >> ui >> vi >> ci;\n\
    \        graph.add_edge(ui, vi, ci);\n    }\n    int ans = graph.max_flow(0, v\
    \ - 1);\n    cout << ans << \"\\n\";\n}\n"
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
  timestamp: '2021-09-08 23:15:27+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_6_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_6_A.test.cpp
- /verify/test/aoj/GRL_6_A.test.cpp.html
title: test/aoj/GRL_6_A.test.cpp
---
