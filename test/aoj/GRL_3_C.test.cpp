#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C"

#include <iostream>
#include "lib/graph/strongly_connected_components.hpp"

int main() {
    using namespace std;
    size_t v, e;
    cin >> v >> e;
    vector graph(v, vector<size_t>{});
    while (e--) {
        size_t s, t;
        cin >> s >> t;
        graph[s].push_back(t);
    }
    auto scc = StronglyConnectedComponents(graph);
    size_t q;
    cin >> q;
    while (q--) {
        size_t ui, vi;
        cin >> ui >> vi;
        cout << (scc[ui] == scc[vi] ? 1 : 0) << "\n";
    }
}
