#pragma once

#include "../include.hpp"

/**
 * @brief Union Find
 * @docs docs/union_find.md
 */

struct UnionFind {
    int n;
    vector<int> node;
    explicit UnionFind(const int n):
        n(n), node(n, -1) {}
    bool unite(int u, int v) {
        u = root(u), v = root(v);
        if (u == v) return false;
        if (node[u] > node[v]) swap(u, v);
        node[u] += node[v];
        node[v] = u;
        return true;
    }
    int root(int v) { return node[v] < 0 ? v : node[v] = root(node[v]); }
    int size(int v) { return -node[root(v)]; }
    bool same(int u, int v) { return root(u) == root(v); }
    vector<vector<int>> group() {
        vector ret(n, vector<int>{});
        rep(i, n) ret[root(i)].push_back(i);
        ret.erase(remove_if(begin(ret), end(ret), [&](const auto &ri) { return empty(ri); }));
        return ret;
    }
};
