#include "lca.hpp"

struct CompressedTree {
  LCA lca;
  std::vector<std::vector<int>> g;
  CompressedTree(const std::vector<std::vector<int>>& graph, int root = 1) : lca(graph, root), g(graph.size()) {}

  int construct(std::vector<int> vertex) {
    auto cmp = [this](int u, int v) { return this->lca.ST[u] < lca.ST[v]; };
    sort(vertex.begin(), vertex.end(), cmp);
    int n = vertex.size();
    for (int i = 1; i < n; i++) {
      vertex.push_back(lca.query(vertex[i], vertex[i - 1]));
    }
    sort(vertex.begin(), vertex.end(), cmp);
    vertex.erase(unique(vertex.begin(), vertex.end()), vertex.end());
    std::vector<int> sd;
    for (auto v : vertex) {
      g[v].clear();
      for (; !sd.empty() && !(lca.ST[sd.back()] <= lca.ST[v] && lca.ST[v] <= lca.ED[sd.back()]); sd.pop_back());
      if (!sd.empty()) {
        g[sd.back()].push_back(v);
      }
      sd.push_back(v);
    }
    return vertex[0];
  }
};
