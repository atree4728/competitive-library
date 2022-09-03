---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/math/extgcd.hpp
    title: "Extended Euclidean algorithm / \u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_A.test.cpp
    title: test/aoj/DPL_5_A.test.cpp
  - icon: ':x:'
    path: test/aoj/DPL_5_B.test.cpp
    title: test/aoj/DPL_5_B.test.cpp
  - icon: ':x:'
    path: test/aoj/DPL_5_D.test.cpp
    title: test/aoj/DPL_5_D.test.cpp
  - icon: ':x:'
    path: test/aoj/DPL_5_E.test.cpp
    title: test/aoj/DPL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_B.test.cpp
    title: test/aoj/NTL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/117.test.cpp
    title: test/yukicoder/117.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Modint
    links: []
  bundledCode: "#line 2 \"lib/modulus/modint.hpp\"\n\n/**\n * @brief Modint\n */\n\
    \n#include <functional>\n#include <iostream>\n#include <limits>\n#include <numeric>\n\
    #line 2 \"lib/math/extgcd.hpp\"\n\n#include <cassert>\n#line 5 \"lib/math/extgcd.hpp\"\
    \n#include <utility>\n\n/**\n * @brief Extended Euclid's Algorithm\n * @note return\
    \ pair of minimum x, y s.t. ax + by = gcd(x, y)\n * @ref https://noshi91.hatenablog.com/entry/2019/04/01/184957\n\
    \ */\n\nconstexpr std::pair<intmax_t, intmax_t> extgcd(intmax_t a, intmax_t b)\
    \ {\n    intmax_t s = a, xs = 1, ys = 0, t = b, xt = 0, yt = 1;\n    while (s\
    \ % t != 0) {\n        const intmax_t tmp = s / t,\n                       u =\
    \ s - t * tmp,\n                       xu = xs - xt * tmp,\n                 \
    \      yu = ys - yt * tmp;\n        s = t, xs = xt, ys = yt;\n        t = u, xt\
    \ = xu, yt = yu;\n    }\n    assert(t == std::gcd(a, b));\n    return { xt, yt\
    \ };\n}\n#line 12 \"lib/modulus/modint.hpp\"\n\ntemplate<auto Modulo> struct Modint\
    \ {\n    using value_type = decltype(Modulo);\n\n  private:\n    value_type value\
    \ = 0;\n    template<class T> static constexpr value_type normalize(T n) {\n \
    \       if (static_cast<std::common_type_t<value_type, T>>(n) >= Modulo) n %=\
    \ Modulo;\n        if (n < 0) (n %= Modulo) += Modulo;\n        return n;\n  \
    \  }\n\n  public:\n    constexpr Modint() noexcept: value(0) {}\n    template<class\
    \ T, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr> constexpr\
    \ Modint(const T& n)\n        : value(normalize(n)) {}\n    template<class T =\
    \ value_type> constexpr std::enable_if_t<std::is_convertible_v<value_type, T>,\
    \ T> val() const noexcept {\n        return static_cast<T>(value);\n    }\n  \
    \  template<class T = value_type> static constexpr std::enable_if_t<std::is_convertible_v<value_type,\
    \ T>, T> mod() noexcept {\n        return static_cast<T>(Modulo);\n    }\n   \
    \ template<class T> static constexpr auto raw(const T& v) noexcept {\n       \
    \ Modint tmp{};\n        tmp.value = static_cast<value_type>(v);\n        return\
    \ tmp;\n    }\n\n    constexpr auto operator+() const noexcept { return *this;\
    \ }\n    constexpr auto operator-() const noexcept {\n        if (value == 0)\
    \ return *this;\n        return Modint::raw(mod() - value);\n    }\n\n    constexpr\
    \ bool operator==(const Modint& rhs) { return value == rhs.value; }\n    constexpr\
    \ bool operator!=(const Modint& rhs) { return value != rhs.value; }\n\n    constexpr\
    \ auto& operator++() noexcept {\n        if (++value == mod()) value = 0;\n  \
    \      return *this;\n    }\n    constexpr auto& operator--() noexcept {\n   \
    \     if (value-- == 0) value = mod() - 1;\n        return *this;\n    }\n   \
    \ constexpr auto operator++(int) {\n        const auto tmp{ *this };\n       \
    \ ++*this;\n        return tmp;\n    }\n    constexpr auto operator--(int) {\n\
    \        const auto tmp{ *this };\n        --*this;\n        return tmp;\n   \
    \ }\n\n    constexpr auto operator+(const Modint& rhs) const noexcept { return\
    \ Modint{ *this } += rhs; }\n    constexpr auto operator-(const Modint& rhs) const\
    \ noexcept { return Modint{ *this } -= rhs; }\n    constexpr auto operator*(const\
    \ Modint& rhs) const noexcept { return Modint{ *this } *= rhs; }\n    constexpr\
    \ auto operator/(const Modint& rhs) const noexcept { return Modint{ *this } /=\
    \ rhs; }\n\n    constexpr auto& operator+=(const Modint& rhs) noexcept {\n   \
    \     if ((value += rhs.value) >= mod()) value -= mod();\n        return *this;\n\
    \    }\n    constexpr auto& operator-=(const Modint& rhs) noexcept {\n       \
    \ if ((value -= rhs.value) < 0) value += mod();\n        return *this;\n    }\n\
    \    constexpr auto& operator*=(const Modint& rhs) noexcept {\n        value =\
    \ static_cast<value_type>(static_cast<uint_fast64_t>(value) * static_cast<uint_fast64_t>(rhs.value)\
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
    \ Modint998244353 = Modint<998244353>;\n"
  code: "#pragma once\n\n/**\n * @brief Modint\n */\n\n#include <functional>\n#include\
    \ <iostream>\n#include <limits>\n#include <numeric>\n#include \"lib/math/extgcd.hpp\"\
    \n\ntemplate<auto Modulo> struct Modint {\n    using value_type = decltype(Modulo);\n\
    \n  private:\n    value_type value = 0;\n    template<class T> static constexpr\
    \ value_type normalize(T n) {\n        if (static_cast<std::common_type_t<value_type,\
    \ T>>(n) >= Modulo) n %= Modulo;\n        if (n < 0) (n %= Modulo) += Modulo;\n\
    \        return n;\n    }\n\n  public:\n    constexpr Modint() noexcept: value(0)\
    \ {}\n    template<class T, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t>\
    \ = nullptr> constexpr Modint(const T& n)\n        : value(normalize(n)) {}\n\
    \    template<class T = value_type> constexpr std::enable_if_t<std::is_convertible_v<value_type,\
    \ T>, T> val() const noexcept {\n        return static_cast<T>(value);\n    }\n\
    \    template<class T = value_type> static constexpr std::enable_if_t<std::is_convertible_v<value_type,\
    \ T>, T> mod() noexcept {\n        return static_cast<T>(Modulo);\n    }\n   \
    \ template<class T> static constexpr auto raw(const T& v) noexcept {\n       \
    \ Modint tmp{};\n        tmp.value = static_cast<value_type>(v);\n        return\
    \ tmp;\n    }\n\n    constexpr auto operator+() const noexcept { return *this;\
    \ }\n    constexpr auto operator-() const noexcept {\n        if (value == 0)\
    \ return *this;\n        return Modint::raw(mod() - value);\n    }\n\n    constexpr\
    \ bool operator==(const Modint& rhs) { return value == rhs.value; }\n    constexpr\
    \ bool operator!=(const Modint& rhs) { return value != rhs.value; }\n\n    constexpr\
    \ auto& operator++() noexcept {\n        if (++value == mod()) value = 0;\n  \
    \      return *this;\n    }\n    constexpr auto& operator--() noexcept {\n   \
    \     if (value-- == 0) value = mod() - 1;\n        return *this;\n    }\n   \
    \ constexpr auto operator++(int) {\n        const auto tmp{ *this };\n       \
    \ ++*this;\n        return tmp;\n    }\n    constexpr auto operator--(int) {\n\
    \        const auto tmp{ *this };\n        --*this;\n        return tmp;\n   \
    \ }\n\n    constexpr auto operator+(const Modint& rhs) const noexcept { return\
    \ Modint{ *this } += rhs; }\n    constexpr auto operator-(const Modint& rhs) const\
    \ noexcept { return Modint{ *this } -= rhs; }\n    constexpr auto operator*(const\
    \ Modint& rhs) const noexcept { return Modint{ *this } *= rhs; }\n    constexpr\
    \ auto operator/(const Modint& rhs) const noexcept { return Modint{ *this } /=\
    \ rhs; }\n\n    constexpr auto& operator+=(const Modint& rhs) noexcept {\n   \
    \     if ((value += rhs.value) >= mod()) value -= mod();\n        return *this;\n\
    \    }\n    constexpr auto& operator-=(const Modint& rhs) noexcept {\n       \
    \ if ((value -= rhs.value) < 0) value += mod();\n        return *this;\n    }\n\
    \    constexpr auto& operator*=(const Modint& rhs) noexcept {\n        value =\
    \ static_cast<value_type>(static_cast<uint_fast64_t>(value) * static_cast<uint_fast64_t>(rhs.value)\
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
    \ Modint998244353 = Modint<998244353>;\n"
  dependsOn:
  - lib/math/extgcd.hpp
  isVerificationFile: false
  path: lib/modulus/modint.hpp
  requiredBy: []
  timestamp: '2022-01-16 17:37:48+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/117.test.cpp
  - test/aoj/DPL_5_D.test.cpp
  - test/aoj/DPL_5_B.test.cpp
  - test/aoj/DPL_5_E.test.cpp
  - test/aoj/NTL_1_B.test.cpp
  - test/aoj/DPL_5_A.test.cpp
documentation_of: lib/modulus/modint.hpp
layout: document
redirect_from:
- /library/lib/modulus/modint.hpp
- /library/lib/modulus/modint.hpp.html
title: Modint
---
