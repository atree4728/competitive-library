#pragma once

#include <array>
#include <optional>

namespace {
template<typename T, size_t N, size_t... Extents> struct ndarray_impl {
    using type = std::array<typename ndarray_impl<T, Extents...>::type, N>;
};
template<typename T, size_t N> struct ndarray_impl<T, N> { using type = std::array<T, N>; };

template<typename T, size_t... Extents> using ndarray = typename ndarray_impl<T, Extents...>::type;

template<typename T, size_t N, size_t... Extents, typename... Args>
constexpr T& ndarray_at(ndarray<T, N, Extents...>& ary, size_t i, Args... args) {
    if constexpr (sizeof...(Extents) == 0) return ary[i];
    else return ndarray_at<T, Extents...>(ary[i], args...);
}

template<typename F, size_t... Extents> struct rec_memorize_impl {
    F f;
    rec_memorize_impl(F&& f_): f(std::forward<F>(f_)) {}
    template<typename... Args> decltype(auto) operator()(Args... args) const {
        using Result = decltype(f(*this, args...));
        static ndarray<std::optional<Result>, Extents...> memo;
        if (not ndarray_at<std::optional<Result>, Extents...>(memo, args...))
            ndarray_at<std::optional<Result>, Extents...>(memo, args...) = f(*this, args...);
        return ndarray_at<std::optional<Result>, Extents...>(memo, args...).value();
    }
};
}  // namespace

template<size_t... Extents, typename F> decltype(auto) rec_memorize(F&& f) {
    return rec_memorize_impl<F, Extents...>(std::forward<F>(f));
}
