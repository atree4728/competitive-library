#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B"

#include <iostream>
#include "lib/modulus/modint.hpp"

int main() {
    using namespace std;
    int m, n;
    cin >> m >> n;
    const auto ans = Modint1000000007{ m }.pow(n);
    cout << ans << "\n";
}
