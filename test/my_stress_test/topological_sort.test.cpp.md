---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/graph/topological_sort.hpp
    title: Topological Sort
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
    \n\n#line 2 \"lib/graph/topological_sort.hpp\"\n\n#include <queue>\n#include <vector>\n\
    \nstd::vector<std::size_t> topological_sort(std::vector<std::vector<std::size_t>>\
    \ const &graph) {\n    using namespace std;\n    const size_t n = size(graph);\n\
    \    vector<unsigned int> indegree(n, 0);\n    for (const auto &edges: graph)\n\
    \        for (const auto &to: edges) indegree[to]++;\n    queue<size_t> indeg0{};\n\
    \    for (size_t i = 0; i < n; i++)\n        if (indegree[i] == 0) indeg0.push(i);\n\
    \    vector<size_t> ordered{};\n    while (not empty(indeg0)) {\n        size_t\
    \ from = indeg0.front();\n        ordered.push_back(from);\n        indeg0.pop();\n\
    \        for (const auto &to: graph[from])\n            if (--indegree[to] ==\
    \ 0) indeg0.push(to);\n    }\n    if (size(ordered) < n) return {};  // graph\
    \ is not a DAG.\n    return ordered;\n}\n#line 4 \"test/my_stress_test/topological_sort.test.cpp\"\
    \n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <numeric>\n\
    #include <random>\nusing namespace std;\n\nrandom_device seed_gen;\nmt19937_64\
    \ rnd(seed_gen());\n\nint rand() { return uniform_int_distribution<int>(0, 100000)(rnd);\
    \ }\n\nvoid test() {\n    for (size_t _ = 0; _ < 500000; _++) {\n        size_t\
    \ n = rand() % 20, m = n ? rand() % 30 : 0;\n        bool is_cycle = rand() %\
    \ 2;\n        vector<int> ordered(n);\n        iota(begin(ordered), end(ordered),\
    \ 0);\n        shuffle(begin(ordered), end(ordered), rnd);\n        vector<vector<int>>\
    \ ed(n);\n        for (size_t i = 0; i < m; i++) {\n            int a = rand()\
    \ % n;\n            int b = rand() % n;\n            if (is_cycle and a >= b)\
    \ continue;\n            ed[ordered[a]].push_back(ordered[b]);\n        }\n  \
    \      vector<int> ret = topological_sort(ed);\n        if (is_cycle) assert(size(ret)\
    \ == n);\n        else\n            assert(size(ret) <= n);\n        vector<int>\
    \ seen(n);\n        for (const auto& i: ret) {\n            assert(not seen[i]++);\n\
    \            for (const auto& j: ed[i]) assert(not seen[j]);\n        }\n    }\n\
    }\n\nint main() {\n    test();\n    std::cout << \"Hello World\\n\";\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#include \"lib/graph/topological_sort.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <iostream>\n#include <numeric>\n#include <random>\nusing\
    \ namespace std;\n\nrandom_device seed_gen;\nmt19937_64 rnd(seed_gen());\n\nint\
    \ rand() { return uniform_int_distribution<int>(0, 100000)(rnd); }\n\nvoid test()\
    \ {\n    for (size_t _ = 0; _ < 500000; _++) {\n        size_t n = rand() % 20,\
    \ m = n ? rand() % 30 : 0;\n        bool is_cycle = rand() % 2;\n        vector<int>\
    \ ordered(n);\n        iota(begin(ordered), end(ordered), 0);\n        shuffle(begin(ordered),\
    \ end(ordered), rnd);\n        vector<vector<int>> ed(n);\n        for (size_t\
    \ i = 0; i < m; i++) {\n            int a = rand() % n;\n            int b = rand()\
    \ % n;\n            if (is_cycle and a >= b) continue;\n            ed[ordered[a]].push_back(ordered[b]);\n\
    \        }\n        vector<int> ret = topological_sort(ed);\n        if (is_cycle)\
    \ assert(size(ret) == n);\n        else\n            assert(size(ret) <= n);\n\
    \        vector<int> seen(n);\n        for (const auto& i: ret) {\n          \
    \  assert(not seen[i]++);\n            for (const auto& j: ed[i]) assert(not seen[j]);\n\
    \        }\n    }\n}\n\nint main() {\n    test();\n    std::cout << \"Hello World\\\
    n\";\n    return 0;\n}\n"
  dependsOn:
  - lib/graph/topological_sort.hpp
  isVerificationFile: true
  path: test/my_stress_test/topological_sort.test.cpp
  requiredBy: []
  timestamp: '2021-11-15 23:15:51+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/my_stress_test/topological_sort.test.cpp
layout: document
redirect_from:
- /verify/test/my_stress_test/topological_sort.test.cpp
- /verify/test/my_stress_test/topological_sort.test.cpp.html
title: test/my_stress_test/topological_sort.test.cpp
---
