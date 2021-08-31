#pragma once

#include <bits/stdc++.h>
using namespace std;
#define overload3(_1, _2, _3, name, ...) name
#define rep1(n) for (decltype(n) _tmp = 0; _tmp < (n); _tmp++)
#define rep2(i, n) for (decltype(n) i = 0; i < (n); i++)
#define rep3(i, a, b) for (decltype(b) i = a; i < (b); i++)
#define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
struct IOSetup {
    IOSetup() noexcept {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
} iosetup;
template<class T> bool chmax(T &a, const T &b) { return a < b and (a = b, true); }
template<class T> bool chmin(T &a, const T &b) { return a > b and (a = b, true); }
using i64 = long long;
using f64 = long double;
