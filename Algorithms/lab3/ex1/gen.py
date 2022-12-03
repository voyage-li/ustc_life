import random

left = random.sample(range(1, 24), 23)
right = random.sample(range(29, 50), 19)
left_loc, right_loc = 0, 0
for i in range(30):
    if right_loc > 19 or (left_loc < 23 and random.randint(1, 2) == 1):
        print(left[left_loc], end=' ')
        print(random.randint(left[left_loc]+1, 25))
        left_loc += 1
    else:
        print(right[right_loc], end=' ')
        print(random.randint(right[right_loc]+1, 50))
        right_loc += 1
