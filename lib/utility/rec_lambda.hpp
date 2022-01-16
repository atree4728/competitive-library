#pragma once

#include <utility>

template<class F> struct rec_lambda {
    F f;
    explicit constexpr rec_lambda(F&& f): f(std::forward<F>(f)) {}
    template<class... Args> constexpr decltype(auto) operator()(Args&&... args) const {
        return f(*this, std::forward<Args>(args)...);
    }
};
