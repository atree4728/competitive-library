#pragma once

#include <tuple>
#include <vector>

template<typename T> std::vector<T> bellman_ford(std::vector<std::vector<std::pair<std::size_t, T>>> const& graph, std::size_t root) {
    using namespace std;
    static_assert(is_signed_v<T>);
    constexpr T INF = numeric_limits<T>::max();
    auto chmin = [](auto& a, const auto& b) { return a > b and (a = b, true); };

    vector<T> dist(size(graph), INF);
    dist[root] = 0;
    vector<tuple<size_t, size_t, T>> edges{};
    for (size_t i = 0; i < size(graph); i++)
        for (const auto& [j, w]: graph[i]) edges.emplace_back(i, j, w);
    for (size_t i = 0; i < size(graph); i++) {
        for (const auto& [u, v, w]: edges)
            if (dist[u] != INF and chmin(dist[v], dist[u] + w) and i + 1 == size(graph)) return {};
    }
    return dist;
}
