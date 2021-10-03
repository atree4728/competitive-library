#pragma once

#include <algorithm>
#include <cassert>
#include <vector>

struct StronglyConnectedComponents {
    template<class T> using vector = std::vector<T>;
    using usize = std::size_t;

    usize n;
    vector<vector<usize>> rev_graph;
    vector<vector<usize>> contracted;
    vector<usize> component;
    vector<usize> post_order;

    StronglyConnectedComponents(const vector<vector<usize>>& graph): n(std::size(graph)), rev_graph(n, vector<usize>{}), component(n, -1), seen(n, false) {
        for (usize v = 0; v < n; v++) {
            for (const auto& u: graph[v]) {
                rev_graph[u].push_back(v);
            }
        }
        for (usize v = 0; v < n; v++) dfs(v, graph);
        usize index = 0;
        std::reverse(std::begin(post_order), std::end(post_order));
        for (const auto& v: post_order)
            if (component[v] == (usize) -1) rev_dfs(v, index++);
        contracted.resize(index);
        for (usize i = 0; i < n; i++) {
            for (const auto& j: graph[i]) {
                const auto& [u, v] = std::pair{ component[i], component[j] };
                if (u != v) contracted[u].push_back(v);
            }
        }
    }
    usize& operator[](usize v) {
        return component[v];
    }

  private:
    vector<bool> seen;
    void dfs(usize v, const vector<vector<usize>>& graph) {
        if (seen[v]) return;
        seen[v] = true;
        for (const auto& u: graph[v]) dfs(u, graph);
        post_order.push_back(v);
    }
    void rev_dfs(usize v, usize index) {
        if (component[v] != (usize) -1) return;
        component[v] = index;
        for (const auto& u: rev_graph[v]) rev_dfs(u, index);
    }
};
