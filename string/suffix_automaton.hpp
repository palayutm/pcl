#include <bits/stdc++.h>

using namespace std;

struct SuffixAutomaton {
  vector<vector<int>> ch;
  vector<int> len, link;
  int head, last;
  SuffixAutomaton(string s = "") : ch(2, vector<int>(26)), len(2), link(2) {
    head = last = 1;
    for (auto x : s) {
      add(x - 'a');
    }
  }
  void add(int x) {
    int p = ch.size(), mid;
    ch.push_back(vector<int>(26));
    len.push_back(len[last] + 1);
    link.push_back(0);
    mid = last, last = p;
    for (; mid && !ch[mid][x]; ch[mid][x] = p, mid = link[mid]);
    if (!mid) link[p] = head;
    else {
      if (len[mid] + 1 == len[ch[mid][x]]) {
        link[p] = ch[mid][x];
      } else {
        int r = ch.size(), q = ch[mid][x];
        ch.push_back(ch[q]);
        len.push_back(len[mid] + 1);
        link.push_back(link[q]);
        link[q] = link[p] = r;
        for (; mid && ch[mid][x] == q; ch[mid][x] = r, mid = link[mid]);
      }
    }
  }
};
