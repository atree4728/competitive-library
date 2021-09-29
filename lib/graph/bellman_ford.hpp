#pragma once

#include "../include.hpp"

/**
 * @brief Bellman-Ford Algorithm / 負辺を許す単一始点最短経路問題
 * @docs docs/bellman_ford.md
*/

template<typename T> vector<T> bellman_ford(vector<vector<pair<size_t, T>>> const& graph, size_t root) {
    static_assert(is_signed_v<T>);
    constexpr T INF = numeric_limits<T>::max();
    using Edge = tuple<size_t, size_t, T>;
    auto chmin = [](auto& a, const auto& b) { return a > b and (a = b, true); };
    vector<T> dist(size(graph), INF);
    dist[root] = 0;
    vector<Edge> edges{};
    rep(i, size(graph)) for (const auto& [j, w]: graph[i]) edges.emplace_back(Edge{ i, j, w });
    rep(i, size(graph)) {
        for (const auto& [u, v, w]: edges)
            if (dist[u] != INF and chmin(dist[v], dist[u] + w) and i + 1 == size(graph)) return {};
    }
    return dist;
}
