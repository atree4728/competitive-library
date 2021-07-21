#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A"

#include "../../lib/graph/topological_sort.hpp"

int main() {
    size_t n, m;
    cin >> n >> m;
    vector graph(n, vector<size_t>{});
    while (m--) {
        size_t s, t;
        cin >> s >> t;
        graph[s].push_back(t);
    }
    auto is_dag = topological_sort(graph);
    cout << (empty(is_dag) ? 1 : 0) << "\n";
}
