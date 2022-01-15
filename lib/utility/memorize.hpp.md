---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/utility/memorize.hpp\"\n\n#include <array>\n#include\
    \ <map>\n#include <optional>\n\nnamespace {\ntemplate<class T, size_t N, size_t...\
    \ Extents> struct ndarray_impl {\n    using type = std::array<class ndarray_impl<T,\
    \ Extents...>::type, N>;\n};\ntemplate<class T, size_t N> struct ndarray_impl<T,\
    \ N> { using type = std::array<T, N>; };\n\ntemplate<class T, size_t... Extents>\
    \ using ndarray = typename ndarray_impl<T, Extents...>::type;\n\ntemplate<class\
    \ T, size_t N, size_t... Extents, class... Args>\nconstexpr T& ndarray_at(ndarray<T,\
    \ N, Extents...>& ary, size_t i, Args... args) {\n    if constexpr (sizeof...(Extents)\
    \ == 0) return ary[i];\n    else return ndarray_at<T, Extents...>(ary[i], args...);\n\
    }\n\ntemplate<class F, size_t... Extents> struct rec_memorize_impl {\n    F f;\n\
    \    rec_memorize_impl(F&& f_): f(std::forward<F>(f_)) {}\n    template<class...\
    \ Args> decltype(auto) operator()(Args&&... args) const {\n        using R = std::invoke_result_t<std::decay_t<F>,\
    \ decltype(*this), Args...>;\n        static ndarray<std::optional<R>, Extents...>\
    \ memo;\n        if (not ndarray_at<std::optional<R>, Extents...>(memo, args...))\n\
    \            ndarray_at<std::optional<R>, Extents...>(memo, args...) = f(*this,\
    \ args...);\n        return ndarray_at<std::optional<R>, Extents...>(memo, args...).value();\n\
    \    }\n};\n\ntemplate<class F> struct rec_memorize_impl_on_map {\n    F f;\n\
    \    rec_memorize_impl_on_map(F&& f_): f(std::forward<F>(f_)) {}\n    template<class...\
    \ Args> decltype(auto) operator()(Args&&... args) const {\n        using R = std::invoke_result_t<std::decay_t<F>,\
    \ decltype(*this), Args...>;\n        static std::map<std::tuple<std::decay_t<Args>...>,\
    \ R> memo{};\n        return memo[{ args... }] = f(*this, args...);\n    }\n};\n\
    }  // namespace\n\ntemplate<size_t E0, size_t... Extents, class F> decltype(auto)\
    \ rec_memorize(F&& f) {\n    return rec_memorize_impl<F, E0, Extents...>(std::forward<F>(f));\n\
    }\n\ntemplate<class F> decltype(auto) rec_memorize(F&& f) { return rec_memorize_impl_on_map<F>(std::forward<F>(f));\
    \ }\n"
  code: "#pragma once\n\n#include <array>\n#include <map>\n#include <optional>\n\n\
    namespace {\ntemplate<class T, size_t N, size_t... Extents> struct ndarray_impl\
    \ {\n    using type = std::array<class ndarray_impl<T, Extents...>::type, N>;\n\
    };\ntemplate<class T, size_t N> struct ndarray_impl<T, N> { using type = std::array<T,\
    \ N>; };\n\ntemplate<class T, size_t... Extents> using ndarray = typename ndarray_impl<T,\
    \ Extents...>::type;\n\ntemplate<class T, size_t N, size_t... Extents, class...\
    \ Args>\nconstexpr T& ndarray_at(ndarray<T, N, Extents...>& ary, size_t i, Args...\
    \ args) {\n    if constexpr (sizeof...(Extents) == 0) return ary[i];\n    else\
    \ return ndarray_at<T, Extents...>(ary[i], args...);\n}\n\ntemplate<class F, size_t...\
    \ Extents> struct rec_memorize_impl {\n    F f;\n    rec_memorize_impl(F&& f_):\
    \ f(std::forward<F>(f_)) {}\n    template<class... Args> decltype(auto) operator()(Args&&...\
    \ args) const {\n        using R = std::invoke_result_t<std::decay_t<F>, decltype(*this),\
    \ Args...>;\n        static ndarray<std::optional<R>, Extents...> memo;\n    \
    \    if (not ndarray_at<std::optional<R>, Extents...>(memo, args...))\n      \
    \      ndarray_at<std::optional<R>, Extents...>(memo, args...) = f(*this, args...);\n\
    \        return ndarray_at<std::optional<R>, Extents...>(memo, args...).value();\n\
    \    }\n};\n\ntemplate<class F> struct rec_memorize_impl_on_map {\n    F f;\n\
    \    rec_memorize_impl_on_map(F&& f_): f(std::forward<F>(f_)) {}\n    template<class...\
    \ Args> decltype(auto) operator()(Args&&... args) const {\n        using R = std::invoke_result_t<std::decay_t<F>,\
    \ decltype(*this), Args...>;\n        static std::map<std::tuple<std::decay_t<Args>...>,\
    \ R> memo{};\n        return memo[{ args... }] = f(*this, args...);\n    }\n};\n\
    }  // namespace\n\ntemplate<size_t E0, size_t... Extents, class F> decltype(auto)\
    \ rec_memorize(F&& f) {\n    return rec_memorize_impl<F, E0, Extents...>(std::forward<F>(f));\n\
    }\n\ntemplate<class F> decltype(auto) rec_memorize(F&& f) { return rec_memorize_impl_on_map<F>(std::forward<F>(f));\
    \ }\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/utility/memorize.hpp
  requiredBy: []
  timestamp: '2022-01-15 17:41:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/utility/memorize.hpp
layout: document
title: Recursively Memorize
---

[C++14 における自動メモ化再帰](https://taotao54321.hatenablog.com/entry/2019/07/20/003446) を C++17 で書き直した。

## Usage
```
auto dfs = rec_memorize<limit_of_t1, limit_of_t2, limit_of_t3, ...>([&](auto &&self, T1, T2, T3, ...) -> R { ... });
auto ans = dfs(T1, T2, T3, ...);
```
