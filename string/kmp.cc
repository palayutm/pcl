#include <bits/stdc++.h>

using namespace std;

/*    
 *    S:    a  b  c  a  b  a  b  c
 * fail: -1 0  0  0  1  2  1  2  3
 */

vector<int> getFail(string s) {
  vector<int> fail(s.size() + 1);
  fail[0] = -1;
  int p = -1;
  for (int i = 0; i < s.size(); i++) {
    while (p != -1 && s[i] != s[p]) p = fail[p];
    fail[i + 1] = ++p;
  }
  return fail;
}

int main(int argc, char *argv[]) {
  for (auto x : getFail("abcababc")) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
