#include <bits/stdc++.h>

using namespace std;

vector<int> toposort(vector<vector<int>> g, int base = 1) {
  int n = g.size();
  vector<int> in(n);
  for (int i = base; i < n; ++i) {
    for (auto x: g[i]) {
      in[x]++;
    }
  }
  queue<int> q;
  for (int i = base; i < n; ++i) {
    if (in[i] == 0) {
      q.push(i);
    }
  }
  vector<int> ret;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    ret.push_back(u);
    for (auto v: g[u]) {
      if (--in[v] == 0) {
        q.push(v);
      }
    }
  }
  return ret.size() == n - base ? ret : vector<int>();
}

int main(int argc, char *argv[]) {
  vector<vector<int>> a{{}, {2, 3}, {}, {2}};
  for (auto x : toposort(a)) {
    cout << x << " ";
  }
  return 0;
}
