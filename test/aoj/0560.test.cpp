#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0560"

#include "../../lib/data_structure/partial_sum_2D.hpp"

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<string> field(n);
    for (auto &&elem: field) cin >> elem;
    vector<vector<int>> jcnt(n, vector(m, 0)), ocnt(n, vector(m, 0)), icnt(n, vector(m, 0));
    rep(i, n) rep(j, m) {
        switch (field[i][j]) {
            case 'J': jcnt[i][j]++; break;
            case 'O': ocnt[i][j]++; break;
            case 'I': icnt[i][j]++; break;
            default: assert(false);
        }
    }
    CumSum2D<int> jc(jcnt), oc(ocnt), ic(icnt);
    while (q--) {
        int sx, sy, gx, gy;
        cin >> sx >> sy >> gx >> gy;
        cout << jc(sx - 1, sy - 1, gx, gy) << " " << oc(sx - 1, sy - 1, gx, gy)
             << " " << ic(sx - 1, sy - 1, gx, gy) << "\n";
    }
}
