#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100005;

vector<int> g[N];
int sz[N], st[N], ed[N], ver[N], lay = 0;
int col[N];
ll ans[N];

int dfs1(int u, int fa) {
  ver[lay] = u;
  st[u] = lay++;
  sz[u] = 1;
  for (auto v : g[u]) {
    if (v != fa) {
      sz[u] += dfs1(v, u);
    }
  }
  ed[u] = lay;
  return sz[u];
}

void add(int u) {
}

void del(int u) {
}

void dfs2(int u, int fa, bool keep) {
  int mx = -1, heavy = -1;
  for (auto v : g[u]) {
    if (v != fa && sz[v] > mx) {
      mx = sz[v], heavy = v;
    }
  }
  for (auto v : g[u]) {
    if (v != fa && v != heavy) {
      dfs2(v, u, false);
    }
  }
  if (heavy != -1) {
    dfs2(heavy, u, true);
  }
  add(u);
  for (auto v : g[u]) {
    if (v != fa && v != heavy) {
      for (int i = st[v]; i < ed[v]; i++) {
        add(ver[i]);
      }
    }
  }
  // calculate answer
  if (!keep) {
    for (int i = st[u]; i < ed[u]; i++) {
      del(ver[i]);
    }
  }
}

