#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_E"
#include "../../include.hpp"
#include "../../modulus/combination.hpp"
#include "../../modulus/modint.hpp"

constexpr int MOD = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    CombinationTable<MOD> C(1100);
    cout << C(k, n) << endl;
    return 0;
}
