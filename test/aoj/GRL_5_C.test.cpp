#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C"

#include "lib/graph/lowest_common_ancestor.hpp"

int main() {
    int n;
    cin >> n;
    vector graph(n, vector<int>{});
    rep(i, n) {
        int k;
        cin >> k;
        while (k--) {
            int c;
            cin >> c;
            graph[i].push_back(c);
        }
    }
    LCA lca(graph, 0);
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        int ans = lca(u, v);
        cout << ans << "\n";
    }
}