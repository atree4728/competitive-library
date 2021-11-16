#pragma once

/**
 * @brief Finite Field / 有限体
 */

#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include "lib/math/extgcd.hpp"

template<intmax_t Modulo> struct Modint {
    using value_type = typename std::conditional_t < 0 < Modulo and Modulo<std::numeric_limits<int>::max() / 2, int, intmax_t>;

  private:
    value_type value = 0;
    static constexpr value_type compiletime_mod = Modulo;
    static value_type runtime_mod;
    static constexpr value_type normalize(intmax_t n, value_type m) {
        if (n >= m) n %= m;
        else if (n < 0 and (n %= m) < 0) n += m;
        return n;
    }

  public:
    constexpr Modint() = default;
    constexpr Modint(intmax_t n): value(normalize(n, mod())) {}
    constexpr value_type val() const noexcept { return value; }
    constexpr static value_type mod() noexcept { return compiletime_mod > 0 ? compiletime_mod : runtime_mod; }
    static void set_modulo(value_type m) {
        assert(Modulo <= 0);
        runtime_mod = m;
    }
    constexpr Modint& operator=(intmax_t n) noexcept {
        value = normalize(n, mod());
        return *this;
    }

    constexpr Modint& operator+=(const Modint& arg) noexcept {
        if ((value += arg.val()) >= mod()) value -= mod();
        return *this;
    }
    constexpr Modint& operator-=(const Modint& arg) noexcept {
        if ((value -= arg.val()) < 0) value += mod();
        return *this;
    }
    constexpr Modint& operator*=(const Modint& arg) noexcept {
        intmax_t tmp = value;
        tmp *= arg.val();
        value = tmp % mod();
        return *this;
    }
    constexpr Modint& operator/=(const Modint& arg) noexcept {
        auto tmp = value;
        tmp *= arg.inv();
        value = tmp % mod();
        return *this;
    }

    constexpr Modint& operator++() noexcept {
        if (++value == mod()) value = 0;
        return *this;
    }
    constexpr Modint& operator--() noexcept {
        if (value-- == 0) value = mod() - 1;
        return *this;
    }

    constexpr Modint operator++(int) {
        const auto tmp(*this);
        ++*this;
        return tmp;
    }
    constexpr Modint operator--(int) {
        const auto tmp(*this);
        --*this;
        return tmp;
    }

    constexpr Modint operator+(Modint const& rhs) const noexcept { return Modint(*this) += rhs; }
    constexpr Modint operator-(Modint const& rhs) const noexcept { return Modint(*this) -= rhs; }
    constexpr Modint operator*(Modint const& rhs) const noexcept { return Modint(*this) *= rhs; }
    constexpr Modint operator/(Modint const& rhs) const noexcept { return Modint(*this) /= rhs; }

    constexpr Modint operator+() const { return *this; }
    constexpr Modint operator-() const {
        if (value == 0) return *this;
        return Modint(mod() - value);
    }

    constexpr friend bool operator==(Modint const& lhs, Modint const& rhs) { return lhs.value == rhs.value; }
    constexpr friend bool operator!=(Modint const& lhs, Modint const& rhs) { return std::not_fn(operator==(lhs, rhs)); }

    constexpr friend std::ostream& operator<<(std::ostream& os, const Modint<Modulo>& arg) {
        os << arg.val();
        return os;
    }
    constexpr friend std::istream& operator>>(std::istream& os, Modint<Modulo>& arg) {
        os >> arg.val();
        return os;
    }

    constexpr Modint inv() const { return Modint{ extgcd(this->val(), this->mod()).first }; }
    constexpr Modint pow(value_type n) const {
        Modint a = *this, ans = 1;
        for (; n; n >>= 1) {
            if (n & 1) ans *= a;
            a *= a;
        }
        return ans;
    }
};

using Modint1000000007 = Modint<1000000007>;
using Modint998244353 = Modint<998244353>;
