#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C"

#include <iostream>
#include <limits>
#include "lib/graph/floyd_warshall.hpp"

int main() {
    using namespace std;
    size_t v, e;
    cin >> v >> e;
    using P = pair<size_t, long long>;
    vector<vector<P>> graph(v, vector<P>{});
    while (e--) {
        size_t s, t;
        long long d;
        cin >> s >> t >> d;
        graph[s].emplace_back(P{ t, d });
    }
    const auto result = floyd_warshall(graph);
    if (empty(result))
        cout << "NEGATIVE CYCLE\n";
    else
        for (size_t i = 0; i < v; i++)
            for (size_t j = 0; j < v; j++) {
                if (result[i][j] >= numeric_limits<long long>::max()) cout << "INF";
                else
                    cout << result[i][j];
                cout << " \n"[j + 1 == v];
            }
}
