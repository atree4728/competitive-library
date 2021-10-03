#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A"

#include <iostream>
#include "lib/graph/topological_sort.hpp"

int main() {
    using namespace std;
    size_t n, m;
    cin >> n >> m;
    vector graph(n, vector<int>{});
    while (m--) {
        int s, t;
        cin >> s >> t;
        graph[s].push_back(t);
    }
    auto is_dag = topological_sort(graph);
    cout << (empty(is_dag) ? 1 : 0) << "\n";
}
