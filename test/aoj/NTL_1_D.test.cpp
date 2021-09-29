#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_D"

#include <iostream>
#include "../../lib/math/euler_phi.hpp"

int main() {
    int n;
    std::cin >> n;
    std::cout << euler_phi(n) << "\n";
}
