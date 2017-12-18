int powMod(int x, int y, int z) {
  long long ret = 1;
  for (; y; y >>= 1, x = (long long)x * x % z) {
    if (y & 1) ret = ret * x % z;
  }
  return ret;
}
