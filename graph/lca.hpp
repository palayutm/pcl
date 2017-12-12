#include "../data-structure/sparse_table.hpp"

struct LCA {
  const std::vector<std::vector<int>>& g;
  SparseTable<std::pair<int, int>> st;
  std::vector<int> sp;
  std::vector<int> dep, ST, ED;

  LCA(const std::vector<std::vector<int>>& graph, int root = 1) : g(graph) {
    int sz = graph.size();
    dep = ST = ED = std::vector<int>(sz);
    dfs(root, -1, 0);
    std::vector<std::pair<int, int>> vec;
    for (int i = 0; i < sp.size(); i++) {
      vec.emplace_back(ST[sp[i]], sp[i]);
    }
    st.init(vec);
  }
  
  void dfs(int u, int fa, int d) {
    dep[u] = d + 1;
    ST[u] = sp.size();
    sp.push_back(u);
    for (auto v : g[u]) {
      if (v != fa) {
        dfs(v, u, d + 1);
        sp.push_back(u);
      }
    }
    ED[u] = (int)sp.size() - 1;
  }

  int query(int u, int v) {
    int l = ST[u], r = ST[v];
    if (l > r) std::swap(l, r);
    return st.query(l, r).second;
  }
};
