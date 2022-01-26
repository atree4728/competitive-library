#pragma once

#include <numeric>
#include <optional>
#include <vector>
#include "lib/utility/rec_lambda.hpp"

template<class value_type, class E, class F, class H, class G>
auto rerooting_dp(std::vector<std::vector<E>> const& graph, F const& op, H const& id, G const& propagate) {
    const auto n = size(graph);
    auto dp_on_subtree = std::vector<std::optional<value_type>>(n, std::nullopt);
    rec_lambda([&](auto&& self, const size_t u, const size_t p) {
        if (dp_on_subtree[u].has_value()) return *dp_on_subtree[u];
        *dp_on_subtree[u] = id();
        for (const auto& [v, w]: graph[u]) {
            if (v == p) continue;
            *dp_on_subtree[u] = op(*dp_on_subtree[u], propagate(self(v, u), v, u, w));
        }
        return *dp_on_subtree[u];
    })(0, 0);

    auto rerooting_dp = std::vector(n, id());
    rec_lambda([&](auto&& self, const size_t u, const size_t p, const value_type& to_parent) -> void {
        auto from_left = std::vector{ id() };
        auto children = std::vector<E>{};
        for (const auto& [v, w]: graph[u]) {
            if (v == p) continue;
            children.emplace_back(v, w);
            from_left.emplace_back(propagate(*dp_on_subtree[v], v, u, w));
        }
        rerooting_dp[u] = reduce(cbegin(from_left), cend(from_left), to_parent, op);
        if (empty(children)) return;
        auto from_right = from_left;
        from_right.erase(begin(from_right));
        from_right.emplace_back(id());
        partial_sum(begin(from_left), end(from_left), begin(from_left), op);
        partial_sum(rbegin(from_right), rend(from_right), rbegin(from_right), op);
        for (size_t i = 0; i < size(children); ++i) {
            const auto& [v, w] = children[i];
            const auto& except_ci = op(from_left[i], from_right[i + 1]);
            self(v, u, propagate(op(to_parent, except_ci), v, u, w));
        }
    })(0, 0, id());
    return rerooting_dp;
}
