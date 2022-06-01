l = []
temp = input()
while temp != '':
    l.append([int(x) for x in temp.split(' ')])
    temp = input()

a = len(l)
b = len(l[0])

for i in l:
    i.append(sum(i))

l_p = []
for i in range(len(l[0])):
    num = 0
    for j in range(len(l)):
        num += l[j][i]
    l_p.append(num)

l.append(l_p)

for i in l:
    print(i)

ans = float(0)  # 我这是不是c系写多了 淦

for i in range(a):
    for j in range(b):
        ans += (l[i][j]-l[a][j]*l[i][b]/l[a][b])**2/(l[a][j]*l[i][b]/l[a][b])

print(ans)
