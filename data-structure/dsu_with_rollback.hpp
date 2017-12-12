#include <bits/stdc++.h>

struct DSU {
  std::vector<int> pre, rank;
  std::vector<int> op;

  DSU(int n) : rank(n), pre(n) {
    for (int i = 0; i < n; i++) {
      pre[i] = i;
    }
  }

  int find(int u) { return u == pre[u] ? pre[u] : find(pre[u]); }

  void merge(int u, int v) {
    int fu = find(u), fv = find(v);
    if (fu == fv)
      return;
    if (rank[fu] > rank[fv]) {
      std::swap(fu, fv);
    }
    if (rank[fu] == rank[fv]) {
      rank[fv]++;
      op.push_back(-fv);
    }
    pre[fu] = fv;
    op.push_back(fu);
  }

  int getStamp() { return op.size(); }

  void restore(int stamp) {
    while (op.size() > stamp) {
      if (op.back() > 0) {
        pre[op.back()] = op.back();
      } else {
        rank[-op.back()]--;
      }
      op.pop_back();
    }
  }
};
