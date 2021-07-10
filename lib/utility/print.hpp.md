---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Print
    links: []
  bundledCode: "#line 1 \"lib/utility/print.hpp\"\n#define IGNORE\n#line 2 \"lib/include.hpp\"\
    \n#include <bits/stdc++.h>\n#include <experimental/iterator>\nusing namespace\
    \ std;\n#define overload3(_1, _2, _3, name, ...) name\n#define rep1(n) for (auto\
    \ _i = 0; _i < n; _i++)\n#define rep2(i, n) for (auto i = 0; i < n; i++)\n#define\
    \ rep3(i, a, b) for (auto i = a; i < b; i++)\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\ntemplate <class T> bool chmax(T &a, const T\
    \ &b) { return a < b ? a = b, true : false; }\ntemplate <class T> bool chmin(T\
    \ &a, const T &b) { return a > b ? a = b, true : false; }\nusing i64 = long long;\n\
    using f64 = long double;\n#line 3 \"lib/utility/print.hpp\"\n\n/**\n * @brief\
    \ Print\n */\n\nstruct Print {\n    ostream &os;\n    const string sep;\n    bool\
    \ is_debug;\n    Print(ostream &os, string sep, bool is_debug):\n        os(os),\
    \ sep(sep), is_debug(is_debug) {}\n    void operator()(bool) { os << \"\\n\";\
    \ }\n    template<class Head, class... Tail> void operator()(bool is_first, Head\
    \ &&head, Tail &&...tail) {\n        os << head;\n        if (not is_first and\
    \ sizeof...(tail) != 0) os << sep;\n        operator()(false, forward<Tail>(tail)...);\n\
    \    }\n    template<class T> void operator()(bool, vector<T> &vec) {\n      \
    \  copy(cbegin(vec), cend(vec), experimental::make_ostream_joiner(os, sep));\n\
    \        os << \"\\n\";\n    }\n    template<class T> void operator()(bool, vector<vector<T>>\
    \ &vv) {\n        size_t ind = 0;\n        if (is_debug) os << \"\\n\";\n    \
    \    for (auto &vec: vv) {\n            if (is_debug) os << ind++ << \": \";\n\
    \            operator()(false, vec);\n        }\n    }\n};\n\nauto print_impl\
    \ = Prnt(cout, \" \", false);\n#define print(...) print_impl(true, \"\", __VA_ARGS__)\n\
    #ifdef LOCAL\nauto debug_impl = Print(cerr, \" \", true);\n    #define debug(...)\
    \ debug_impl(true, \"(\" #__VA_ARGS__ \") \"s, __VA_ARGS__)\n#else\n    #define\
    \ debug(...)\n#endif\n"
  code: "#define IGNORE\n#include \"../include.hpp\"\n\n/**\n * @brief Print\n */\n\
    \nstruct Print {\n    ostream &os;\n    const string sep;\n    bool is_debug;\n\
    \    Print(ostream &os, string sep, bool is_debug):\n        os(os), sep(sep),\
    \ is_debug(is_debug) {}\n    void operator()(bool) { os << \"\\n\"; }\n    template<class\
    \ Head, class... Tail> void operator()(bool is_first, Head &&head, Tail &&...tail)\
    \ {\n        os << head;\n        if (not is_first and sizeof...(tail) != 0) os\
    \ << sep;\n        operator()(false, forward<Tail>(tail)...);\n    }\n    template<class\
    \ T> void operator()(bool, vector<T> &vec) {\n        copy(cbegin(vec), cend(vec),\
    \ experimental::make_ostream_joiner(os, sep));\n        os << \"\\n\";\n    }\n\
    \    template<class T> void operator()(bool, vector<vector<T>> &vv) {\n      \
    \  size_t ind = 0;\n        if (is_debug) os << \"\\n\";\n        for (auto &vec:\
    \ vv) {\n            if (is_debug) os << ind++ << \": \";\n            operator()(false,\
    \ vec);\n        }\n    }\n};\n\nauto print_impl = Prnt(cout, \" \", false);\n\
    #define print(...) print_impl(true, \"\", __VA_ARGS__)\n#ifdef LOCAL\nauto debug_impl\
    \ = Print(cerr, \" \", true);\n    #define debug(...) debug_impl(true, \"(\" #__VA_ARGS__\
    \ \") \"s, __VA_ARGS__)\n#else\n    #define debug(...)\n#endif\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/utility/print.hpp
  requiredBy: []
  timestamp: '2021-07-10 14:38:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/utility/print.hpp
layout: document
redirect_from:
- /library/lib/utility/print.hpp
- /library/lib/utility/print.hpp.html
title: Print
---
