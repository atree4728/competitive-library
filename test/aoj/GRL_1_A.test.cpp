#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include <iostream>
#include "lib/graph/dijkstra.hpp"

int main() {
    using namespace std;
    size_t v, e, r;
    cin >> v >> e >> r;
    using P = pair<size_t, long long>;
    vector<vector<P>> graph(v, vector<P>{});
    while (e--) {
        size_t s, t;
        long long d;
        cin >> s >> t;
        cin >> d;
        graph[s].emplace_back(P{ t, d });
    }
    auto dist = dijkstra(graph, r);
    for (const auto &d: dist) {
        if (not d.has_value()) cout << "INF\n";
        else cout << *d << "\n";
    }
    return 0;
}
