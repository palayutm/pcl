#include <bits/stdc++.h>

std::vector<std::vector<std::pair<int, int>>> preFactorize(int n) {
  std::vector<std::vector<std::pair<int, int>>> ret(n + 1);
  for (int i = 2; i <= n; i++) {
    if (ret[i].empty()) {
      for (int j = i; j <= n; j += i) {
        int cnt = 0, t = j;
        while (t % i == 0) t /= i, cnt++;
        ret[j].emplace_back(i, cnt);
      }
    }
  }
  return ret;
}

std::vector<std::pair<int, int>> factorize(long long n) {
  std::vector<std::pair<int, int>> ret;
  for (long long i = 2; i * i <= n; i++) {
    int cnt = 0;
    while (n % i == 0) n /= i, cnt++;
    if (cnt) ret.emplace_back(i, cnt);
  }
  if (n > 1) ret.emplace_back(n, 1);
  return ret;
}
