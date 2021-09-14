#pragma once

#include "../include.hpp"

/**
 * @brief Subtree Info / 部分木の情報
 * @docs docs/subtree_info.md
 */

template<typename T> struct SubtreeInfo {
    int n;
    vector<int> parents, sizes;
    vector<T> depths;
    SubtreeInfo(const vector<vector<int>>& tree, int root):
        n(size(tree)), parents(n, -1), sizes(n, -1), depths(n, -1) {
        parents[root] = -1;
        depths[root] = 0;
        auto dfs = [&](auto&& self, int v, int prev) -> void {
            if (size(tree[v]) == 1) sizes[v] = 1;
            for (const auto& u: tree[v])
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
    SubtreeInfo(const vector<vector<pair<int, T>>>& tree, int root):
        n(size(tree)), parents(n, -1), sizes(n, -1), depths(n, -1) {
        parents[root] = -1;
        depths[root] = 0;
        auto dfs = [&](auto&& self, int v, int prev) -> void {
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
    int parent(int u) { return parents[u]; }
    int size(int u) { return sizes[u]; }
    int depth(int u) { return depths[u]; }
};
