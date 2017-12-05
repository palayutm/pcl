#include <bits/stdc++.h>

using namespace std;

namespace prime_mod {
int inverse(int a, int md) {
  return a == 1 ? a : (long long)(md - md / a) * inverse(md % a, md) % md;
}
vector<int> preInverse(int n, int md) {
  vector<int> inv(n + 1);
  inv[1] = 1;
  for (int i = 2; i <= n; ++i) {
    inv[i] = (long long)(md - md / i) * inv[md % i] % md;
  }
  return inv;
}  
}

namespace non_prime_mod {
int inverse(int a, int md) {
  a %= md;
  if (a < 0) a += md;
  int b = md, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += md;
  return u;
}
}

int main(int argc, char *argv[]) {
  
  return 0;
}
