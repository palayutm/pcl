#include <bits/stdc++.h>

using namespace std;

struct PalindromicTree {
  vector<vector<int>> ch;
  vector<int> fail, len;
  string S;
  int last;

  PalindromicTree() {
    last = 0;
    newNode(0), newNode(-1);
    S = "$";
    fail[0] = 1;
  }

  int newNode(int l) {
    int sz = ch.size();
    ch.push_back(vector<int>(26));
    len.push_back(l);
    fail.push_back(0);
    return sz;
  }

  int getFail(int x) {
    int n = S.size() - 1;
    while (S[n - len[x] - 1] != S[n]) x = fail[x];
    return x;
  }

  void add(char c) {
    S += c;
    c -= 'a';
    int cur = getFail(last);
    if (!ch[cur][c]) {
      int now = newNode(len[cur] + 2);
      fail[now] = ch[getFail(fail[cur])][c];
      ch[cur][c] = now;
    }
    last = ch[cur][c];
  }
};

int main(int argc, char *argv[]) {
  PalindromicTree pt;
  for (auto c : string("abaaba")) {
    pt.add(c);
    cout << pt.len[pt.last] << " ";
  }
  return 0;
}

/*
 *   a b a a b a
 *   1 1 3 2 4 6
 *
 */
