#include <bits/stdc++.h>

using namespace std;

/*
 *  s[]: $ # a # b # a # a # b # a #
 * Mp[]: 0 1 2 1 4 1 2 7 2 1 4 1 2 1
 */

vector<int> manacher(string s) {
  vector<int> Mp(s.size());
  int len = s.size();
  int mx = 0, idx = 0;
  for (int i = 1; i < len; i++) {
    Mp[i] = (mx > i ? min(Mp[2 * idx - i], mx - i) : 1);
    while (s[i + Mp[i]] == s[i - Mp[i]]) Mp[i]++;
    if (i + Mp[i] > mx) {
      mx = i + Mp[i];
      idx = i;
    }
  }
  return Mp;
}

int main(int argc, char *argv[]) {
  for (auto x : manacher("$#a#b#a#a#b#a#")) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
