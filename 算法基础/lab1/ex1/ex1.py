import os
import random
from matplotlib import pyplot as plt

data = ['quick_sort', 'heap_sort', 'merge_sort', 'counting_sort']
picdata = {
    data[0]: [],
    data[1]: [],
    data[2]: [],
    data[3]: []
}


def command_line(string):
    print(string)
    os.system(string)


def draw_pic(ylim, name):
    A = [x for x in range(3, 21, 3)]
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
    command_line('rm -rf ./output/**/*.txt')
    command_line('rm -rf ./output/*.png')
    command_line('rm -rf ./input/*.txt')
    command_line('g++ ./src/quick_sort.cpp -o ./src/quick_sort')
    command_line('g++ ./src/merge_sort.cpp -o ./src/merge_sort')
    command_line('g++ ./src/heap_sort.cpp -o ./src/heap_sort')
    command_line('g++ ./src/counting_sort.cpp -o ./src/counting_sort')

    for i in range(3, 21, 3):
        with open('./input/input_' + str(i) + '.txt', 'w') as f:
            for _ in range(0, 2**i):
                f.write(str(random.randint(0, 2**15-1))+'\n')
        for sort in data:
            command_line('./src/' + sort + ' <./input/input_' + str(i) + '.txt >./output/' + sort + '/result_' + str(i) + '.txt')

    for x in data:
        with open('./output/' + x + '/time.txt') as f:
            for line in f:
                picdata[x].append(float(line[:-2]))

    draw_pic(0.002, 1)
    draw_pic(0.1, 2)
    command_line('rm -rf ./src/quick_sort')
    command_line('rm -rf ./src/heap_sort')
    command_line('rm -rf ./src/counting_sort')
    command_line('rm -rf ./src/merge_sort')
