#include <bits/stdc++.h>

using namespace std;

template<typename T>
using Row = vector<T>;

template<typename T>
using MatrixMap = vector<Row<T>>;

const long long M = 1e9 + 7;

template <typename T>
T binpow(T obj, long long pow) {
  if (pow == 1) {
    return obj;
  } else {
    if (pow % 2) {
      return binpow(obj, pow - 1) * obj;
    } else {
      T tmp = binpow(obj, pow / 2);
      return tmp * tmp;
    }
  }
}

template <typename T>
struct Matrix {
  long long row_count;
  long long column_count;
  MatrixMap<T> matrix;

  Matrix() {
    row_count = 0;
    column_count = 0;
    matrix = {};
  }

  Matrix(long long _row_count, long long _column_count) {
    row_count = _row_count;
    column_count = _column_count;
    matrix = Row<Row<long long>> (_row_count, Row<long long>(_column_count, 0));
  }

  Matrix(long long _row_count, long long _column_count, const MatrixMap<T>& _matrix) {
    row_count = _row_count;
    column_count = _column_count;
    matrix = _matrix;
  }

  T fullsum() {
    T sum = 0;
    for (int i = 0; i < row_count; ++i) {
      for (int j = 0; j < column_count; ++j) {
        sum = (sum + matrix[i][j]) % M;
      }
    }
    return sum;
  }
};

template <typename T>
Matrix<T> operator*(const Matrix<T>& first, const Matrix<T>& second) {
  if (first.column_count != second.row_count) {
    return {0, 0, {}};
  }
  
  MatrixMap<T> resulting_matrix = vector<Row<T>> (first.column_count, Row<T>(second.row_count));
  Matrix<T> result(first.row_count, second.column_count);

  for (int i = 0; i < first.row_count; ++i) {
    for (int j = 0; j < second.column_count; ++j) {
      for (int k = 0; k < first.column_count; ++k) {
        result.matrix[i][j] = (result.matrix[i][j] + (first.matrix[i][k] * second.matrix[k][j]) % M) % M;
      }
    }
  }
  return result;
}

template <typename T>
ostream& operator<<(ostream& output_stream, const Matrix<T>& matrix) {
  for (int i = 0; i < matrix.row_count; ++i) {
    for (int j = 0; j < matrix.column_count; ++j) {
      output_stream << matrix.matrix[i][j] << ' ';
    }
    output_stream << '\n';
  }
  return output_stream;
}

template <typename T>
istream& operator>>(istream& input_stream, Matrix<T>& matrix) {
  for (int i = 0; i < matrix.row_count; ++i) {
    for (int j = 0; j < matrix.column_count; ++j) {
      input_stream >> matrix.matrix[i][j];
    }
  }
  return input_stream;
}

int main() {
  int n = 0;
  cin >> n;
  if (n == 1) {
    cout << 9 << '\n';
    return 0;
  }

  Matrix<long long> matrix
  {10, 10,
    {
      {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
      {1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
      {0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
      {0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
      {0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
      {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
      {0, 0, 0, 0, 0, 1, 1, 1, 0, 0},
      {0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
      {0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
      {0, 0, 0, 0, 0, 0, 0, 0, 1, 1}
    }
  };

  Matrix<long long> base {10, 1, {{0}, {1}, {1}, {1}, {1}, {1}, {1}, {1}, {1}, {1}}};

  cout << (binpow(matrix, n - 1) * base).fullsum() << '\n';
  
  return 0;
}