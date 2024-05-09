import sys
import copy
from pysat.solvers import Glucose3


def dpll(var, cnflist, orderlist):
    if len(cnflist) == 0 or len(orderlist) == var:
        if len(cnflist) == 0:
            retlist = []
            for i in orderlist:
                retlist.append(i if orderlist[i] else -i)
            return retlist
        else:
            return []
    jdg_this = -1
    for cnf_text in cnflist:
        if len(cnf_text) != 0:
            jdg_this = abs(cnf_text[0])
        if len(cnf_text) == 1:
            orderlist[abs(cnf_text[0])] = (cnf_text[0] > 0)
            break

    basecnf = copy.deepcopy(cnflist)

    if jdg_this in orderlist:
        for cnf_text in basecnf:
            if jdg_this in cnf_text:
                if orderlist[jdg_this] == True:
                    cnflist.remove(cnf_text)
                else:
                    cnflist[cnflist.index(cnf_text)].remove(jdg_this)
            elif -jdg_this in cnf_text:
                if orderlist[jdg_this] == False:
                    cnflist.remove(cnf_text)
                else:
                    cnflist[cnflist.index(cnf_text)].remove(-jdg_this)
        return dpll(var, cnflist, copy.deepcopy(orderlist))
    else:
        orderlist[jdg_this] = True
        for cnf_text in basecnf:
            if jdg_this in cnf_text:
                cnflist.remove(cnf_text)
            elif -jdg_this in cnf_text:
                cnflist[cnflist.index(cnf_text)].remove(-jdg_this)
        ret = dpll(var, cnflist, copy.deepcopy(orderlist))
        if ret:
            return ret

        cnflist = copy.deepcopy(basecnf)
        orderlist[jdg_this] = False
        for cnf_text in basecnf:
            if jdg_this in cnf_text:
                cnflist[cnflist.index(cnf_text)].remove(jdg_this)
            elif -jdg_this in cnf_text:
                cnflist.remove(cnf_text)
        return dpll(var, cnflist, copy.deepcopy(orderlist))


if __name__ == '__main__':
    var = 0
    cnf = []

    for line in sys.stdin:
        if line[0] == 'p':
            var = int(line.split()[2])
        else:
            cnf.append([int(i) for i in line.split()[:-1]])

    var_num = var
    cnf_num = len(cnf)

    orderlist = {}

    g = Glucose3()
    for i in cnf:
        g.add_clause(i)
    g.solve()
    py_ans = g.get_model()
    py_ans = sorted(py_ans, key=abs) if py_ans else []
    my_ans = sorted(dpll(var_num, cnf, orderlist), key=abs)
    print('py SAT   ', py_ans)
    print('my dpll  ', my_ans)
