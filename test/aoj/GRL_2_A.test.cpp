#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A"

#include <iostream>
#include <numeric>
#include "lib/graph/kruskal.hpp"

int main() {
    using namespace std;
    size_t v, e;
    cin >> v >> e;
    using Edge = pair<size_t, size_t>;
    vector<vector<Edge>> graph(v, vector<Edge>{});
    while (e--) {
        size_t s, t;
        int w;
        cin >> s >> t >> w;
        graph[s].emplace_back(Edge{ t, w });
    }
    auto mst = kruskal(graph);
    int ans = accumulate(cbegin(mst), cend(mst), 0, [](int acc, auto e) { return acc + get<2>(e); });
    cout << ans << "\n";
}
