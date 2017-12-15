#include <bits/stdc++.h>

template <class T> struct FenwickTree {
  std::vector<T> in;
  int N;
  FenwickTree(int N) : N(N), in(N) {}
  int lowbit(int n) {return n & (-n);}
  void update(int p, T val) {
    for (int i = p; i < N; i += lowbit(i)) {
      in[i] += val;
    }
  }
  T query(int p) {
    T sum = 0;
    for (int i = p; i; i -= lowbit(i)) {
      sum += in[i];
    }
    return sum;
  }
};
