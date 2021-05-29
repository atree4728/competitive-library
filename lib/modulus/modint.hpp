#pragma once

#include <iostream>

using namespace std;

/**
 *@brief Modint
 */

template <int MOD>
class Modint {
    using mint = Modint<MOD>;

   public:
    int value;
    Modint(long long value_ = 0) : value((value_ % MOD + MOD) % MOD) {}

    static constexpr int mod() { return MOD; }
    mint val() const { return *this; }

    inline mint operator-() const { return mint(-value); }

    inline mint operator++() const { return *this += 1; }
    inline mint operator--() const { return *this -= 1; }

    inline mint operator+(mint arg) const { return mint(*this) += arg; }
    inline mint operator-(mint arg) const { return mint(*this) -= arg; }
    inline mint operator*(mint arg) const { return mint(*this) *= arg; }

    inline mint& operator+=(mint arg) {
        value += arg.value;
        if (value >= MOD) value -= MOD;
        return *this;
    }
    inline mint& operator-=(mint arg) {
        value -= arg.value;
        if (value < 0) value += MOD;
        return *this;
    }
    inline mint& operator*=(mint arg) {
        value = (long long)value * arg.value % MOD;
        return *this;
    }

    inline bool operator==(mint arg) const { return value == arg.value; }
    inline bool operator!=(mint arg) const { return value != arg.value; }

    inline mint pow(long long k) const {
        Modint ret = 1, a(*this);
        while (k > 0) {
            if (k & 1) ret *= a;
            k >>= 1;
            a *= a;
        }
        return ret;
    }
    inline mint inv() const { return pow(MOD - 2); }

    inline mint operator/(mint arg) const { return *this * arg.inv(); }
    inline mint& operator/=(mint arg) { return *this *= arg.inv(); }
};

template <int MOD>
Modint<MOD> operator+(long long value, Modint<MOD> a) {
    return Modint<MOD>(value) + a;
}
template <int MOD>
Modint<MOD> operator-(long long value, Modint<MOD> a) {
    return Modint<MOD>(value) - a;
}
template <int MOD>
Modint<MOD> operator*(long long value, Modint<MOD> a) {
    return Modint<MOD>(value) * a;
}
template <int MOD>
Modint<MOD> operator/(long long value, Modint<MOD> a) {
    return Modint<MOD>(value) / a;
}
template <int MOD>
ostream& operator<<(ostream& os, Modint<MOD> a) {
    return os << a.value;
}
