#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D"

#include "lib/modulus/combination.hpp"
#include "lib/modulus/modint.hpp"

int main() {
    int n, k;
    std::cin >> n >> k;
    constexpr int MOD = 1000000007;
    CombTable<Modint<MOD>> ct(2100);
    std::cout << ct.H(k, n) << "\n";
    return 0;
}
