n = int(input())
m = []

for j in range(n):
    r = [float(input()) for k in range(n)]
    m.append(r)

min_i, min_j = 0, 0
max_i, max_j = 0, 0

for i in range(n):
    for j in range(n):
        if m[i][j] < m[min_i][min_j]:
            min_i, min_j = i, j
        if m[i][j] > m[max_i][max_j]:
            max_i, max_j = i, j

# Swap the minimum and maximum elements
m[min_i][min_j], m[max_i][max_j] = m[max_i][max_j], m[min_i][min_j]

# Print the modified matrix
for row in m:
    print(row)