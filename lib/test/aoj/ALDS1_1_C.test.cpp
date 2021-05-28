#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"
#include "lib/math/eratosthenes.hpp"
#include <iostream>

const int M = 100000003;

int main() {
    int n;
    cin >> n;
    Sieve sieve(M);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt += sieve.is_prime(a);
    }
    cout << cnt << "\n";
    return 0;
}
