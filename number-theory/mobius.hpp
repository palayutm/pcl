#include "prime_sieve.hpp"

std::vector<int> mobius(int n) {
  std::vector<bool> is_prime;
  std::vector<int> prime;
  tie(is_prime, prime) = primeSieve(n);
  std::vector<int> mu(n + 1, 0);
  mu[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i]) mu[i] = -1;
    for (int j = 0; j < prime.size() && i * prime[j] <= n; j++) {
      if (i % prime[j] == 0) {
        mu[i * prime[j]] = 0;
        break;
      }
      mu[i * prime[j]] = -mu[i];
    }
  }
  return mu;
}

std::vector<int> simpleMobius(int n) {
  std::vector<int> mu(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    mu[i] += i == 1;
    for (int j = i + i; j <= n; j += i) {
      mu[j] -= mu[i];
    }
  }
  return mu;
}
