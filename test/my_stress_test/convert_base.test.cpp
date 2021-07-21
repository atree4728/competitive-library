#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include "../../lib/math/convert_base.hpp"

void test() {
    int M = 1e5;
    rep(i, M) {
        stringstream ss;
        ss << oct << i;
        assert(ss.str() == from_base10(i, 8));
        assert(i == to_base10(ss.str(), 8));
    }
    rep(i, M) {
        stringstream ss;
        ss << hex << i;
        assert(ss.str() == from_base10(i, 16));
        assert(i == to_base10(ss.str(), 16));
    }
}

int main() {
    test();
    cout << "Hello World\n";
    return 0;
}
