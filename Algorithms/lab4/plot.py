from matplotlib import pyplot as plt
from matplotlib.pyplot import MultipleLocator

x1 = [1, 3, 5, 7]
x2 = [2, 4, 6, 8]

data1 = [0.002037, 0.022001, 0.230020, 2.194196]

data2 = [0.001415, 0.020800, 0.208533, 2.319497]

plt.figure(figsize=(12, 8), dpi=72)
plt.xlim(0, 9)
plt.ylim(0, 2)
plt.xlabel('input')
plt.ylabel('T/s')

ax = plt.gca()
x_major_locator = MultipleLocator(1)
ax.xaxis.set_major_locator(x_major_locator)

plt.plot(x1, data1, color='r', label=r'$\log_{5}{N}$')
plt.plot(x2, data2, color='b', label=r'$\log_{7}{N}$')
plt.legend()
plt.savefig('1.png')
plt.close()
