---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/utility/utility.hpp\"\nusing namespace std;\n\n#include\
    \ <algorithm>\n#include <string>\n\nbool is_palindrome(const string& s) {\n  \
    \  return equal(s.begin(), s.end(), s.rbegin());\n}\n\ntemplate <class T>\ninline\
    \ bool chmax(T& a, T b) {\n    return a < b and (a = b, true);\n}\n\ntemplate\
    \ <class T>\ninline bool chmin(T& a, T b) {\n    return a > b and (a = b, true);\n\
    }\n"
  code: "#pragma once\nusing namespace std;\n\n#include <algorithm>\n#include <string>\n\
    \nbool is_palindrome(const string& s) {\n    return equal(s.begin(), s.end(),\
    \ s.rbegin());\n}\n\ntemplate <class T>\ninline bool chmax(T& a, T b) {\n    return\
    \ a < b and (a = b, true);\n}\n\ntemplate <class T>\ninline bool chmin(T& a, T\
    \ b) {\n    return a > b and (a = b, true);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/utility/utility.hpp
  requiredBy: []
  timestamp: '2021-05-29 23:05:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/utility/utility.hpp
layout: document
redirect_from:
- /library/lib/utility/utility.hpp
- /library/lib/utility/utility.hpp.html
title: lib/utility/utility.hpp
---
