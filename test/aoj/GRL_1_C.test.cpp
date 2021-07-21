#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C"

#include "../../lib/graph/floyd_warshall.hpp"

int main() {
    size_t v, e;
    cin >> v >> e;
    using P = pair<size_t, i64>;
    vector<vector<P>> graph(v, vector<P>{});
    while (e--) {
        size_t s, t;
        i64 d;
        cin >> s >> t >> d;
        graph[s].emplace_back(P{t, d});
    }
    const auto result = floyd_warshall(graph);
    if (empty(result)) cout << "NEGATIVE CYCLE\n";
    else
        rep(i, v) rep(j, v) {
            if (result[i][j] >= numeric_limits<i64>::max()) cout << "INF";
            else
                cout << result[i][j];
            cout << " \n"[j + 1 == v];
        }
}