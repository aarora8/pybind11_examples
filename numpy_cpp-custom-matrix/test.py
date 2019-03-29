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
C = np.array([[0,0,0],[0,0,0]])
print("A = ", A)
print("B = ", B)
print("A * B = ", example.Multiply(A,B,C,2,2,3))

print()
A = np.array([[1,1,1],[2,2,2]])
C = np.array([[0,0],[0,0],[0,0]])
print("A = ", A)
print("A Transpose = ", example.Transpose(A,C,2,3))

a = 10
print("a Exponential = ", example.Exp(a))
