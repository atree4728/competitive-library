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
  code: "#define PROBLEM \"https://atcoder.jp/contests/arc025/tasks/arc025_2\"\n\n\
    #include <bits/stdc++.h>\n#include \"utility/cumulative_sum.hpp\"\n#include \"\
    utility/utility.hpp\"\n\n#define rep(i, n) for (int i = 0; i < n; i++)\n\nint\
    \ main() {\n    int h, w;\n    cin >> h >> w;\n    vector<vector<int>> c(h, vector<int>(w));\n\
    \    for (vector<int> &vec : c)\n        for (auto &&elem : vec) cin >> elem;\n\
    \    rep(i, h) rep(j, w) if ((i + j) % 2 == 0) c[i][j] *= -1;\n    CumulativeSum2D<int>\
    \ cs(c);\n    int ans = 0;\n    for (int sh = 0; sh <= h; sh++) {\n        for\
    \ (int sw = 0; sw <= w; sw++) {\n            for (int gh = sh + 1; gh <= h; gh++)\
    \ {\n                for (int gw = sw + 1; gw <= w; gw++) {\n                \
    \    if (cs(sh, sw, gh, gw) == 0) {\n                        chmax(ans, (gh -\
    \ sh) * (gw - sw));\n                    }\n                }\n            }\n\
    \        }\n    }\n    cout << ans << \"\\n\";\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: lib/test/atcoder/arc025b.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: lib/test/atcoder/arc025b.test.cpp
layout: document
redirect_from:
- /verify/lib/test/atcoder/arc025b.test.cpp
- /verify/lib/test/atcoder/arc025b.test.cpp.html
title: lib/test/atcoder/arc025b.test.cpp
---
