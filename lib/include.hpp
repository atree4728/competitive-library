#pragma once

#include <bits/stdc++.h>
using namespace std;
#define overload3(_1, _2, _3, name, ...) name
#define rep1(n) for (auto _tmp = 0; _tmp < (n); _tmp++)
#define rep2(i, n) for (auto i = 0; i < (n); i++)
#define rep3(i, a, b) for (auto i = a; i < (b); i++)
#define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
template<class T> bool chmax(T &a, const T &b) { return a < b and (a = b, true); }
template<class T> bool chmin(T &a, const T &b) { return a > b and (a = b, true); }
using i64 = long long;
using f64 = long double;
