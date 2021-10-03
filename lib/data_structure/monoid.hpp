#pragma once

/**
 * @brief Monoids
 * @note Monoid 集
 */

#include <algorithm>
#include <limits>
#include <numeric>

struct Add {
    using T = int;
    static T op(T a, T b) { return a + b; }
    static inline T id = 0;
};

struct Mul {
    using T = int;
    static T op(T a, T b) { return a * b; }
    static inline T id = 1;
};

struct Xor {
    using T = int;
    static T op(T a, T b) { return a xor b; }
    static inline T id = 0;
};

struct Min {
    using T = int;
    static T op(T a, T b) { return std::min(a, b); }
    static inline T id = std::numeric_limits<T>::max();
};

struct Max {
    using T = int;
    static T op(T a, T b) { return std::max(a, b); }
    static inline T id = std::numeric_limits<T>::min();
};

struct Gcd {
    using T = int;
    static T op(T a, T b) { return std::gcd(a, b); }
    static inline T id = 0;
};

struct Lcm {
    using T = int;
    static T op(T a, T b) { return std::lcm(a, b); }
    static inline T id = 1;
};
