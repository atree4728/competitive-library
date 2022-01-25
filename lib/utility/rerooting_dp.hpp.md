---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/utility/rec_lambda.hpp
    title: lib/utility/rec_lambda.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1595.test.cpp
    title: test/aoj/1595.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/utility/rerooting_dp.hpp\"\n\n#include <numeric>\n#include\
    \ <optional>\n#include <vector>\n#line 2 \"lib/utility/rec_lambda.hpp\"\n\n#include\
    \ <utility>\n\ntemplate<class F> struct rec_lambda {\n    F f;\n    explicit constexpr\
    \ rec_lambda(F&& f): f(std::forward<F>(f)) {}\n    template<class... Args> constexpr\
    \ decltype(auto) operator()(Args&&... args) const {\n        return f(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n#line 7 \"lib/utility/rerooting_dp.hpp\"\n\ntemplate<class value_type,\
    \ class E, class F, class H, class G>\nauto rerooting_dp(std::vector<std::vector<E>>\
    \ const& graph, F const& op, H const& id, G const& propagate) {\n    const auto\
    \ n = size(graph);\n    auto dp_on_subtree = std::vector<std::optional<value_type>>(n,\
    \ std::nullopt);\n    rec_lambda([&](auto&& self, const size_t u, const size_t\
    \ p) {\n        if (dp_on_subtree[u].has_value()) return *dp_on_subtree[u];\n\
    \        *dp_on_subtree[u] = id();\n        for (const auto& [v, w]: graph[u])\
    \ {\n            if (v == p) continue;\n            *dp_on_subtree[u] = op(*dp_on_subtree[u],\
    \ propagate(self(v, u), v, u, w));\n        }\n        return *dp_on_subtree[u];\n\
    \    })(0, 0);\n\n    auto rerooting_dp = std::vector(n, id());\n    rec_lambda([&](auto&&\
    \ self, const size_t u, const size_t p, const value_type& to_parent) -> void {\n\
    \        auto from_left = std::vector{ id() };\n        auto children = std::vector<E>{};\n\
    \        for (const auto& [v, w]: graph[u]) {\n            if (v == p) continue;\n\
    \            children.emplace_back(v, w);\n            from_left.emplace_back(propagate(*dp_on_subtree[v],\
    \ v, u, w));\n        }\n        rerooting_dp[u] = reduce(cbegin(from_left), cend(from_left),\
    \ to_parent, op);\n        if (empty(children)) return;\n        auto from_right\
    \ = from_left;\n        from_right.erase(begin(from_right));\n        from_right.emplace_back(id());\n\
    \        partial_sum(begin(from_left), end(from_left), begin(from_left), op);\n\
    \        partial_sum(rbegin(from_right), rend(from_right), rbegin(from_right),\
    \ op);\n        for (size_t i = 0; i < size(children); ++i) {\n            const\
    \ auto& [v, w] = children[i];\n            const auto& except_ci = op(from_left[i],\
    \ from_right[i + 1]);\n            self(v, u, propagate(op(to_parent, except_ci),\
    \ v, u, w));\n        }\n    })(0, 0, id());\n    return rerooting_dp;\n}\n"
  code: "#pragma once\n\n#include <numeric>\n#include <optional>\n#include <vector>\n\
    #include \"rec_lambda.hpp\"\n\ntemplate<class value_type, class E, class F, class\
    \ H, class G>\nauto rerooting_dp(std::vector<std::vector<E>> const& graph, F const&\
    \ op, H const& id, G const& propagate) {\n    const auto n = size(graph);\n  \
    \  auto dp_on_subtree = std::vector<std::optional<value_type>>(n, std::nullopt);\n\
    \    rec_lambda([&](auto&& self, const size_t u, const size_t p) {\n        if\
    \ (dp_on_subtree[u].has_value()) return *dp_on_subtree[u];\n        *dp_on_subtree[u]\
    \ = id();\n        for (const auto& [v, w]: graph[u]) {\n            if (v ==\
    \ p) continue;\n            *dp_on_subtree[u] = op(*dp_on_subtree[u], propagate(self(v,\
    \ u), v, u, w));\n        }\n        return *dp_on_subtree[u];\n    })(0, 0);\n\
    \n    auto rerooting_dp = std::vector(n, id());\n    rec_lambda([&](auto&& self,\
    \ const size_t u, const size_t p, const value_type& to_parent) -> void {\n   \
    \     auto from_left = std::vector{ id() };\n        auto children = std::vector<E>{};\n\
    \        for (const auto& [v, w]: graph[u]) {\n            if (v == p) continue;\n\
    \            children.emplace_back(v, w);\n            from_left.emplace_back(propagate(*dp_on_subtree[v],\
    \ v, u, w));\n        }\n        rerooting_dp[u] = reduce(cbegin(from_left), cend(from_left),\
    \ to_parent, op);\n        if (empty(children)) return;\n        auto from_right\
    \ = from_left;\n        from_right.erase(begin(from_right));\n        from_right.emplace_back(id());\n\
    \        partial_sum(begin(from_left), end(from_left), begin(from_left), op);\n\
    \        partial_sum(rbegin(from_right), rend(from_right), rbegin(from_right),\
    \ op);\n        for (size_t i = 0; i < size(children); ++i) {\n            const\
    \ auto& [v, w] = children[i];\n            const auto& except_ci = op(from_left[i],\
    \ from_right[i + 1]);\n            self(v, u, propagate(op(to_parent, except_ci),\
    \ v, u, w));\n        }\n    })(0, 0, id());\n    return rerooting_dp;\n}\n"
  dependsOn:
  - lib/utility/rec_lambda.hpp
  isVerificationFile: false
  path: lib/utility/rerooting_dp.hpp
  requiredBy: []
  timestamp: '2022-01-25 23:16:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1595.test.cpp
documentation_of: lib/utility/rerooting_dp.hpp
layout: document
title: "Rerooting DP / \u5168\u65B9\u4F4D\u6728 DP"
---

木上の catamorphism を考える。
ある頂点を根とした catamorphism は自明な木 DP により $\mathcal{O}(N)$ で求まる。 これを各頂点から求めるとき、愚直な解法を用いると $\mathcal{O}(N^2)}$ だが、適切な工夫により $\mathcal{O}(N)$ に時間計算量を落とすことが可能である。

## Usage
- `rerooting_dp<value_type>(std::vector<std::vector<E>> const& g, F const& op, H const& id, G const& propagate) -> std::vector<value_type>`: `op`, `id`, `propagate` で全頂点からの catamorphism を求める。

## Reference
- https://rsk0315.github.io/library-rs/nekolib/graph/tree/struct.Tree.html
- https://qiita.com/keymoon/items/2a52f1b0fb7ef67fb89e
- https://ei1333.hateblo.jp/entry/2017/04/10/224413
ss
