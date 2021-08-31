#include <cassert>
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"

#include "lib/data_structure/union_find.hpp"

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    while (q--) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) {
            uf.unite(x, y);
        } else if (com == 1) {
            cout << (uf.same(x, y) ? 1 : 0) << "\n";
        } else {
            assert(false);
        }
    }
}
