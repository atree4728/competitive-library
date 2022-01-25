#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1595"

#include "lib/utility/rerooting_dp.hpp"
#include "lib/utility/template.hpp"

auto main() -> int {
    const auto n = in<usize>();
    const auto graph = [n] {
        auto tmp = std::vector(n, std::vector<std::pair<usize, int>>{});
        for (const auto& [u, v]: in_vec<std::tuple<usize_1, usize_1>>(n - 1)) {
            tmp[u].emplace_back(v, 1);
            tmp[v].emplace_back(u, 1);
        }
        return tmp;
    }();
    const auto op = [](const auto& a, const auto& b) { return std::max(a, b); };
    const static auto id = [] { return 0; };
    const static auto propagate = [](const int& c, [[maybe_unused]] const usize u, [[maybe_unused]] const usize p, const int& w) {
        return c + w;
    };
    for (const auto& p: rerooting_dp<int>(graph, op, id, propagate)) println((n - 1) * 2 - p);
}
