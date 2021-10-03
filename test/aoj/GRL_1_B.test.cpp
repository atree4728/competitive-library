#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B"

#include <iostream>
#include <limits>
#include "lib/graph/bellman_ford.hpp"

int main() {
    using namespace std;
    size_t v, e, r;
    cin >> v >> e >> r;
    using P = pair<size_t, int>;
    vector graph(v, vector<P>{});
    while (e--) {
        size_t s, t;
        int d;
        cin >> s >> t >> d;
        graph[s].emplace_back(P{ t, d });
    }
    auto dist = bellman_ford(graph, r);
    if (empty(dist)) {
        cout << "NEGATIVE CYCLE\n";
    } else {
        for (const auto& d: dist) {
            if (d == numeric_limits<int>::max()) cout << "INF\n";
            else
                cout << d << "\n";
        }
    }
}
