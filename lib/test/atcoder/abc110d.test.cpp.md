---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: modulus/modint.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc110/tasks/abc110_d\"\n\n\
    #include <bits/stdc++.h>\n#include \"modulus/modint.hpp\"\n#include \"modulus/combination.hpp\"\
    \n#include \"math/utility.hpp\"\nusing namespace std;\n\nconstexpr int MOD = 1000000007;\n\
    constexpr int M = 200000;\nusing mint = Modint<MOD>;\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    long long n, m;\n    cin >> n >> m;\n    map<long\
    \ long, int> factor = prime_factorize(n);\n    mint ans = 1;\n    CombinationTable<MOD>\
    \ ct(M);\n    for (auto [_, ex] : factor) ans *= ct.C(n + ex - 1, ex);\n    cout\
    \ << ans.val() << \"\\n\";\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: lib/test/atcoder/abc110d.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: lib/test/atcoder/abc110d.test.cpp
layout: document
redirect_from:
- /verify/lib/test/atcoder/abc110d.test.cpp
- /verify/lib/test/atcoder/abc110d.test.cpp.html
title: lib/test/atcoder/abc110d.test.cpp
---
