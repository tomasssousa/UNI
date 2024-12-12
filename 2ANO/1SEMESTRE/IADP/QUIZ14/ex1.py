import csv

# Input parameters
filename = input("Filename:")
estado_filter = input("'estado' column value:")

with open(filename) as file:
    reader = csv.reader(file, delimiter=';')
    headers = next(reader)
    headers.append('sexo')

    print(';'.join(headers))
    count = 0

    for row in reader:
        if len(row) != len(headers) - 1:
            continue

        estado = row[headers.index('estado')]

        if estado[:-1] == estado_filter[:-1]:
            if estado.endswith('a'):
                sexo = 'F'
            elif estado.endswith('o'):
                sexo = 'M'
        else:
            sexo = ''

        row.append(sexo)

        print(';'.join(row))

        count += 1
        if count == 10:
            break