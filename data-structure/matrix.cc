#include <bits/stdc++.h>

using namespace std;

struct Matrix {
  static constexpr int md = 1e9 + 7;
  int rowCount, columnCount;
  vector<vector<int>> a;

  Matrix(int rowCount, int columnCount) {
    this->rowCount = rowCount;
    this->columnCount = columnCount;
    a.assign(rowCount, vector<int>(columnCount));
  }
  
  static Matrix identityMatrix(int size) {
    Matrix result(size, size);
    for (int i = 0; i < size; i++) {
      result.a[i][i] = 1;
    }
    return result;
  }
  
  Matrix operator+(const Matrix &o) {
    assert(rowCount == o.rowCount);
    assert(columnCount == o.columnCount);
    Matrix result = *this;
    for (int i = 0; i < rowCount; i++) {
      for (int j = 0; j < columnCount; j++) {
        result.a[i][j] = (this->a[i][j] + o.a[i][j]) % md;
      }
    }
    return result;
  }

  Matrix operator*(const Matrix &o) {
    assert(columnCount == o.rowCount);
    Matrix result(rowCount, o.columnCount);
    for (int i = 0; i < rowCount; i++) {
      for (int j = 0; j < o.columnCount; j++) {
        for (int k = 0; k < columnCount; k++) {
          result.a[i][j] = (result.a[i][j] + (long long)this->a[i][k] * o.a[k][j]) % md;
        }
      }
    }
    return result;
  }

  Matrix operator^(long long n) {
    assert(rowCount == columnCount);
    auto result = Matrix::identityMatrix(rowCount);
    auto t = *this;
    for (; n; n >>= 1, t = t * t) {
      if (n & 1) result = result * t;
    }
    return result;
  }
};
