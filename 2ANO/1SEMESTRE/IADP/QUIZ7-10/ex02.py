vector_size = int(input())
l1 = []
l2 = []
res = 0.0

for i in range(vector_size):
    l1.append(float(input()))

for j in range(vector_size):
    l2.append(float(input()))

for k in range(vector_size):
    res += l1[k] * l2[k]

print("Scalar product =", res)