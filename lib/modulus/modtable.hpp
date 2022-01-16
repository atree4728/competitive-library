#pragma once

#include <cassert>
#include <vector>

template<typename Modint> class ModTable {
    std::vector<Modint> factorials, factorials_inv, inverse;

  public:
    constexpr ModTable() = default;
    constexpr ModTable(const size_t n): factorials(n + 1), factorials_inv(n + 1), inverse(n + 1) {
        inverse[1] = 1;
        for (size_t i = 2; i <= n; ++i) inverse[i] = -inverse[Modint::mod() % i] * (Modint::mod() / i);
        factorials[0] = 1;
        for (size_t i = 0; i < n; i++) factorials[i + 1] = factorials[i] * Modint{ i + 1 };
        factorials_inv[n] = factorials[n].inv();
        for (size_t i = n; i--;) factorials_inv[i] = factorials_inv[i + 1] * Modint{ i + 1 };
    }
    constexpr auto inv(const int i) const {
        assert(i != 0);
        return inverse[i];
    }
    constexpr auto fact(const int i) const { return factorials[i]; }
    constexpr auto fact_inv(const int i) const { return factorials_inv[i]; }
    constexpr auto perm(const int i, const int j) const { return i >= j ? fact(i) * fact_inv(i - j) : 0; }
    constexpr auto binom(const int i, const int j) const {
        if (i < 0 or j < 0 or i < j) return Modint::raw(0);
        return factorials[i] * factorials_inv[j] * factorials_inv[i - j];
    }
    constexpr auto homo(const int i, const int j) const {
        if (i == 0 and j == 0) return Modint::raw(1);
        return binom(i + j - 1, j);
    }
};
