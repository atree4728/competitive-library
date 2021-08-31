#pragma once

#include "../include.hpp"

/**
 * @brief Eratosthenes's Sieve
 * @note construct in $O(NloglogN)$, return prime determination in $O(1)$ and number of constants and prime factorization fastly(<-?).
 */

struct Sieve {
    int size;
    vector<int> min_factor, prime_list;
    explicit Sieve(const int size_):
        size(size_), min_factor(size_ + 1) {
        iota(begin(min_factor), end(min_factor), 0);
        for (int i = 2; i <= size; i++) {
            if (min_factor[i] != i) {
                prime_list.emplace_back(i);
                continue;
            }
            for (int mul = i * 2; mul <= size; mul += i)
                if (min_factor[mul] == mul) min_factor[mul] = i;
        }
    };
    bool is_prime(const int n) { return n >= 2 and (int) min_factor[n] == n; }
    map<int, int> prime_factorize(const int n) {
        assert(1 <= n and n <= (int)size);
        if (n == 1) return {};
        map<int, int> factor{};
        int cur = n;
        while (cur != 1) {
            factor[min_factor[cur]]++;
            cur /= min_factor[cur];
        }
        return factor;
    }
    int count_divisor(const int n) {
        assert(1 <= n and n <= (int)size);
        int ret = 1;
        map<int, int> factor = prime_factorize(n);
        for (auto [_, ex]: factor) ret *= (ex + 1);
        return ret;
    }
};
