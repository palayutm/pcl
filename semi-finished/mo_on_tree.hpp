#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100005;

vector<int> g[N], sp, sd;
int dep[N], dfn[N], lg[2 * N], ST[N], EN[N];
pair<int, int> dp[21][2 * N];

void dfs(int u, int fa) {
  dep[u] = dep[fa] + 1;
  dfn[u] = sp.size();
  ST[u] = sd.size();
  sd.push_back(u);
  sp.push_back(u);
  for (auto v : g[u]) {
    if (v != fa) {
      dfs(v, u);
      sp.push_back(u);
    }
  }
  EN[u] = sd.size();
  sd.push_back(u);
}

void lca_init() {
  int n = sp.size();
  for (int i = 1, j = 0; i <= n; i++) {
    if (i == (1 << (j + 1))) j++;
    lg[i] = j;
  }
  for (int i = 0; i < n; i++) {
    dp[0][i] = {dfn[sp[i]], sp[i]};
  }
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 0; i + (1 << j) - 1 < n; i++) {
      dp[j][i] = min(dp[j - 1][i], dp[j - 1][i + (1 << (j - 1))]);
    }
  }
}

int LCA(int u, int v) {
  int l = dfn[u], r = dfn[v];
  if (l > r) swap(l, r);
  int j = lg[r - l + 1];
  return min(dp[j][l], dp[j][r - (1 << j) + 1]).second;
}

int a[N], b[N], BK = 320;
int sum[2][N];
ll S = 0;
bool vis[N];

struct A{
  int l, r, id, lca;
};

void insert(int u) {
  S += sum[a[u] ^ 1][b[u]];
  sum[a[u]][b[u]]++;
}

void erase(int u) {
  S -= sum[a[u] ^ 1][b[u]];
  sum[a[u]][b[u]]--;
}

void toggle(int p) {
  int u = sd[p];
  vis[u] ? erase(u) : insert(u);
  vis[u] ^= 1;
}

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    if (!mp.count(b[i])) {
      int sz = mp.size();
      mp[b[i]] = sz;
    }
    b[i] = mp[b[i]];
  }
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  lca_init();
  vector<A> Q;
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    if (ST[u] > ST[v]) swap(u, v);
    int lca = LCA(u, v);
    if (lca != u) {
      Q.push_back({EN[u], ST[v], i, lca});
    } else {
      Q.push_back({ST[u], ST[v], i, -1});
    }
  }
  sort(Q.begin(), Q.end(), [](const A& x, const A& y) {
      return x.l / BK < y.l / BK || (x.l / BK == y.l / BK && x.r < y.r);
    });
  vector<ll> ans(m);
  int L = 0, R = 0;
  for (auto q : Q) {
    while (R <= q.r) toggle(R++);
    while (R > q.r + 1) toggle(--R);
    while (L < q.l) toggle(L++);
    while (L > q.l) toggle(--L);
    if (q.lca != -1) toggle(ST[q.lca]);
    ans[q.id] = S;
    if (q.lca != -1) toggle(ST[q.lca]);
  }
  for (auto x : ans) {
    printf("%lld\n", x);
  }
  return 0;
}
