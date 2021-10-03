#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_E"

#include "lib/modulus/combination.hpp"
#include "lib/modulus/modint.hpp"

constexpr int MOD = 1000000007;

int main() {
    int n, k;
    std::cin >> n >> k;
    CombTable<Modint<MOD>> C(1100);
    std::cout << C(k, n) << "\n";
    return 0;
}
