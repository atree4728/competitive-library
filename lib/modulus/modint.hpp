#pragma once

/**
 * @brief Modint
 */

#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include "lib/math/extgcd.hpp"

template<uint_fast32_t Modulo> struct Modint {
    using value_type = decltype(Modulo);

  private:
    value_type value = 0;
    template<class T> static constexpr value_type normalize(T n) {
        static_assert(std::is_integral_v<T>);
        if (n >= Modulo) n %= Modulo;
        if (n < 0) (n %= Modulo) += Modulo;
        return n;
    }

  public:
    constexpr Modint() noexcept: value(0) {}
    template<class T, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr> constexpr Modint(const T& n)
        : value(normalize(n)) {}
    template<class T = value_type> constexpr std::enable_if_t<std::is_convertible_v<value_type, T>, T> val() const noexcept {
        return static_cast<T>(value);
    }
    template<class T = value_type> static constexpr std::enable_if_t<std::is_convertible_v<value_type, T>, T> mod() noexcept {
        return static_cast<T>(Modulo);
    }
    template<class T> static constexpr auto raw(const T& v) noexcept {
        Modint tmp{};
        tmp.value = static_cast<uint_fast32_t>(v);
        return tmp;
    }

    constexpr auto operator+() const noexcept { return *this; }
    constexpr auto operator-() const noexcept {
        if (value == 0) return *this;
        return Modint::raw(mod() - value);
    }

    constexpr bool operator==(const Modint& rhs) { return value == rhs.value; }
    constexpr bool operator!=(const Modint& rhs) { return value != rhs.value; }

    constexpr auto& operator++() noexcept {
        if (++value == mod()) value = 0;
        return *this;
    }
    constexpr auto& operator--() noexcept {
        if (value-- == 0) value = mod() - 1;
        return *this;
    }
    constexpr auto operator++(int) {
        const auto tmp{ *this };
        ++*this;
        return tmp;
    }
    constexpr auto operator--(int) {
        const auto tmp{ *this };
        --*this;
        return tmp;
    }

    constexpr auto operator+(const Modint& rhs) const noexcept { return Modint{ *this } += rhs; }
    constexpr auto operator-(const Modint& rhs) const noexcept { return Modint{ *this } -= rhs; }
    constexpr auto operator*(const Modint& rhs) const noexcept { return Modint{ *this } *= rhs; }
    constexpr auto operator/(const Modint& rhs) const noexcept { return Modint{ *this } /= rhs; }

    constexpr auto& operator+=(const Modint& rhs) noexcept {
        if ((value += rhs.value) >= mod()) value -= mod();
        return *this;
    }
    constexpr auto& operator-=(const Modint& rhs) noexcept {
        if ((value -= rhs.value) < 0) value += mod();
        return *this;
    }
    constexpr auto& operator*=(const Modint& rhs) noexcept {
        value = static_cast<uint_fast32_t>(static_cast<uint_fast64_t>(value) * static_cast<uint_fast64_t>(rhs.value) % mod());
        return *this;
    }
    constexpr auto& operator/=(const Modint& rhs) noexcept { return *this *= rhs.inv(); }

    constexpr auto inv() const { return Modint{ extgcd(this->val(), this->mod()).first }; }
    template<class T> constexpr auto pow(T n) const {
        auto a = *this, ans = raw(1);
        while (n != 0) {
            if (n & 1) ans *= a;
            a *= a;
            n >>= 1;
        }
        return ans;
    }

    constexpr friend std::ostream& operator<<(std::ostream& os, const Modint& arg) {
        os << arg.value;
        return os;
    }
    constexpr friend std::istream& operator>>(std::istream& os, Modint& arg) {
        os >> arg.value;
        return os;
    }
};

using Modint1000000007 = Modint<1000000007>;
using Modint998244353 = Modint<998244353>;
