#include <bits/stdc++.h>

using namespace std;

template<class T>
struct SparseTable {
  std::vector<std::vector<T>> f;
  std::vector<int> lg;
  SparseTable(){}
  SparseTable(const std::vector<T> &a) { init(a); }
  void init(const std::vector<T>& a) {
    int n = a.size();
    lg.assign(n + 1, 0);
    for (int i = 1, j = 0; i <= n; i++) {
      if (i == (1 << (j + 1))) j++;
      lg[i] = j;
    }
    f.assign(lg.back() + 1, std::vector<T>(a.size()));
    f[0] = a;
    for (int j = 1; (1 << j) <= n; j++) {
      for (int i = 0; i + (1 << j) - 1 < n; i++) {
        f[j][i] = min(f[j - 1][i], f[j - 1][i + (1 << (j - 1))]);
      }
    }
  }
  T query(int l, int r) {
    int j = lg[r - l + 1];
    return min(f[j][l], f[j][r - (1 << j) + 1]);
  }
};

struct LCA {
  const std::vector<std::vector<int>>& g;
  SparseTable<std::pair<int, int>> st;
  std::vector<int> sp;
  std::vector<int> dep, dfn;

  LCA(const std::vector<std::vector<int>>& graph, int root = 1) : g(graph) {
    int sz = graph.size();
    dep = dfn = std::vector<int>(sz);
    dfs(root, -1, 0);
    std::vector<std::pair<int, int>> vec;
    for (int i = 0; i < sp.size(); i++) {
      vec.emplace_back(dfn[sp[i]], sp[i]);
    }
    st.init(vec);
  }
  
  void dfs(int u, int fa, int d) {
    dep[u] = d + 1;
    dfn[u] = sp.size();
    sp.push_back(u);
    for (auto v : g[u]) {
      if (v != fa) {
        dfs(v, u, d + 1);
        sp.push_back(u);
      }
    }
  }

  int query(int u, int v) {
    int l = dfn[u], r = dfn[v];
    if (l > r) std::swap(l, r);
    return st.query(l, r).second;
  }
};
