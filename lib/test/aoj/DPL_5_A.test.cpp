#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A"
#include "../../include.hpp"
#include "../../modulus/modint.hpp"

constexpr int MOD = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    cout << Modint<MOD>(k).pow(n) << "\n";
    return 0;
}
