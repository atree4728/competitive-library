#define PROBLEM "https://yukicoder.me/problems/no/1140"

#include "../../lib/math/eratosthenes.hpp"

const int M = 5000005;

Sieve sieve(M);

int solve(long long a, int p) {
    if (not sieve.is_prime(p)) return -1;
    if (a % p == 0) return 0;
    return 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a;
        int p;
        cin >> a >> p;
        cout << solve(a, p) << "\n";
    }
    return 0;
}