#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include <cassert>
#include <iostream>
#include "lib/data_structure/fenwick_tree.hpp"

int main() {
    using namespace std;
    size_t n, q;
    cin >> n >> q;
    FenwickTree<int> bit(n);
    while (q--) {
        size_t com, x;
        int y;
        cin >> com >> x >> y;
        if (com == 0) {
            bit.add(--x, y);
        } else if (com == 1) {
            cout << bit.sum(--x, y) << "\n";
        } else {
            assert(false);
        }
    }
}
