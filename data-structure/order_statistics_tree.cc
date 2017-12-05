#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;

template <class T>
using Tree = tree<T, null_type, std::less<T>, rb_tree_tag,
                  tree_order_statistics_node_update>;

int main(int argc, char *argv[]) {
  Tree<int> tree;
  for (int i = 0; i < 10; i += 2) {
    tree.insert(10 - i);
  }
  for (auto x : tree) {
    cout << x << " ";
  }
  cout << endl;
  cout << "order_of_key" << endl;
  for (int i = 0; i < 10; i++) {
    cout << i << " : " << tree.order_of_key(i) << endl;
  }
  cout << "find_by_order" << endl;
  for (int i = 0; i < tree.size(); ++i) {
    cout << i << " : " << *tree.find_by_order(i) << endl;
  }
  return 0;
}
