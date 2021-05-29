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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: math/convert_base.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#include <bits/stdc++.h>\n#include \"math/convert_base.hpp\"\n\nusing namespace\
    \ std;\n\nvoid test() {\n    for (int i = 0; i < 100000; i++) {\n        stringstream\
    \ ss;\n        ss << oct << i;\n        assert(ss.str() == from_base10(i, 8));\n\
    \        assert(i == to_base10(ss.str(), 8));\n    }\n    for (int i = 0; i <\
    \ 100000; i++) {\n        stringstream ss;\n        ss << hex << i;\n        assert(ss.str()\
    \ == from_base10(i, 16));\n        assert(i == to_base10(ss.str(), 16));\n   \
    \ }\n}\n\nint main() {\n    cout << \"Hello World\\n\";\n    test();\n    return\
    \ 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: lib/test/my_stress_test/convert_base.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: lib/test/my_stress_test/convert_base.test.cpp
layout: document
redirect_from:
- /verify/lib/test/my_stress_test/convert_base.test.cpp
- /verify/lib/test/my_stress_test/convert_base.test.cpp.html
title: lib/test/my_stress_test/convert_base.test.cpp
---
