---
title: Recursively Memorize
documentation_of: //lib/utility/memorize.hpp
---

[C++14 における自動メモ化再帰](https://taotao54321.hatenablog.com/entry/2019/07/20/003446) を C++17 で書き直した。

## Usage
```
auto dfs = rec_memorize<limit_of_t1, limit_of_t2, limit_of_t3, ...>([&](auto &&self, T1, T2, T3, ...) -> R { ... });
auto ans = dfs(T1, T2, T3, ...);
```
