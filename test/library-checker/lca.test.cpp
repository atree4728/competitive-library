#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "lib/graph/lowest_common_ancestor.hpp"

int main() {
    int n, q;
    cin >> n >> q;
    vector graph(n, vector<int>{});
    rep(i, 1, n) {
        int p;
        cin >> p;
        graph[p].push_back(i);
    }
    LCA lca(graph, 0);
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }
}