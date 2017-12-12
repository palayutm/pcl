#include <bits/stdc++.h>

std::vector<int> preInverse(int n, int md) {
  std::vector<int> inv(n + 1);
  inv[1] = 1;
  for (int i = 2; i <= n; ++i) {
    inv[i] = (long long)(md - md / i) * inv[md % i] % md;
  }
  return inv;
}

struct Binomial {
  int n, md;
  std::vector<int> factorial, inv_factorial;
  Binomial(int n, int mod) : n(n), md(mod) {
    factorial.resize(n + 1);
    inv_factorial = preInverse(n, md);
    factorial[0] = inv_factorial[0] = 1;
    for (int i = 1; i <= n; i++) {
      factorial[i] = (long long)factorial[i - 1] * i % md;
      inv_factorial[i] = (long long)inv_factorial[i - 1] * inv_factorial[i] % md;
    }
  }
  int choose(int n, int k) {
    if (k > n) return 0;
    return (long long)factorial[n] * inv_factorial[k] % md * inv_factorial[n - k] % md;
  }
};

struct Lucas {
  Binomial bn;
  int md;
  Lucas(int mod) : bn(mod, mod), md(mod) {}
  int choose(int n, int k) {
    return n && k ? (long long)bn.choose(n % md, k % md) * choose(n / md, k / md) % md : 1;
  }
};
/*
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
1 5 10 10 5 1 
1 6 15 20 15 6 1 
1 7 21 35 35 21 7 1 
1 8 28 56 70 56 28 8 1 
1 9 36 84 126 126 84 36 9 1 
1 10 45 120 210 252 210 120 45 10 1 
*/
