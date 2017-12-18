#include <bits/stdc++.h>

using namespace std;

namespace fft {
typedef complex<double> Complex;
const double PI = acos(-1);

int revv(int x, int bits) {
  int ret = 0;
  for (int i = 0; i < bits; i++) {
    ret <<= 1, ret |= x & 1, x >>= 1;
  }
  return ret;
}

void fft(vector<Complex> &a, bool rev = false) {
  int n = a.size(), bits = 32 - __builtin_clz(n) - 1;
  for (int i = 0; i < n; i++) {
    int j = revv(i, bits);
    if (i < j) swap(a[i], a[j]);
  }
  for (int k = 1; k < n; k <<= 1) {
    Complex wn = {cos(PI / k), rev ? -sin(PI / k) : sin(PI / k)};
    for (int i = 0; i < n; i += 2 * k) {
      Complex w = {1, 0};
      for (int j = 0; j < k; j++, w *= wn) {
        Complex x = a[i + j], y = w * a[i + j + k];
        a[i + j] = x + y, a[i + j + k] = x - y;
      }
    }
  }
  if (rev) {
    for (int i = 0; i < n; i++) a[i] /= n;
  }
}

vector<long long> convolution(const vector<int> &a, const vector<int> &b) {
  int sz = (int)a.size() + (int)b.size() - 1;
  int L = sz > 1 ? 32 - __builtin_clz(sz - 1) : 0, n = 1 << L;
  vector<Complex> av(n), bv(n);
  copy(a.begin(), a.end(), av.begin());
  copy(b.begin(), b.end(), bv.begin());
  fft(av), fft(bv);
  for (int i = 0; i < n; i++) {
    av[i] *= bv[i];
  }
  fft(av, true);
  vector<long long> c(sz);
  for (int i = 0; i < sz; i++) {
    c[i] = av[i].real() + 0.5;
  }
  return c;
}
} // namespace fft
