#pragma once

#include <iostream>
#include <tuple>
#include <type_traits>

#include "lib/utility/type.hpp"

template<class> struct is_tuple_like: std::false_type {};
template<class... Ts> struct is_tuple_like<std::tuple<Ts...>>: std::true_type {};
template<class T1, class T2> struct is_tuple_like<std::pair<T1, T2>>: std::true_type {};
template<class T, std::size_t N> struct is_tuple_like<std::array<T, N>>: std::true_type {};

template<class, class = std::void_t<>> struct is_printable: std::false_type {};
template<class T> struct is_printable<T, std::void_t<decltype(std::cout << std::declval<T>())>>: std::true_type {};

template<class, class = std::void_t<>> struct is_iteratable: std::false_type {};
template<class T> struct is_iteratable<T, std::void_t<decltype(std::begin(std::declval<T>()), std::end(std::declval<T>()))>>
    : std::true_type {};

template<class T> struct is_1indexed: std::false_type {};
#define INDEXED_IMPL(type)                                                                                                       \
    struct type##_##1 {                                                                                                          \
        using base = type;                                                                                                       \
    };                                                                                                                           \
    template<> struct is_1indexed<type##_##1>: std::true_type {};
INDEXED_IMPL(int)
INDEXED_IMPL(size_t)
INDEXED_IMPL(i32)
INDEXED_IMPL(u32)
INDEXED_IMPL(i64)
INDEXED_IMPL(u64)
INDEXED_IMPL(usize)
#undef INDEXED_IMPL
