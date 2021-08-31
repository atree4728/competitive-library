#pragma once

#include "../include.hpp"

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
    static T op(T a, T b) { return min(a, b); }
    static inline T id = numeric_limits<T>::max();
};

struct Max {
    using T = int;
    static T op(T a, T b) { return max(a, b); }
    static inline T id = numeric_limits<T>::min();
};

struct Gcd {
    using T = int;
    static T op(T a, T b) { return gcd(a, b); }
    static inline T id = 0;
};

struct Lcm {
    using T = int;
    static T op(T a, T b) { return lcm(a, b); }
    static inline T id = 0;
};
