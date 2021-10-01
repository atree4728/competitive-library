#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <iostream>
#include "lib/graph/strongly_connected_components.hpp"

int main() {
    using namespace std;
    size_t n, m;
    cin >> n >> m;
    vector graph(n, vector<size_t>{});
    while (m--) {
        size_t a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    auto scc = StronglyConnectedComponents(graph);
    vector ans(size(scc.contracted), vector<size_t>{});
    for (size_t v = 0; v < n; v++) ans[scc[v]].push_back(v);
    cout << size(scc.contracted) << "\n";
    for (size_t i = 0; i < size(scc.contracted); i++) {
        cout << size(ans[i]);
        for (const auto& ai: ans[i]) cout << " " << ai;
        cout << "\n";
    }
}
