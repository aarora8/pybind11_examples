# Introduction

Wrapping NumPy array to/from C++ Matrix using pybind11.

# Compile and Run

Assuming **cmake** is installed, run the following commands in Linux to compile and run the example:

```bash
virtualenv -p `which python3` venvpy3
source venvpy3/bin/activate
pip install pybind11
pip install numpy
cd numpy_cpp-custom-matrix/
c++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` example.cpp -o example`python3-config --extension-suffix`
python test.py
```
