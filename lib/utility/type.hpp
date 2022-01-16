#pragma once

#include <cstddef>
#include <cstdint>

using i32 = std::int_fast32_t;
using u32 = std::uint_fast32_t;
using i64 = std::int_fast64_t;
using u64 = std::uint_fast64_t;
using usize = std::size_t;
using bit_t = u64;

constexpr auto operator""_i32(unsigned long long n) noexcept { return static_cast<i32>(n); }
constexpr auto operator""_i64(unsigned long long n) noexcept { return static_cast<i64>(n); }
constexpr auto operator""_u32(unsigned long long n) noexcept { return static_cast<u32>(n); }
constexpr auto operator""_u64(unsigned long long n) noexcept { return static_cast<u64>(n); }
constexpr auto operator""_uz(unsigned long long n) noexcept { return static_cast<usize>(n); }
constexpr auto operator""_bit(unsigned long long n) noexcept { return static_cast<bit_t>(n); }
