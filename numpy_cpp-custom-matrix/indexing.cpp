#include "matrix.h"
#include "pybind_matrix.h"

using namespace std;

// C++ code for tensor indexing and slicing operations

// Returns a new tensor that slices the input tensor along the selected
// dimension at the given index
Matrix<double> Select(const Matrix<double> &a, const int dim, const int index)
{
  Matrix<double> ret(a.shape());
  return ret;
}

// Returns a new tensor that indexes the input tensor along dimension dim
// using the entries in index
Matrix<double> IndexSelect(const Matrix<double> &a, const int dim, const vector<int> index)
{
  Matrix<double> ret(a.shape());
  return ret;
}

// Removes a tensor dimension. Returns a tuple of all slices along a given dimension
Matrix<double> Unbind(const Matrix<double> &a, const int dim)
{
  Matrix<double> ret(a.shape());
  return ret;
}

// Returns a new tensor that is a narrowed version of input tensor.
// The dimension dim is input from start to start + len. 
Matrix<double> Narrow(const Matrix<double> &a, const int dim, const int start,
    const int len)
{
  Matrix<double> ret(a.shape());
  return ret;
}

// Returns a tensor with the same data as input, but with the specified shape.
// TODO: currently only supports 2D tensors. extend to nD tensors.
Matrix<double> Reshape(const Matrix<double> &a, const vector<double> new_shape)
{ 
  size_t a_rows =  a.shape()[0];
  size_t a_cols =  a.shape()[1];
  std::vector<size_t> mat_dimension = {new_shape[0], new_shape[1]};
  if (a_rows*a_cols != new_shape[0]*new_shape[1])
    return a;

  Matrix<double> ret(mat_dimension);
  int i=0, j=0;
  for (int row = 0; row < a_rows; ++row) {
    for (int col = 0; col < a_cols; ++col) {
      ret[i * a_cols + j] = a[i * a_cols + j];
      j++;
      if (j >= a.shape()[1]) {
        i++;
        j = 0;
      }
    }
  }
 
  return ret;
}

// Python interface

namespace py = pybind11;

PYBIND11_MODULE(indexing,m)
{
  m.doc() = "pybind11 plugin";
  m.def("Select", &Select);
  m.def("IndexSelect", &IndexSelect);
  m.def("Unbind", &Unbind);
  m.def("Narrow", &Narrow);
  m.def("Reshape", &Reshape);
}
