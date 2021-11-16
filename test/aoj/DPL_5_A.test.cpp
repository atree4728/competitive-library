#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A"

#include <iostream>
#include "lib/modulus/modint.hpp"

int main() {
    using namespace std;
    int n, k;
    cin >> n >> k;
    cout << Modint1000000007{ k }.pow(n) << "\n";
    return 0;
}
