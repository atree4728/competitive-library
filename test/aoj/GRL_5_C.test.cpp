#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C"

#include "lib/graph/lowest_common_ancestor.hpp"

int main() {
    size_t n;
    cin >> n;
    vector graph(n, vector<size_t>{});
    for (size_t i = 0; i < n; i++) {
        size_t k;
        cin >> k;
        while (k--) {
            size_t c;
            cin >> c;
            graph[i].push_back(c);
        }
    }
    auto lca = LowestCommonAncestor(graph, 0);
    size_t q;
    cin >> q;
    while (q--) {
        size_t u, v;
        cin >> u >> v;
        size_t ans = lca(u, v);
        cout << ans << "\n";
    }
}
