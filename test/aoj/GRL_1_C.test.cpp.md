---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/floyd_warshall.hpp
    title: "Floyd Warshall Algorithm / \u8CA0\u8FBA\u3092\u8A31\u3059\u5168\u70B9\u5BFE\
      \u6700\u77ED\u7D4C\u8DEF\u554F\u984C"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
  bundledCode: "#line 1 \"test/aoj/GRL_1_C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n\n#include <iostream>\n#include <limits>\n#line 2 \"lib/graph/floyd_warshall.hpp\"\
    \n\n#include <utility>\n#include <vector>\n\ntemplate<typename T> std::vector<std::vector<T>>\
    \ floyd_warshall(std::vector<std::vector<std::pair<std::size_t, T>>> const& graph)\
    \ {\n    using namespace std;\n    const size_t n = size(graph);\n    constexpr\
    \ T INF = numeric_limits<T>::max();\n    vector<vector<T>> dp(n, vector<T>(n,\
    \ INF));\n    for (size_t i = 0; i < n; i++) {\n        dp[i][i] = 0;\n      \
    \  for (const auto& [to, cost]: graph[i]) dp[i][to] = cost;\n    }\n    for (size_t\
    \ k = 0; k < n; k++)\n        for (size_t i = 0; i < n; i++)\n            for\
    \ (size_t j = 0; j < n; j++)\n                if (dp[i][k] < INF and dp[k][j]\
    \ < INF) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);\n    for (size_t i = 0;\
    \ i < n; i++)\n        if (dp[i][i] < 0) return {};\n    return dp;\n}\n#line\
    \ 6 \"test/aoj/GRL_1_C.test.cpp\"\n\nint main() {\n    using namespace std;\n\
    \    size_t v, e;\n    cin >> v >> e;\n    using P = pair<size_t, long long>;\n\
    \    vector<vector<P>> graph(v, vector<P>{});\n    while (e--) {\n        size_t\
    \ s, t;\n        long long d;\n        cin >> s >> t >> d;\n        graph[s].emplace_back(P{\
    \ t, d });\n    }\n    const auto result = floyd_warshall(graph);\n    if (empty(result))\n\
    \        cout << \"NEGATIVE CYCLE\\n\";\n    else\n        for (size_t i = 0;\
    \ i < v; i++)\n            for (size_t j = 0; j < v; j++) {\n                if\
    \ (result[i][j] >= numeric_limits<long long>::max()) cout << \"INF\";\n      \
    \          else\n                    cout << result[i][j];\n                cout\
    \ << \" \\n\"[j + 1 == v];\n            }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n\n#include <iostream>\n#include <limits>\n#include \"lib/graph/floyd_warshall.hpp\"\
    \n\nint main() {\n    using namespace std;\n    size_t v, e;\n    cin >> v >>\
    \ e;\n    using P = pair<size_t, long long>;\n    vector<vector<P>> graph(v, vector<P>{});\n\
    \    while (e--) {\n        size_t s, t;\n        long long d;\n        cin >>\
    \ s >> t >> d;\n        graph[s].emplace_back(P{ t, d });\n    }\n    const auto\
    \ result = floyd_warshall(graph);\n    if (empty(result))\n        cout << \"\
    NEGATIVE CYCLE\\n\";\n    else\n        for (size_t i = 0; i < v; i++)\n     \
    \       for (size_t j = 0; j < v; j++) {\n                if (result[i][j] >=\
    \ numeric_limits<long long>::max()) cout << \"INF\";\n                else\n \
    \                   cout << result[i][j];\n                cout << \" \\n\"[j\
    \ + 1 == v];\n            }\n}\n"
  dependsOn:
  - lib/graph/floyd_warshall.hpp
  isVerificationFile: true
  path: test/aoj/GRL_1_C.test.cpp
  requiredBy: []
  timestamp: '2021-10-03 22:09:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_C.test.cpp
- /verify/test/aoj/GRL_1_C.test.cpp.html
title: test/aoj/GRL_1_C.test.cpp
---
