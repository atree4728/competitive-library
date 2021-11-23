#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D"

#include "lib/modulus/modint.hpp"
#include "lib/modulus/modtable.hpp"

int main() {
    int n, k;
    std::cin >> n >> k;
    const auto table = ModTable<Modint1000000007>(2100);
    std::cout << table.homo(k, n) << "\n";
    return 0;
}
