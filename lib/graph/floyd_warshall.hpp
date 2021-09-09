#pragma once

#include "../include.hpp"

/**
 * @brief Floyd Warshall Algorithm / 負辺を許す全点対最短経路問題
 * @docs docs/floyd_warshall.md
 */

template<typename T> vector<vector<T>> floyd_warshall(vector<vector<pair<int, T>>> const& graph) {
    int n = size(graph);
    constexpr T INF = numeric_limits<T>::max();
    vector<vector<T>> dp(n, vector<T>(n, INF));
    rep(i, n) {
        dp[i][i] = 0;
        for (const auto& [to, cost]: graph[i]) dp[i][to] = cost;
    }
    rep(k, n) rep(i, n) rep(j, n) if (dp[i][k] < INF and dp[k][j] < INF) chmin(dp[i][j], dp[i][k] + dp[k][j]);
    rep(i, n) if (dp[i][i] < 0) return {};
    return dp;
}