---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_A.test.cpp
    title: test/aoj/GRL_6_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_7_A.test.cpp
    title: test/aoj/GRL_7_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/graph/ford_fulkerson.hpp\"\n\n#include <limits>\n#include\
    \ <vector>\n\nstruct FordFulkerson {\n    using size_t = std::size_t;\n    using\
    \ flow_t = int;\n\n  private:\n    struct Edge {\n        size_t to, from, rev_ind;\n\
    \        flow_t cap;\n        Edge(size_t to, size_t from, size_t rev_ind, flow_t\
    \ cap): to(to), from(from), rev_ind(rev_ind), cap(cap) {}\n    };\n    std::vector<std::vector<Edge>>\
    \ data;\n    Edge &rev(const Edge &e) { return data[e.to][e.rev_ind]; }\n    void\
    \ run_flow(Edge &e, flow_t f) {\n        e.cap -= f;\n        rev(e).cap += f;\n\
    \    }\n    flow_t find(const size_t &v, const size_t &t, const flow_t &f, std::vector<bool>\
    \ &seen) {\n        if (v == t) return f;\n        seen[v] = true;\n        for\
    \ (auto &&e: data[v]) {\n            if (seen[e.to] or e.cap <= 0) continue;\n\
    \            flow_t flow = find(e.to, t, std::min(f, e.cap), seen);\n        \
    \    if (flow == 0) continue;\n            run_flow(e, flow);\n            return\
    \ flow;\n        }\n        return 0;\n    }\n\n  public:\n    explicit FordFulkerson(const\
    \ size_t n = 0): data(n) {}\n    [[nodiscard]] size_t size() const { return std::size(data);\
    \ }\n    std::vector<Edge> &operator[](size_t i) { return data[i]; }\n    void\
    \ add_edge(size_t from, size_t to, flow_t cap) {\n        size_t reg_ind = data[from].size();\n\
    \        size_t rev_ind = data[to].size();\n        data[from].emplace_back(Edge{\
    \ to, from, rev_ind, cap });\n        data[to].emplace_back(Edge{ from, to, reg_ind,\
    \ 0 });\n    }\n    flow_t max_flow(size_t s, size_t t) {\n        flow_t res\
    \ = 0;\n        while (true) {\n            std::vector<bool> seen(data.size(),\
    \ false);\n            flow_t flow = find(s, t, std::numeric_limits<int>::max(),\
    \ seen);\n            if (flow == 0) return res;\n            res += flow;\n \
    \       }\n    }\n};\n"
  code: "#pragma once\n\n#include <limits>\n#include <vector>\n\nstruct FordFulkerson\
    \ {\n    using size_t = std::size_t;\n    using flow_t = int;\n\n  private:\n\
    \    struct Edge {\n        size_t to, from, rev_ind;\n        flow_t cap;\n \
    \       Edge(size_t to, size_t from, size_t rev_ind, flow_t cap): to(to), from(from),\
    \ rev_ind(rev_ind), cap(cap) {}\n    };\n    std::vector<std::vector<Edge>> data;\n\
    \    Edge &rev(const Edge &e) { return data[e.to][e.rev_ind]; }\n    void run_flow(Edge\
    \ &e, flow_t f) {\n        e.cap -= f;\n        rev(e).cap += f;\n    }\n    flow_t\
    \ find(const size_t &v, const size_t &t, const flow_t &f, std::vector<bool> &seen)\
    \ {\n        if (v == t) return f;\n        seen[v] = true;\n        for (auto\
    \ &&e: data[v]) {\n            if (seen[e.to] or e.cap <= 0) continue;\n     \
    \       flow_t flow = find(e.to, t, std::min(f, e.cap), seen);\n            if\
    \ (flow == 0) continue;\n            run_flow(e, flow);\n            return flow;\n\
    \        }\n        return 0;\n    }\n\n  public:\n    explicit FordFulkerson(const\
    \ size_t n = 0): data(n) {}\n    [[nodiscard]] size_t size() const { return std::size(data);\
    \ }\n    std::vector<Edge> &operator[](size_t i) { return data[i]; }\n    void\
    \ add_edge(size_t from, size_t to, flow_t cap) {\n        size_t reg_ind = data[from].size();\n\
    \        size_t rev_ind = data[to].size();\n        data[from].emplace_back(Edge{\
    \ to, from, rev_ind, cap });\n        data[to].emplace_back(Edge{ from, to, reg_ind,\
    \ 0 });\n    }\n    flow_t max_flow(size_t s, size_t t) {\n        flow_t res\
    \ = 0;\n        while (true) {\n            std::vector<bool> seen(data.size(),\
    \ false);\n            flow_t flow = find(s, t, std::numeric_limits<int>::max(),\
    \ seen);\n            if (flow == 0) return res;\n            res += flow;\n \
    \       }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/ford_fulkerson.hpp
  requiredBy: []
  timestamp: '2021-10-03 22:09:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_7_A.test.cpp
  - test/aoj/GRL_6_A.test.cpp
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