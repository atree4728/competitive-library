#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E"

#include "lib/math/extgcd.hpp"

int main() {
    int a, b;
    cin >> a >> b;
    const auto& [x, y] = extgcd(a, b);
    cout << x << " " << y << "\n";
}
