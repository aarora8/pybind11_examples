#include "matrix.h"
#include "pybind_matrix.h"

// C++ code for matrix operations: Add, Subtract, ScalarMultiply, Multiply

Matrix<double> Add(const Matrix<double> &a, const Matrix<double> &b)
{
  if (a.shape() != b.shape())
    throw std::length_error("Matrix 'a' and 'b' are inconsistent");
  Matrix<double> ret(a.shape());
  for (int i = 0; i < a.size(); i++)
    ret[i] = a[i] + b[i];
  return ret;
}

Matrix<double> Subtract(const Matrix<double> &a, const Matrix<double> &b)
{
  if (a.shape() != b.shape())
    throw std::length_error("Matrix 'a' and 'b' are inconsistent");
  Matrix<double> ret(a.shape());
  for (int i = 0; i < a.size(); i++)
    ret[i] = a[i] - b[i];
  return ret;
}

Matrix<double> ScalarMultiply(const Matrix<double> &a, const double c)
{
  Matrix<double> ret(a.shape());
  for (int i=0; i < a.size(); i++)
    ret[i] = c * a[i];
  return ret;
}

Matrix<double> Multiply(const Matrix<double> &a, const Matrix<double> &b) {
  size_t a_rows =  a.shape()[0];
  size_t a_cols = a.shape()[1];
  size_t b_rows =  b.shape()[0];
  size_t b_cols = b.shape()[1];
  std::vector<size_t> shape(2);
  shape[0] = a_rows;
  shape[1] = b_cols;
  Matrix<double> ret(shape);
  for (int i = 0; i < a_rows; i++) {
    for (int j = 0; j < b_cols; j++) {
      ret[j + i * b_cols] = 0;
      for (int k = 0; k < a_cols; k++) {
        ret[j + i * b_cols] += a[k + i * a_cols] * b[j + k * b_cols];
      }
    }
  }
  return ret;
}

Matrix<double> Transpose(const Matrix<double> &a) {
  size_t rows =  a.shape()[0];
  size_t cols = a.shape()[1];
  std::vector<size_t> shape(2);
  shape[0] = cols;
  shape[1] = rows;
  Matrix<double> ret(shape);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      ret[i + j * rows] = a[i * cols + j];
    }
  }
  return ret;
}

Matrix<double> Exp(const Matrix<double> &a) {
  Matrix<double> ret(a.shape());
  size_t rows =  a.shape()[0];
  size_t cols = a.shape()[1];
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      double element_val = a[i * cols + j];
      double exp_val = 1;
      int terms = 1000;
      for (int k = terms - 1; k > 0; --k ) {
        exp_val = 1 + element_val*exp_val/k;
      }
      ret[i * cols + j] = exp_val;
    }
  }
  return ret;
}

// Python interface

namespace py = pybind11;

PYBIND11_MODULE(example,m)
{
  m.doc() = "pybind11 plugin";
  m.def("Add", &Add);
  m.def("Subtract", &Subtract);
  m.def("ScalarMultiply", &ScalarMultiply);
  m.def("Multiply", &Multiply);
  m.def("Transpose", &Transpose);
  m.def("Exp", &Exp);
}
