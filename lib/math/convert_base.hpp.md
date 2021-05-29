---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Base conversion
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: math/utility.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include <string>\n#include <algorithm>\n#include <cassert>\n\
    \n#include \"math/utility.hpp\"\n\nusing namespace std;\n\n/**\n * @brief Base\
    \ conversion\n * @detail when base > 10, it will be used lower case letters\n\
    \ */\nlong long to_base10(string n, int base) {\n    long long ret = 0;\n    int\
    \ s = (n[0] == '-' ? 1 : 0);\n    reverse(begin(n), end(n));\n    for (int i =\
    \ s; (size_t)i < size(n); i++) {\n        int d = (isdigit(n[i]) ? (n[i] - '0')\
    \ : (n[i] - 'a' + 10));\n        ret += mypow(base, i) * d;\n    }\n    return\
    \ ret * (s == 1 ? -1 : 1);\n}\n\nstring from_base10(long long n, int base) {\n\
    \    assert(2 <= base and base <= 36);\n    const string table = \"0123456789abcdefghijklmnopqrstuvwxyz\"\
    ;\n    bool is_negative = (n < 0);\n    if (is_negative) n *= -1;\n    assert(n\
    \ >= 0);\n    string ret;\n    while (n >= base) {\n        ret.push_back(table[n\
    \ % base]);\n        n /= base;\n    }\n    ret.push_back(table[n]);\n    reverse(begin(ret),\
    \ end(ret));\n    return (is_negative ? \"-\" : \"\") + ret;\n}\n\nstring convert_base(string\
    \ n, int from_base, int to_base) {\n    return from_base10((to_base10(n, from_base)),\
    \ to_base);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/convert_base.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/convert_base.hpp
layout: document
redirect_from:
- /library/lib/math/convert_base.hpp
- /library/lib/math/convert_base.hpp.html
title: Base conversion
---
