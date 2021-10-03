#pragma once

#include <algorithm>
#include <vector>

struct UnionFind {
    std::size_t n;
    std::vector<int> node;
    explicit UnionFind(const std::size_t n): n(n), node(n, -1) {}
    bool unite(std::size_t u, std::size_t v) {
        u = root(u), v = root(v);
        if (u == v) return false;
        if (node[u] > node[v]) std::swap(u, v);
        node[u] += node[v];
        node[v] = (int) u;
        return true;
    }
    std::size_t root(const std::size_t &v) { return node[v] < 0 ? v : node[v] = (int) root(node[v]); }
    std::size_t size(const std::size_t &v) { return (std::size_t) -node[root(v)]; }
    bool same(const std::size_t &u, const std::size_t &v) { return root(u) == root(v); }
    std::vector<std::vector<std::size_t>> group() {
        std::vector ret(n, std::vector<std::size_t>{});
        for (std::size_t i = 0; i < n; i++) ret[root(i)].push_back(i);
        ret.erase(std::remove_if(begin(ret), end(ret), [&](const auto &ri) { return empty(ri); }));
        return ret;
    }
};
