#include <bits/stdc++.h>

using namespace std;

template <class T> struct MCMF {
  struct Edge {
    int dest, back;
    T cap, cost;
  };
  T total_flow, total_cost;
  vector<vector<Edge>> g;
  MCMF(int n) : g(n), total_flow(0), total_cost(0) {}

  void addEdge(int u, int v, T cap, T cost) {
    Edge a{v, (int)g[v].size(), cap, cost};
    Edge b{u, (int)g[u].size(), 0, -cost};
    g[u].push_back(a);
    g[v].push_back(b);
  }

  bool spfaFlow(int st, int ed) {
    int n = g.size();
    vector<T> dis(n, numeric_limits<T>::max() / 3);
    vector<bool> vis(n, false);
    vector<Edge*> path(n, nullptr);
    dis[st] = 0, vis[st] = true;
    queue<int> q;
    q.push(st);
    while (!q.empty()) {
      int u = q.front();
      q.pop(), vis[u] = false;
      for (auto& forward : g[u]) {
        if (forward.cap && dis[forward.dest] > dis[u] + forward.cost) {
          dis[forward.dest] = dis[u] + forward.cost;
          path[forward.dest] = &forward;
          if (!vis[forward.dest]) {
            vis[forward.dest] = true, q.push(forward.dest);
          }
        }
      }
    }
    T flow = -1;
    if (path[ed] != nullptr) {
      for (int u = ed; u != st; ) {
        flow = (flow == -1 ? path[u]->cap : min(flow, path[u]->cap));
        Edge& back = g[path[u]->dest][path[u]->back];
        u = back.dest;
      }
      total_flow += flow;
      for (int u = ed; u != st; ) {
        Edge& back = g[path[u]->dest][path[u]->back];
        path[u]->cap -= flow;
        back.cap += flow;
        total_cost += flow * path[u]->cost;
        u = back.dest;
      }
    }
    return path[ed] != nullptr;
  }
  
  pair<T, T> mcmf(int st, int ed) {
    while (spfaFlow(st, ed));
    return {total_flow, total_cost};
  }
};
