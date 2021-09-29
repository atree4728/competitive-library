#pragma once

#include <bits/stdc++.h>
using namespace std;
#define overload3(_NULL, _2, _3, name, ...) name
#define rep1(i, n) for (remove_const_t<remove_reference_t<decltype(n)>> i = 0; i < (n); i++)
#define rep2(i, a, b) for (remove_const_t<remove_reference_t<decltype(b)>> i = a; i < (b); i++)
#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
using size_type = size_t;
