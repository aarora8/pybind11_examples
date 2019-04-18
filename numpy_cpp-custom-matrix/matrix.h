#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cstdlib>
#include <vector>

template <class T>
class Matrix {
  private:
    std::vector<T> m_data_;     // data array
    std::vector<size_t> m_shape_;    // number of entries in each dimensions
    std::vector<size_t> m_strides_;  // stride length for each index

  public:
    Matrix<T>(){};
    
    Matrix<T>(const std::vector<size_t> &shape, const T *data=NULL) {
      int n = shape.size();

      // use unit-length for "extra" dimensions (> 'shape.size()')
      while ( m_shape_  .size()< n ) { m_shape_  .push_back(1); }
      while ( m_strides_.size()< n ) { m_strides_.push_back(1); }

      for (int i=0 ; i<n ; i++)
        m_shape_[i] = shape[i];

      m_strides_[n-1] = 1;
      for (int i = n-2; i >= 0; i--)
        m_strides_[i] = m_strides_[i+1]*m_shape_[i+1];
      
      int size = m_shape_[0];
      for (int i = 1; i < n; i++)
        size *= m_shape_[i];
      
      for (int i = 0 ; i < m_data_.size() ; i++)
        m_data_[i] = (T)0;

      while (m_data_.size() < size)
        m_data_.push_back((T)0);

      if (data!=NULL)
        for (int i=0; i<size; i++)
          m_data_[i] = data[i];
    };

    Matrix (const Matrix<T> &) = default;
    Matrix<T>& operator= (const Matrix<T> &) = default;
    T& operator[](size_t i) { return m_data_[i]; };
    const T& operator[](size_t i) const { return m_data_[i]; };
    
    T& operator()(size_t h, size_t i=0, size_t j=0){
      return m_data_[h*m_strides_[0]+i*m_strides_[1]+j*m_strides_[2]];
    };

    const T& operator()(size_t h, size_t i=0, size_t j=0) const {
      return m_data_[h*m_strides_[0]+i*m_strides_[1]+j*m_strides_[2]];
    };

    const T* data(void) const { return m_data_.data(); };

    std::vector<size_t> shape(size_t ndim=0) const {
      if (ndim == 0)
        ndim = this->ndim();

      std::vector<size_t> ret(ndim);
      for (size_t i = 0 ; i < ndim ; ++i)
        ret[i] = m_shape_[i];

      return ret;
    };

    std::vector<size_t> strides(bool bytes=false) const {
      size_t ndim = this->ndim();
      std::vector<size_t> ret(ndim);
      for (size_t i = 0; i < ndim; ++i)
        ret[i] = m_strides_[i];

      if (bytes)
        for (size_t i = 0; i < ndim; ++i)
          ret[i] *= sizeof(T);

      return ret;
    };

    size_t size(void) const { return m_data_.size(); };

    size_t ndim(void) const {
      // size_t i;
      // for (i = 3 ; i > 0 ; i--) {
      //   if (m_shape_[i] != 1)
      //     break;
      // }
      // return i+1;
      return m_shape_.size();
    };
}; // class Matrix

#endif
