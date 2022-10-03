import os
import random
import numpy as np
from matplotlib import pyplot as plt

data = ['quicksort', 'heapsort', 'mergesort', 'countingsort']
picdata = {
    data[0]: [],
    data[1]: [],
    data[2]: [],
    data[3]: []
}


def draw_pic(ylim, name):
    A = [x for x in np.arange(3, 21, 3)]
    plt.figure(figsize=(12, 8), dpi=72)
    plt.xlim(0, 20)
    plt.ylim(0, ylim)
    plt.xlabel('n')
    plt.ylabel('T/s')
    plt.plot(A, picdata[data[0]], color='r', label=data[0])
    plt.plot(A, picdata[data[1]], color='g', label=data[1])
    plt.plot(A, picdata[data[2]], color='b', label=data[2])
    plt.plot(A, picdata[data[3]], color='y', label=data[3])
    plt.legend()
    plt.savefig('./output/' + str(name) + '.png')
    plt.close()


if __name__ == '__main__':
    os.system('rm -rf ./output/**/*.txt')
    os.system('rm -rf ./output/*.png')
    os.system('rm -rf ./input/*.txt')
    os.system('g++ ./src/quicksort.cpp -o ./src/quicksort')
    os.system('g++ ./src/mergesort.cpp -o ./src/mergesort')
    os.system('g++ ./src/heapsort.cpp -o ./src/heapsort')
    os.system('g++ ./src/countingsort.cpp -o ./src/countingsort')

    for i in range(3, 21, 3):
        print('2^'+str(i))
        with open('./input/input_' + str(i) + '.txt', 'w') as f:
            for _ in range(0, 2**i):
                f.write(str(random.randint(0, 2**15-1))+'\n')
        for sort in data:
            os.system('./src/' + sort + ' <./input/input_' + str(i) + '.txt >./output/' + sort + '/result_' + str(i) + '.txt')

    for x in data:
        with open('./output/' + x + '/time.txt') as f:
            for line in f:
                picdata[x].append(float(line[:-2]))

    for x in picdata:
        print(x, picdata[x])

    draw_pic(0.002, 1)
    draw_pic(0.1, 2)
    os.system('rm -rf ./src/quicksort')
    os.system('rm -rf ./src/heapsort')
    os.system('rm -rf ./src/countingsort')
    os.system('rm -rf ./src/mergesort')
