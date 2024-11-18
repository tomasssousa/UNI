n = int(input("n:"))
pos = 1
max = 0
for i in range(1, n+1, 1):
    cur = int(input("value " + str(i) + ":"))
    if cur > max:
        max = cur
        pos = i

print("Maximum = " + str(max) + " position = " + str(pos))