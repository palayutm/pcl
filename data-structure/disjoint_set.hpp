#include <bits/stdc++.h>

struct DisjointSet {
  std::vector<int> pre;

  DisjointSet(int n) : pre(n){
    for (int i = 0; i < n; i++) {
      pre[i] = i;
    }
  }
  int find(int u) { return pre[u] == u ? pre[u] : pre[u] = find(pre[u]); }
  void merge(int u, int v) { pre[find(u)] = find(v); }
};
