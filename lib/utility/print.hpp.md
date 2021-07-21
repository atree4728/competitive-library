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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ lib/utility/print.hpp: line 3: #pragma once found in a non-first line\n"
  code: "#define IGNORE\n\n#pragma once\n\n#include \"../include.hpp\"\n\n/**\n *\
    \ @brief Print\n */\n\nstruct Print {\n    ostream &os;\n    const string sep;\n\
    \    bool is_debug;\n    Print(ostream &os, string sep, bool is_debug):\n    \
    \    os(os), sep(sep), is_debug(is_debug) {}\n    void operator()(bool) { os <<\
    \ \"\\n\"; }\n    template<class Head, class... Tail> void operator()(bool is_first,\
    \ Head &&head, Tail &&...tail) {\n        os << head;\n        if (not is_first\
    \ and sizeof...(tail) != 0) os << sep;\n        operator()(false, forward<Tail>(tail)...);\n\
    \    }\n    template<class T> void operator()(bool, vector<T> &vec) {\n      \
    \  copy(cbegin(vec), cend(vec), experimental::make_ostream_joiner(os, sep));\n\
    \        os << \"\\n\";\n    }\n    template<class T> void operator()(bool, vector<vector<T>>\
    \ &vv) {\n        size_t ind = 0;\n        if (is_debug) os << \"\\n\";\n    \
    \    for (auto &vec: vv) {\n            if (is_debug) os << ind++ << \": \";\n\
    \            operator()(false, vec);\n        }\n    }\n};\n\nauto print_impl\
    \ = Print(cout, \" \", false);\n#define print(...) print_impl(true, \"\", __VA_ARGS__)\n\
    #ifdef LOCAL\nauto debug_impl = Print(cerr, \" \", true);\n    #define debug(...)\
    \ debug_impl(true, \"(\" #__VA_ARGS__ \") \"s, __VA_ARGS__)\n#else\n    #define\
    \ debug(...) void(0)\n#endif\n"
  dependsOn:
  - lib/include.hpp
  isVerificationFile: false
  path: lib/utility/print.hpp
  requiredBy: []
  timestamp: '2021-07-21 10:45:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/utility/print.hpp
layout: document
redirect_from:
- /library/lib/utility/print.hpp
- /library/lib/utility/print.hpp.html
title: Print
---
