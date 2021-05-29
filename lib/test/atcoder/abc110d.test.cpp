#define PROBLEM "https://atcoder.jp/contests/abc110/tasks/abc110_d"

#include <bits/stdc++.h>
#include "modulus/modint.hpp"
#include "modulus/combination.hpp"
#include "math/utility.hpp"
using namespace std;

constexpr int MOD = 1000000007;
constexpr int M = 200000;
using mint = Modint<MOD>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, m;
    cin >> n >> m;
    map<long long, int> factor = prime_factorize(n);
    mint ans = 1;
    CombinationTable<MOD> ct(M);
    for (auto [_, ex] : factor) ans *= ct.C(n + ex - 1, ex);
    cout << ans.val() << "\n";
    return 0;
}
