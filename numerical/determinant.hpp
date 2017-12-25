#include <bits/stdc++.h>

using namespace std;

int det(vector<vector<int>> a, int mod) {
  long long ret = 1;
  int n = a.size();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      while (a[j][i] != 0) {
        long long t = a[i][i] / a[j][i];
        for (int k = i; k <= n; k++) {
          a[i][k] = (a[i][k] - a[j][k] * t % mod + mod) % mod;
        }
        swap(a[i], a[j]);
        ret *= -1;
      }
    }
    ret = ret * a[i][i] % mod;
  }
  return (ret + mod) % mod;
}

double det(vector<vector<double>> &a) {
  double ret = 1;
  int n = a.size();
  for (int i = 0; i < n; i++) {
    int p = i;
    for (int j = i + 1; j < n; j++) {
      if (fabs(a[j][i]) > fabs(a[p][i])) {
        p = j;
      }
    }
    if (p != i) {
      swap(a[i], a[p]), ret *= -1;
    }
    ret *= a[i][i];
    for (int j = i + 1; j < n; j++) {
      double v = a[j][i] / a[i][i];
      for (int k = i + 1; k < n; k++) {
        a[j][k] -= v * a[i][k];
      }
    }
  }
  return ret;
}
