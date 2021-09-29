---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/graph/topological_sort.hpp
    title: Topological Sort
  - icon: ':question:'
    path: lib/include.hpp
    title: lib/include.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/my_stress_test/topological_sort.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#line 2 \"lib/graph/topological_sort.hpp\"\n\n#line 2 \"lib/include.hpp\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#define overload3(_NULL, _2,\
    \ _3, name, ...) name\n#define rep1(i, n) for (remove_const_t<remove_reference_t<decltype(n)>>\
    \ i = 0; i < (n); i++)\n#define rep2(i, a, b) for (remove_const_t<remove_reference_t<decltype(b)>>\
    \ i = a; i < (b); i++)\n#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)\n\
    using size_type = size_t;\n#line 4 \"lib/graph/topological_sort.hpp\"\n\n/**\n\
    \ * @brief Topological Sort\n * @docs docs/topological_sort.md\n*/\n\ntemplate<typename\
    \ T> vector<T> topological_sort(vector<vector<T>> const &graph) {\n    const size_type\
    \ n = size(graph);\n    vector<unsigned int> indegree(n, 0);\n    for (const auto\
    \ edges: graph)\n        for (const auto to: edges) indegree[to]++;\n    queue<T>\
    \ indegree_is_0{};\n    rep(i, n) if (indegree[i] == 0) indegree_is_0.push(i);\n\
    \    vector<T> ordered{};\n    while (not empty(indegree_is_0)) {\n        T from\
    \ = indegree_is_0.front();\n        ordered.push_back(from);\n        indegree_is_0.pop();\n\
    \        for (const auto to: graph[from])\n            if (--indegree[to] == 0)\
    \ indegree_is_0.push(to);\n    }\n    if (size(ordered) < n) return {}; // graph\
    \ is not a DAG.\n    return ordered;\n}\n#line 4 \"test/my_stress_test/topological_sort.test.cpp\"\
    \n\nrandom_device seed_gen;\nmt19937_64 rnd(seed_gen());\n\nint rand() { return\
    \ uniform_int_distribution<int>(0, 100000)(rnd); }\n\nvoid test() {\n    rep(it,\
    \ 50000) {\n        size_t n = rand() % 20, m = n ? rand() % 30 : 0;\n       \
    \ bool is_cycle = rand() % 2;\n        vector<int> ordered(n);\n        iota(begin(ordered),\
    \ end(ordered), 0);\n        shuffle(begin(ordered), end(ordered), rnd);\n   \
    \     vector<vector<int>> ed(n);\n        rep(i, m) {\n            int a = rand()\
    \ % n;\n            int b = rand() % n;\n            if (is_cycle and a >= b)\
    \ continue;\n            ed[ordered[a]].push_back(ordered[b]);\n        }\n  \
    \      vector<int> ret = topological_sort(ed);\n        if (is_cycle) assert(size(ret)\
    \ == n);\n        else\n            assert(size(ret) <= n);\n        vector<int>\
    \ seen(n);\n        for (const auto& i: ret) {\n            assert(not seen[i]++);\n\
    \            for (const auto& j: ed[i]) assert(not seen[j]);\n        }\n    }\n\
    }\n\nint main() {\n    test();\n    cout << \"Hello World\\n\";\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#include \"../../lib/graph/topological_sort.hpp\"\n\nrandom_device seed_gen;\n\
    mt19937_64 rnd(seed_gen());\n\nint rand() { return uniform_int_distribution<int>(0,\
    \ 100000)(rnd); }\n\nvoid test() {\n    rep(it, 50000) {\n        size_t n = rand()\
    \ % 20, m = n ? rand() % 30 : 0;\n        bool is_cycle = rand() % 2;\n      \
    \  vector<int> ordered(n);\n        iota(begin(ordered), end(ordered), 0);\n \
    \       shuffle(begin(ordered), end(ordered), rnd);\n        vector<vector<int>>\
    \ ed(n);\n        rep(i, m) {\n            int a = rand() % n;\n            int\
    \ b = rand() % n;\n            if (is_cycle and a >= b) continue;\n          \
    \  ed[ordered[a]].push_back(ordered[b]);\n        }\n        vector<int> ret =\
    \ topological_sort(ed);\n        if (is_cycle) assert(size(ret) == n);\n     \
    \   else\n            assert(size(ret) <= n);\n        vector<int> seen(n);\n\
    \        for (const auto& i: ret) {\n            assert(not seen[i]++);\n    \
    \        for (const auto& j: ed[i]) assert(not seen[j]);\n        }\n    }\n}\n\
    \nint main() {\n    test();\n    cout << \"Hello World\\n\";\n    return 0;\n\
    }\n"
  dependsOn:
  - lib/graph/topological_sort.hpp
  - lib/include.hpp
  isVerificationFile: true
  path: test/my_stress_test/topological_sort.test.cpp
  requiredBy: []
  timestamp: '2021-09-29 20:09:01+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/my_stress_test/topological_sort.test.cpp
layout: document
redirect_from:
- /verify/test/my_stress_test/topological_sort.test.cpp
- /verify/test/my_stress_test/topological_sort.test.cpp.html
title: test/my_stress_test/topological_sort.test.cpp
---
