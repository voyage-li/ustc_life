import random
import math
# 27、81、243、729
l = [729]

for num in l:
    a = int(math.log(num, 5))
    b = int(math.log(num, 7))
    if a == b:
        for i in range(1, num + 1):
            L = random.sample(range(1, num+1), num)
            L.remove(i)
            for j in range(a):
                print(i, L[j], random.randint(-10, 50))
    else:
        for i in range(1, num + 1):
            L = random.sample(range(1, num+1), num)
            L.remove(i)
            for j in range(a):
                print(i, L[j], random.randint(-10, 50))
        print("==========================")
        for i in range(1, num + 1):
            L = random.sample(range(1, num+1), num)
            L.remove(i)
            for j in range(b):
                print(i, L[j], random.randint(-10, 50))
