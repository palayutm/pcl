#include <bits/stdc++.h>

long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  long long g = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return g;
}
