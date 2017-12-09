#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100005;
const int inf = 1e9;

vector<pair<int, int>> g[N];
int sz[N], d[N], st[N], root, minn, top;
bool done[N];

void dfs1(int u, int fa, int n) {
  sz[u] = 1;
  int mx = 0;
  for (auto e : g[u]) {
    int v = e.first;
    if (v != fa && !done[v]) {
      dfs1(v, u, n);
      sz[u] += sz[v];
      mx = max(mx, sz[v]);
    }
  }
  mx = max(mx, n - sz[u]);
  if (mx < minn) {
    minn = mx;
    root = u;
  }
}

void dfs2(int u, int fa, int x) {
  st[top++] = u;
  d[u] = d[fa] + 1;
  for (auto e : g[u]) {
    int v = e.first, w = e.second;
    if (v != fa && !done[v]) {
      dfs2(v, u, w);
    }
  }
}

ll cal(int l, int r) {
  for (int i = l; i < r; ++i) {
    int v = st[i];
    // modify
  }
  return 0;
}

ll solve(int u, int n) {
  minn = inf;
  dfs1(u, -1, n);
  u = root;
  dfs1(u, -1, n);
  done[u] = true;
  ll ans = 0;
  for (auto e : g[u]) {
    int v = e.first;
    if (!done[v]) {
      ans += solve(v, sz[v]);
    }
  }
  done[u] = false;
  st[0] = u;
  top = 1;
  d[u] = 0;
  for (auto e : g[u]) {
    int v = e.first, w = e.second;
    if (!done[v]) {
      int pre = top;
      dfs2(v, u, w);
      ans -= cal(pre, top);
    }
  }
  return ans + cal(0, top);
}
