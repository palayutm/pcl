#include <bits/stdc++.h>

namespace fft {
using namespace std;
const double PI = acos(-1);
typedef valarray<complex<double>> carray;
void fft(valarray<complex<double>> &x, valarray<complex<double>> &roots) {
  int N = x.size();
  if (N <= 1) return;
  carray even = x[slice(0, N / 2, 2)];
  carray odd = x[slice(1, N / 2, 2)];
  carray rs = roots[slice(0, N / 2, 2)];
  fft(even, rs);
  fft(odd, rs);
  for (int k = 0; k < N / 2; k++) {
    auto t = roots[k] * odd[k];
    x[k] = even[k] + t;
    x[k + N / 2] = even[k] - t;
  }
}

vector<double> convolution(const vector<double> &a, const vector<double> &b) {
  int s = (int)a.size() + (int)b.size() - 1, L = 32 - __builtin_clz(s), n = 1 << L;
  if (s <= 0) return {};
  carray av(n), bv(n), roots(n);
  for (int i = 0; i < n; i++) {
    roots[i] = polar(1.0, -2 * PI * i / n);
  }
  copy(a.begin(), a.end(), begin(av)); fft(av, roots);
  copy(b.begin(), b.end(), begin(bv)); fft(bv, roots);
  roots = roots.apply(conj);
  carray cv = av * bv;
  fft(cv, roots);
  vector<double> c(s);
  for (int i = 0; i < s; i++) {
    c[i] = cv[i].real() / n;
  }
  return c;
}
}
