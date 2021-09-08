---
title: neighbor on grid / グリッド上での近傍
documentation_of: //lib/utility/neighbor.hpp
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