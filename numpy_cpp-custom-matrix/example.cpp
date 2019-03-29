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

//TODO: remove argument c. Build c with the desired shape inside this function.
Matrix<double> Multiply(const Matrix<double> &a, const Matrix<double> &b, 
    const Matrix<double> &c, const int m, const int l, const int n) {
 // std::vector<size_t> c(6);
 // for ( int i = 0 ; i < 6 ; ++i )
 //     c[i] = 1; 
 // Matrix<double> ret(c);
  Matrix<double> ret(c.shape()); 
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      ret[j + i * n] = 0;
      for (int k = 0; k < l; k++) {
        ret[j + i * n] += a[k + i * l] * b[j + k * n];
      }
    }
  }
  // for (int i=0; i<m*n; i++)
   // std::cout << "ret[" << i << "]" << ret[i] << "\n";
  return ret;
}

Matrix<double> Transpose(const Matrix<double> &a, const Matrix<double> &b,
    const int m, const int n) {
  Matrix<double> ret(b.shape());
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
        ret[i + j * m] = a[i * n + j];
    }
  }
  return ret;
}

double Exp(const double a) {
  double ret = 1;
  int terms = 1000;
  for (int i = terms - 1; i > 0; --i )
    ret = 1 + a * ret / i;
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
