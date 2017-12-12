#include <bits/stdc++.h>

struct Euler {
  std::vector<std::vector<int>> g;
  std::vector<int> path;

  Euler(const std::vector<std::vector<int>> &graph, int start) : g(graph) {
    find(start);
    std::reverse(path.begin(), path.end());
  }

  void find(int u) {
    while (!g[u].empty()) {
      int v = g[u].back();
      g[u].pop_back();
      find(v);
    }
    path.push_back(u);
  }
};
