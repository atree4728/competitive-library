#define PROBLEM "https://yukicoder.me/problems/no/1140"

#include <iostream>
#include "lib/math/sieve.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    const int M = 5000005;
    Sieve sieve(M);
    int t;
    std::cin >> t;
    while (t--) {
        long long a;
        int p;
        std::cin >> a >> p;
        int ans{};
        if (not sieve.is_prime(p)) ans = -1;
        else if (a % p == 0) ans = 0;
        else ans = 1;
        std::cout << ans << "\n";
    }
    return 0;
}
