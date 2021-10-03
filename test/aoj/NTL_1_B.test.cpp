#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B"

#include <iostream>
#include "lib/math/power.hpp"

int main() {
    using namespace std;
    int m, n;
    cin >> m >> n;
    const int MOD = 1'000'000'007;
    int ans = power(m, n, MOD);
    cout << ans << "\n";
}
