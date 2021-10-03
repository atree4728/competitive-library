---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/utility/neighbor.hpp\"\n\n#include <cassert>\n#include\
    \ <utility>\n#include <vector>\n\ntemplate<class F> std::vector<std::pair<std::size_t,\
    \ std::size_t>> neighbor(size_t x, size_t y, int dir, const F& ok) {\n    using\
    \ namespace std;\n    assert(dir == 4 or dir == 8);\n    const int dx[8] = { 0,\
    \ 0, -1, 1, -1, -1, 1, 1 };\n    const int dy[8] = { -1, 1, 0, 0, -1, 1, -1, 1\
    \ };\n    vector<pair<size_t, size_t>> ret{};\n    for (int i = 0; i < dir; i++)\
    \ {\n        const auto& [nx, ny] = pair{ x + dx, y + dy };\n        if (ok(nx,\
    \ ny)) ret.emplace_back(pair{ nx, ny });\n    }\n    return ret;\n}\n"
  code: "#pragma once\n\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    \ntemplate<class F> std::vector<std::pair<std::size_t, std::size_t>> neighbor(size_t\
    \ x, size_t y, int dir, const F& ok) {\n    using namespace std;\n    assert(dir\
    \ == 4 or dir == 8);\n    const int dx[8] = { 0, 0, -1, 1, -1, -1, 1, 1 };\n \
    \   const int dy[8] = { -1, 1, 0, 0, -1, 1, -1, 1 };\n    vector<pair<size_t,\
    \ size_t>> ret{};\n    for (int i = 0; i < dir; i++) {\n        const auto& [nx,\
    \ ny] = pair{ x + dx, y + dy };\n        if (ok(nx, ny)) ret.emplace_back(pair{\
    \ nx, ny });\n    }\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/utility/neighbor.hpp
  requiredBy: []
  timestamp: '2021-10-03 22:09:41+09:00'
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