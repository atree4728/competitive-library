#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "../../lib/data_structure/cumulative_sum.hpp"

int main() {
    int n, q;
    cin >> n >> q;
    vector<i64> a(n);
    for (auto &&elem: a) cin >> elem;
    CumSum<i64> cs(a);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << cs(l, r) << "\n";
    }
    return 0;
}
