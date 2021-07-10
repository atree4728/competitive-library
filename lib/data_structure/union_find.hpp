#pragma once

#include "../include.hpp"

/**
 * @brief Union-Find
 */
struct UnionFind {
    vector<int> parents_or_size;
    UnionFind(int size_):
        parents_or_size(size_, -1) {}
    bool unite(int u, int v) {
        u = root(u), v = root(v);
        if (u == v) return false;
        if (parents_or_size[u] > parents_or_size[v]) swap(u, v);
        parents_or_size[u] += parents_or_size[v];
        parents_or_size[v] = u;
        return true;
    }
    int root(int k) { return parents_or_size[k] < 0 ? k : parents_or_size[k] = root(parents_or_size[k]); }
    int size(int k) { return -parents_or_size[root(k)]; }
    bool same(int u, int v) { return root(u) == root(v); }
    vector<vector<int>> groups() {
        size_t n = parents_or_size.size();
        vector<vector<int>> ret(n);
        rep(i, n) ret[root(i)].emplace_back(i);
        ret.erase(remove_if(begin(ret), end(ret), [&](const vector<int> &v) { return v.empty(); }));
        return ret;
    }
};
