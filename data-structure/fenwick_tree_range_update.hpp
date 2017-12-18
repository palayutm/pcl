#include "fenwick_tree.hpp"

template <class T> struct FenwickTreeRangeUpdate {
  FenwickTree<T> add, mul;
  FenwickTreeRangeUpdate(int N) : add(N), mul(N) {}
  void update(int left, int right, T by) {
    mul.update(left, by), mul.update(right, -by);
    add.update(left, -by * (left - 1)), add.update(right, by * right);
  }
  T query(int at) {
    return mul.query(at) * at + add.query(at);
  }
};
