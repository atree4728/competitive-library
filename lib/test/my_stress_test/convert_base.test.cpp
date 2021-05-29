#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include <bits/stdc++.h>
#include "lib/math/convert_base.hpp"

using namespace std;

void test() {
    for (int i = 0; i < 100000; i++) {
        stringstream ss;
        ss << oct << i;
        assert(ss.str() == from_base10(i, 8));
        assert(i == to_base10(ss.str(), 8));
    }
    for (int i = 0; i < 100000; i++) {
        stringstream ss;
        ss << hex << i;
        assert(ss.str() == from_base10(i, 16));
        assert(i == to_base10(ss.str(), 16));
    }
}

int main() {
    cout << "Hello World\n";
    test();
    return 0;
}
