#include <bits/stdc++.h>

struct FenwickTree {
  std::vector<int> in;
  int N;
  FenwickTree(int N) : N(N), in(N) {}
  int lowbit(int n) {return n & (-n);}
  void update(int p, int val) {
    for (int i = p; i < N; i += lowbit(i)) {
      in[i] += val;
    }
  }
  int query(int p) {
    int sum = 0;
    for (int i = p; i; i -= lowbit(i)) {
      sum += in[i];
    }
    return sum;
  }
};
