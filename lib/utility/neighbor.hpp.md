---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/neighbor.md
    document_title: "neighbor on grid / \u30B0\u30EA\u30C3\u30C9\u4E0A\u3067\u306E\
      \u8FD1\u508D"
    links: []
  bundledCode: "#line 2 \"lib/utility/neighbor.hpp\"\n\n#line 2 \"lib/include.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_1, _2,\
    \ _3, name, ...) name\n#define rep1(n) for (decltype(n) _tmp = 0; _tmp < (n);\
    \ _tmp++)\n#define rep2(i, n) for (decltype(n) i = 0; i < (n); i++)\n#define rep3(i,\
    \ a, b) for (decltype(b) i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\nstruct IOSetup {\n    IOSetup() noexcept {\n\
    \        ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n        cout\
    \ << fixed << setprecision(10);\n        cerr << fixed << setprecision(10);\n\
    \    }\n} iosetup;\ntemplate<class T> bool chmax(T &a, const T &b) { return a\
    \ < b and (a = b, true); }\ntemplate<class T> bool chmin(T &a, const T &b) { return\
    \ a > b and (a = b, true); }\nusing i64 = long long;\nusing f64 = long double;\n\
    #line 4 \"lib/utility/neighbor.hpp\"\n\n/**\n * @brief neighbor on grid / \u30B0\
    \u30EA\u30C3\u30C9\u4E0A\u3067\u306E\u8FD1\u508D\n * @docs docs/neighbor.md\n\
    \ */\n\ntemplate<class F> vector<pair<int, int>> neighbor(int x, int y, int dir\
    \ const F ok) {\n    assert(dir == 4 or dir == 8);\n    const int dx[8] = {0,\
    \ 0, -1, 1, -1, -1, 1, 1};\n    const int dx[8] = {-1, 1, 0, 0, -1, 1, -1, 1};\n\
    \    auto ret{};\n    rep(i, dir) {\n        const auto& [nx, ny] = pair{x + dx,\
    \ y + dy};\n        if (ok(nx, ny)) ret.emplace_back(pair{nx, ny});\n    }\n \
    \   return ret;\n}\n"
  code: "#pragma once\n\n#include \"../include.hpp\"\n\n/**\n * @brief neighbor on\
    \ grid / \u30B0\u30EA\u30C3\u30C9\u4E0A\u3067\u306E\u8FD1\u508D\n * @docs docs/neighbor.md\n\
    \ */\n\ntemplate<class F> vector<pair<int, int>> neighbor(int x, int y, int dir\
    \ const F ok) {\n    assert(dir == 4 or dir == 8);\n    const int dx[8] = {0,\
    \ 0, -1, 1, -1, -1, 1, 1};\n    const int dx[8] = {-1, 1, 0, 0, -1, 1, -1, 1};\n\
    \    auto ret{};\n    rep(i, dir) {\n        const auto& [nx, ny] = pair{x + dx,\
    \ y + dy};\n        if (ok(nx, ny)) ret.emplace_back(pair{nx, ny});\n    }\n \
    \   return ret;\n}"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/utility/neighbor.hpp
  requiredBy: []
  timestamp: '2021-09-08 23:15:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/utility/neighbor.hpp
layout: document
title: "neighbor on grid / \u30B0\u30EA\u30C3\u30C9\u4E0A\u3067\u306E\u8FD1\u508D"
---

## 概要

座標を渡すと、範囲内（関数 `f`が`true`を返す）の四近傍（上下左右）または八近傍 （加えて斜め）の座標を`std::vector`で返す。

想定されたユースケース:

```c++
auto ok = [&](int i, int j) { return 0 <= i and 0 <= j and i < h and j < w; };
for (const auto&[ni, nj]: neighbor(i, j, 4, ok)) {
    ...
}
```

## 使い方

- `neighbor(i, j, dir, f)`: 座標`(i, j)`、`dir`近傍で`f(i, j)`が`true`となる座標を`std::vector<std::pair<int, int>>`で返す。`dir`$\notin
  {4,8}$なら実行時にエラーを吐く。

**もう少しきれいなインターフェースがあるといいなと思っているので誰か教えてください。**