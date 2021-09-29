#pragma once

#include "../include.hpp"

/**
 * @brief Union Find
 * @docs docs/union_find.md
 */

struct UnionFind {
    size_type n;
    vector<int> node;
    explicit UnionFind(const size_type n):
        n(n), node(n, -1) {}
    bool unite(size_type u, size_type v) {
        u = root(u), v = root(v);
        if (u == v) return false;
        if (node[u] > node[v]) swap(u, v);
        node[u] += node[v];
        node[v] = (int)u;
        return true;
    }
    size_type root(size_type v) { return node[v] < 0 ? v : node[v] = (int)root(node[v]); }
    size_type size(size_type v) { return (size_type)-node[root(v)]; }
    bool same(size_type u, size_type v) { return root(u) == root(v); }
    vector<vector<size_type>> group() {
        vector ret(n, vector<size_type>{});
        rep(i, n) ret[root(i)].push_back(i);
        ret.erase(remove_if(begin(ret), end(ret), [&](const auto &ri) { return empty(ri); }));
        return ret;
    }
};
