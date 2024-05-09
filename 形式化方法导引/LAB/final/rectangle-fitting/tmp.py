import random

l = [i*(-1 if i % 2 == 0 else 1) for i in range(1, 26+1)]

cnf_num = random.randint(10, 20)

print(f"p cnf {26} {cnf_num}")

cnt = 0

for i in range(cnf_num):
    num = random.randint(1, 8)
    for j in range(num):
        print(l[(cnt+j) % 26], end=' ')
    cnt += num
    print('0')
