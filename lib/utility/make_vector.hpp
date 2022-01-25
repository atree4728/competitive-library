#pragma once

#include <vector>
#include "lib/utility/rec_lambda.hpp"

template<class T, size_t N> auto construct_vector(std::vector<size_t>& sizes, T x = std::decay_t<T>{}) {
    if constexpr (N == 1) {
        return std::vector<std::decay_t<T>>(sizes[0], x);
    } else {
        size_t size = sizes[N - 1];
        sizes.pop_back();
        return std::vector(size, construct_vector<T, N - 1>(sizes, x));
    }
}

template<class T, size_t N> decltype(auto) make_vector(size_t(&&sizes)[N], T&& x = std::decay_t<T>{}) {
    std::vector<size_t> s(N);
    for (size_t i = 0; i < N; ++i) s[i] = sizes[N - i - 1];
    if constexpr (std::is_invocable_v<std::decay_t<T>>) {
        auto ret = construct_vector<std::invoke_result_t<std::decay_t<T>>, N>(s);
        rec_lambda([](auto&& self, auto& v, auto&& f) {
            for (auto it = std::begin(v); it != std::end(v); ++it) {
                if constexpr (std::is_same_v<std::decay_t<decltype(*it)>, std::invoke_result_t<decltype(f)>>) *it = f();
                else self(*it, f);
            }
        })(ret, x);
        return ret;
    } else {
        return construct_vector<std::decay_t<T>, N>(s, x);
    }
}
