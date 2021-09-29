#pragma once

#include "../include.hpp"

/**
 * @brief  Finite Field
 * @note Since Fermat's little theorem is used for division, the modulo must be prime.
 */

template<int MOD> struct Modint {
    using mint = Modint<MOD>;
    unsigned int value;
    Modint(long long value_ = 0): value((value_ % MOD + MOD) % MOD) {}
    mint val() const { return *this; }
    mint operator-() const { return mint(-value); }
    mint operator++() const { return *this += 1; }
    mint operator--() const { return *this -= 1; }
    mint operator+(mint arg) const { return mint(*this) += arg; }
    mint operator-(mint arg) const { return mint(*this) -= arg; }
    mint operator*(mint arg) const { return mint(*this) *= arg; }
    mint& operator+=(mint arg) {
        value += arg.value;
        if (value >= MOD) value -= MOD;
        return *this;
    }
    mint& operator-=(mint arg) {
        value -= arg.value;
        if (value < 0) value += MOD;
        return *this;
    }
    mint& operator*=(mint arg) {
        value = (long long) value * arg.value % MOD;
        return *this;
    }
    bool operator==(mint arg) const { return value == arg.value; }
    bool operator!=(mint arg) const { return value != arg.value; }
    mint pow(long long k) const {
        Modint ret = 1, a(*this);
        while (k > 0) {
            if (k & 1) ret *= a;
            k >>= 1;
            a *= a;
        }
        return ret;
    }
    mint inv() const { return pow(MOD - 2); }
    mint operator/(mint arg) const { return *this * arg.inv(); }
    mint& operator/=(mint arg) { return *this *= arg.inv(); }
    friend mint operator+(long long value, Modint<MOD> a) { return Modint<MOD>(value) + a; }
    friend mint operator-(long long value, Modint<MOD> a) { return Modint<MOD>(value) - a; }
    friend mint operator*(long long value, Modint<MOD> a) { return Modint<MOD>(value) * a; }
    friend mint operator/(long long value, Modint<MOD> a) { return Modint<MOD>(value) / a; }
    friend ostream& operator<<(ostream& os, Modint<MOD> a) { return os << a.value; }
};
