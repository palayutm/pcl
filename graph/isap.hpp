#include <bits/stdc++.h>

using namespace std;

template <class T> struct ISAP {
  struct Edge {
    int dest, back;
    T cap;
  };
  vector<vector<Edge>> g;
  vector<int> d, vd;
  ISAP(int n) : g(n), d(n), vd(n * 2) {
    vd[0] = n;
  }

  void addEdge(int u, int v, T cap) {
    Edge a{v, (int)g[v].size(), cap};
    Edge b{u, (int)g[u].size(), 0};
    g[u].push_back(a);
    g[v].push_back(b);
  }

  T sap(int u, int st, int ed, T flow) {
    if (u == ed) return flow;
    T ret = 0;
    for (auto& forward : g[u]) {
      auto& back = g[forward.dest][forward.back];
      if (d[forward.dest] < d[u] && forward.cap) {
        T f = sap(forward.dest, st, ed, flow == -1 ? forward.cap : min(flow - ret, forward.cap));
        ret += f;
        forward.cap -= f;
        back.cap += f;
        if (ret == flow) return ret;
      }
    }
    if (!(--vd[d[u]])) d[st] = g.size() + 2;
    vd[++d[u]]++;
    return ret;
  }
  
  T maxFlow(int st, int ed) {
    T ret = 0;
    while (d[st] < g.size()) ret += sap(st, st, ed, -1);
    return ret;
  }
};
