#pragma once

#include <array>
#include <map>
#include <optional>

namespace {
template<class T, size_t N, size_t... Extents> struct ndarray_impl {
    using type = std::array<class ndarray_impl<T, Extents...>::type, N>;
};
template<class T, size_t N> struct ndarray_impl<T, N> { using type = std::array<T, N>; };

template<class T, size_t... Extents> using ndarray = typename ndarray_impl<T, Extents...>::type;

template<class T, size_t N, size_t... Extents, class... Args>
constexpr T& ndarray_at(ndarray<T, N, Extents...>& ary, size_t i, Args... args) {
    if constexpr (sizeof...(Extents) == 0) return ary[i];
    else return ndarray_at<T, Extents...>(ary[i], args...);
}

template<class F, size_t... Extents> struct rec_memorize_impl {
    F f;
    rec_memorize_impl(F&& f_): f(std::forward<F>(f_)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) const {
        using R = std::invoke_result_t<std::decay_t<F>, decltype(*this), Args...>;
        static ndarray<std::optional<R>, Extents...> memo;
        if (not ndarray_at<std::optional<R>, Extents...>(memo, args...))
            ndarray_at<std::optional<R>, Extents...>(memo, args...) = f(*this, args...);
        return ndarray_at<std::optional<R>, Extents...>(memo, args...).value();
    }
};

template<class F> struct rec_memorize_impl_on_map {
    F f;
    rec_memorize_impl_on_map(F&& f_): f(std::forward<F>(f_)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) const {
        using R = std::invoke_result_t<std::decay_t<F>, decltype(*this), Args...>;
        static std::map<std::tuple<std::decay_t<Args>...>, R> memo{};
        return memo[{ args... }] = f(*this, args...);
    }
};
}  // namespace

template<size_t E0, size_t... Extents, class F> decltype(auto) rec_memorize(F&& f) {
    return rec_memorize_impl<F, E0, Extents...>(std::forward<F>(f));
}

template<class F> decltype(auto) rec_memorize(F&& f) { return rec_memorize_impl_on_map<F>(std::forward<F>(f)); }
