import numpy as np
import sys

input_data = sys.stdin.read().strip().split("\n")
for line in input_data:
    print(line)

rows = []
for line in input_data[:-1]:
    rows.append([float(x) for x in line.split(",")])

A = np.array(rows)

b = np.array([float(x) for x in input_data[-1].split(",")])

x = np.linalg.solve(A, b)
print("solution:")
print(x)