#pragma once

#include "../include.hpp"

/**
 * @brief Floyd Warshall's Algorithm
 * @note Solve APSP; All Pair Shortest Path in $O(|V|^3)$ and if given graph has a negative path.
 * @note Return an empty vector when given graph has a negative cycle.
 * @note If there is no path, return std::numeric_limits<T>::max().
 * @note When the graph is more dense, it runs faster than the Dijkstra's Algorithm (O(|V||E|log|E)) from arbitrary vertices.
 */

template<typename T> vector<vector<T>> floyd_warshall(vector<vector<pair<int, T>>> const& graph) {
    int n = size(graph);
    constexpr T INF = numeric_limits<T>::max();
    vector<vector<T>> dp(n, vector<T>(n, INF));
    rep(i, n) {
        dp[i][i] = 0;
        for (const auto& [to, cost]: graph[i]) dp[i][to] = cost;
    }
    rep(k, n) rep(i, n) rep(j, n) if (T tok = dp[i][k], fromk = dp[k][j]; tok != INF and fromk != INF) chmin(dp[i][j], dp[i][k] + dp[k][j]);
    rep(i, n) if (dp[i][i] < 0) return {};
    return dp;
}