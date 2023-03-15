from matplotlib import pyplot as plt

if __name__ == '__main__':
    x = [5, 10, 15, 20, 25]
    data1 = []
    with open('./ex1/output/time.txt') as f:
        data1 = f.read().split()
    plt.figure(figsize=(12, 8), dpi=72)
    plt.xlabel('size')
    plt.ylabel('T/s')
    plt.plot(x, data1)
    x_locator = plt.MultipleLocator(5)
    ax = plt.gca()
    ax.xaxis.set_major_locator(x_locator)
    plt.savefig('1.png')
    plt.close()

    x = [10, 15, 20, 25, 30]
    data2 = []
    with open('./ex2/output/time.txt') as f:
        data2 = f.read().split()
    plt.figure(figsize=(12, 8), dpi=72)
    plt.xlabel('size')
    plt.ylabel('T/s')
    plt.plot(x, data2)
    x_locator = plt.MultipleLocator(5)
    ax = plt.gca()
    ax.xaxis.set_major_locator(x_locator)
    plt.savefig('2.png')
    plt.close()
