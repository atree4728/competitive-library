#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <cassert>
#include <iostream>
#include "lib/data_structure/union_find.hpp"

int main() {
    using namespace std;
    size_t n, q;
    cin >> n >> q;
    UnionFind uf(n);
    while (q--) {
        size_t t, u, v;
        cin >> t >> u >> v;
        switch (t) {
            case 0: uf.unite(u, v); break;
            case 1: cout << uf.same(u, v) << "\n"; break;
            default: assert(false);
        }
    }
}
