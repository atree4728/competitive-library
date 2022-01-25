#pragma once

#include <iostream>
#include <tuple>
#include <type_traits>

#include "lib/utility/make_vector.hpp"
#include "lib/utility/type_traits.hpp"

// Copyright (c) 2021 Mitama Lab | `tuple_scan`, `scan`, `in` are based on the code released under the ISC license. see
// https://opensource.org/licenses/ISC.
template<class Tp, std::size_t... I> inline decltype(auto) tuple_scan(Tp&, std::index_sequence<I...>);

inline auto scan = [](auto&... args) {
    return (..., [&] {
        if constexpr (is_tuple_like<std::decay_t<decltype(args)>>::value) {
            return tuple_scan(args, std::make_index_sequence<std::tuple_size_v<std::decay_t<decltype(args)>>>{});
        } else {
            return not (std::cin >> args).fail();
        }
    }());
};

template<class Tp, std::size_t... I> inline auto tuple_scan(Tp& tup, std::index_sequence<I...>) {
    return (... and scan(std::get<I>(tup)));
}

template<class T, class... Args> decltype(auto) inline in();

template<class Tp, std::size_t... I> inline auto tuple_in(std::index_sequence<I...>) {
    return std::tuple{ in<typename std::tuple_element_t<I, Tp>>()... };
}

template<class T, class... Args> decltype(auto) inline in() {
    if constexpr (sizeof...(Args) == 0) {
        if constexpr (is_tuple_like<T>::value) {
            auto t = tuple_in<T>(std::make_index_sequence<std::tuple_size_v<T>>());
            return t;
        } else if constexpr (is_1indexed<T>::value) {
            typename T::base x;
            scan(x);
            --x;
            return x;
        } else {
            T x;
            scan(x);
            return x;
        }
    } else {
        return std::tuple{ in<T>(), in<Args>()... };
    }
}

template<class T, class... size_t> inline auto in_vec(size_t&&... args) {
    return make_vector({ static_cast<usize>(args)... }, *in<T>);
}
