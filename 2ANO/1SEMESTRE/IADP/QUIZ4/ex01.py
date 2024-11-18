value = int(input("number:"))

print("Numbers:")

n1 = int(value // 100)
n2 = int((value // 10) % 10)
n3 = int(value % 10)

print(value)
print(n1 * 100 + n3 * 10 + n2)
print(n2 * 100 + n3 * 10 + n1)
print(n2 * 100 + n1 * 10 + n3)
print(n3 * 100 + n2 * 10 + n1)
print(n3 * 100 + n1 * 10 + n2)
