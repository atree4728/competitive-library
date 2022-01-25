---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/utility/type.hpp
    title: lib/utility/type.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/utility/io.hpp
    title: lib/utility/io.hpp
  - icon: ':heavy_check_mark:'
    path: lib/utility/printer.hpp
    title: lib/utility/printer.hpp
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
  bundledCode: "#line 2 \"lib/utility/type_traits.hpp\"\n\n#include <iostream>\n#include\
    \ <tuple>\n#include <type_traits>\n\n#line 2 \"lib/utility/type.hpp\"\n\n#include\
    \ <cstddef>\n#include <cstdint>\n\nusing i32 = std::int_fast32_t;\nusing u32 =\
    \ std::uint_fast32_t;\nusing i64 = std::int_fast64_t;\nusing u64 = std::uint_fast64_t;\n\
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
    INDEXED_IMPL(u64)\nINDEXED_IMPL(usize)\n#undef INDEXED_IMPL\n"
  code: "#pragma once\n\n#include <iostream>\n#include <tuple>\n#include <type_traits>\n\
    \n#include \"lib/utility/type.hpp\"\n\ntemplate<class> struct is_tuple_like: std::false_type\
    \ {};\ntemplate<class... Ts> struct is_tuple_like<std::tuple<Ts...>>: std::true_type\
    \ {};\ntemplate<class T1, class T2> struct is_tuple_like<std::pair<T1, T2>>: std::true_type\
    \ {};\ntemplate<class T, std::size_t N> struct is_tuple_like<std::array<T, N>>:\
    \ std::true_type {};\n\ntemplate<class, class = std::void_t<>> struct is_printable:\
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
    INDEXED_IMPL(u64)\nINDEXED_IMPL(usize)\n#undef INDEXED_IMPL\n"
  dependsOn:
  - lib/utility/type.hpp
  isVerificationFile: false
  path: lib/utility/type_traits.hpp
  requiredBy:
  - lib/utility/printer.hpp
  - lib/utility/template.hpp
  - lib/utility/scanner.hpp
  - lib/utility/io.hpp
  timestamp: '2022-01-16 21:32:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1595.test.cpp
documentation_of: lib/utility/type_traits.hpp
layout: document
redirect_from:
- /library/lib/utility/type_traits.hpp
- /library/lib/utility/type_traits.hpp.html
title: lib/utility/type_traits.hpp
---
