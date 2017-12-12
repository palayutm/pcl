#include <bits/stdc++.h>

struct PersistentIntervalTree {
  std::vector<int> a, ls, rs;
  int tail;
  int N;

  PersistentIntervalTree(int n) {
    ls = rs = a = std::vector<int>(n * 20);
    tail = 1;
    N = n;
  }

  void build(int& root) {
    build(1, N, root);
  }
  
  void build(int l, int r, int& root) {
    root = tail++;
    if (l == r) return;
    int m = (l + r) / 2;
    build(l, m, ls[root]);
    build(m + 1, r, rs[root]);
  }

  void update(int pre, int& now, int P, int val) {
    update(1, N, pre, now, P, val);
  }
  
  void update(int l, int r, int pre, int& now, int P, int val) {
    now = tail++;
    a[now] = a[pre] + val;
    ls[now] = ls[pre], rs[now] = rs[pre];
    if (l == r) return;
    int m = (l + r) / 2;
    if (P <= m) update(l, m, ls[pre], ls[now], P, val);
    else update(m + 1, r, rs[pre], rs[now], P, val);
  }

  int query(int now, int L, int R) {
    return query(1, N, now, L, R);
  }
  
  int query(int l, int r, int now, int L, int R) {
    if (l >= L && r <= R) return a[now];
    int m = (l + r) / 2, sum = 0;
    if (m >= L) sum += query(l, m, ls[now], L, R);
    if (m + 1 <= R) sum += query(m + 1, r, rs[now], L, R);
    return sum;
  }
};
/*
using namespace std;

int main(int argc, char *argv[]) {
  PersistentIntervalTree pit(10);
  std::vector<int> a(5, 0);
  pit.build(a[0]);
  pit.update(a[0], a[1], 2, 2);
  pit.update(a[1], a[2], 3, 3);
  cout << pit.query(a[1], 1, 10) << endl;
  cout << pit.query(a[2], 1, 10) << endl;
  return 0;
}
*/
