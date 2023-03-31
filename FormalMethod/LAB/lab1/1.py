from z3 import *

def n_queen_smt(n):
    Q = [Int('Q%i' % (i + 1)) for i in range(n)]
    val_c = [And (1 <= Q[i], Q[i] <= n) for i in range(n)]
    col_c = [Distinct(Q)]
    diag_c = [If(i == j,
                 True,
                 And(i + Q[i] != j + Q[j], i + Q[j] != j + Q[i])) for i in range(n) for j in range(i) ]
    s = Solver()
    s.add(val_c + col_c + diag_c)
    r = s.check()
    if r == unsat:
        print('No Solution')
    elif r == unknown:
        print("failed to solve")
    else:
        result = s.model()
        for i in range(n):
            for j in range(n):
                print('Q' if result[Q[i]]== j + 1 else '*',end = ' ')
            print('')

def n_queen_sat(n):
    P = [[Bool(f'P{i+1}{j+1}') for j in range(n)] for i in range(n)]
    
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
            for k in range(j+1,n):
                l.append(Or(Not(P[i][j]),Not(P[i][k])))
        case3.append(And(l))
    
    case4 = []
    for j in range(n):
        l = []
        for i in range(n):
            for k in range(i+1,n):
                l.append(Or(Not(P[i][j]),Not(P[k][j])))
        case4.append(And(l))

    case5 = []
    for i in range(n):
        for i_ in range(i+1,n):
            l = []
            for j in range(n):
                j_ = i + j - i_
                if 0 <= j_ <= n-1:
                    l.append(Or(Not(P[i][j]),Not(P[i_][j_])))
                j_ = - i + j + i_
                if 0 <= j_ <= n-1:
                    l.append(Or(Not(P[i][j]),Not(P[i_][j_])))
            case5.append(And(l))

    s = Solver()
    s.add(And(case1), And(case2), And(case3), And(case4), And(case5))
    r = s.check()
    if r == unsat:
        print('No Solution')
    elif r == unknown:
        print("failed to solve")
    else:
        result = s.model()
        for i in range(n):
            for j in range(n):
                print('Q' if result[P[i][j]]==True else '*',end = ' ')
            print('')



if __name__ == '__main__':
    n = 15
    print('SMT')
    n_queen_smt(n)
    print('SAT')
    n_queen_sat(n)