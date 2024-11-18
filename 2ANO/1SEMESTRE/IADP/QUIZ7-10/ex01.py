n1 = int(input("Number of elements in first list = "))
l1 = []
l2 = []
l3 = []

for i in range(n1):
    l1.append(int(input("l1[" + str(i) + "]=")))

n2 = int(input("Number of elements in second list = "))

for j in range(n2):
    l2.append(int(input("l2[" + str(j) + "]=")))

for k in l1:
    if k not in l2:
        l3.append(k)

print(l3)