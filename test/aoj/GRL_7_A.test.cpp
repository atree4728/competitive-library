#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/7/GRL_7_A"

#include "lib/graph/ford_fulkerson.hpp"

int main() {
    int x, y, e;
    cin >> x >> y >> e;
    FordFulkerson graph(x + y + 2);
    rep(v, 1, x + 1) graph.add_edge(0, v, 1);
    rep(v, x + 1, x + y + 1) graph.add_edge(v, x + y + 1, 1);
    while (e--) {
        int u, v;
        cin >> u >> v;
        graph.add_edge(u + 1, x + v + 1, 1);
    }
    int ans = graph.max_flow(0, x + y + 1);
    cout << ans << "\n";
}