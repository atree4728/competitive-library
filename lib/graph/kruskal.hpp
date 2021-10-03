#pragma once

#include <utility>
#include "lib/data_structure/union_find.hpp"
/**
 * @brief Kruskal's Algorithm
 * @note Solve MST; Minimum Spanning Tree in $O(|E|log|E)$.
 * @note The sum of the weights of the edges can be obtained from
 * ```accumulate(begin(ret), end(ret), 0, [](T acc, auto e) { return acc + get<2>(e); })```.
 * @return Set of edges by vector<tuple<u, v, weight>>
*/

template<typename T> std::vector<std::tuple<size_t, size_t, T>> kruskal(std::vector<std::vector<std::pair<size_t, T>>> const& graph) {
    using namespace std;
    using Edge = tuple<size_t, size_t, T>;
    vector<Edge> edges{};
    const size_t n = size(graph);
    if (n == 1) return {};
    for (size_t i = 0; i < n; i++)
        for (const auto& [j, cost]: graph[i]) edges.emplace_back(Edge{ i, j, cost });
    sort(begin(edges), end(edges), [](Edge a, Edge b) { return get<2>(a) < get<2>(b); });
    UnionFind uf(n);
    vector<Edge> ret{};
    for (const auto& [u, v, cost]: edges) {
        if (not uf.same(u, v)) {
            ret.emplace_back(Edge{ u, v, cost });
            uf.unite(u, v);
        }
        if (size(ret) + 1 == n) break;
    }
    return ret;
}
