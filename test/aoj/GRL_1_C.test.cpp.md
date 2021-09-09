---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/floyd_warshall.hpp
    title: "Floyd Warshall Algorithm / \u8CA0\u8FBA\u3092\u8A31\u3059\u5168\u70B9\u5BFE\
      \u6700\u77ED\u7D4C\u8DEF\u554F\u984C"
  - icon: ':heavy_check_mark:'
    path: lib/include.hpp
    title: lib/include.hpp
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
    \n\n#line 2 \"lib/graph/floyd_warshall.hpp\"\n\n#line 2 \"lib/include.hpp\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_1, _2, _3,\
    \ name, ...) name\n#define rep1(n) for (decltype(n) _tmp = 0; _tmp < (n); _tmp++)\n\
    #define rep2(i, n) for (decltype(n) i = 0; i < (n); i++)\n#define rep3(i, a, b)\
    \ for (decltype(b) i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\nstruct IOSetup {\n    IOSetup() noexcept {\n\
    \        ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n        cout\
    \ << fixed << setprecision(10);\n        cerr << fixed << setprecision(10);\n\
    \    }\n} iosetup;\ntemplate<class T> bool chmax(T &a, const T &b) { return a\
    \ < b and (a = b, true); }\ntemplate<class T> bool chmin(T &a, const T &b) { return\
    \ a > b and (a = b, true); }\nusing i64 = long long;\nusing f64 = long double;\n\
    #line 4 \"lib/graph/floyd_warshall.hpp\"\n\n/**\n * @brief Floyd Warshall Algorithm\
    \ / \u8CA0\u8FBA\u3092\u8A31\u3059\u5168\u70B9\u5BFE\u6700\u77ED\u7D4C\u8DEF\u554F\
    \u984C\n * @docs docs/floyd_warshall.md\n */\n\ntemplate<typename T> vector<vector<T>>\
    \ floyd_warshall(vector<vector<pair<int, T>>> const& graph) {\n    int n = size(graph);\n\
    \    constexpr T INF = numeric_limits<T>::max();\n    vector<vector<T>> dp(n,\
    \ vector<T>(n, INF));\n    rep(i, n) {\n        dp[i][i] = 0;\n        for (const\
    \ auto& [to, cost]: graph[i]) dp[i][to] = cost;\n    }\n    rep(k, n) rep(i, n)\
    \ rep(j, n) if (dp[i][k] < INF and dp[k][j] < INF) chmin(dp[i][j], dp[i][k] +\
    \ dp[k][j]);\n    rep(i, n) if (dp[i][i] < 0) return {};\n    return dp;\n}\n\
    #line 4 \"test/aoj/GRL_1_C.test.cpp\"\n\nint main() {\n    size_t v, e;\n    cin\
    \ >> v >> e;\n    using P = pair<int, i64>;\n    vector<vector<P>> graph(v, vector<P>{});\n\
    \    while (e--) {\n        int s, t;\n        i64 d;\n        cin >> s >> t >>\
    \ d;\n        graph[s].emplace_back(P{t, d});\n    }\n    const auto result =\
    \ floyd_warshall(graph);\n    if (empty(result)) cout << \"NEGATIVE CYCLE\\n\"\
    ;\n    else\n        rep(i, v) rep(j, v) {\n            if (result[i][j] >= numeric_limits<i64>::max())\
    \ cout << \"INF\";\n            else\n                cout << result[i][j];\n\
    \            cout << \" \\n\"[j + 1 == v];\n        }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n\n#include \"../../lib/graph/floyd_warshall.hpp\"\n\nint main() {\n    size_t\
    \ v, e;\n    cin >> v >> e;\n    using P = pair<int, i64>;\n    vector<vector<P>>\
    \ graph(v, vector<P>{});\n    while (e--) {\n        int s, t;\n        i64 d;\n\
    \        cin >> s >> t >> d;\n        graph[s].emplace_back(P{t, d});\n    }\n\
    \    const auto result = floyd_warshall(graph);\n    if (empty(result)) cout <<\
    \ \"NEGATIVE CYCLE\\n\";\n    else\n        rep(i, v) rep(j, v) {\n          \
    \  if (result[i][j] >= numeric_limits<i64>::max()) cout << \"INF\";\n        \
    \    else\n                cout << result[i][j];\n            cout << \" \\n\"\
    [j + 1 == v];\n        }\n}\n"
  dependsOn:
  - lib/graph/floyd_warshall.hpp
  - lib/include.hpp
  isVerificationFile: true
  path: test/aoj/GRL_1_C.test.cpp
  requiredBy: []
  timestamp: '2021-09-09 23:28:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_C.test.cpp
- /verify/test/aoj/GRL_1_C.test.cpp.html
title: test/aoj/GRL_1_C.test.cpp
---
