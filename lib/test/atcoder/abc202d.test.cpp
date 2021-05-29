#define PROBLEM "https://atcoder.jp/contests/abc202/tasks/abc202_d"

#include <bits/stdc++.h>
using namespace std;

#include "lib/math/simple_combination.hpp"

int main() {
    long long a, b, k;
    cin >> a >> b >> k;
    SimpleCombinationTable<long long> ct(60);
    auto dfs = [&ct](auto self, long long a, long long b, long long k,
                     string ans) {
        if (a == 0 or b == 0) {
            return ans + string((a == 0 ? 'b' : 'a'), (a == 0 ? b : a));
        }
        long long c = ct.C(a + b - 1, b);
        if (k <= c) {
            ans.push_back('a');
            a--;
        } else {
            ans.push_back('b');
            b--;
            k -= c;
        }
        return self(self, a, b, k, ans);
    };
    cout << dfs(dfs, a, b, k, "") << "\n";
    return 0;
}
