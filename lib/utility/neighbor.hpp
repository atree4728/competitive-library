#pragma once

#include <cassert>
#include <utility>
#include <vector>

/**
 * @brief neighbor on grid / グリッド上での近傍
 * @docs docs/neighbor.md
 */

template<class F> std::vector<std::pair<std::size_t, std::size_t>> neighbor(size_t x, size_t y, int dir, const F& ok) {
    using namespace std;
    assert(dir == 4 or dir == 8);
    const int dx[8] = { 0, 0, -1, 1, -1, -1, 1, 1 };
    const int dy[8] = { -1, 1, 0, 0, -1, 1, -1, 1 };
    vector<pair<size_t, size_t>> ret{};
    for (int i = 0; i < dir; i++) {
        const auto& [nx, ny] = pair{ x + dx, y + dy };
        if (ok(nx, ny)) ret.emplace_back(pair{ nx, ny });
    }
    return ret;
}
