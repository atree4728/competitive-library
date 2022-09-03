---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/utility/rec_lambda.hpp
    title: lib/utility/rec_lambda.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/utility/io.hpp
    title: lib/utility/io.hpp
  - icon: ':heavy_check_mark:'
    path: lib/utility/scanner.hpp
    title: lib/utility/scanner.hpp
  - icon: ':heavy_check_mark:'
    path: lib/utility/template.hpp
    title: lib/utility/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1595.test.cpp
    title: test/aoj/1595.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/utility/make_vector.hpp\"\n\n#include <vector>\n#line\
    \ 2 \"lib/utility/rec_lambda.hpp\"\n\n#include <utility>\n\ntemplate<class F>\
    \ struct rec_lambda {\n    F f;\n    explicit constexpr rec_lambda(F&& f): f(std::forward<F>(f))\
    \ {}\n    template<class... Args> constexpr decltype(auto) operator()(Args&&...\
    \ args) const {\n        return f(*this, std::forward<Args>(args)...);\n    }\n\
    };\n#line 5 \"lib/utility/make_vector.hpp\"\n\ntemplate<class T, size_t N> auto\
    \ construct_vector(std::vector<size_t>& sizes, T x = std::decay_t<T>{}) {\n  \
    \  if constexpr (N == 1) {\n        return std::vector<std::decay_t<T>>(sizes[0],\
    \ x);\n    } else {\n        size_t size = sizes[N - 1];\n        sizes.pop_back();\n\
    \        return std::vector(size, construct_vector<T, N - 1>(sizes, x));\n   \
    \ }\n}\n\ntemplate<class T, size_t N> decltype(auto) make_vector(size_t(&&sizes)[N],\
    \ T&& x = std::decay_t<T>{}) {\n    std::vector<size_t> s(N);\n    for (size_t\
    \ i = 0; i < N; ++i) s[i] = sizes[N - i - 1];\n    if constexpr (std::is_invocable_v<std::decay_t<T>>)\
    \ {\n        auto ret = construct_vector<std::invoke_result_t<std::decay_t<T>>,\
    \ N>(s);\n        rec_lambda([](auto&& self, auto& v, auto&& f) {\n          \
    \  for (auto it = std::begin(v); it != std::end(v); ++it) {\n                if\
    \ constexpr (std::is_same_v<std::decay_t<decltype(*it)>, std::invoke_result_t<decltype(f)>>)\
    \ *it = f();\n                else self(*it, f);\n            }\n        })(ret,\
    \ x);\n        return ret;\n    } else {\n        return construct_vector<std::decay_t<T>,\
    \ N>(s, x);\n    }\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include \"lib/utility/rec_lambda.hpp\"\
    \n\ntemplate<class T, size_t N> auto construct_vector(std::vector<size_t>& sizes,\
    \ T x = std::decay_t<T>{}) {\n    if constexpr (N == 1) {\n        return std::vector<std::decay_t<T>>(sizes[0],\
    \ x);\n    } else {\n        size_t size = sizes[N - 1];\n        sizes.pop_back();\n\
    \        return std::vector(size, construct_vector<T, N - 1>(sizes, x));\n   \
    \ }\n}\n\ntemplate<class T, size_t N> decltype(auto) make_vector(size_t(&&sizes)[N],\
    \ T&& x = std::decay_t<T>{}) {\n    std::vector<size_t> s(N);\n    for (size_t\
    \ i = 0; i < N; ++i) s[i] = sizes[N - i - 1];\n    if constexpr (std::is_invocable_v<std::decay_t<T>>)\
    \ {\n        auto ret = construct_vector<std::invoke_result_t<std::decay_t<T>>,\
    \ N>(s);\n        rec_lambda([](auto&& self, auto& v, auto&& f) {\n          \
    \  for (auto it = std::begin(v); it != std::end(v); ++it) {\n                if\
    \ constexpr (std::is_same_v<std::decay_t<decltype(*it)>, std::invoke_result_t<decltype(f)>>)\
    \ *it = f();\n                else self(*it, f);\n            }\n        })(ret,\
    \ x);\n        return ret;\n    } else {\n        return construct_vector<std::decay_t<T>,\
    \ N>(s, x);\n    }\n}\n"
  dependsOn:
  - lib/utility/rec_lambda.hpp
  isVerificationFile: false
  path: lib/utility/make_vector.hpp
  requiredBy:
  - lib/utility/io.hpp
  - lib/utility/scanner.hpp
  - lib/utility/template.hpp
  timestamp: '2022-01-25 23:16:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1595.test.cpp
documentation_of: lib/utility/make_vector.hpp
layout: document
redirect_from:
- /library/lib/utility/make_vector.hpp
- /library/lib/utility/make_vector.hpp.html
title: lib/utility/make_vector.hpp
---
