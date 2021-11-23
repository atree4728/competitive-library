#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_B"

#include "lib/modulus/modint.hpp"
#include "lib/modulus/modtable.hpp"

int main() {
    int n, k;
    std::cin >> n >> k;

    using mint = Modint1000000007;
    ModTable<mint> f(1100);
    std::cout << f.perm(k, n) << "\n";
    return 0;
}
