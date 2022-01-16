---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: lib/utility/type.hpp
    title: lib/utility/type.hpp
  - icon: ':warning:'
    path: lib/utility/type_traits.hpp
    title: lib/utility/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: lib/utility/io.hpp
    title: lib/utility/io.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://opensource.org/licenses/ISC.
  bundledCode: "#line 2 \"lib/utility/scanner.hpp\"\n\n#include <iostream>\n#include\
    \ <tuple>\n#include <type_traits>\n\n#line 2 \"lib/utility/type_traits.hpp\"\n\
    \n#line 6 \"lib/utility/type_traits.hpp\"\n\n#line 2 \"lib/utility/type.hpp\"\n\
    \n#include <cstddef>\n#include <cstdint>\n\nusing i32 = std::int_fast32_t;\nusing\
    \ u32 = std::uint_fast32_t;\nusing i64 = std::int_fast64_t;\nusing u64 = std::uint_fast64_t;\n\
    using usize = std::size_t;\nusing bit_t = u64;\n\nconstexpr auto operator\"\"\
    _i32(unsigned long long n) noexcept { return static_cast<i32>(n); }\nconstexpr\
    \ auto operator\"\"_i64(unsigned long long n) noexcept { return static_cast<i64>(n);\
    \ }\nconstexpr auto operator\"\"_u32(unsigned long long n) noexcept { return static_cast<u32>(n);\
    \ }\nconstexpr auto operator\"\"_u64(unsigned long long n) noexcept { return static_cast<u64>(n);\
    \ }\nconstexpr auto operator\"\"_uz(unsigned long long n) noexcept { return static_cast<usize>(n);\
    \ }\nconstexpr auto operator\"\"_bit(unsigned long long n) noexcept { return static_cast<bit_t>(n);\
    \ }\n#line 8 \"lib/utility/type_traits.hpp\"\n\ntemplate<class> struct is_tuple_like:\
    \ std::false_type {};\ntemplate<class... Ts> struct is_tuple_like<std::tuple<Ts...>>:\
    \ std::true_type {};\ntemplate<class T1, class T2> struct is_tuple_like<std::pair<T1,\
    \ T2>>: std::true_type {};\ntemplate<class T, std::size_t N> struct is_tuple_like<std::array<T,\
    \ N>>: std::true_type {};\n\ntemplate<class, class = std::void_t<>> struct is_printable:\
    \ std::false_type {};\ntemplate<class T> struct is_printable<T, std::void_t<decltype(std::cout\
    \ << std::declval<T>())>>: std::true_type {};\n\ntemplate<class, class = std::void_t<>>\
    \ struct is_iteratable: std::false_type {};\ntemplate<class T> struct is_iteratable<T,\
    \ std::void_t<decltype(std::begin(std::declval<T>()), std::end(std::declval<T>()))>>\n\
    \    : std::true_type {};\n\ntemplate<class T> struct is_1indexed: std::false_type\
    \ {};\n#define INDEXED_IMPL(type)                                            \
    \                                                           \\\n    struct type##_##1\
    \ {                                                                          \
    \                                \\\n        using base = type;              \
    \                                                                            \
    \             \\\n    };                                                     \
    \                                                                      \\\n  \
    \  template<> struct is_1indexed<type##_##1>: std::true_type {};\nINDEXED_IMPL(int)\n\
    INDEXED_IMPL(size_t)\nINDEXED_IMPL(i32)\nINDEXED_IMPL(u32)\nINDEXED_IMPL(i64)\n\
    INDEXED_IMPL(u64)\nINDEXED_IMPL(usize)\n#undef INDEXED_IMPL\n#line 8 \"lib/utility/scanner.hpp\"\
    \n\n// Copyright (c) 2021 Mitama Lab | `tuple_scan`, `scan`, `in` are based on\
    \ the code released under the ISC license. see\n// https://opensource.org/licenses/ISC.\n\
    template<class Tp, std::size_t... I> inline decltype(auto) tuple_scan(Tp&, std::index_sequence<I...>);\n\
    \ninline auto scan = [](auto&... args) {\n    return (..., [&] {\n        if constexpr\
    \ (is_tuple_like<std::decay_t<decltype(args)>>::value) {\n            return tuple_scan(args,\
    \ std::make_index_sequence<std::tuple_size_v<std::decay_t<decltype(args)>>>{});\n\
    \        } else {\n            return not (std::cin >> args).fail();\n       \
    \ }\n    }());\n};\n\ntemplate<class Tp, std::size_t... I> inline auto tuple_scan(Tp&\
    \ tup, std::index_sequence<I...>) {\n    return (... and scan(std::get<I>(tup)));\n\
    }\n\ntemplate<class T, class... Args> decltype(auto) inline in();\n\ntemplate<class\
    \ Tp, std::size_t... I> inline auto tuple_in(std::index_sequence<I...>) {\n  \
    \  return Tp{ in<typename std::tuple_element_t<I, Tp>>()... };\n}\n\ntemplate<class\
    \ T, class... Args> decltype(auto) inline in() {\n    if constexpr (sizeof...(Args)\
    \ == 0) {\n        if constexpr (is_tuple_like<T>::value) {\n            auto\
    \ t = tuple_in<T>(std::make_index_sequence<std::tuple_size_v<T>>());\n       \
    \     return t;\n        } else if constexpr (is_1indexed<T>::value) {\n     \
    \       typename T::base x;\n            scan(x);\n            --x;\n        \
    \    return x;\n        } else {\n            T x;\n            scan(x);\n   \
    \         return x;\n        }\n    } else {\n        return std::tuple{ in<T>(),\
    \ in<Args>()... };\n    }\n}\n"
  code: "#pragma once\n\n#include <iostream>\n#include <tuple>\n#include <type_traits>\n\
    \n#include \"lib/utility/type_traits.hpp\"\n\n// Copyright (c) 2021 Mitama Lab\
    \ | `tuple_scan`, `scan`, `in` are based on the code released under the ISC license.\
    \ see\n// https://opensource.org/licenses/ISC.\ntemplate<class Tp, std::size_t...\
    \ I> inline decltype(auto) tuple_scan(Tp&, std::index_sequence<I...>);\n\ninline\
    \ auto scan = [](auto&... args) {\n    return (..., [&] {\n        if constexpr\
    \ (is_tuple_like<std::decay_t<decltype(args)>>::value) {\n            return tuple_scan(args,\
    \ std::make_index_sequence<std::tuple_size_v<std::decay_t<decltype(args)>>>{});\n\
    \        } else {\n            return not (std::cin >> args).fail();\n       \
    \ }\n    }());\n};\n\ntemplate<class Tp, std::size_t... I> inline auto tuple_scan(Tp&\
    \ tup, std::index_sequence<I...>) {\n    return (... and scan(std::get<I>(tup)));\n\
    }\n\ntemplate<class T, class... Args> decltype(auto) inline in();\n\ntemplate<class\
    \ Tp, std::size_t... I> inline auto tuple_in(std::index_sequence<I...>) {\n  \
    \  return Tp{ in<typename std::tuple_element_t<I, Tp>>()... };\n}\n\ntemplate<class\
    \ T, class... Args> decltype(auto) inline in() {\n    if constexpr (sizeof...(Args)\
    \ == 0) {\n        if constexpr (is_tuple_like<T>::value) {\n            auto\
    \ t = tuple_in<T>(std::make_index_sequence<std::tuple_size_v<T>>());\n       \
    \     return t;\n        } else if constexpr (is_1indexed<T>::value) {\n     \
    \       typename T::base x;\n            scan(x);\n            --x;\n        \
    \    return x;\n        } else {\n            T x;\n            scan(x);\n   \
    \         return x;\n        }\n    } else {\n        return std::tuple{ in<T>(),\
    \ in<Args>()... };\n    }\n}\n"
  dependsOn:
  - lib/utility/type_traits.hpp
  - lib/utility/type.hpp
  isVerificationFile: false
  path: lib/utility/scanner.hpp
  requiredBy:
  - lib/utility/io.hpp
  timestamp: '2022-01-16 21:32:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/utility/scanner.hpp
layout: document
redirect_from:
- /library/lib/utility/scanner.hpp
- /library/lib/utility/scanner.hpp.html
title: lib/utility/scanner.hpp
---
