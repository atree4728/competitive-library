#pragma once

#include <cassert>
#include <numeric>
#include <unordered_map>
#include <vector>

struct Sieve {
    intmax_t n;
    std::vector<intmax_t> min_factor;
    explicit Sieve(const intmax_t n): n(n), min_factor(n + 1) {
        std::iota(begin(min_factor), end(min_factor), 0);
        for (intmax_t i = 2; i * i <= n; i++) {
            if (min_factor[i] != i) continue;
            for (intmax_t mul = i * i; mul <= n; mul += i) {
                if (min_factor[mul] == mul) min_factor[mul] = i;
            }
        }
    };
    bool is_prime(const intmax_t n) {
        assert(1 <= n and n <= n);
        return n >= 2 and min_factor[n] == n;
    }
    std::vector<intmax_t> factor(intmax_t n) {
        assert(1 <= n and n <= n);
        if (n == 1) return {};
        std::vector<intmax_t> factor{};
        while (n != 1) {
            factor.emplace_back(min_factor[n]);
            n /= min_factor[n];
        }
        return factor;
    }
    intmax_t count_divisor(const intmax_t n) {
        assert(1 <= n and n <= n);
        std::unordered_map<intmax_t, intmax_t> factor_map{};
        for (const auto& p: this->factor(n)) factor_map[p]++;
        return std::transform_reduce(cbegin(factor_map), cend(factor_map), static_cast<intmax_t>(1), std::multiplies<>{},
                                     [](const auto p_e) { return p_e.second + 1; });
    }
};
