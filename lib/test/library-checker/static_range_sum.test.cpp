#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include <bits/stdc++.h>
using namespace std;

#include "lib/utility/cumulative_sum.hpp"

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
    vector<long long> a(n);
    for (auto &&elem : a) cin >> elem;
    CumulativeSum1D cs(a);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << cs(l, r) << "\n";
    }
    return 0;
}
