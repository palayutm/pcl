#include <bits/stdc++.h>

const int mod = 1e9 + 7;

int inverse(int x) {
  return x == 1 ? x : (long long)(mod - mod / x) * inverse(mod % x) % mod;
}

void FWT(std::vector<int> &a) {
  int n = a.size();
  for (int d = 1; d < n; d <<= 1) {
    for (int m = d << 1, i = 0; i < n; i += m) {
      for (int j = 0; j < d; j++) {
        int x = a[i + j], y = a[i + j + d];
        a[i + j] = (x + y) % mod, a[i + j + d] = (x - y + mod) % mod;
        // xor : a[i + j] = x + y, a[i + j + d] = x - y;
        // and : a[i + j] = x + y;
        // or  : a[i + j + d] = x + y;
      }
    }
  }
}

void IFWT(std::vector<int> &a) {
  int n = a.size();
  int inv2 = inverse(2);
  for (int d = 1; d < n; d <<= 1) {
    for (int m = d << 1, i = 0; i < n; i += m) {
      for (int j = 0; j < d; j++) {
        int x = a[i + j], y = a[i + j + d];
        a[i + j] = 1LL * (x + y) * inv2 % mod;
        a[i + j + d] = (1LL * (x - y) * inv2 % mod + mod) % mod;
        // xor : a[i + j] = (x + y) / 2, a[i + j + d] = (x - y) / 2;
        // and : a[i + j] = x - y;
        // or  : a[i + j + d] = y - x;
      }
    }
  }
}
