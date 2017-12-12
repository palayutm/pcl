#include <bits/stdc++.h>

namespace treap {
template <class T> struct Node {
  int sz, fix;
  T key;
  bool lazy;
  Node *ch[2];
  Node(T key) : sz(1), key(key), fix(rand()), lazy(false) {
    ch[0] = ch[1] = nullptr;
  }
  void pushup() {
    sz = 1;
    for (int i = 0; i < 2; i++) {
      if (ch[i]) {
        sz += ch[i]->sz;
      }
    }
  }
  void pushdown() {
    if (lazy) {
      lazy = false;
      std::swap(ch[0], ch[1]);
      if (ch[0] != nullptr) ch[0]->lazy ^= 1;
      if (ch[1] != nullptr) ch[1]->lazy ^= 1;
    }
  }
};
template <class T> Node<T> *merge(Node<T> *A, Node<T> *B) {
  if (B == nullptr) return A;
  if (A == nullptr) return B;
  if (A->fix < B->fix) {
    A->pushdown();
    A->ch[1] = merge(A->ch[1], B);
    A->pushup();
    return A;
  } else {
    B->pushdown();
    B->ch[0] = merge(A, B->ch[0]);
    B->pushup();
    return B;
  }
}
template <class T> std::pair<Node<T> *, Node<T> *> split(Node<T> *A, int k) {
  if (A == nullptr) return {nullptr, nullptr};
  A->pushdown();
  std::pair<Node<T> *, Node<T> *> ret;
  if ((A->ch[0] ? A->ch[0]->sz : 0) >= k) {
    ret = split(A->ch[0], k);
    A->ch[0] = ret.second;
    A->pushup();
    ret.second = A;
  } else {
    ret = split(A->ch[1], k - 1 - (A->ch[0] ? A->ch[0]->sz : 0));
    A->ch[1] = ret.first;
    A->pushup();
    ret.first = A;
  }
  return ret;
}
} // namespace Treap
