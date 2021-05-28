#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A"
#include <iostream>
#include "lib/modulus/modint.hpp"

using namespace std;

constexpr int MOD = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    cout << Modint<MOD>(k).pow(n) << "\n";
    return 0;
}
