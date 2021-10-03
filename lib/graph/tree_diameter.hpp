#pragma once

#include <algorithm>
#include <cassert>
#include <limits>
#include <vector>

template<typename T> T tree_diameter(const std::vector<std::vector<std::pair<std::size_t, T>>> &tree) {
    using namespace std;
    const size_t n = size(tree);
    const T INF = numeric_limits<T>::max();
    vector<T> dist(n, INF);
    auto dfs = [&](auto &&self, size_t v, size_t prev) -> void {
        for (const auto &[u, w]: tree[v]) {
            if (u == prev) continue;
            assert(dist[u] == INF);  // graph must be a tree
            dist[u] = dist[v] + w;
            self(self, u, v);
        }
    };
    dist[0] = 0;
    dfs(dfs, 0, 0);
    size_t farthest = distance(begin(dist), max_element(begin(dist), end(dist)));
    assert(dist[farthest] != INF);  // graph must be a tree
    fill(begin(dist), end(dist), INF);
    dist[farthest] = 0;
    dfs(dfs, farthest, 0);
    T ans = *max_element(begin(dist), end(dist));
    return ans;
}
