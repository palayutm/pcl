#include <bits/stdc++.h>
#include "pow_mod.hpp"

namespace miller_rabin {
bool isPrime(long long n) {
  if (n <= 1) return false;
  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}
const int S = 6;
bool millerRabin(long long n) {
  if (n < 100) return isPrime(n);
  if (!(n & 1)) return false;
  int t = 0;
  long long u = n - 1;
  for (; !(u & 1); t++, u >>= 1);
  for (int i = 0; i < S; i++) {
    long long a = rand() % (n - 1) + 1;
    long long x = powMod(a, u, n);
    for (int j = 0; j < t; j++) {
      long long y = powMod(x, 2LL, n);
      if (y == 1 && x != 1 && x != n - 1) { return false;}
      x = y;
    }
    if (x != 1) return false;
  }
  return true;
}
} // namespace miller_rabin
