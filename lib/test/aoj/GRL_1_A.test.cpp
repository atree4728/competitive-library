#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"
#include "../../graph/dijkstra.hpp"
#include "../../include.hpp"

int main() {
    size_t v, e, r;
    cin >> v >> e >> r;
    using P = pair<size_t, i64>;
    vector<vector<P>> graph(v, vector<P>{});
    rep(e) {
        size_t s, t;
        cin >> s >> t;
        i64 d;
        cin >> d;
        graph[s].emplace_back(P{t, d});
    }
    auto dist = dijkstra(graph, r);
    for (const auto &d: dist) {
        if (d == -1) cout << "INF\n";
        else
            cout << d << "\n";
    }
    return 0;
}