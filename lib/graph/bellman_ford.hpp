#pragma once

#include "../include.hpp"

/**
 * @brief Bellman-Ford's Algorithm
 * @note Solve SSSP in $O(|V||E|)$ about graph $G = (V, E)$. It's accepted to exist edges which have negative cost.
 * @nate Return an empty vector when given graph has a negative cycle.
 * @note numeric_limits<T>::max() for unreachable nodes.
*/

template<typename T> vector<T> bellman_ford(vector<vector<pair<int, T>>> const &graph, int root) {
    static_assert(is_signed<T>::value, "template parameter T must be signed type!");
    constexpr T INF = numeric_limits<T>::max();
    using Edge = tuple<int, int, T>;
    vector<T> dist(size(graph), INF);
    dist[root] = 0;
    vector<Edge> edges{};
    rep(i, size(graph)) for (const auto &[j, w]: graph[i]) edges.emplace_back(Edge{i, j, w});
    rep(i, size(graph)) {
        for (const auto &[u, v, w]: edges)
            if (dist[u] != INF and chmin(dist[v], dist[u] + w) and i + 1 == size(graph)) return {};
    }
    return dist;
}
