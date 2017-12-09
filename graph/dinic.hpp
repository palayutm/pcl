#include <bits/stdc++.h>

using namespace std;

template <class T> struct Dinic {
  struct Edge {
    int dest, back;
    T cap;
  };
  vector<vector<Edge>> g;
  vector<int> dis;
  Dinic(int n) : g(n), dis(n) {}

  void addEdge(int u, int v, T cap) {
    Edge a{v, (int)g[v].size(), cap};
    Edge b{u, (int)g[u].size(), 0};
    g[u].push_back(a);
    g[v].push_back(b);
  }

  bool bfs(int st, int ed) {
    fill(dis.begin(), dis.end(), -1);
    dis[st] = 0;
    queue<int> q;
    q.push(st);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto& e : g[u]) {
        if (e.cap && dis[e.dest] == -1) {
          dis[e.dest] = dis[u] + 1;
          q.push(e.dest);
          if (e.dest == ed) return true;
        }
      }
    }
    return false;
  }

  T dfs(int u, int ed, T flow) {
    if (u == ed) return flow;
    T ret = 0;
    for (int i = 0; i < g[u].size(); i++) {
      Edge& forward = g[u][i], back = g[forward.dest][forward.back];
      if (forward.cap && dis[forward.dest] == dis[u] + 1) {
        T f = dfs(forward.dest, ed, flow == -1 ? forward.cap : min(forward.cap, flow - ret));
        forward.cap -= f;
        back.cap += f;
        ret += f;
        if (ret == flow) break;
      }
    }
    if (!ret) dis[u] = -1;
    return ret;
  }
  
  T maxFlow(int st, int ed) {
    T ret = 0;
    while (bfs(st, ed)) {
      ret += dfs(st, ed, -1);
    }
    return ret;
  }
};

