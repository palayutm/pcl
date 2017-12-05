#include <bits/stdc++.h>

using namespace std;

int totient(int n){
  int rea = n;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0){
      rea -= rea/i;
      while (n % i == 0)  n /= i;
    }
  }
  if (n > 1)  rea -= rea/n;
  return rea;
}

vector<int> preTotient(int n){
  vector<int> phi(n + 1);
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

int main(int argc, char *argv[]) {
  auto vec = preTotient(100000);
  for (int i = 1; i <= 100000; ++i) {
    assert(vec[i] == totient(i));
  }
  return 0;
}
