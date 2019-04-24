import numpy as np
import example
import indexing

#A = np.arange(8)
#B = np.arange(8)
#print("A = ", A)
#print("B = ", B)
#print("A + B = ", example.Add(A,B))
#
#print()
#A = np.arange(8).reshape(4,2)
#B = np.arange(8).reshape(4,2)
#print("A = ", A)
#print("B = ", B)
#print("A + B = ", example.Add(A,B))
#
#print()
#A = np.arange(125).reshape(5,5,5)
#print("A = ", A)
#print("2.3 * A = ", example.ScalarMultiply(A,2.3))
#
#print()
#A = np.array([[1,3],[2,4]])
#B = np.array([[5,2,1],[6,3,7]])
#print("A = ", A)
#print("B = ", B)
#print("A * B = ", example.Multiply(A,B))
#
#print()
#A = np.array([[1,2,3],[4,5,6]])
#print("A = ", A)
#print("A Transpose = ", example.Transpose(A))
#
#print()
#A = np.array([[1,2,3],[4,5,6]])
#print("A = ", A)
#print("A Exponential = ", example.Exp(A))

print()
print("Test tensor indexing and slicing functions")

print()
A = np.array([[1,2,3],[4,5,6]])
print("A = ", A)
print("Select(A, 0, 0) = ", indexing.Select(A, 0, 0)) # [1, 2, 3]
print("Select(A, 1, 0) = ", indexing.Select(A, 1, 0)) # [1, 4]
print("Select(A, 1, 2) = ", indexing.Select(A, 1, 2)) # [3, 6]

print()
print("IndexSelect(A, 0, [0,2]) = ", indexing.IndexSelect(A, 0, [0])) # [1, 2, 3]
print("IndexSelect(A, 1, [0,2]) = ", indexing.IndexSelect(A, 1, [0,2]))
# [[1, 3],[4, 6]]
#
#print()
#print("Unbind(A, 0) = ", indexing.Unbind(A, 0))# [1, 2, 3], [4, 5, 6]
#print("Unbind(A, 1) = ", indexing.Unbind(A, 1))# [1, 4], [2, 5], [3, 6]
#
#print()
#print("Narrow(A, 0, 0, 2) = ", indexing.Narrow(A, 0, 0, 2)) # [[1, 2, 3], [4, 5, 6]]
#print("Narrow(A, 1, 0, 2) = ", indexing.Narrow(A, 1, 0, 2)) # [[1, 2], [4, 5]]
#print("Narrow(A, 1, 1, 2) = ", indexing.Narrow(A, 1, 1, 2)) # [[2, 3], [5, 6]]
#
#print()
#print("Rshape(A, (3,2)) = ", indexing.Reshape(A, (3,2)))
