long long powMod(long long x, long long y, long long z) {
  long long ret = 1;
  for (; y; y >>= 1, x = x * x % z) {
    if (y & 1)
      ret = ret * x % z;
  }
  return ret;
}
