#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B"

#include "lib/math/power.hpp"

const int MOD = 1'000'000'007;

int main() {
    int m, n;
    cin >> m >> n;
    int ans = power(m, n, MOD);
    cout << ans << "\n";
}
