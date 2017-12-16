#include <bits/stdc++.h>

struct SuffixArray {
  std::vector<int> sa, rank, height;
  SuffixArray(std::vector<int> r, int m = 255) : sa(r.size() + 2), rank(r.size()), height(r.size() + 1) {
    r.push_back(0);
    int n = r.size();
    std::vector<int> wv(n + m), ws(n + m), wa(n + m), wb(n + m);
    int i, j, k = 0, p;
    std::vector<int>::iterator x = wa.begin(), y = wb.begin(), t;
    for (i = 0; i < m; i++) ws[i] = 0;
    for (i = 0; i < n; i++) ws[x[i] = r[i]]++;
    for (i = 1; i < m; i++) ws[i] += ws[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--ws[x[i]]] = i;
    for (j = 1, p = 1; p < n; j *= 2, m = p) {
      for (p = 0, i = n - j; i < n; i++) y[p++] = i;
      for (i = 0; i < n; i++) if (sa[i] >= j) y[p++] = sa[i] - j;
      for (i = 0; i < n; i++) wv[i] = x[y[i]];
      for (i = 0; i < m; i++) ws[i] = 0;
      for (i = 0; i < n; i++) ws[wv[i]]++;
      for (i = 1; i < m; i++) ws[i] += ws[i - 1];
      for (i = n - 1; i >= 0; i--) sa[--ws[wv[i]]] = y[i];
      for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++) {
        x[sa[i]] = (y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + j] == y[sa[i] + j]) ? p - 1 : p++;
      }
    }
    --n;
    for (i = 1; i <= n; i++) rank[sa[i]] = i;
    for (i = 0; i < n; height[rank[i++]] = k) {
      for (k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++);
    }
  }
};
