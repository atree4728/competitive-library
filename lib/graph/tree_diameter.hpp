#pragma once

#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <vector>

template<class T> std::vector<T> tree_diameter(const std::vector<std::vector<T>>& tree) {
    const T n = size(tree);
    const auto furthest = [&](T s) {
        std::vector<T> dist(n, static_cast<T>(-1));
        dist[s] = 0;
        std::queue<T> que{ { s } };
        while (not empty(que)) {
            const T u = que.front();
            que.pop();
            for (const T& v: tree[u]) {
                if (dist[v] != static_cast<T>(-1)) continue;
                dist[v] = dist[u] + 1;
                que.emplace(v);
            }
        }
        const T f = distance(cbegin(dist), max_element(cbegin(dist), cend(dist)));
        std::vector<T> path{ f };
        while (dist[path.back()] != 0) {
            for (const T& u: tree[path.back()]) {
                if (dist[u] + 1 == dist[path.back()]) {
                    path.emplace_back(u);
                    break;
                }
            }
        }
        reverse(begin(path), end(path));
        return path;
    };
    return furthest(furthest(0).back());
}
