#pragma once

#include "../include.hpp"

/**
 * @brief MaxFlow(Ford-Fulkerson) / 最大費用流
 * @docs docs/ford_fulkerson.md
*/

struct FordFulkerson {
  private:
    struct Edge {
        int to, from, cap, rev_ind;
        Edge(int to, int from, int cap, int rev_ind):
            to(to), from(from), cap(cap), rev_ind(rev_ind) {}
    };
    vector<vector<Edge>> data;
    explicit FordFulkerson(const int n = 0):
        data(n) {}
    Edge &rev(const Edge &e) { return data[e.to][e.rev_ind]; }
    void run_flow(Edge &e, int f) {
        e.cap -= f;
        rev(e).cap += f;
    }
    int find(int v, const int &t, int f, vector<bool> &seen) {
        if (v == t) return f;
        seen[v] = true;
        for (auto &&e: data[v])
            if (not seen[e.to] and e.cap > 0) {
                int flow = find(e.to, t, min(f, e.cap), seen);
                if (flow == 0) continue;
                run_flow(e, flow);
                return flow;
            }
        return 0;
    }

  public:
    [[nodiscard]] size_t size() const { return std::size(data); }
    vector<Edge> &operator[](int i) { return data[i]; }
    void add_edge(int from, int to, int cap) {
        int reg_ind = (int)data[from].size();
        int rev_ind = (int)data[to].size();
        data[from].emplace_back(Edge{to, from, cap, rev_ind});
        data[to].emplace_back(Edge{from, to, 0, reg_ind});
    }
    int max_flow(int s, int t) {
        int res = 0;
        while (true) {
            vector<bool> seen(data.size(), false);
            int flow = find(s, t, numeric_limits<int>::max(), seen);
            if (flow == 0) return res;
            res += flow;
        }
    }
};
