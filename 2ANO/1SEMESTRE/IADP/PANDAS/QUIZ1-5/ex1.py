import numpy as np

def matrix_product(N, M, P):

  A = np.zeros((N, M))  
  for i in range(M):
    A[i] = np.array(list(map(float, input().split())))

  B = np.zeros((M, P))
  for i in range(P):
    B[i] = np.array(list(map(float, input().split())))
  
  result = np.dot(A, B)
  
  for row in result:
    print(row)

N = int(input())
M = int(input())
P = int(input())
matrix_product(N, M, P)