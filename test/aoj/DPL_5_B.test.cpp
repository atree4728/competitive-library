#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_B"

#include "lib/modulus/combination.hpp"
#include "lib/modulus/modint.hpp"

int main() {
    int n, k;
    std::cin >> n >> k;

    constexpr int MOD = 1000000007;
    using mint = Modint<MOD>;
    CombTable<mint> ct(1100);
    std::cout << ct.P(k, n) << "\n";
    return 0;
}
