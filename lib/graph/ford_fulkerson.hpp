#pragma once

#include <limits>
#include <vector>

/**
 * @brief MaxFlow(Ford-Fulkerson) / 最大費用流
 * @docs docs/ford_fulkerson.md
*/

struct FordFulkerson {
    using size_t = std::size_t;
    using flow_t = int;

  private:
    struct Edge {
        size_t to, from, rev_ind;
        flow_t cap;
        Edge(size_t to, size_t from, size_t rev_ind, flow_t cap): to(to), from(from), rev_ind(rev_ind), cap(cap) {}
    };
    std::vector<std::vector<Edge>> data;
    Edge &rev(const Edge &e) { return data[e.to][e.rev_ind]; }
    void run_flow(Edge &e, flow_t f) {
        e.cap -= f;
        rev(e).cap += f;
    }
    flow_t find(const size_t &v, const size_t &t, const flow_t &f, std::vector<bool> &seen) {
        if (v == t) return f;
        seen[v] = true;
        for (auto &&e: data[v]) {
            if (seen[e.to] or e.cap <= 0) continue;
            flow_t flow = find(e.to, t, std::min(f, e.cap), seen);
            if (flow == 0) continue;
            run_flow(e, flow);
            return flow;
        }
        return 0;
    }

  public:
    explicit FordFulkerson(const size_t n = 0): data(n) {}
    [[nodiscard]] size_t size() const { return std::size(data); }
    std::vector<Edge> &operator[](size_t i) { return data[i]; }
    void add_edge(size_t from, size_t to, flow_t cap) {
        size_t reg_ind = data[from].size();
        size_t rev_ind = data[to].size();
        data[from].emplace_back(Edge{ to, from, rev_ind, cap });
        data[to].emplace_back(Edge{ from, to, reg_ind, 0 });
    }
    flow_t max_flow(size_t s, size_t t) {
        flow_t res = 0;
        while (true) {
            std::vector<bool> seen(data.size(), false);
            flow_t flow = find(s, t, std::numeric_limits<int>::max(), seen);
            if (flow == 0) return res;
            res += flow;
        }
    }
};
