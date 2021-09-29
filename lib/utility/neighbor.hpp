#pragma once

#include "../include.hpp"

/**
 * @brief neighbor on grid / グリッド上での近傍
 * @docs docs/neighbor.md
 */

template<class F> vector<pair<int, int>> neighbor(int x, int y, int dir, const F& ok) {
    assert(dir == 4 or dir == 8);
    const int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1};
    const int dy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
    vector<pair<int, int>> ret{};
    rep(i, dir) {
        const auto& [nx, ny] = pair{x + dx, y + dy};
        if (ok(nx, ny)) ret.emplace_back(pair{nx, ny});
    }
    return ret;
}
