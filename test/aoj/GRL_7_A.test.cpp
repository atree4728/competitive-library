#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/7/GRL_7_A"

#include <iostream>
#include "lib/graph/ford_fulkerson.hpp"

int main() {
    using namespace std;
    size_t x, y, e;
    cin >> x >> y >> e;
    FordFulkerson graph(x + y + 2);
    for (size_t v = 1; v <= x; v++) graph.add_edge(0, v, 1);
    for (size_t v = x + 1; v < x + y + 1; v++) graph.add_edge(v, x + y + 1, 1);
    while (e--) {
        size_t u, v;
        cin >> u >> v;
        graph.add_edge(u + 1, x + v + 1, 1);
    }
    int ans = graph.max_flow(0, x + y + 1);
    cout << ans << "\n";
}
