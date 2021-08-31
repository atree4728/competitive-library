#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include "../../lib/graph/dijkstra.hpp"

int main() {
    int v, e, r;
    cin >> v >> e >> r;
    using P = pair<int, i64>;
    vector<vector<P>> graph(v, vector<P>{});
    while (e--) {
        int s, t;
        i64 d;
        cin >> s >> t;
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
