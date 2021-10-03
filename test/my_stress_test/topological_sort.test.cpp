#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include "lib/graph/topological_sort.hpp"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <random>
using namespace std;

random_device seed_gen;
mt19937_64 rnd(seed_gen());

int rand() { return uniform_int_distribution<int>(0, 100000)(rnd); }

void test() {
    for (size_t _ = 0; _ < 500000; _++) {
        size_t n = rand() % 20, m = n ? rand() % 30 : 0;
        bool is_cycle = rand() % 2;
        vector<int> ordered(n);
        iota(begin(ordered), end(ordered), 0);
        shuffle(begin(ordered), end(ordered), rnd);
        vector<vector<int>> ed(n);
        for (size_t i = 0; i < m; i++) {
            int a = rand() % n;
            int b = rand() % n;
            if (is_cycle and a >= b) continue;
            ed[ordered[a]].push_back(ordered[b]);
        }
        vector<int> ret = topological_sort(ed);
        if (is_cycle) assert(size(ret) == n);
        else
            assert(size(ret) <= n);
        vector<int> seen(n);
        for (const auto& i: ret) {
            assert(not seen[i]++);
            for (const auto& j: ed[i]) assert(not seen[j]);
        }
    }
}

int main() {
    test();
    std::cout << "Hello World\n";
    return 0;
}
