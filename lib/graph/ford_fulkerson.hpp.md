---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_6_A.test.cpp
    title: test/aoj/GRL_6_A.test.cpp
  - icon: ':x:'
    path: test/aoj/GRL_7_A.test.cpp
    title: test/aoj/GRL_7_A.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/ford_fulkerson.md
    document_title: "MaxFlow(Ford-Fulkerson) / \u6700\u5927\u8CBB\u7528\u6D41"
    links: []
  bundledCode: "#line 2 \"lib/graph/ford_fulkerson.hpp\"\n\n#line 2 \"lib/include.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_1, _2,\
    \ _3, name, ...) name\n#define rep1(n) for (decltype(n) _tmp = 0; _tmp < (n);\
    \ _tmp++)\n#define rep2(i, n) for (decltype(n) i = 0; i < (n); i++)\n#define rep3(i,\
    \ a, b) for (decltype(b) i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__,\
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
    \ return res;\n            res += flow;\n        }\n    }\n};\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief MaxFlow(Ford-Fulkerson)\
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
    \ return res;\n            res += flow;\n        }\n    }\n};\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/graph/ford_fulkerson.hpp
  requiredBy: []
  timestamp: '2021-09-08 23:15:27+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL_6_A.test.cpp
  - test/aoj/GRL_7_A.test.cpp
documentation_of: lib/graph/ford_fulkerson.hpp
layout: document
title: "Max flow(with Ford-Fulkerson) / \u6700\u5927\u8CBB\u7528\u6D41"
---

## 概要

Ford-Fulkerson 法を用いて最大費用流問題を解く。

## 使い方

- `FordFulkerson graph()`: 空グラフを定義する。
- `FordFulkerson graph(n)`: $n$頂点のグラフを定義する。
- `graph.add_edge(u, v, c)`: 頂点$u$から頂点$v$に容量$c$の辺を張る。
- `graph.size()`: グラフの頂点数を`std::size_t`で返す。
- `graph.max_flow(s, t)`: 始点$s$、終点$t$についての最大費用流問題を解く。

## 計算量

$f$を最大費用流としたときに、$\mathcal{O}(fE)$。一回の`find`で$\mathcal{O}(E)$を要し、かつそれによって暫定流量は1以上増えるため、`find`
の回数は$f$で抑えられるためである。このように「数値に関しては多項式時間ではあるが、実際には多項式時間では無い計算量」を**擬多項式時間**と呼ぶ。