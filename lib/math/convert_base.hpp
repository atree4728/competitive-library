#pragma once

#include "../include.hpp"

/**
 * @brief Convert base
 * @note when base > 10, it will be used lower case letters
 */
i64 to_base10(string n, int base) {
    i64 ret = 0;
    int s = (n[0] == '-' ? 1 : 0);
    reverse(begin(n), end(n));
    rep(i, s, size(n)) {
        int d = (isdigit(n[i]) ? (n[i] - '0') : (n[i] - 'a' + 10));
        ret += pow(base, i) * d;
    }
    return ret * (s == 1 ? -1 : 1);
}

string from_base10(i64 n, int base) {
    assert(2 <= base and base <= 36);
    const string table = "0123456789abcdefghijklmnopqrstuvwxyz";
    bool is_negative = (n < 0);
    if (is_negative) n *= -1;
    string ret;
    while (n >= base) {
        ret.push_back(table[n % base]);
        n /= base;
    }
    ret.push_back(table[n]);
    reverse(begin(ret), end(ret));
    return (is_negative ? "-" : "") + ret;
}

string convert_base(string n, int from_base, int to_base) {
    return from_base10((to_base10(n, from_base)), to_base);
}
