n = int(input("n:"))

for i in range(n-1, 0, -1):
    n *= i;

print("Factorial = " + str(n))