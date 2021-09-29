#pragma once

#include "../include.hpp"

/**
 * @brief MaxFlow(Ford-Fulkerson) / 最大費用流
 * @docs docs/ford_fulkerson.md
*/

struct FordFulkerson {
    using flow_t = int;

  private:
    struct Edge {
        size_type to, from, rev_ind;
        flow_t cap;
        Edge(size_type to, size_type from, size_type rev_ind, flow_t cap):
            to(to), from(from), rev_ind(rev_ind), cap(cap) {}
    };
    vector<vector<Edge>> data;
    Edge &rev(const Edge e) { return data[e.to][e.rev_ind]; }
    void run_flow(Edge e, flow_t f) {
        e.cap -= f;
        rev(e).cap += f;
    }
    flow_t find(size_type v, const size_type t, flow_t f, vector<bool> &seen) {
        if (v == t) return f;
        seen[v] = true;
        for (auto &&e: data[v])
            if (not seen[e.to] and e.cap > 0) {
                flow_t flow = find(e.to, t, min(f, e.cap), seen);
                if (flow == 0) continue;
                run_flow(e, flow);
                return flow;
            }
        return 0;
    }

  public:
    explicit FordFulkerson(const size_type n = 0):
        data(n) {}
    [[nodiscard]] size_t size() const { return std::size(data); }
    vector<Edge> &operator[](size_type i) { return data[i]; }
    void add_edge(size_type from, size_type to, flow_t cap) {
        size_type reg_ind = data[from].size();
        size_type rev_ind = data[to].size();
        data[from].emplace_back(Edge{to, from, rev_ind, cap});
        data[to].emplace_back(Edge{from, to, reg_ind, 0});
    }
    flow_t max_flow(size_type s, size_type t) {
        flow_t res = 0;
        while (true) {
            vector<bool> seen(data.size(), false);
            flow_t flow = find(s, t, numeric_limits<int>::max(), seen);
            if (flow == 0) return res;
            res += flow;
        }
    }
};
