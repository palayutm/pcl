#include <bits/stdc++.h>

template <class T> struct IntervalTree {
  std::vector<T> a, b;
  int n;

  IntervalTree(int size) {
    a = std::vector<T>(size * 4);
    b = std::vector<T>(size * 4);
    n = size;
  }
  // modify here
  void pushDown(int l, int r, int p) {}
  // modify here
  void pushUp(int l, int r, int p) { a[p] = min(a[p * 2], a[p * 2 + 1]); }

  void update(int L, int R, T val) { update(1, n, 1, L, R, val); }

  void update(int l, int r, int p, int L, int R, T val) {
    if (l >= L && r <= R) {
      // modify here
      a[p] += val;
      b[p] += val;
      // modify here
      return;
    }
    pushDown(l, r, p);
    int m = (l + r) / 2;
    if (m >= L) update(l, m, p * 2, L, R, val);
    if (m + 1 <= R) update(m + 1, r, p * 2 + 1, L, R, val);
    pushUp(l, r, p);
  }

  T query(int L, int R) { return query(1, n, 1, L, R); }

  T query(int l, int r, int p, int L, int R) {
    if (l >= L && r <= R) {
      return a[p];
    }
    pushDown(l, r, p);
    int m = (l + r) / 2;
    // modify here
    T ret = 1e18;
    if (m >= L) ret = min(ret, query(l, m, p * 2, L, R));
    if (m + 1 <= R) ret = min(ret, query(m + 1, r, p * 2 + 1, L, R));
    // modify here
    return ret;
  }
};
