import csv

def calculate_function_on_column(filename, column_name, func_name):
    func_map = {
        'max': max,
        'min': min,
        'sum': sum,
    }

    with open(filename) as file:
        reader = csv.DictReader(file, delimiter=';')
        values = []
        for row in reader:
            values.append(float(row[column_name]))
        result = func_map[func_name](values)
        return result

filename = input("Filename:")
column_name = input("Column name:")
func_name = input("Function name:")

result = calculate_function_on_column(filename, column_name, func_name)
print(f"{func_name}({column_name})={result:.2f}")