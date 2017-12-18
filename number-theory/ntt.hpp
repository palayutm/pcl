#include <bits/stdc++.h>
#include "pow_mod.hpp"

using namespace std;

namespace ntt {
const int mod = (119 << 23) + 1, root = 3; // = 998244353
// For p < 2^30 there is also e.g. (5 << 25, 3), (7 << 26, 3),
// (479 << 21, 3) and (483 << 21, 5). The last two are > 10^9.

int revv(int x, int bits) {
  int ret = 0;
  for (int i = 0; i < bits; i++) {
    ret <<= 1, ret |= x & 1, x >>= 1;
  }
  return ret;
}

void fft(vector<int> &a, bool rev = false) {
  int n = a.size(), bits = 32 - __builtin_clz(n) - 1;
  for (int i = 0; i < n; i++) {
    int j = revv(i, bits);
    if (i < j) swap(a[i], a[j]);
  }
  for (int k = 1; k < n; k <<= 1) {
    int e = powMod(root, (mod - 1) / 2 / k, mod);
    if (rev) e = powMod(e, mod - 2, mod);
    for (int i = 0; i < n; i += 2 * k) {
      long long w = 1;
      for (int j = 0; j < k; j++, w = w * e % mod) {
        int x = a[i + j], y = w * a[i + j + k] % mod;
        a[i + j] = (x + y) % mod, a[i + j + k] = (x - y + mod) % mod;
      }
    }
  }
  if (rev) {
    int inv = powMod(n, mod - 2, mod);
    for (int i = 0; i < n; i++) a[i] = (long long)a[i] * inv % mod;
  }
}

vector<int> convolution(const vector<int> &a, const vector<int> &b) {
  int sz = (int)a.size() + (int)b.size() - 1;
  int L = sz > 1 ? 32 - __builtin_clz(sz - 1) : 0, n = 1 << L;
  vector<int> av(n), bv(n);
  copy(a.begin(), a.end(), av.begin());
  copy(b.begin(), b.end(), bv.begin());
  fft(av), fft(bv);
  for (int i = 0; i < n; i++) {
    av[i] = (long long)av[i] * bv[i] % mod;
  }
  fft(av, true);
  return av;
}
} // namespace ntt
