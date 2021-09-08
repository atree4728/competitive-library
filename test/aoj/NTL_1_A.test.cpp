#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A"

#include "lib/math/prime_factorize.hpp"

int main() {
    int n;
    cin >> n;
    auto pf = prime_factorize(n);
    cout << n << ":";
    for (auto [p, e]: pf) {
        while (e--) cout << " " << p;
    }
    cout << "\n";
}
