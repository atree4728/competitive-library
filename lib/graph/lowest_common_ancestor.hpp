#pragma once

#include "../include.hpp"

/**
 * @brief Lowest Common Ancestor(Doubling, Binary Search) / 最近共通祖先
 * @docs docs/lowest_common_ancestor.md
*/

struct LCA {
    size_t n, height;
    vector<int> depth;
    vector<vector<int>> dp;
    LCA(const vector<vector<size_t>>& tree, size_t root): n(size(tree)),
                                                          height(32 - __builtin_clz(n)),
                                                          depth(n, -1),
                                                          dp(height, vector<int>(n, -1)) {
        depth[root] = 0;
        dfs(tree, root, root);
        rep(k, height - 1) rep(v, n) {
            if (dp[k][v] == -1) dp[k + 1][v] = -1;
            else
                dp[k + 1][v] = dp[k][dp[k][v]];
        }
    }
    size_t operator()(size_t u, size_t v) {
        assert(u < n and v < n);
        if (depth[u] < depth[v]) swap(u, v);
        for (size_t k = height - 1; k--;)
            if (((depth[u] - depth[v]) >> k) & 1) u = dp[k][u];
        if (u == v) return u;
        for (size_t k = height - 1; k--;)
            if (dp[k][u] != dp[k][v]) {
                u = dp[k][u];
                v = dp[k][v];
            }
        return dp[0][u];
    }
    int dist(size_t u, size_t v) { return depth[u] + depth[v] - depth[(*this)(u, v)] * 2; }

  private:
    void dfs(const vector<vector<size_t>>& tree, size_t v, size_t prev) {
        for (const auto u: tree[v])
            if (u != prev) {
                assert(depth[u] == -1 and dp[0][u] == -1);  // The graph may not be a tree Graph.
                dp[0][u] = (int) v;
                depth[u] = depth[v] + 1;
                dfs(tree, u, v);
            }
    }
};
