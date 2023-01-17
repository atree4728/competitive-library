---
data:
  _extendedDependsOn: []
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
  - icon: ':heavy_check_mark:'
    path: lib/utility/type_traits.hpp
    title: lib/utility/type_traits.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1595.test.cpp
    title: test/aoj/1595.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 2 "lib/utility/type.hpp"


    #include <cstddef>

    #include <cstdint>


    using i32 = std::int_fast32_t;

    using u32 = std::uint_fast32_t;

    using i64 = std::int_fast64_t;

    using u64 = std::uint_fast64_t;

    using usize = std::size_t;

    using bit_t = u64;


    constexpr auto operator""_i32(unsigned long long n) noexcept { return static_cast<i32>(n);
    }

    constexpr auto operator""_i64(unsigned long long n) noexcept { return static_cast<i64>(n);
    }

    constexpr auto operator""_u32(unsigned long long n) noexcept { return static_cast<u32>(n);
    }

    constexpr auto operator""_u64(unsigned long long n) noexcept { return static_cast<u64>(n);
    }

    constexpr auto operator""_uz(unsigned long long n) noexcept { return static_cast<usize>(n);
    }

    constexpr auto operator""_bit(unsigned long long n) noexcept { return static_cast<bit_t>(n);
    }

    '
  code: '#pragma once


    #include <cstddef>

    #include <cstdint>


    using i32 = std::int_fast32_t;

    using u32 = std::uint_fast32_t;

    using i64 = std::int_fast64_t;

    using u64 = std::uint_fast64_t;

    using usize = std::size_t;

    using bit_t = u64;


    constexpr auto operator""_i32(unsigned long long n) noexcept { return static_cast<i32>(n);
    }

    constexpr auto operator""_i64(unsigned long long n) noexcept { return static_cast<i64>(n);
    }

    constexpr auto operator""_u32(unsigned long long n) noexcept { return static_cast<u32>(n);
    }

    constexpr auto operator""_u64(unsigned long long n) noexcept { return static_cast<u64>(n);
    }

    constexpr auto operator""_uz(unsigned long long n) noexcept { return static_cast<usize>(n);
    }

    constexpr auto operator""_bit(unsigned long long n) noexcept { return static_cast<bit_t>(n);
    }

    '
  dependsOn: []
  isVerificationFile: false
  path: lib/utility/type.hpp
  requiredBy:
  - lib/utility/type_traits.hpp
  - lib/utility/scanner.hpp
  - lib/utility/printer.hpp
  - lib/utility/io.hpp
  - lib/utility/template.hpp
  timestamp: '2022-01-16 21:32:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1595.test.cpp
documentation_of: lib/utility/type.hpp
layout: document
redirect_from:
- /library/lib/utility/type.hpp
- /library/lib/utility/type.hpp.html
title: lib/utility/type.hpp
---
