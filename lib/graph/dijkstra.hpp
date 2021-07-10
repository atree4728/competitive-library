#pragma once

#include "../include.hpp"

/**
 * @brief Dijkstra's Algorithm
 * @note Find SSSP;Single Source Shortest Path in $O(|E|log|V|)$. There must be no negative edges. Return -1 for unreachable vertex.
 */

template<class T = i64> vector<T> dijkstra(vector<vector<pair<size_t, T>>> const& graph, size_t s) {
    static_assert(is_signed<T>::value, "template parameter T must be signed type");
    using P = pair<T, size_t>;
    constexpr T INF = numeric_limits<T>::max() / 2;
    vector<T> dist(size(graph), INF);
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({dist[s] = 0, s});
    while (not empty(pq)) {
        const auto [c, v] = pq.top();
        pq.pop();
        if (dist[v] < c) continue;
        for (const auto& [to, cost]: graph[v])
            if (chmin(dist[to], dist[v] + cost)) pq.emplace(dist[to], to);
    }
    for (auto&& e: dist) if (e == INF) e = -1;
    return dist;
}
