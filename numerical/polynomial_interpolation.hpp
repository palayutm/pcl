#include <bits/stdc++.h>

struct Polynomial {
  std::vector<double> a;
  Polynomial(int n) : a(n + 1) {}
  Polynomial(std::vector<double> g) : a(g) {}
  Polynomial(std::vector<std::pair<double, double>> point) {
    int n = point.size();
    a.assign(n, 0);
    std::vector<double> temp(n);
    for (int k = 0; k < n - 1; ++k) {
      for (int i = k + 1; i < n; ++i) {
        point[i].second = (point[i].second - point[k].second) / (point[i].first - point[k].first);  
      }
    }
    double last = 0; temp[0] = 1;
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        a[i] += point[k].second * temp[i];
        std::swap(last, temp[i]);
        temp[i] -= last * point[k].first;
      }
    }
  }
  double operator()(double x) const {
    double val = 0;
    for(int i = (int)a.size() - 1; i >= 0; --i) (val *= x) += a[i];
    return val;
  }
};
