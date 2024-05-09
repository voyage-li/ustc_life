from z3 import *
import sys
import math
import time


def solve_z3(wlist, hlist):
    maxw = wlist[0]
    maxh = hlist[0]
    wlist = wlist[1:]
    hlist = hlist[1:]
    length = len(wlist)
    X = [Int(f"x{i}") for i in range(length)]
    Y = [Int(f"y{i}") for i in range(length)]
    W = [Int(f"w{i}") for i in range(length)]
    H = [Int(f"h{i}") for i in range(length)]
    s = Solver()
    # 约束 长方形的长宽,可以颠倒
    for i in range(length):
        s.add(Or(And(W[i] == wlist[i], H[i] == hlist[i]),
              And(W[i] == hlist[i], H[i] == wlist[i])))

    # 约束 长方形的范围不超过最大
    for i in range(length):
        s.add(X[i] >= 0)
        s.add(Y[i] >= 0)
        s.add(X[i] + W[i] <= maxw)
        s.add(Y[i] + H[i] <= maxh)

    # 约束 长方形不覆盖
    for i in range(length):
        for j in range(i+1, length):
            s.add(Or(X[j] >= X[i]+W[i], X[i] >= X[j]+W[j],
                  Y[j] >= Y[i]+H[i], Y[i] >= Y[j]+H[j]))

    r = s.check()
    if r == unsat:
        print("No Solution")
        return -1
    elif r == unknown:
        print("failed to solve")
        return -1
    else:
        result = s.model()
        for i in range(length):
            print(f"X{i} =", result[X[i]], end=" ")
            print(f"Y{i} =", result[Y[i]], end=" ")
            print(f"W{i} =", result[W[i]], end=" ")
            print(f"H{i} =", result[H[i]])
        return result


def find_gcd(wlist, hlist):
    l = wlist+hlist
    gcdv = l[0]
    for i in l:
        gcdv = math.gcd(gcdv, i)
    return gcdv


def isvalid(wlist, hlist, x, y):
    l = len(x)
    for i in range(l):
        for j in range(i+1, l):
            if x[j] < x[i]+wlist[i] and x[i] < x[j]+wlist[j] and y[j] < y[i]+hlist[i] and y[i] < y[j]+hlist[j]:
                return False
    return True


def solve_recursion(maxw, maxh, wlist, hlist, now_x, now_y):
    if not isvalid(wlist, hlist, now_x, now_y):
        return False, [], []

    now_loc = len(now_x)
    if now_loc == len(wlist):
        print(wlist, hlist)
        return True, now_x, now_y

    now_w, now_h = wlist[now_loc], hlist[now_loc]
    for i in range(maxw):
        for j in range(maxh):
            if i + now_w <= maxw and j + now_h <= maxh:
                now_x.append(i)
                now_y.append(j)
                ret = solve_recursion(maxw, maxh, wlist, hlist, now_x, now_y)
                if ret[0]:
                    return True, ret[1], ret[2]
                now_x = now_x[:now_loc]
                now_y = now_y[:now_loc]

    wlist[now_loc], hlist[now_loc] = hlist[now_loc], wlist[now_loc]
    now_w, now_h = wlist[now_loc], hlist[now_loc]
    for i in range(maxw):
        for j in range(maxh):
            if i + now_w <= maxw and j + now_h <= maxh:
                now_x.append(i)
                now_y.append(j)
                ret = solve_recursion(maxw, maxh, wlist, hlist, now_x, now_y)
                if ret[0]:
                    return True, ret[1], ret[2]
                now_x = now_x[:now_loc]
                now_y = now_y[:now_loc]

    return False, [], []


def solve_me(wlist, hlist):
    gcdv = find_gcd(wlist, hlist)
    wlist = [i // gcdv for i in wlist]
    hlist = [i // gcdv for i in hlist]
    maxw = wlist[0]
    maxh = hlist[0]
    wlist = wlist[1:]
    hlist = hlist[1:]

    rectangles = list(zip(wlist, hlist))
    sorted_rectangles = sorted(
        rectangles, key=lambda r: r[0] * r[1], reverse=True)
    wlist, hlist = zip(*sorted_rectangles)
    wlist = list(wlist)
    hlist = list(hlist)
    return solve_recursion(maxw, maxh, wlist, hlist, [], []), gcdv


if __name__ == '__main__':
    wlist = []
    hlist = []
    for line in sys.stdin:
        w, h = map(int, line.split())
        wlist.append(w)
        hlist.append(h)

    start = time.process_time()
    solve_z3(wlist=wlist, hlist=hlist)
    end = time.process_time()
    s1 = str(end - start)

    start = time.process_time()
    print(solve_me(wlist=wlist, hlist=hlist))
    end = time.process_time()
    s2 = str(end - start)

    print(s1, "  ", s2)
