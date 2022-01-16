#pragma once

#include <vector>

template<class V> auto make_graph(size_t n, const std::vector<std::tuple<V, V>>& edges, bool is_directed = false) {
    std::vector graph(n, std::vector<size_t>{});
    for (const auto& [u, v]: edges) {
        graph[u].emplace_back(v);
        if (not is_directed) graph[v].emplace_back(u);
    }
    return graph;
}

template<class V, class W> auto make_graph(size_t n, const std::vector<std::tuple<V, V, W>>& edges, bool is_directed = false) {
    std::vector graph(n, std::vector<std::pair<size_t, W>>{});
    for (const auto& [u, v, w]: edges) {
        graph[u].emplace_back(v, w);
        if (not is_directed) graph[v].emplace_back(u, w);
    }
    return graph;
}
