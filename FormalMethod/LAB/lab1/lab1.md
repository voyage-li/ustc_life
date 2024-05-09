## Lab1

<p style="text-align:right">李远航 PB20000137</p>

#### 实验小作业1

##### 1. 实现思路

$$
(\mathop{\land}_{i=1}^{n}\mathop{\lor}_{j=1}^np_{ij})\land(\mathop{\land}_{i=1}^{n}\mathop{\land}_{0<j<k\leq n}(\neg p_{ij}\or \neg p_{ik}))\land(\mathop{\land}_{j=1}^{n}\mathop{\lor}_{i=1}^{n}p_{ij})\land(\mathop{\land}_{j=1}^{n}\mathop{\land}_{0<i<k\leq n}(\neg p_{ij}\lor\neg p_{kj}))\\
\land(\mathop{\land}_{0<i<i^{'}\leq n}(\mathop{\land}_{j,j^{'}:i+j=i^{'}+j^{'}\lor i-j=i^{'}-j^{'}}(\neg p_{ij}\lor\neg p_{i^{'}j^{'}}))
$$

​	将上述的逻辑表达式写成代码，即可

```python
P = [[Bool(f"P{i+1}{j+1}") for j in range(n)] for i in range(n)]
case1 = []
for i in range(n):
    l = []
    for j in range(n):
        l.append(P[i][j])
    case1.append(Or(l))
case2 = []
for j in range(n):
    l = []
    for i in range(n):
        l.append(P[i][j])
    case2.append(Or(l))
case3 = []
for i in range(n):
    l = []
    for j in range(n):
        for k in range(j + 1, n):
            l.append(Or(Not(P[i][j]), Not(P[i][k])))
    case3.append(And(l))
case4 = []
for j in range(n):
    l = []
    for i in range(n):
        for k in range(i + 1, n):
            l.append(Or(Not(P[i][j]), Not(P[k][j])))
    case4.append(And(l))
case5 = []
for i in range(n):
    for i_ in range(i + 1, n):
        l = []
        for j in range(n):
            j_ = i + j - i_
            if 0 <= j_ <= n - 1:
                l.append(Or(Not(P[i][j]), Not(P[i_][j_])))
            j_ = -i + j + i_
            if 0 <= j_ <= n - 1:
                l.append(Or(Not(P[i][j]), Not(P[i_][j_])))
        case5.append(And(l))
s = Solver()
s.add(And(case1 + case2 + case3 + case4 + case5))
r = s.check()
```

##### 2. 运行时间效率的对比：

SMT使用课程ppt中算法，此处仅比较`check()`求解使用的时间，不计入创建模型需要的时间

- 可以看到`SMT`在求解n皇后问题时，用时和n基本成正相关的关系，在求特定的n时，出现了一定的波动，而`SAT`在求解n皇后问题时，虽然整体求解用时也随着n的增加而增加，但是仍然明显快于`SMT`求解
- 但值得提出的是，`SAT`创建模型的过程会消耗大量的时间

|n|SMT用时(s)|SAT用时(s)|
|---|---|---|
| 4 | 0.0110 | 0.0072 |
| 5 | 0.0100 | 0.0074 |
| 6 | 0.0105 | 0.0161 |
| 7 | 0.0248 | 0.0174 |
| 8 | 0.0302 | 0.0088 |
| 9 | 0.0134 | 0.0088 |
| 10 | 0.0181 | 0.0131 |
| 11 | 0.1122 | 0.0121 |
| 12 | 0.0907 | 0.0169 |
| 13 | 0.0472 | 0.0132 |
| 14 | 0.2193 | 0.0184 |
| 15 | 0.0792 | 0.0249 |
| 16 | 0.2882 | 0.0198 |
| 17 | 0.0414 | 0.2449 |
| 18 | 0.6266 | 0.0244 |
| 19 | 0.2557 | 0.0335 |
| 20 | 0.4512 | 0.0323 |
| 21 | 0.5872 | 0.0355 |
| 22 | 0.5527 | 0.0386 |
| 23 | 0.7801 | 0.0287 |
| 24 | 0.7496 | 0.0290 |
| 25 | 0.8592 | 0.1093 |
| 26 | 0.6496 | 0.0378 |
| 27 | 2.1110 | 0.0394 |
| 28 | 0.4009 | 0.0542 |
| 29 | 1.2193 | 0.0727 |
| 30 | 1.6506 | 0.0497 |
| 31 | 1.0758 | 0.6075 |
| 32 | 1.4434 | 0.0702 |
| 33 | 6.5438 | 0.0989 |
| 34 | 2.2946 | 0.0893 |
| 35 | 3.4797 | 0.0801 |
| 36 | 11.4958 | 0.0925 |
| 37 | 2.8874 | 0.1110 |
| 38 | 16.4952 | 0.6867 |
| 39 | 15.6673 | 0.1379 |
| 40 | 24.6798 | 0.2134 |


