#pragma once

#include "../include.hpp"

/**
 * @brief Subtree Info / 部分木の情報
 * @docs docs/subtree_info.md
 */

template<typename T> struct SubtreeInfo {
    size_type n;
    vector<size_type> parents, sizes;
    vector<T> depths;
    SubtreeInfo(const vector<vector<size_type>>& tree, size_type root):
        n(size(tree)), parents(n, -1), sizes(n, -1), depths(n, -1) {
        parents[root] = -1;
        depths[root] = 0;
        auto dfs = [&](auto&& self, size_type v, size_type prev) -> void {
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
    SubtreeInfo(const vector<vector<pair<size_type, T>>>& tree, size_type root):
        n(size(tree)), parents(n, -1), sizes(n, -1), depths(n, -1) {
        parents[root] = -1;
        depths[root] = 0;
        auto dfs = [&](auto&& self, size_type v, size_type prev) -> void {
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
    size_type parent(size_type u) { return parents[u]; }
    size_type size(size_type u) { return sizes[u]; }
    int depth(size_type u) { return depths[u]; }
};
