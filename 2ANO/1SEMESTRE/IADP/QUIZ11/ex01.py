fname = str(input())
nparts = fname.split()
ab = []

for i in nparts[:-1]:
    if 'A' <= i[0] <= 'Z':
        ab.append(i[0] + ".")

ab.append(nparts[-1])

print(" ".join(ab))