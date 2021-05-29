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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: utility/cumulative_sum.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"utility/cumulative_sum.hpp\"\
    \n\nstruct IOSetup {\n    IOSetup() noexcept {\n        ios::sync_with_stdio(false);\n\
    \        cin.tie(nullptr);\n        cout << fixed << setprecision(10);\n     \
    \   cerr << fixed << setprecision(10);\n    }\n} IOSetup;\n\nint main() {\n  \
    \  int n, q;\n    cin >> n >> q;\n    vector<long long> a(n);\n    for (auto &&elem\
    \ : a) cin >> elem;\n    CumulativeSum1D cs(a);\n    while (q--) {\n        int\
    \ l, r;\n        cin >> l >> r;\n        cout << cs(l, r) << \"\\n\";\n    }\n\
    \    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: lib/test/library-checker/static_range_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: lib/test/library-checker/static_range_sum.test.cpp
layout: document
redirect_from:
- /verify/lib/test/library-checker/static_range_sum.test.cpp
- /verify/lib/test/library-checker/static_range_sum.test.cpp.html
title: lib/test/library-checker/static_range_sum.test.cpp
---
