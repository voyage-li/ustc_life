import numpy as np
from fractions import Fraction

def pivot():
    # 求转入基变量的列索引id
    l = list(matrix[0][:-1])
    index_intoB = l.index(max(l))#即取检验数的最大值列索引

    # 算出基变量在表中的行索引，用b列除以入基变量列后的值进行比较判断
    col_inB = []#入基的基变量的列，看哪个基变量出基
    for i in range(b_num):
        if matrix[i][index_intoB] == 0:
            col_inB.append(0.)
        else:
            col_inB.append(matrix[i][-1] / matrix[i][index_intoB])
    index_outB = col_inB.index(min([x for x in col_inB[1:] if x > 0]))#取b/aij的最小值，否则其他约束会不可行

    #将基变量列表中进行新旧基的替换
    indexes_B[index_outB - 1] = index_intoB #index_outB - 1为实际出基变量在基变量列表中的索引，因为矩阵第一行是c，约束矩阵A从第二行开始
    cur_cell_to1 = matrix[index_outB][index_intoB] #新基的应为1的位置当前的数值
    matrix[index_outB] /= cur_cell_to1 #该行全部除以该值，使其为1，即该行标准化

    #通过行变换将其他行非零元去除
    #注意，这一操作对第一行也执行了，是在将表达式中的新基变量也给消除！用其他非基变量来表示！第一行的最后一个数值极为z0，即目标函数值！
    for row in [x for x in range(b_num) if x != index_outB]:
        cur_cell_to0 = matrix[row][index_intoB]
        matrix[row] -= cur_cell_to0 * matrix[index_outB]

def solve():
    flag = True
    while flag:
        printf()
        if max(list(matrix[0][:-1])) <= 0:  # 直至所有系数小于等于0
            flag = False
        else:
            pivot()

def printf():
    (a,b) = matrix.shape
    for i in range(a):
        for j in range(b):
            print(matrix[i][j],end=' ')
        print('')
    print('--------------------')

def printSol():
    printf()
    for i in range(c_num - 1):
        if i in indexes_B:
            print("x" + str(i) + "=%.2f" % matrix[indexes_B.index(i) + 1][-1])
        else:
            print("x" + str(i) + "=0.00")
    print("objective is %.2f" % (-matrix[0][-1]))

matrix = np.loadtxt("data.txt", dtype=float)
(b_num, c_num) = matrix.shape
# b_num为约束行数加第一行的目标函数表达式行，c_num为约束系数列加上常数项b列
indexes_B = list(range(c_num - b_num, c_num - 1)) #基变量列表
solve()
printSol()

