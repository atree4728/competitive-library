---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/extgcd.hpp
    title: "Extended Euclidean algorithm / \u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5"
  - icon: ':heavy_check_mark:'
    path: lib/modulus/modint.hpp
    title: Modint
  - icon: ':heavy_check_mark:'
    path: lib/modulus/modtable.hpp
    title: lib/modulus/modtable.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_B
  bundledCode: "#line 1 \"test/aoj/DPL_5_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_B\"\
    \n\n#line 2 \"lib/modulus/modint.hpp\"\n\n/**\n * @brief Modint\n */\n\n#include\
    \ <functional>\n#include <iostream>\n#include <limits>\n#include <numeric>\n#line\
    \ 2 \"lib/math/extgcd.hpp\"\n\n#include <cassert>\n#line 5 \"lib/math/extgcd.hpp\"\
    \n#include <utility>\n\n/**\n * @brief Extended Euclid's Algorithm\n * @note return\
    \ pair of minimum x, y s.t. ax + by = gcd(x, y)\n * @ref https://noshi91.hatenablog.com/entry/2019/04/01/184957\n\
    \ */\n\nconstexpr std::pair<intmax_t, intmax_t> extgcd(intmax_t a, intmax_t b)\
    \ {\n    intmax_t s = a, xs = 1, ys = 0, t = b, xt = 0, yt = 1;\n    while (s\
    \ % t != 0) {\n        const intmax_t tmp = s / t,\n                       u =\
    \ s - t * tmp,\n                       xu = xs - xt * tmp,\n                 \
    \      yu = ys - yt * tmp;\n        s = t, xs = xt, ys = yt;\n        t = u, xt\
    \ = xu, yt = yu;\n    }\n    assert(t == std::gcd(a, b));\n    return { xt, yt\
    \ };\n}\n#line 12 \"lib/modulus/modint.hpp\"\n\ntemplate<unsigned int Modulo>\
    \ struct Modint {\n    using value_type = decltype(Modulo);\n\n  private:\n  \
    \  value_type value = 0;\n    template<class T> static constexpr value_type normalize(T\
    \ n) {\n        static_assert(std::is_integral_v<T>);\n        if (n >= Modulo)\
    \ n %= Modulo;\n        if (n < 0) (n %= Modulo) += Modulo;\n        return n;\n\
    \    }\n\n  public:\n    constexpr Modint() noexcept: value(0) {}\n    template<class\
    \ T, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr> constexpr\
    \ Modint(const T& n)\n        : value(normalize(n)) {}\n    template<class T =\
    \ value_type>\n    constexpr std::enable_if_t<std::is_convertible_v<value_type,\
    \ T>, T> val() const noexcept {\n        return static_cast<T>(value);\n    }\n\
    \    template<class T = value_type>\n    constexpr std::enable_if_t<std::is_convertible_v<value_type,\
    \ T>, T> mod() const noexcept {\n        return static_cast<T>(Modulo);\n    }\n\
    \    template<class T> static constexpr auto raw(const T& v) noexcept {\n    \
    \    Modint tmp{};\n        tmp.value = static_cast<unsigned int>(v);\n      \
    \  return tmp;\n    }\n\n    constexpr auto operator+() const noexcept { return\
    \ *this; }\n    constexpr auto operator-() const noexcept {\n        if (value\
    \ == 0) return *this;\n        return Modint::raw(mod() - value);\n    }\n\n \
    \   constexpr bool operator==(const Modint& rhs) { return value == rhs.value;\
    \ }\n    constexpr bool operator!=(const Modint& rhs) { return value != rhs.value;\
    \ }\n\n    constexpr auto& operator++() noexcept {\n        if (++value == mod())\
    \ value = 0;\n        return *this;\n    }\n    constexpr auto& operator--() noexcept\
    \ {\n        if (value-- == 0) value = mod() - 1;\n        return *this;\n   \
    \ }\n    constexpr auto operator++(int) {\n        const auto tmp{ *this };\n\
    \        ++*this;\n        return tmp;\n    }\n    constexpr auto operator--(int)\
    \ {\n        const auto tmp{ *this };\n        --*this;\n        return tmp;\n\
    \    }\n\n    constexpr auto operator+(const Modint& rhs) const noexcept { return\
    \ Modint{ *this } += rhs; }\n    constexpr auto operator-(const Modint& rhs) const\
    \ noexcept { return Modint{ *this } -= rhs; }\n    constexpr auto operator*(const\
    \ Modint& rhs) const noexcept { return Modint{ *this } *= rhs; }\n    constexpr\
    \ auto operator/(const Modint& rhs) const noexcept { return Modint{ *this } /=\
    \ rhs; }\n\n    constexpr auto& operator+=(const Modint& rhs) noexcept {\n   \
    \     if ((value += rhs.value) >= mod()) value -= mod();\n        return *this;\n\
    \    }\n    constexpr auto& operator-=(const Modint& rhs) noexcept {\n       \
    \ if ((value -= rhs.value) < 0) value += mod();\n        return *this;\n    }\n\
    \    constexpr auto& operator*=(const Modint& rhs) noexcept {\n        value =\
    \ static_cast<unsigned int>(static_cast<intmax_t>(value) * static_cast<intmax_t>(rhs.value)\
    \ % mod());\n        return *this;\n    }\n    constexpr auto& operator/=(const\
    \ Modint& rhs) noexcept { return *this *= rhs.inv(); }\n\n    constexpr auto inv()\
    \ const { return Modint{ extgcd(this->val(), this->mod()).first }; }\n    template<class\
    \ T> constexpr auto pow(T n) const {\n        auto a = *this, ans = raw(1);\n\
    \        while (n != 0) {\n            if (n & 1) ans *= a;\n            a *=\
    \ a;\n            n >>= 1;\n        }\n        return ans;\n    }\n\n    constexpr\
    \ friend std::ostream& operator<<(std::ostream& os, const Modint& arg) {\n   \
    \     os << arg.value;\n        return os;\n    }\n    constexpr friend std::istream&\
    \ operator>>(std::istream& os, Modint& arg) {\n        os >> arg.value;\n    \
    \    return os;\n    }\n};\n\nusing Modint1000000007 = Modint<1000000007>;\nusing\
    \ Modint998244353 = Modint<998244353>;\n#line 2 \"lib/modulus/modtable.hpp\"\n\
    \n#line 4 \"lib/modulus/modtable.hpp\"\n#include <vector>\n\ntemplate<typename\
    \ Modint> class ModTable {\n    std::vector<Modint> factorials, factorials_inv;\n\
    \n  public:\n    constexpr ModTable() = default;\n    constexpr ModTable(const\
    \ int n): factorials(n + 1), factorials_inv(n + 1) {\n        factorials[0] =\
    \ 1;\n        for (size_t i = 0; i < n; i++) factorials[i + 1] = factorials[i]\
    \ * Modint{ i + 1 };\n        factorials_inv[n] = factorials[n].inv();\n     \
    \   for (size_t i = n; i--;) factorials_inv[i] = factorials_inv[i + 1] * Modint{\
    \ i + 1 };\n    }\n    constexpr auto fact(const int i) const { return factorials[i];\
    \ }\n    constexpr auto fact_inv(const int i) const { return factorials_inv[i];\
    \ }\n    constexpr auto perm(const int i, const int j) const { return i >= j ?\
    \ fact(i) * fact_inv(i - j) : 0; }\n    constexpr auto binom(const int i, const\
    \ int j) const {\n        if (i < 0 or j < 0 or i < j) return Modint{ 0 };\n \
    \       return factorials[i] * factorials_inv[j] * factorials_inv[i - j];\n  \
    \  }\n    constexpr auto homo(const int i, const int j) const { return binom(i\
    \ + j - 1, j); }\n};\n#line 5 \"test/aoj/DPL_5_B.test.cpp\"\n\nint main() {\n\
    \    int n, k;\n    std::cin >> n >> k;\n\n    using mint = Modint1000000007;\n\
    \    ModTable<mint> f(1100);\n    std::cout << f.perm(k, n) << \"\\n\";\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_B\"\n\n\
    #include \"lib/modulus/modint.hpp\"\n#include \"lib/modulus/modtable.hpp\"\n\n\
    int main() {\n    int n, k;\n    std::cin >> n >> k;\n\n    using mint = Modint1000000007;\n\
    \    ModTable<mint> f(1100);\n    std::cout << f.perm(k, n) << \"\\n\";\n    return\
    \ 0;\n}\n"
  dependsOn:
  - lib/modulus/modint.hpp
  - lib/math/extgcd.hpp
  - lib/modulus/modtable.hpp
  isVerificationFile: true
  path: test/aoj/DPL_5_B.test.cpp
  requiredBy: []
  timestamp: '2021-11-23 21:36:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DPL_5_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_5_B.test.cpp
- /verify/test/aoj/DPL_5_B.test.cpp.html
title: test/aoj/DPL_5_B.test.cpp
---