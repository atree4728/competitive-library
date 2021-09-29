#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A"

#include <iostream>
#include "lib/graph/tree_diameter.hpp"

int main() {
    size_t n;
    cin >> n;
    using Edge = pair<size_t, int>;
    vector tree(n, vector<Edge>{});
    for (size_t _ = 0; _ < n - 1; _++) {
        size_t s, t;
        int w;
        cin >> s >> t >> w;
        tree[s].emplace_back(t, w);
        tree[t].emplace_back(s, w);
    }
    const auto ans = tree_diameter(tree);
    cout << ans << "\n";
}
