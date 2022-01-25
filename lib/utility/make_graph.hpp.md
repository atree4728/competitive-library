---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/utility/template.hpp
    title: lib/utility/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1595.test.cpp
    title: test/aoj/1595.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/utility/make_graph.hpp\"\n\n#include <vector>\n\ntemplate<class\
    \ V> auto make_graph(size_t n, const std::vector<std::tuple<V, V>>& edges, bool\
    \ is_directed = false) {\n    std::vector graph(n, std::vector<size_t>{});\n \
    \   for (const auto& [u, v]: edges) {\n        graph[u].emplace_back(v);\n   \
    \     if (not is_directed) graph[v].emplace_back(u);\n    }\n    return graph;\n\
    }\n\ntemplate<class V, class W> auto make_graph(size_t n, const std::vector<std::tuple<V,\
    \ V, W>>& edges, bool is_directed = false) {\n    std::vector graph(n, std::vector<std::pair<size_t,\
    \ W>>{});\n    for (const auto& [u, v, w]: edges) {\n        graph[u].emplace_back(v,\
    \ w);\n        if (not is_directed) graph[v].emplace_back(u, w);\n    }\n    return\
    \ graph;\n}\n"
  code: "#pragma once\n\n#include <vector>\n\ntemplate<class V> auto make_graph(size_t\
    \ n, const std::vector<std::tuple<V, V>>& edges, bool is_directed = false) {\n\
    \    std::vector graph(n, std::vector<size_t>{});\n    for (const auto& [u, v]:\
    \ edges) {\n        graph[u].emplace_back(v);\n        if (not is_directed) graph[v].emplace_back(u);\n\
    \    }\n    return graph;\n}\n\ntemplate<class V, class W> auto make_graph(size_t\
    \ n, const std::vector<std::tuple<V, V, W>>& edges, bool is_directed = false)\
    \ {\n    std::vector graph(n, std::vector<std::pair<size_t, W>>{});\n    for (const\
    \ auto& [u, v, w]: edges) {\n        graph[u].emplace_back(v, w);\n        if\
    \ (not is_directed) graph[v].emplace_back(u, w);\n    }\n    return graph;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/utility/make_graph.hpp
  requiredBy:
  - lib/utility/template.hpp
  timestamp: '2022-01-16 21:32:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1595.test.cpp
documentation_of: lib/utility/make_graph.hpp
layout: document
redirect_from:
- /library/lib/utility/make_graph.hpp
- /library/lib/utility/make_graph.hpp.html
title: lib/utility/make_graph.hpp
---
