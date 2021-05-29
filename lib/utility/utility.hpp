#pragma once
using namespace std;

#include <algorithm>
#include <string>

bool palindrome(const string& s) {
    return equal(s.begin(), s.end(), s.rbegin());
}

template <class T>
inline bool chmax(T& a, T b) {
    return a < b and (a = b, true);
}

template <class T>
inline bool chmin(T& a, T b) {
    return a > b and (a = b, true);
}
