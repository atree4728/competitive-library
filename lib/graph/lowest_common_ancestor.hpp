#pragma once

#include <cassert>
#include <vector>
#include "lib/utility/rec_lambda.hpp"

struct LowestCommonAncestor {
    std::size_t n, height;
    std::vector<int> depth;
    std::vector<std::vector<int>> dp;
    LowestCommonAncestor(const std::vector<std::vector<std::size_t>>& tree, std::size_t root)
        : n(size(tree)), height(32 - __builtin_clz(n)), depth(n, -1), dp(height, std::vector<int>(n, -1)) {
        depth[root] = 0;
        rec_lambda([&](auto&& self, const auto v, const auto p) -> void {
            for (const auto u: tree[v]) {
                if (u == p) continue;
                assert(depth[u] == -1 and dp[0][u] == -1);  // The graph may not be a tree Graph.
                dp[0][u] = static_cast<int>(v);
                depth[u] = depth[v] + 1;
                self(u, v);
            }
            return;
        })(root, root);
        for (std::size_t k = 0; k + 1 < height; k++)
            for (std::size_t v = 0; v < n; v++) {
                if (dp[k][v] == -1) dp[k + 1][v] = -1;
                else dp[k + 1][v] = dp[k][dp[k][v]];
            }
    }
    std::size_t operator()(std::size_t u, std::size_t v) {
        assert(u < n and v < n);
        if (depth[u] < depth[v]) std::swap(u, v);
        for (std::size_t k = 0; k < height; ++k)
            if ((depth[u] - depth[v]) >> k & 1) u = dp[k][u];
        if (u == v) return u;
        for (size_t k = height; k--;) {
            if (dp[k][u] != dp[k][v]) {
                u = dp[k][u];
                v = dp[k][v];
            }
        }
        return dp[0][u];
    }
    int dist(size_t u, size_t v) { return depth[u] + depth[v] - depth[(*this)(u, v)] * 2; }
};
