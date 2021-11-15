#pragma once

#include <queue>
#include <vector>

std::vector<std::size_t> topological_sort(std::vector<std::vector<std::size_t>> const &graph) {
    using namespace std;
    const size_t n = size(graph);
    vector<unsigned int> indegree(n, 0);
    for (const auto &edges: graph)
        for (const auto &to: edges) indegree[to]++;
    queue<size_t> indeg0{};
    for (size_t i = 0; i < n; i++)
        if (indegree[i] == 0) indeg0.push(i);
    vector<size_t> ordered{};
    while (not empty(indeg0)) {
        size_t from = indeg0.front();
        ordered.push_back(from);
        indeg0.pop();
        for (const auto &to: graph[from])
            if (--indegree[to] == 0) indeg0.push(to);
    }
    if (size(ordered) < n) return {};  // graph is not a DAG.
    return ordered;
}
