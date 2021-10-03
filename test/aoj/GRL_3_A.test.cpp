#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_A"

#include <iostream>
#include "lib/graph/lowlink.hpp"

int main() {
    using namespace std;
    size_t v, e;
    cin >> v >> e;
    vector graph(v, vector<size_t>{});
    while (e--) {
        size_t s, t;
        cin >> s >> t;
        graph[s].push_back(t);
        graph[t].push_back(s);
    }
    auto articulation = Lowlink(graph).articulation;
    sort(begin(articulation), end(articulation));
    for (const auto &u: articulation) {
        cout << u << "\n";
    }
}
