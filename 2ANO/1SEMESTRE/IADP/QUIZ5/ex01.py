import math

value = int(input("value:"))
result = math.sqrt(value)

i = 2;
count = 0;

while(i < result):
    if(value % i == 0):
        count += 1
    i += 1

if(count > 0):
    print(str(value) + " is not prime")

else:
    print(str(value) + " is prime")