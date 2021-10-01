#pragma once

#include <algorithm>
#include <vector>

/**
 * @brief Lowlink / 橋・関節点
 * @docs docs/lowlink.md
 */

struct Lowlink {
    using usize = std::size_t;
    template<class T> using vector = std::vector<T>;
    using edge_t = std::pair<usize, usize>;

    usize n;
    vector<usize> order, lowlink, articulation;
    vector<edge_t> bridge;
    Lowlink(const vector<vector<usize>> &graph): n(size(graph)), order(n, 0), lowlink(n, 0), seen(n, false) {
        usize time = 0;
        for (usize i = 0; i < n; i++)
            if (not seen[i]) time = dfs(i, i, time, graph);
        // When you comment below two lines out, the complexity is $\mathcal{O}(N \log N)$.
        // std::sort(articulation.begin(), articulation.end());
        // std::sort(bridge.begin(), bridge.end());
    }

  private:
    vector<bool> seen;
    usize dfs(const usize &v, const usize &prev, usize &time, const vector<vector<usize>> &graph) {
        seen[v] = true;
        order[v] = time++;
        lowlink[v] = order[v];
        bool is_aps = false;
        int count = 0;
        for (const auto &u: graph[v]) {
            if (not seen[u]) {
                count++;
                time = dfs(u, v, time, graph);
                lowlink[v] = std::min(lowlink[v], lowlink[u]);
                if (prev != v && order[v] <= lowlink[u]) is_aps = true;
                if (order[v] < lowlink[u]) bridge.emplace_back(std::minmax(u, v));
            } else if (u != prev) {
                lowlink[v] = std::min(lowlink[v], order[u]);
            }
        }
        if (prev == v && count >= 2) is_aps = true;
        if (is_aps) articulation.push_back(v);
        return time;
    }
};
