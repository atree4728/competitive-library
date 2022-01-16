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
  bundledCode: "#line 2 \"lib/utility/make_vector.hpp\"\n\n#include <vector>\n\ntemplate<class\
    \ T, size_t N> auto construct_vector(std::vector<size_t>& sizes, T x = std::decay_t<T>{})\
    \ {\n    if constexpr (N == 1) {\n        return std::vector<std::decay_t<T>>(sizes[0],\
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
  code: "#pragma once\n\n#include <vector>\n\ntemplate<class T, size_t N> auto construct_vector(std::vector<size_t>&\
    \ sizes, T x = std::decay_t<T>{}) {\n    if constexpr (N == 1) {\n        return\
    \ std::vector<std::decay_t<T>>(sizes[0], x);\n    } else {\n        size_t size\
    \ = sizes[N - 1];\n        sizes.pop_back();\n        return std::vector(size,\
    \ construct_vector<T, N - 1>(sizes, x));\n    }\n}\n\ntemplate<class T, size_t\
    \ N> decltype(auto) make_vector(size_t(&&sizes)[N], T&& x = std::decay_t<T>{})\
    \ {\n    std::vector<size_t> s(N);\n    for (size_t i = 0; i < N; ++i) s[i] =\
    \ sizes[N - i - 1];\n    if constexpr (std::is_invocable_v<std::decay_t<T>>) {\n\
    \        auto ret = construct_vector<std::invoke_result_t<std::decay_t<T>>, N>(s);\n\
    \        rec_lambda([](auto&& self, auto& v, auto&& f) {\n            for (auto\
    \ it = std::begin(v); it != std::end(v); ++it) {\n                if constexpr\
    \ (std::is_same_v<std::decay_t<decltype(*it)>, std::invoke_result_t<decltype(f)>>)\
    \ *it = f();\n                else self(*it, f);\n            }\n        })(ret,\
    \ x);\n        return ret;\n    } else {\n        return construct_vector<std::decay_t<T>,\
    \ N>(s, x);\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/utility/make_vector.hpp
  requiredBy: []
  timestamp: '2022-01-16 21:32:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/utility/make_vector.hpp
layout: document
redirect_from:
- /library/lib/utility/make_vector.hpp
- /library/lib/utility/make_vector.hpp.html
title: lib/utility/make_vector.hpp
---
