// tested on http://codeforces.com/contest/898/problem/F 
#include <bits/stdc++.h>

template <int T> struct StringHash {
  std::vector<std::vector<int>> ha, pw;
  std::vector<int> M;
  
  StringHash(const std::vector<int>& vec, long long CC = -1, long long MM = -1) {
    pw = ha = std::vector<std::vector<int>>(T, std::vector<int>(vec.size() + 1));
    std::vector<int> C(T, CC);
    M.assign(T, MM);
    for (int i = 0; i < T; i++) {
      pw[i][0] = 1;
      if (C[i] == -1) C[i] = randomInt();
      if (M[i] == -1) M[i] = randomInt();
    }
    for (int z = 0; z < T; z++) {
      for (int i = 0; i < vec.size(); ++i) {
        ha[z][i + 1] = ((long long)ha[z][i] * C[z] + vec[i]) % M[z], pw[z][i + 1] = (long long)pw[z][i] * C[z] % M[z];  
      }
    }
  }
  
  std::vector<int> hashInterval(int a, int b) {
    std::vector<int> ret(T);
    for (int z = 0; z < T; z++) {
      ret[z] = (ha[z][b] - (long long)ha[z][a] * pw[z][b - a] % M[z] + M[z]) % M[z];
    }
    return ret;
  }

  static int randomInt() {
    static std::mt19937 gen((std::random_device())());
    static std::uniform_int_distribution<int> uid(1e8, 1e9);
    return uid(gen);
  }
};
