#include <cassert>
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

#include "lib/data_structure/monoid.hpp"
#include "lib/data_structure/segment_tree.hpp"

int main() {
    int n, q;
    cin >> n >> q;
    SegmentTree<Min> segtree(n);
    while (q--) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) {
            segtree.set(x, y);
        } else if (com == 1) {
            cout << segtree.fold(x, ++y) << "\n";
        } else {
            assert(false);
        }
    }
}
