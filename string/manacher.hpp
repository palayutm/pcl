#include <bits/stdc++.h>

/*
 *  s[]: $ # a # b # a # a # b # a #
 * Mp[]: 0 1 2 1 4 1 2 7 2 1 4 1 2 1
 */

std::vector<int> manacher(std::string s) {
  std::vector<int> Mp(s.size());
  int len = s.size();
  int mx = 0, idx = 0;
  for (int i = 1; i < len; i++) {
    Mp[i] = (mx > i ? std::min(Mp[2 * idx - i], mx - i) : 1);
    while (s[i + Mp[i]] == s[i - Mp[i]]) Mp[i]++;
    if (i + Mp[i] > mx) {
      mx = i + Mp[i];
      idx = i;
    }
  }
  return Mp;
}
