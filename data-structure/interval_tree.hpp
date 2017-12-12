#include <bits/stdc++.h>

template <class T> struct IntervalTree {
  std::vector<T> a, b;
  int n;
  IntervalTree(int size) {
    a = std::vector<T>(size * 4);
    b = std::vector<T>(size * 4);
    n = size;
  }
  void pushDown(int l, int r, int p) {
    if (b[p]) {
      int m = (l + r) / 2;
      a[p * 2] += b[p] * (m - l + 1);
      a[p * 2 + 1] += b[p] * (r - m);
      b[p * 2] += b[p];
      b[p * 2 + 1] += b[p];
      b[p] = 0;
    }
  }
  void pushUp(int l, int r, int p) { a[p] = a[p * 2] +  a[p * 2 + 1]; }
  void update(int L, int R, T val) { update(1, n, 1, L, R, val); }
  void update(int l, int r, int p, int L, int R, T val) {
    if (l >= L && r <= R) {
      a[p] += val * (r - l + 1);
      b[p] += val;
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
    T ret = 0;
    if (m >= L) ret += query(l, m, p * 2, L, R);
    if (m + 1 <= R) ret += query(m + 1, r, p * 2 + 1, L, R);
    return ret;
  }
};
