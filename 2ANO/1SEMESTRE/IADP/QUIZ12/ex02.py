n = int(input())
m = []

for j in range(n):
    r = [str(input()) for k in range(n)]
    m.append(r)

for i in range(n):
    m[i].sort()

for r in m:
    print(r)