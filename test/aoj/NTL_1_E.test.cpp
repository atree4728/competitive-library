#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E"

#include <iostream>
#include "lib/math/extgcd.hpp"

int main() {
    int a, b;
    std::cin >> a >> b;
    const auto& [x, y] = extgcd(a, b);
    std::cout << x << " " << y << "\n";
}
