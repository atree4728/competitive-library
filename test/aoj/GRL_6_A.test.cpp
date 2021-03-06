#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A"

#include <iostream>
#include "lib/graph/ford_fulkerson.hpp"

int main() {
    using namespace std;
    size_t v, e;
    cin >> v >> e;
    FordFulkerson graph(v);
    while (e--) {
        size_t ui, vi;
        int ci;
        cin >> ui >> vi >> ci;
        graph.add_edge(ui, vi, ci);
    }
    int ans = graph.max_flow(0, v - 1);
    cout << ans << "\n";
}
