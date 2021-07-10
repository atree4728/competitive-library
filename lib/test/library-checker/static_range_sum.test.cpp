#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "../../include.hpp"
#include "../../utility/cumulative_sum.hpp"

struct IOSetup {
    IOSetup() noexcept {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
} IOSetup;

int main() {
    int n, q;
    cin >> n >> q;
    vector<i64> a(n);
    for (auto &&elem : a) cin >> elem;
    CumulativeSum1D<i64> cs(a);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << cs(l, r) << "\n";
    }
    return 0;
}
