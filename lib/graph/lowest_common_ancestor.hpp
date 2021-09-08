#pragma once

#include "../include.hpp"

/**
 * @brief Lowest Common Ancestor
 * @note with doubling
*/

struct LCA {
    vector<int> parent, depth;
    vector<vector<int>> dp;
    explicit LCA(const vector<vector<int>> tree, int root):
        parent(size(tree), -1), depth(size(tree), -1) {
        depth[root] = 0;
        auto init = [&](auto&& dfs, int v, int prev) {
            assert(parent[v] == -1 and depth[v] == -1);
            parent[v] = prev;
            depth[v] = depth[prev] + 1;
            for (const auto& u: tree[u])
                if (u != prev) self(self, u, v);
        };
        init(init, root, -1);
        int max_depth = *max_element(begin(depth), end(depth));
    }
};