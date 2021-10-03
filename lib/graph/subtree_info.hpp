#pragma once

#include <utility>
#include <vector>

/**
 * @brief Subtree Info / 部分木の情報
 * @docs docs/subtree_info.md
 */

template<typename T> struct SubtreeInfo {
    using size_t = std::size_t;
    template<class U> using vector = std::vector<U>;
    size_t n;
    vector<size_t> parents, sizes;
    vector<T> depths;
    SubtreeInfo(const vector<vector<size_t>>& tree, size_t root): n(size(tree)), parents(n, -1), sizes(n, -1), depths(n, -1) {
        parents[root] = -1;
        depths[root] = 0;
        auto dfs = [&](auto&& self, size_t v, size_t prev) -> void {
            if (size(tree[v]) == 1) sizes[v] = 1;
            for (const auto u: tree[v])
                if (u != prev) {
                    parents[u] = v;
                    depths[u] = depths[v] + 1;
                    if (sizes[u] == -1) self(self, u, v);
                    sizes[v] += sizes[u];
                }
            sizes[v]++;
        };
        dfs(dfs, root, -1);
    }
    SubtreeInfo(const vector<vector<std::pair<size_t, T>>>& tree, size_t root): n(size(tree)), parents(n, -1), sizes(n, -1), depths(n, -1) {
        parents[root] = -1;
        depths[root] = 0;
        auto dfs = [&](auto&& self, size_t v, size_t prev) -> void {
            if (size(tree[v]) == 1) sizes[v] = 1;
            for (const auto& [u, w]: tree[v])
                if (u != prev) {
                    parents[u] = v;
                    depths[u] = depths[v] + w;
                    if (sizes[u] == -1) self(self, u, v);
                    sizes[v] += sizes[u];
                }
            sizes[v]++;
        };
        dfs(dfs, root, -1);
    }
    size_t parent(size_t u) { return parents[u]; }
    size_t size(size_t u) { return sizes[u]; }
    int depth(size_t u) { return depths[u]; }
};
