#include <bits/stdc++.h>

using namespace std;

pair<vector<bool>, vector<int>> primeSieve(int n) {
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  vector<int> prime_list;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i]) {
      prime_list.push_back(i);
    }
    for (int j = 0; j < prime_list.size() && i * prime_list[j] <= n; j++) {
      is_prime[i * prime_list[j]] = false;
      if (i % prime_list[j] == 0) break;
    }
  }
  return {is_prime, prime_list};
}
