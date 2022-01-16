#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_E"                                                           

#include "lib/modulus/modint.hpp"
#include "lib/modulus/modtable.hpp"

int main() {
    int n, k;
    std::cin >> n >> k;
    const auto table = ModTable<Modint1000000007>(1100);
    std::cout << table.binom(k, n) << "\n";
    return 0;
}
