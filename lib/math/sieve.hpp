#pragma once

#include <cassert>
#include <numeric>
#include <unordered_map>
#include <vector>

template<class T = std::uint32_t> struct Sieve {
  private:
    T n;
    std::vector<T> min_factor;
    std::vector<int> m_mobius;

  public:
    explicit Sieve(const T n): n(n), min_factor(n + 1), m_mobius(n + 1, 1) {
        std::iota(begin(min_factor), end(min_factor), 0);
        for (T p = 2; p <= n; ++p) {
            if (min_factor[p] != p) continue;
            m_mobius[p] = -1;
            for (T m = p * 2; m <= n; m += p) {
                if (min_factor[m] == m) min_factor[m] = p;
                if (m / p % p == 0) m_mobius[m] = 0;
                else m_mobius[m] *= -1;
            }
        }
    };
    bool is_prime(const T n) const {
        assert(1 <= n and n <= n);
        return n >= 2 and min_factor[n] == n;
    }
    int mobius(const T n) const {
        assert(1 <= n and n <= n);
        return m_mobius[n];
    }
    std::vector<T> factor(T n) const {
        assert(1 <= n and n <= n);
        if (n == 1) return {};
        std::vector<T> factor{};
        while (n != 1) {
            factor.emplace_back(min_factor[n]);
            n /= min_factor[n];
        }
        return factor;
    }
    T count_divisor(const T n) const {
        assert(1 <= n and n <= n);
        std::unordered_map<T, T> factor_map{};
        for (const auto& p: this->factor(n)) factor_map[p]++;
        return std::transform_reduce(cbegin(factor_map), cend(factor_map), static_cast<T>(1), std::multiplies<>{},
                                     [](const auto p_e) { return p_e.second + 1; });
    }
};