#### 实验小作业2

##### 1. 实验思路

|$c_1$|$c_2$|$c_3$|$c_4$|$c_5$|$c_6$|
|-|-|-|-|-|-|
|$a_1$|$a_2$|$a_3$|$a_4$|$a_5$|$a_6$|
|$b_1$|$b_2$|$b_3$|$b_4$|$b_5$|$b_6$|
|$d_1$|$d_2$|$d_3$|$d_4$|$d_5$|$d_6$|

将两个数写成二进制形式展开:
$$
a = \mathop{\sum}_{i=1}^{6}2^{6-i}\times a_i\\
b = \mathop{\sum}_{i=1}^{6}2^{6-i}\times b_i
$$
$c_i$表示每一位的进位，$d_i$为二进制下计算的结果，上述的变量之间存在着如下的逻辑关系
$$
d_i\leftrightarrow(a_i\leftrightarrow(b_i\leftrightarrow c_i)) \\
c_{i-1}\leftrightarrow ((a_i\land b_i)\lor(a_i \land c_i)\lor(b_i \land c_i))
$$
上述两个逻辑表达式完成了对每一位计算和进位的处理，但这仅仅完成了相加逻辑的处理，还需要加上$a$和$b$的初值，这里用$13+7$举例，$13=(01101)_2$，$7=(00111)_2$
$$
\phi \land \neg a_1 \land a_2 \land a_3 \land \neg a_4 \land a_5 \land \neg b_1 \land \neg b_2 \land b_3 \land b_4 \land b_5
$$
此后运用`SAT`即可以完成对 $a+b$ 的计算

扩展到 $a-b$ ：直接使用b的补码，或 因为有$d = a + b$，所以我们有 $ b = d - a$，直接对上述逻辑式中的变量进行一定的更改，整体逻辑是不变的，这里使用第一种转换为补码的方式，由于本实验不考虑 $a$ 比 $b$ 更大的情况，故不作特殊处理

##### 2. 具体实现代码

将输入数据转换成补码的代码如下:

```python
def num_to_bit(num):
    if num == 0:
        return "00"
    elif num > 0:
        return "00" + bin(num)[2:]
    elif num < 0:
        string = "".join(["1" if i == "0" else "0" for i in bin(-num)[2:]])
        l = len(string)
        negnum = bin(int("".join(string), 2) + 1)[2:]
        negnum = (l - len(negnum)) * "0" + negnum
        return "11" + negnum
```

`SAT`求解部分：

```python
def cal_a_b(a, b):
    assert type(a) == int and type(b) == int
    stra = num_to_bit(a)
    strb = num_to_bit(b)
    if len(strb) > len(stra):
        stra, strb = strb, stra
    la, lb = len(stra), len(strb)
    strb = (la - lb) * strb[0] + strb
    A = [Bool(f"a{i}") for i in range(1, la + 1)]
    B = [Bool(f"b{i}") for i in range(1, la + 1)]
    C = [Bool(f"c{i}") for i in range(1, la + 1)]
    D = [Bool(f"d{i}") for i in range(1, la + 1)]
    s = Solver()
    for i in range(la):
        s.add(A[i] if stra[i] == "1" else Not(A[i]))
        s.add(B[i] if strb[i] == "1" else Not(B[i]))
        s.add(NXor(D[i], NXor(A[i], NXor(B[i], C[i]))))
        if i != 0:
            s.add(NXor(C[i - 1], Or(And(A[i], B[i]), And(A[i], C[i]), And(B[i], C[i]))))
    s.add(Not(C[la - 1]))
    r = s.check()
    if r == unsat:
        print("No Solution")
        return -1
    elif r == unknown:
        print("failed to solve")
        return -1
    else:
        result = s.model()
        ans = ""
        for i in D:
            ans += "1" if result[i] == True else "0"
        return int(ans, 2)
```

`cal_a_b()`函数实现了对 $a+b$ 和 $a-b$ 的求解，函数获得两个int类型的参数，返回两者相加的值，如`cal_a_b(13,-7)`，返回 $5$，`cal_a_b(13,7)`，返回 $20$

最后可以编写随机函数，验证程序计算的正确性:

```python
def judge():
    a = random.randint(1, 1000)
    b = random.randint(1, 1000)
    c = random.randint(1, 2)
    if c == 1:
        if a + b == cal_a_b(a, b):
            print(f"{a} + {b} = {a + b}")
            return 1
        else:
            print(f"Error at {a} + {b}")
            return -1
    else:
        b = random.randint(1, a)
        if a - b == cal_a_b(a, -b):
            print(f"{a} - {b} = {a - b}")
            return 1
        else:
            print(f"Error at {a} - {b}")
            return -1
```

循环10000次验证，程序没有出现错误：

```python
if __name__ == "__main__":
    for i in range(100):
        if judge() == -1:
            break
```

运行效果截图：

![image-20230404172249700](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20230404172249700.png)
