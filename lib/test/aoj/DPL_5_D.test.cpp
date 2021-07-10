#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D"
#include "../../include.hpp"
#include "../../modulus/combination.hpp"

constexpr int MOD = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    CombinationTable<MOD> ct(2100);
    cout << ct.H(k, n) << endl;
    return 0;
}
