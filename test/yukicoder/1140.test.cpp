#define PROBLEM "https://yukicoder.me/problems/no/1140"

#include <iostream>
#include "lib/math/eratosthenes.hpp"

int solve(Sieve& sieve, long long a, int p) {
    if (not sieve.is_prime(p)) return -1;
    if (a % p == 0) return 0;
    return 1;
}

int main() {
    const int M = 5000005;
    Sieve sieve(M);
    int t;
    std::cin >> t;
    while (t--) {
        long long a;
        int p;
        std::cin >> a >> p;
        std::cout << solve(sieve, a, p) << "\n";
    }
    return 0;
}
