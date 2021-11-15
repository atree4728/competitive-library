---
title: Eratosthenes's Sieve / 素数判定・列挙
documentation_of: //lib/graph/sieve.hpp
---

## 概要
Eratosthenes の篩。

## 使い方
- `Sieve(const intmax_t n)`: constructor. $\mathcal{O}(n \log \log n)$.
- `bool is_prime(const intmax_t n)`: `n` の素数判定。$\mathcal{O}(\log n)$.
- `std::vector<intmax_t> factor(intmax_t n)`: `n` の素因数分解。sorted とは限らない。$\mathcal{O}(\log n)$.
- `intmax_t count_divisor(const intmax_t n)`: `n` の正の約数の個数。$\mathcal{O}(\log n)$.
