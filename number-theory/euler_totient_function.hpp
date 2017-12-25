#include <bits/stdc++.h>

long long totient(long long n){
  long long rea = n;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0){
      rea -= rea/i;
      while (n % i == 0)  n /= i;
    }
  }
  if (n > 1)  rea -= rea/n;
  return rea;
}

std::vector<int> preTotient(int n){
  std::vector<int> phi(n + 1);
  for (int i = 1; i <= n; i++)  phi[i] = i;
  for (int i = 2; i <= n; i += 2)  phi[i] /= 2;
  for (int i = 3; i <= n; i += 2) {
    if (phi[i] == i) {
      for (int j = i; j <= n; j += i){
        phi[j] = phi[j]/i*(i-1);
      }
    }
  }
  return phi;
}
