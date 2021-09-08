#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C"

#include "lib/math/gcd.hpp"

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto&& ai: a) cin >> ai;
    int ans = reduce(cbegin(a), cend(a), 1, [](int p, int q) { return mylcm(p, q); });
    cout << ans << "\n";
}
