#include <bits/stdc++.h>

namespace inverse {
namespace prime_mod {
int inverse(int a, int md) {
  return a == 1 ? a : (long long)(md - md / a) * inverse(md % a, md) % md;
}
std::vector<int> preInverse(int n, int md) {
  std::vector<int> inv(n + 1);
  inv[1] = 1;
  for (int i = 2; i <= n; ++i) {
    inv[i] = (long long)(md - md / i) * inv[md % i] % md;
  }
  return inv;
}
} // namespace prime_mod

namespace non_prime_mod {
int inverse(int a, int md) {
  a %= md;
  if (a < 0) a += md;
  int b = md, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; std::swap(a, b);
    u -= t * v; std::swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += md;
  return u;
}
} // namespace non_prime_mod
} // namespace inverse
