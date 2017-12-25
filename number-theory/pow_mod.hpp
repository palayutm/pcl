int powMod(int x, int y, int z) {
  long long ret = 1;
  for (; y; y >>= 1, x = (long long)x * x % z) {
    if (y & 1) ret = ret * x % z;
  }
  return ret;
}

long long multiplyMod(long long y, long long m, long long z) {
  long long ret = 0;
  y %= z;
  for (; m; m >>= 1, y = y * 2 % z) {
    if (m & 1) ret = (ret + y) % z;
  }
  return ret;
}

long long powMod(long long x, long long y, long long z) {
  long long ret = 1;
  for (; y; y >>= 1, x = multiplyMod(x, x, z)) {
    if (y & 1) ret = multiplyMod(ret, x, z);
  }
  return ret;
}
