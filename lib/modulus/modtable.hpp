#pragma once

#include <cassert>
#include <vector>

template<typename M> class ModTable {
    std::vector<M> m_fact, m_fact_inv, m_inv;

  public:
    constexpr ModTable() = default;
    constexpr ModTable(const size_t n): m_fact(n + 1), m_fact_inv(n + 1), m_inv(n + 1) {
        m_inv[1] = 1;
        for (size_t i = 2; i <= n; ++i) m_inv[i] = -m_inv[M::mod() % i] * (M::mod() / i);
        m_fact[0] = 1;
        for (size_t i = 0; i < n; i++) m_fact[i + 1] = m_fact[i] * M{ i + 1 };
        m_fact_inv[n] = m_fact[n].inv();
        for (size_t i = n; i--;) m_fact_inv[i] = m_fact_inv[i + 1] * M{ i + 1 };
    }
    constexpr auto inv(const int i) const {
        assert(i != 0);
        return m_inv[i];
    }
    constexpr auto fact(const int i) const { return m_fact[i]; }
    constexpr auto fact_inv(const int i) const { return m_fact_inv[i]; }
    constexpr auto perm(const int i, const int j) const { return i >= j ? fact(i) * fact_inv(i - j) : 0; }
    constexpr auto binom(const int i, const int j) const {
        if (i < 0 or j < 0 or i < j) return M::raw(0);
        return m_fact[i] * m_fact_inv[j] * m_fact_inv[i - j];
    }
    constexpr auto homo(const int i, const int j) const {
        if (i == 0 and j == 0) return M::raw(1);
        return binom(i + j - 1, j);
    }
};
