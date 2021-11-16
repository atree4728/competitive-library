---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/extgcd.hpp
    title: "Extended Euclidean algorithm / \u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5"
  - icon: ':heavy_check_mark:'
    path: lib/modulus/combination.hpp
    title: Combination on mod
  - icon: ':heavy_check_mark:'
    path: lib/modulus/modint.hpp
    title: "Finite Field / \u6709\u9650\u4F53"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D
  bundledCode: "#line 1 \"test/aoj/DPL_5_D.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D\"\
    \n\n#line 2 \"lib/modulus/combination.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    \n/**\n * @brief Combination on mod\n * @note construct in $O(N)$, return $nCr$,\
    \ $nHr$, $nPr$ in $O(1)$.\n */\n\ntemplate<class Modint> struct CombTable {\n\
    \    std::vector<Modint> fact, ifact;\n    CombTable(int n): fact(n + 1), ifact(n\
    \ + 1) {\n        assert(1 <= n);\n        fact[0] = 1;\n        for (int i =\
    \ 1; i <= n; i++) fact[i] = fact[i - 1] * i;\n        ifact[n] = fact[n].inv();\n\
    \        for (int i = n; i >= 1; i--) ifact[i - 1] = ifact[i] * i;\n    }\n  \
    \  Modint operator()(int n, int r) { return r < 0 or r > n ? 0 : fact[n] * ifact[r]\
    \ * ifact[n - r]; }\n    Modint H(int n, int r) { return operator()(n + r - 1,\
    \ r); }\n    Modint P(int n, int r) { return r < 0 or r > n ? 0 : fact[n] * ifact[n\
    \ - r]; }\n};\n#line 2 \"lib/modulus/modint.hpp\"\n\n/**\n * @brief Finite Field\
    \ / \u6709\u9650\u4F53\n */\n\n#include <functional>\n#include <iostream>\n#include\
    \ <limits>\n#include <numeric>\n#line 2 \"lib/math/extgcd.hpp\"\n\n#line 5 \"\
    lib/math/extgcd.hpp\"\n#include <utility>\n\n/**\n * @brief Extended Euclid's\
    \ Algorithm\n * @note return pair of minimum x, y s.t. ax + by = gcd(x, y)\n *\
    \ @ref https://noshi91.hatenablog.com/entry/2019/04/01/184957\n */\n\nconstexpr\
    \ std::pair<intmax_t, intmax_t> extgcd(intmax_t a, intmax_t b) {\n    intmax_t\
    \ s = a, xs = 1, ys = 0, t = b, xt = 0, yt = 1;\n    while (s % t != 0) {\n  \
    \      const intmax_t tmp = s / t,\n                       u = s - t * tmp,\n\
    \                       xu = xs - xt * tmp,\n                       yu = ys -\
    \ yt * tmp;\n        s = t, xs = xt, ys = yt;\n        t = u, xt = xu, yt = yu;\n\
    \    }\n    assert(t == std::gcd(a, b));\n    return { xt, yt };\n}\n#line 12\
    \ \"lib/modulus/modint.hpp\"\n\ntemplate<intmax_t Modulo> struct Modint {\n  \
    \  using value_type = typename std::conditional_t < 0 < Modulo and Modulo<std::numeric_limits<int>::max()\
    \ / 2, int, intmax_t>;\n\n  private:\n    value_type value = 0;\n    static constexpr\
    \ value_type compiletime_mod = Modulo;\n    static value_type runtime_mod;\n \
    \   static constexpr value_type normalize(intmax_t n, value_type m) {\n      \
    \  if (n >= m) n %= m;\n        else if (n < 0 and (n %= m) < 0) n += m;\n   \
    \     return n;\n    }\n\n  public:\n    constexpr Modint() = default;\n    constexpr\
    \ Modint(intmax_t n): value(normalize(n, mod())) {}\n    constexpr value_type\
    \ val() const noexcept { return value; }\n    constexpr static value_type mod()\
    \ noexcept { return compiletime_mod > 0 ? compiletime_mod : runtime_mod; }\n \
    \   static void set_modulo(value_type m) {\n        assert(Modulo <= 0);\n   \
    \     runtime_mod = m;\n    }\n    constexpr Modint& operator=(intmax_t n) noexcept\
    \ {\n        value = normalize(n, mod());\n        return *this;\n    }\n\n  \
    \  constexpr Modint& operator+=(const Modint& arg) noexcept {\n        if ((value\
    \ += arg.val()) >= mod()) value -= mod();\n        return *this;\n    }\n    constexpr\
    \ Modint& operator-=(const Modint& arg) noexcept {\n        if ((value -= arg.val())\
    \ < 0) value += mod();\n        return *this;\n    }\n    constexpr Modint& operator*=(const\
    \ Modint& arg) noexcept {\n        intmax_t tmp = value;\n        tmp *= arg.val();\n\
    \        value = tmp % mod();\n        return *this;\n    }\n    constexpr Modint&\
    \ operator/=(const Modint& arg) noexcept {\n        auto tmp = value;\n      \
    \  tmp *= arg.inv();\n        value = tmp % mod();\n        return *this;\n  \
    \  }\n\n    constexpr Modint& operator++() noexcept {\n        if (++value ==\
    \ mod()) value = 0;\n        return *this;\n    }\n    constexpr Modint& operator--()\
    \ noexcept {\n        if (value-- == 0) value = mod() - 1;\n        return *this;\n\
    \    }\n\n    constexpr Modint operator++(int) {\n        const auto tmp(*this);\n\
    \        ++*this;\n        return tmp;\n    }\n    constexpr Modint operator--(int)\
    \ {\n        const auto tmp(*this);\n        --*this;\n        return tmp;\n \
    \   }\n\n    constexpr Modint operator+(Modint const& rhs) const noexcept { return\
    \ Modint(*this) += rhs; }\n    constexpr Modint operator-(Modint const& rhs) const\
    \ noexcept { return Modint(*this) -= rhs; }\n    constexpr Modint operator*(Modint\
    \ const& rhs) const noexcept { return Modint(*this) *= rhs; }\n    constexpr Modint\
    \ operator/(Modint const& rhs) const noexcept { return Modint(*this) /= rhs; }\n\
    \n    constexpr Modint operator+() const { return *this; }\n    constexpr Modint\
    \ operator-() const {\n        if (value == 0) return *this;\n        return Modint(mod()\
    \ - value);\n    }\n\n    constexpr friend bool operator==(Modint const& lhs,\
    \ Modint const& rhs) { return lhs.value == rhs.value; }\n    constexpr friend\
    \ bool operator!=(Modint const& lhs, Modint const& rhs) { return std::not_fn(operator==(lhs,\
    \ rhs)); }\n\n    constexpr friend std::ostream& operator<<(std::ostream& os,\
    \ const Modint<Modulo>& arg) {\n        os << arg.val();\n        return os;\n\
    \    }\n    constexpr friend std::istream& operator>>(std::istream& os, Modint<Modulo>&\
    \ arg) {\n        os >> arg.val();\n        return os;\n    }\n\n    constexpr\
    \ Modint inv() const { return Modint{ extgcd(this->val(), this->mod()).first };\
    \ }\n    constexpr Modint pow(value_type n) const {\n        Modint a = *this,\
    \ ans = 1;\n        for (; n; n >>= 1) {\n            if (n & 1) ans *= a;\n \
    \           a *= a;\n        }\n        return ans;\n    }\n};\n\nusing Modint1000000007\
    \ = Modint<1000000007>;\nusing Modint998244353 = Modint<998244353>;\n#line 5 \"\
    test/aoj/DPL_5_D.test.cpp\"\n\nint main() {\n    int n, k;\n    std::cin >> n\
    \ >> k;\n    constexpr int MOD = 1000000007;\n    CombTable<Modint<MOD>> ct(2100);\n\
    \    std::cout << ct.H(k, n) << \"\\n\";\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D\"\
    \n\n#include \"lib/modulus/combination.hpp\"\n#include \"lib/modulus/modint.hpp\"\
    \n\nint main() {\n    int n, k;\n    std::cin >> n >> k;\n    constexpr int MOD\
    \ = 1000000007;\n    CombTable<Modint<MOD>> ct(2100);\n    std::cout << ct.H(k,\
    \ n) << \"\\n\";\n    return 0;\n}\n"
  dependsOn:
  - lib/modulus/combination.hpp
  - lib/modulus/modint.hpp
  - lib/math/extgcd.hpp
  isVerificationFile: true
  path: test/aoj/DPL_5_D.test.cpp
  requiredBy: []
  timestamp: '2021-11-16 21:49:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DPL_5_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_5_D.test.cpp
- /verify/test/aoj/DPL_5_D.test.cpp.html
title: test/aoj/DPL_5_D.test.cpp
---
