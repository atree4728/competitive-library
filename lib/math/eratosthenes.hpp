#pragma once

#include <vector>
#include <numeric>
#include <cassert>
#include <map>

using namespace std;

/**
 *@brief Eratosthenes's sieve
 */

class Eratosthenes {
    int size;
    vector<int> min_factor;
    vector<int> prime_list;

    void init() {
        assert(size >= 0);
        iota(begin(min_factor), end(min_factor), 0);
        for (int i = 2; i * i <= size; i++) {
            if (min_factor[i] != i) {
                prime_list.emplace_back(i);
                continue;
            }
            for (int mul = i * 2; mul <= size; mul += i) {
                if (min_factor[mul] == mul) min_factor[mul] = i;
            }
        }
    }

   public:
    Eratosthenes(const int size_) : size(size_), min_factor(size_ + 1) {
        init();
    };

    bool is_prime(const int n) { return min_factor[n] == n and n >= 2; }

    map<long long, int> prime_factorize(const long long n) {
        assert(1 <= n and n < (long long)size * size);
        if (n == 1) return {};
        map<long long, int> factor;
        long long cur = n;
        while (cur != 1) {
            factor[min_factor[cur]]++;
            cur /= min_factor[cur];
        }
        return factor;
    }

    int count_divisor(const long long n) {
        assert(1 <= n and n < (long long)size * size);
        long long ret = 1;
        map<long long, int> factor = prime_factorize(n);
        for (auto [p, ex] : factor) ret *= (ex + 1);
        return ret;
    }
};
