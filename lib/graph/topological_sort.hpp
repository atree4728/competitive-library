#pragma once

#include "../include.hpp"

/**
 * @brief Topological Sort
 * @docs docs/topological_sort.md
*/

template<typename T = int> vector<T> topological_sort(vector<vector<T>> const &graph) {
    int n = size(graph);
    vector<int> indegree(n, 0);
    for (const auto &edges: graph)
        for (const auto &to: edges) indegree[to]++;
    queue<T> indegree_is_0;
    rep(i, n) if (indegree[i] == 0) indegree_is_0.push(i);
    vector<T> ordered{};
    while (not empty(indegree_is_0)) {
        T from = indegree_is_0.front();
        ordered.push_back(from);
        indegree_is_0.pop();
        for (const auto &to: graph[from])
            if (--indegree[to] == 0) indegree_is_0.push(to);
    }
    if ((int)size(ordered) < n) return {}; // graph is not a DAG.
    return ordered;
}
