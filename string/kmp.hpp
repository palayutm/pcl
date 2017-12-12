#include <bits/stdc++.h>

/*    
 *    S:    a  b  c  a  b  a  b  c
 * fail: -1 0  0  0  1  2  1  2  3
 */

std::vector<int> getFail(string s) {
  std::vector<int> fail(s.size() + 1);
  fail[0] = -1;
  int p = -1;
  for (int i = 0; i < s.size(); i++) {
    while (p != -1 && s[i] != s[p]) p = fail[p];
    fail[i + 1] = ++p;
  }
  return fail;
}
