#pragma once

#include "../include.hpp"

/**
 * @brief Dijkstra's Algorithm
 * @note  $O(|E|log|V|)$. There must be no negative edges. Return -1 for unreachable vertex.
 */

template<class T> vector<T> dijkstra(vector<vector<pair<size_t, T>>> const& graph, size_t root) {
    static_assert(is_signed<T>::value, "template parameter T must be signed type!");
    using P = pair<T, size_t>;
    constexpr T INF = numeric_limits<T>::max() / 2;
    auto chmin = [](auto& a, const auto& b) { return a > b and (a = b, true); };
    vector<T> dist(size(graph), INF);
    priority_queue<P, vector<P>, greater<>> pq;
    pq.emplace(dist[root] = 0, root);
    while (not empty(pq)) {
        const auto [c, from] = pq.top();
        pq.pop();
        if (dist[from] < c) continue;
        for (const auto& [to, cost]: graph[from])
            if (chmin(dist[to], dist[from] + cost)) pq.emplace(dist[to], to);
    }
    for (auto&& e: dist)
        if (e == INF) e = -1;
    return dist;
}
