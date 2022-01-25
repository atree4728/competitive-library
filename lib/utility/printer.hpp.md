---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/utility/type.hpp
    title: lib/utility/type.hpp
  - icon: ':heavy_check_mark:'
    path: lib/utility/type_traits.hpp
    title: lib/utility/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/utility/io.hpp
    title: lib/utility/io.hpp
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
  bundledCode: "#line 2 \"lib/utility/printer.hpp\"\n\n#include <iostream>\n#include\
    \ <tuple>\n#line 2 \"lib/utility/type_traits.hpp\"\n\n#line 5 \"lib/utility/type_traits.hpp\"\
    \n#include <type_traits>\n\n#line 2 \"lib/utility/type.hpp\"\n\n#include <cstddef>\n\
    #include <cstdint>\n\nusing i32 = std::int_fast32_t;\nusing u32 = std::uint_fast32_t;\n\
    using i64 = std::int_fast64_t;\nusing u64 = std::uint_fast64_t;\nusing usize =\
    \ std::size_t;\nusing bit_t = u64;\n\nconstexpr auto operator\"\"_i32(unsigned\
    \ long long n) noexcept { return static_cast<i32>(n); }\nconstexpr auto operator\"\
    \"_i64(unsigned long long n) noexcept { return static_cast<i64>(n); }\nconstexpr\
    \ auto operator\"\"_u32(unsigned long long n) noexcept { return static_cast<u32>(n);\
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
    INDEXED_IMPL(u64)\nINDEXED_IMPL(usize)\n#undef INDEXED_IMPL\n#line 6 \"lib/utility/printer.hpp\"\
    \n\nnamespace print_values {\ninline constexpr char sep = ' ';\ninline constexpr\
    \ char eoln = '\\n';\ninline constexpr auto yes = \"Yes\";\ninline constexpr auto\
    \ no = \"No\";\n}  // namespace print_values\n\ninline auto print(){};\n\ntemplate<class\
    \ T> inline auto print(T&&) -> void;\n\ntemplate<class Tp, std::size_t... I> inline\
    \ auto tuple_print(Tp&& tp, std::index_sequence<I...>) -> void {\n    (\n    \
    \    [&] {\n            print(std::forward<decltype(std::get<I>(tp))>(std::get<I>(tp)));\n\
    \            if constexpr (I + 1 != std::tuple_size_v<std::decay_t<Tp>>) print(print_values::sep);\n\
    \        }(),\n        ...);\n}\n\ntemplate<class...> constexpr bool false_v =\
    \ false;\ntemplate<class T> inline auto print(T&& x) -> void {\n    if constexpr\
    \ (is_printable<std::decay_t<T>>::value) {\n        if constexpr (std::is_same_v<bool,\
    \ std::decay_t<T>>) std::cout << (x ? print_values::yes : print_values::no);\n\
    \        else std::cout << x;\n    } else if constexpr (is_tuple_like<std::decay_t<T>>::value)\
    \ {\n        tuple_print(std::forward<T>(x), std::make_index_sequence<std::tuple_size_v<std::decay_t<T>>>());\n\
    \    } else if constexpr (is_iteratable<T>::value) {\n        for (auto it = std::begin(x);\
    \ it != std::end(x); ++it) {\n            print(std::forward<decltype(*it)>(*it));\n\
    \            if (next(it) != std::end(x)) print(print_values::sep);\n        }\n\
    \    } else {\n        static_assert(false_v<T>, \"print: got an unexpented type.\"\
    );\n    }\n}\n\ntemplate<class T, class... Args> inline auto print(T&& t, Args&&...\
    \ args) {\n    print(std::forward<T>(t));\n    print(print_values::sep);\n   \
    \ print(std::forward<Args>(args)...);\n}\n\ntemplate<class... Args> inline auto\
    \ println(Args&&... args) {\n    print(std::forward<Args>(args)...);\n    print(print_values::eoln);\n\
    }\n\ntemplate<class... Args> [[noreturn]] inline auto drop(Args&&... args) {\n\
    \    println(std::forward<Args>(args)...);\n    exit(0);\n}\n"
  code: "#pragma once\n\n#include <iostream>\n#include <tuple>\n#include \"lib/utility/type_traits.hpp\"\
    \n\nnamespace print_values {\ninline constexpr char sep = ' ';\ninline constexpr\
    \ char eoln = '\\n';\ninline constexpr auto yes = \"Yes\";\ninline constexpr auto\
    \ no = \"No\";\n}  // namespace print_values\n\ninline auto print(){};\n\ntemplate<class\
    \ T> inline auto print(T&&) -> void;\n\ntemplate<class Tp, std::size_t... I> inline\
    \ auto tuple_print(Tp&& tp, std::index_sequence<I...>) -> void {\n    (\n    \
    \    [&] {\n            print(std::forward<decltype(std::get<I>(tp))>(std::get<I>(tp)));\n\
    \            if constexpr (I + 1 != std::tuple_size_v<std::decay_t<Tp>>) print(print_values::sep);\n\
    \        }(),\n        ...);\n}\n\ntemplate<class...> constexpr bool false_v =\
    \ false;\ntemplate<class T> inline auto print(T&& x) -> void {\n    if constexpr\
    \ (is_printable<std::decay_t<T>>::value) {\n        if constexpr (std::is_same_v<bool,\
    \ std::decay_t<T>>) std::cout << (x ? print_values::yes : print_values::no);\n\
    \        else std::cout << x;\n    } else if constexpr (is_tuple_like<std::decay_t<T>>::value)\
    \ {\n        tuple_print(std::forward<T>(x), std::make_index_sequence<std::tuple_size_v<std::decay_t<T>>>());\n\
    \    } else if constexpr (is_iteratable<T>::value) {\n        for (auto it = std::begin(x);\
    \ it != std::end(x); ++it) {\n            print(std::forward<decltype(*it)>(*it));\n\
    \            if (next(it) != std::end(x)) print(print_values::sep);\n        }\n\
    \    } else {\n        static_assert(false_v<T>, \"print: got an unexpented type.\"\
    );\n    }\n}\n\ntemplate<class T, class... Args> inline auto print(T&& t, Args&&...\
    \ args) {\n    print(std::forward<T>(t));\n    print(print_values::sep);\n   \
    \ print(std::forward<Args>(args)...);\n}\n\ntemplate<class... Args> inline auto\
    \ println(Args&&... args) {\n    print(std::forward<Args>(args)...);\n    print(print_values::eoln);\n\
    }\n\ntemplate<class... Args> [[noreturn]] inline auto drop(Args&&... args) {\n\
    \    println(std::forward<Args>(args)...);\n    exit(0);\n}\n"
  dependsOn:
  - lib/utility/type_traits.hpp
  - lib/utility/type.hpp
  isVerificationFile: false
  path: lib/utility/printer.hpp
  requiredBy:
  - lib/utility/template.hpp
  - lib/utility/io.hpp
  timestamp: '2022-01-25 23:16:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1595.test.cpp
documentation_of: lib/utility/printer.hpp
layout: document
redirect_from:
- /library/lib/utility/printer.hpp
- /library/lib/utility/printer.hpp.html
title: lib/utility/printer.hpp
---
