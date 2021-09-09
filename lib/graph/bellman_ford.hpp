#pragma once

#include "../include.hpp"

/**
 * @brief Bellman-Ford Algorithm / 負辺を許す単一始点最短経路問題
 * @docs docs/bellman_ford.md
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
