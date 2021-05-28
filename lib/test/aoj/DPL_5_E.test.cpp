#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_E"
#include <iostream>
#include "lib/modulus/modint.hpp"
#include "lib/modulus/combination.hpp"

using namespace std;

constexpr int MOD = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    CombinationTable<MOD> ct(1100);
    cout << ct.c(k, n) << endl;
    return 0;
}
