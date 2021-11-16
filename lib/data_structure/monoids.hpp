#pragma once

/**
 * @brief Monoids
 * @note Monoid 集
 */

#include <algorithm>
#include <limits>
#include <numeric>

template<class T> struct Add {
    using operand_type = T;
    static operand_type operation(operand_type a, operand_type b) { return a + b; }
    static operand_type identity() { return static_cast<operand_type>(0); }
};

template<class T> struct Mul {
    using operand_type = T;
    static operand_type operation(operand_type a, operand_type b) { return a * b; }
    static operand_type identity() { return static_cast<operand_type>(1); }
};

template<class T> struct Xor {
    using operand_type = T;
    static operand_type operation(operand_type a, operand_type b) { return a xor b; }
    static operand_type identity() { return static_cast<operand_type>(0); }
};

template<class T> struct Min {
    using operand_type = T;
    static operand_type operation(operand_type a, operand_type b) { return std::min(a, b); }
    static operand_type identity() { return std::numeric_limits<operand_type>::max(); }
};

template<class T> struct Max {
    using operand_type = T;
    static operand_type operation(operand_type a, operand_type b) { return std::max(a, b); }
    static operand_type identity() { return std::numeric_limits<operand_type>::min(); }
};

template<class T> struct Gcd {
    using operand_type = T;
    static operand_type operation(operand_type a, operand_type b) { return std::gcd(a, b); }
    static operand_type identity() { return static_cast<operand_type>(0); }
};

template<class T> struct Lcm {
    using operand_type = T;
    static operand_type operation(operand_type a, operand_type b) { return std::lcm(a, b); }
    static operand_type identity() { return static_cast<operand_type>(1); }
};
