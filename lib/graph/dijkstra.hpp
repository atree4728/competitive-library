#pragma once

#include <optional>
#include <queue>
#include <vector>

template<class W, template<class, class> class Tp>
auto dijkstra(std::vector<std::vector<Tp<std::size_t, W>>> const& graph, std::size_t root) {
    using E = std::pair<W, size_t>;
    std::vector<std::optional<W>> dist(size(graph), std::nullopt);
    std::priority_queue<E, std::vector<E>, std::greater<>> pq{};
    pq.emplace(*(dist[root] = W{}), root);
    while (not empty(pq)) {
        const auto [c, from] = pq.top();
        pq.pop();
        if (*dist[from] < c) continue;
        for (const auto& [to, cost]: graph[from]) {
            if (not dist[to] or *dist[to] > *dist[from] + cost) {
                dist[to] = dist[from].value() + cost;
                pq.emplace(*dist[to], to);
            }
        }
    }
    return dist;
}
