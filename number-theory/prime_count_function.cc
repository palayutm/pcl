#include <bits/stdc++.h>

using namespace std;

pair<vector<long long>, vector<long long>> sieve(long long n) {
  long long v = sqrt(n);
  vector<long long> f(v + 1), g(v + 1);
  for (int i = 1; i <= v; i++) {
    f[i] = i - 1;
    g[i] = n / i - 1;
  }
  for (long long p = 2; p <= v; p++) {
    if (f[p] == f[p - 1]) continue;
    for (long long i = 1; i <= v && n / i >= p * p; i++) {
      long long d = n / i / p;
      if (d <= v) {
        g[i] -= (f[d] - f[p - 1]);
      } else {
        d = n / d;
        g[i] -= (g[d] - f[p - 1]);
      }
    }
    for (long long i = v; i >= p * p; i--) {
      f[i] -= (f[i / p] - f[p - 1]);
    }
  }
  return {f, g};
}

int main(int argc, char *argv[]) {
  long long n = 1e12;
  auto ret = sieve(n);
  for (int i = 1; i <= 10; i++) {
    cout << i << " : " << ret.first[i] << endl;
  }
  for (int i = 10; i >= 1; i--) {
    cout << n / i << " : " << ret.second[i] << endl;    
  }
  return 0;
}
