#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A"

#include "lib/graph/tree_diameter.hpp"

int main() {
    int n;
    cin >> n;
    using Edge = pair<int, int>;
    vector tree(n, vector<Edge>{});
    rep(i, n - 1) {
        int s, t, w;
        cin >> s >> t >> w;
        tree[s].emplace_back(t, w);
        tree[t].emplace_back(s, w);
    }
    const auto ans = tree_diameter(tree);
    cout << ans << "\n";
}