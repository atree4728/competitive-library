#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <iostream>
#include "lib/data_structure/fenwick_tree.hpp"

int main() {
    using namespace std;
    size_t n, q;
    cin >> n >> q;
    vector<unsigned long long> a(n);
    for (auto&& ai: a) cin >> ai;
    FenwickTree bit(a);
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            size_t p;
            unsigned long long x;
            cin >> p >> x;
            bit.add(p, x);
        }
        if (t == 1) {
            size_t l, r;
            cin >> l >> r;
            cout << bit.sum(l, r) << "\n";
        }
    }
}
