#pragma once

#include <utility>

template<class T, class U = T> constexpr inline auto chmin(T& a, U&& b) -> bool {
    return b < a ? a = std::forward<U>(b), true : false;
}
template<class T, class U = T> constexpr inline auto chmax(T& a, U&& b) -> bool {
    return a < b ? a = std::forward<U>(b), true : false;
}
