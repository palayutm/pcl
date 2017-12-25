#include "../numerical/determinant.hpp"

int matrixTree(vector<vector<int>>& graph, int mod) {
  int n = graph.size();
  vector<vector<int>> a(n - 1, vector<int>(n - 1, 0));
  for (int u = 0; u < n - 1; u++) {
    for (auto v : graph[u]) {
      a[u][u]++;
      if (v + 1 != n) a[u][v]--;
    }
  }
  return det(a, mod);
}
