#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <iostream>
#include "lib/graph/lowest_common_ancestor.hpp"

int main() {
    size_t n, q;
    std::cin >> n >> q;
    std::vector graph(n, std::vector<size_t>{});
    for (size_t i = 1; i < n; i++) {
        size_t p;
        std::cin >> p;
        graph[p].push_back(i);
        graph[i].push_back(p);
    }
    auto lca = LowestCommonAncestor(graph, 0);
    while (q--) {
        size_t u, v;
        std::cin >> u >> v;
        std::cout << lca(u, v) << "\n";
    }
}
