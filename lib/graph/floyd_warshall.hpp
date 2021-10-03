#pragma once

#include <utility>
#include <vector>

template<typename T> std::vector<std::vector<T>> floyd_warshall(std::vector<std::vector<std::pair<std::size_t, T>>> const& graph) {
    using namespace std;
    const size_t n = size(graph);
    constexpr T INF = numeric_limits<T>::max();
    vector<vector<T>> dp(n, vector<T>(n, INF));
    for (size_t i = 0; i < n; i++) {
        dp[i][i] = 0;
        for (const auto& [to, cost]: graph[i]) dp[i][to] = cost;
    }
    for (size_t k = 0; k < n; k++)
        for (size_t i = 0; i < n; i++)
            for (size_t j = 0; j < n; j++)
                if (dp[i][k] < INF and dp[k][j] < INF) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    for (size_t i = 0; i < n; i++)
        if (dp[i][i] < 0) return {};
    return dp;
}
