#include <bits/stdc++.h>

using namespace std;

template <class T> struct SparseTable {
  std::vector<std::vector<T>> f;
  std::vector<int> lg;
  SparseTable() {}
  SparseTable(const std::vector<T> &a) { init(a); }
  void init(const std::vector<T> &a) {
    int n = a.size();
    lg.assign(n + 1, 0);
    for (int i = 1, j = 0; i <= n; i++) {
      if (i == (1 << (j + 1))) j++;
      lg[i] = j;
    }
    f.assign(lg.back() + 1, std::vector<T>(a.size()));
    f[0] = a;
    for (int j = 1; (1 << j) <= n; j++) {
      for (int i = 0; i + (1 << j) - 1 < n; i++) {
        f[j][i] = min(f[j - 1][i], f[j - 1][i + (1 << (j - 1))]);
      }
    }
  }
  T query(int l, int r) {
    int j = lg[r - l + 1];
    return min(f[j][l], f[j][r - (1 << j) + 1]);
  }
};
