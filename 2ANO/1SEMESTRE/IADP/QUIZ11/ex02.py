n = int(input())
f_count = 0.00
m_count = 0.00

for i in range(n):
    s = str(input())
    if s[-1] == 'a':
        f_count += 1.00
    else:
        m_count += 1.00

f_count = (f_count / n) * 100
m_count = (m_count / n) * 100

print("Male: {:.2f}%, Female: {:.2f}%".format(m_count, f_count))