#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_D"

#include "../../lib/data_structure/union_find.hpp"

int main() {
    size_t n, m;
    cin >> n >> m;
    UnionFind uf(n);
    while (m--) {
        size_t u, v;
        cin >> u >> v;
        uf.unite(u, v);
    }
    size_t q;
    cin >> q;
    while (q--) {
        size_t u, v;
        cin >> u >> v;
        cout << (uf.same(u, v) ? "yes" : "no") << "\n";
    }
}
