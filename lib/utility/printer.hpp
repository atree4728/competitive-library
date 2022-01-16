#pragma once

#include <iostream>
#include <tuple>
#include "lib/utility/type_traits.hpp"

namespace print_values {
inline constexpr char sep = ' ';
inline constexpr char eoln = '\n';
inline constexpr auto yes = "Yes";
inline constexpr auto no = "No";
}  // namespace print_values

inline auto print(){};

template<class T> inline auto print(T&&) -> void;

template<class Tp, std::size_t... I> inline auto tuple_print(Tp&& tp, std::index_sequence<I...>) -> void {
    (
        [&] {
            print(std::forward<decltype(std::get<I>(tp))>(std::get<I>(tp)));
            if constexpr (I + 1 != std::tuple_size_v<std::decay_t<Tp>>) print(print_values::sep);
        }(),
        ...);
}

template<class...> constexpr bool false_v = false;
template<class T> inline auto print(T&& x) -> void {
    if constexpr (is_printable<std::decay_t<T>>::value) {
        if constexpr (std::is_same_v<bool, std::decay_t<T>>) std::cout << (x ? print_values::yes : print_values::no);
        else std::cout << x;
    } else if constexpr (is_tuple_like<std::decay_t<T>>::value) {
        tuple_print(std::forward<T>(x), std::make_index_sequence<std::tuple_size_v<std::decay_t<T>>>());
    } else if constexpr (is_iteratable<T>::value) {
        for (auto it = std::begin(x); it != std::end(x); ++it) {
            print(std::forward<typename std::decay_t<T>::value_type>(*it));
            if (next(it) != std::end(x)) print(print_values::sep);
        }
    } else {
        static_assert(false_v<T>, "print: got an unexpented type.");
    }
}

template<class T, class... Args> inline auto print(T&& t, Args&&... args) {
    print(std::forward<T>(t));
    print(print_values::sep);
    print(std::forward<Args>(args)...);
}

template<class... Args> inline auto println(Args&&... args) {
    print(std::forward<Args>(args)...);
    print(print_values::eoln);
}

template<class... Args> [[noreturn]] inline auto drop(Args&&... args) {
    println(std::forward<Args>(args)...);
    exit(0);
}
