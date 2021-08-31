#pragma once

#include "../data_structure/union_find.hpp"

/**
 * @brief Kruskal's Algorithm
 * @note Solve MST; Minimum Spanning Tree in $O(|E|log|E)$.
 * @note The sum of the weights of the edges can be obtained from
 * ```accumulate(begin(ret), end(ret), 0, [](T acc, auto e) { return acc + get<2>(e); })```.
 * @return Set of edges by vector<tuple<u, v, weight>>
*/

template<typename T> vector<tuple<int, int, T>> kruskal(vector<vector<pair<int, T>>> const& graph) {
    using Edge = tuple<int, int, T>;
    vector<Edge> edges{};
    int n = size(graph);
    if (n == 1) return {};
    rep(i, n) for (const auto& [j, cost]: graph[i]) edges.emplace_back(Edge{i, j, cost});
    sort(begin(edges), end(edges), [](Edge a, Edge b) { return get<2>(a) < get<2>(b); });
    UnionFind uf(n);
    vector<Edge> ret{};
    for (const auto& [u, v, cost]: edges) {
        if (not uf.same(u, v)) {
            ret.emplace_back(Edge{u, v, cost});
            uf.unite(u, v);
        }
        if ((int)size(ret) + 1 == n) break;
    }
    return ret;
}
