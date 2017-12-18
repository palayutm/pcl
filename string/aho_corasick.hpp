#include <bits/stdc++.h>

struct AhoCorasick {
  std::vector<std::vector<int>> ch;
  std::vector<int> fail, state;

  AhoCorasick() : ch(1, std::vector<int>(26)), fail(1), state(1) {}

  void insert(std::string s, int id = 1) {
    int now = 0;
    for (auto c : s) {
      c -= 'a';
      if (!ch[now][c]) {
        ch[now][c] = ch.size();
        ch.push_back(std::vector<int>(26));
        fail.push_back(0), state.push_back(0);
      }
      now = ch[now][c];
    }
    state[now] = id;
  }

  void run() {
    std::queue<int> q;
    for (int i = 0; i < 26; i++) {
      if (ch[0][i]) {
        fail[ch[0][i]] = 0;
        q.push(ch[0][i]);
      }
    }
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int i = 0; i < 26; ++i) {
        int v = ch[u][i];
        if (v) {
          q.push(v);
          int f = fail[u];
          while (f && !ch[f][i]) f = fail[f];
          fail[v] = ch[f][i];
        }
      }
    }
  }
};
