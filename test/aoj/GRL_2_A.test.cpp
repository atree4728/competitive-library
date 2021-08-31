#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A"

#include "../../lib/graph/kruskal.hpp"

int main() {
    size_t v, e;
    cin >> v >> e;
    using Edge = pair<int, int>;
    vector<vector<Edge>> graph(v, vector<Edge>{});
    rep(e) {
        int s, t, w;
        cin >> s >> t >> w;
        graph[s].emplace_back(Edge{t, w});
    }
    auto mst = kruskal(graph);
    int ans = accumulate(begin(mst), end(mst), 0, [](int acc, auto e) { return acc + get<2>(e); });
    cout << ans << "\n";
}
