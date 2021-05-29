#define PROBLEM "https://atcoder.jp/contests/arc025/tasks/arc025_2"

#include <bits/stdc++.h>
#include "utility/cumulative_sum.hpp"
#include "utility/utility.hpp"

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> c(h, vector<int>(w));
    for (vector<int> &vec : c)
        for (auto &&elem : vec) cin >> elem;
    rep(i, h) rep(j, w) if ((i + j) % 2 == 0) c[i][j] *= -1;
    CumulativeSum2D<int> cs(c);
    int ans = 0;
    for (int sh = 0; sh <= h; sh++) {
        for (int sw = 0; sw <= w; sw++) {
            for (int gh = sh + 1; gh <= h; gh++) {
                for (int gw = sw + 1; gw <= w; gw++) {
                    if (cs(sh, sw, gh, gw) == 0) {
                        chmax(ans, (gh - sh) * (gw - sw));
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}
