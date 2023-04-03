from z3 import *


def num_to_bit(num):
    if num == 0:
        return "0"
    elif num > 0:
        return "00" + bin(num)[2:]
    elif num < 0:
        string = "".join(["1" if i == "0" else "0" for i in bin(-num)[2:]])
        l = len(string)
        negnum = bin(int("".join(string), 2) + 1)[2:]
        negnum = (l - len(negnum)) * "0" + negnum
        return "11" + negnum


def NXor(p, q):
    return Not(Xor(p, q))


def cal_a_b(a, b):
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


if __name__ == "__main__":
    cal_a_b(13, 7)
