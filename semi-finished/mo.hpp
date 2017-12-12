#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

namespace Mo {
  struct Query {
    int l, r, id;
  };
  vector<int> a;
  vector<ll> ans;
  vector<Query> b;
  int K, BK;
  int cnt[1<<20];
  ll sum = 0;
  void read() {
    int n, m;
    scanf("%d%d%d", &n, &m, &K);
    BK = 350;
    ans.resize(m);
    a.push_back(0);
    for (int i = 0, t; i < n; i++) {
      scanf("%d", &t);
      a.push_back(t ^ a.back());
    }
    for (int i = 0, l, r; i < m; i++) {
      scanf("%d%d", &l, &r);
      b.push_back({l - 1, r, i});
    }
  }
  void add(int x) {
  }
  void del(int x) {
  }
  void solve() {
    sort(b.begin(), b.end(), [](const Query& x, const Query& y){
        return x.l / BK < y.l / BK || (x.l / BK == y.l / BK && x.r < y.r);
      });
    for (int i = 0, L = 0, R = 0; i < (int)b.size(); i++) {
      while (R <= b[i].r) add(a[R++]);
      while (R - 1 > b[i].r) del(a[--R]);
      while (L < b[i].l) del(a[L++]);
      while (L > b[i].l) add(a[--L]);
      ans[b[i].id] = sum;
    }
  }
};
