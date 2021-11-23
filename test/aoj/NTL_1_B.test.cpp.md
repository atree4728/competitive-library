---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/extgcd.hpp
    title: "Extended Euclidean algorithm / \u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5"
  - icon: ':heavy_check_mark:'
    path: lib/modulus/modint.hpp
    title: Modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
  bundledCode: "#line 1 \"test/aoj/NTL_1_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B\"\
    \n\n#include <iostream>\n#line 2 \"lib/modulus/modint.hpp\"\n\n/**\n * @brief\
    \ Modint\n */\n\n#include <functional>\n#line 9 \"lib/modulus/modint.hpp\"\n#include\
    \ <limits>\n#include <numeric>\n#line 2 \"lib/math/extgcd.hpp\"\n\n#include <cassert>\n\
    #line 5 \"lib/math/extgcd.hpp\"\n#include <utility>\n\n/**\n * @brief Extended\
    \ Euclid's Algorithm\n * @note return pair of minimum x, y s.t. ax + by = gcd(x,\
    \ y)\n * @ref https://noshi91.hatenablog.com/entry/2019/04/01/184957\n */\n\n\
    constexpr std::pair<intmax_t, intmax_t> extgcd(intmax_t a, intmax_t b) {\n   \
    \ intmax_t s = a, xs = 1, ys = 0, t = b, xt = 0, yt = 1;\n    while (s % t !=\
    \ 0) {\n        const intmax_t tmp = s / t,\n                       u = s - t\
    \ * tmp,\n                       xu = xs - xt * tmp,\n                       yu\
    \ = ys - yt * tmp;\n        s = t, xs = xt, ys = yt;\n        t = u, xt = xu,\
    \ yt = yu;\n    }\n    assert(t == std::gcd(a, b));\n    return { xt, yt };\n\
    }\n#line 12 \"lib/modulus/modint.hpp\"\n\ntemplate<unsigned int Modulo> struct\
    \ Modint {\n    using value_type = decltype(Modulo);\n\n  private:\n    value_type\
    \ value = 0;\n    template<class T> static constexpr value_type normalize(T n)\
    \ {\n        static_assert(std::is_integral_v<T>);\n        if (n >= Modulo) n\
    \ %= Modulo;\n        if (n < 0) (n %= Modulo) += Modulo;\n        return n;\n\
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
    \ Modint998244353 = Modint<998244353>;\n#line 5 \"test/aoj/NTL_1_B.test.cpp\"\n\
    \nint main() {\n    using namespace std;\n    int m, n;\n    cin >> m >> n;\n\
    \    const auto ans = Modint1000000007{ m }.pow(n);\n    cout << ans << \"\\n\"\
    ;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B\"\
    \n\n#include <iostream>\n#include \"lib/modulus/modint.hpp\"\n\nint main() {\n\
    \    using namespace std;\n    int m, n;\n    cin >> m >> n;\n    const auto ans\
    \ = Modint1000000007{ m }.pow(n);\n    cout << ans << \"\\n\";\n}\n"
  dependsOn:
  - lib/modulus/modint.hpp
  - lib/math/extgcd.hpp
  isVerificationFile: true
  path: test/aoj/NTL_1_B.test.cpp
  requiredBy: []
  timestamp: '2021-11-23 21:36:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_B.test.cpp
- /verify/test/aoj/NTL_1_B.test.cpp.html
title: test/aoj/NTL_1_B.test.cpp
---
