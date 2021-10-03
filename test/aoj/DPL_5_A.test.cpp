#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A"

#include <iostream>
#include "lib/math/power.hpp"

constexpr int MOD = 1000000007;

int main() {
    using namespace std;
    int n, k;
    cin >> n >> k;
    cout << power(k, n, MOD) << "\n";
    return 0;
}
