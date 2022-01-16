#pragma once

#include <cstdint>
#include <limits>

using bit_t = std::uint_fast64_t;

constexpr inline auto countr_zero(bit_t n) -> int { return n == 0 ? 64 : __builtin_ctzll(n); }
constexpr inline auto countl_zero(bit_t n) -> int { return n == 0 ? 64 : __builtin_clzll(n); }
constexpr inline auto countr_one(bit_t n) -> int { return n == std::numeric_limits<bit_t>::max() ? 64 : countr_zero(compl n); }
constexpr inline auto countl_one(bit_t n) -> int { return n == std::numeric_limits<bit_t>::max() ? 64 : countl_zero(compl n); }
constexpr inline auto mask(unsigned int n) -> bit_t { return (static_cast<bit_t>(1) << n) - 1; }
constexpr inline auto popcount(bit_t n) -> int { return __builtin_popcountll(n); }
constexpr inline auto is_pow2(bit_t n) -> bool { return (n & (n - 1)) == 0; }
constexpr inline auto msb(bit_t n) -> int { return 63 - countl_zero(n); }
constexpr inline auto bit_ceil(bit_t n) -> bit_t { return is_pow2(n) ? n : static_cast<bit_t>(1) << msb(n); }
constexpr inline auto bit_floor(bit_t n) -> bit_t { return is_pow2(n) ? n : static_cast<bit_t>(1) << (msb(n) + 1); }
