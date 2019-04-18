import numpy as np
import example

A = np.arange(8)
B = np.arange(8)
print("A = ", A)
print("B = ", B)
print("A + B = ", example.Add(A,B))

print()
A = np.arange(8).reshape(4,2)
B = np.arange(8).reshape(4,2)
print("A = ", A)
print("B = ", B)
print("A + B = ", example.Add(A,B))

print()
A = np.arange(125).reshape(5,5,5)
print("A = ", A)
print("2.3 * A = ", example.ScalarMultiply(A,2.3))

print()
A = np.array([[1,3],[2,4]])
B = np.array([[5,2,1],[6,3,7]])
print("A = ", A)
print("B = ", B)
print("A * B = ", example.Multiply(A,B))

print()
A = np.array([[1,2,3],[4,5,6]])
print("A = ", A)
print("A Transpose = ", example.Transpose(A))

print()
A = np.array([[1,2,3],[4,5,6]])
print("A = ", A)
print("A Exponential = ", example.Exp(A))
