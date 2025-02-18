import numpy as np

def calculate_squared_sum(initial, final, num_values):
    values = np.linspace(initial, final, num_values)
    squared_values = values ** 2
    total_sum = np.sum(squared_values)
    return round(total_sum, 2)


initial = int(input("Initial value:"))
final = int(input("Final value:"))
num_values = int(input("Number of values:"))

result = calculate_squared_sum(initial, final, num_values)
print(f"Sum of the array: {result}")