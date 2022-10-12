#### 3.2

$$
y = \frac{1}{1+e^{-(w^Tx+b)}}
$$

求导
$$
\frac{\partial y}{\partial w^T} =- \frac{e^{(-w^Tx+b)}(-x)}{(1+e^{-(w^Tx+b)})^{-2}}
= x(y-y^2)
$$
二阶导
$$
\frac{\partial}{\partial w^T}(\frac{\partial y}{\partial w^T}) = x(1-2y)(\frac{\partial y}{\partial w})^T =x(1-2y)x^T(y-y^2)
$$
对于 $xPx^T$，对任意向量$Z$有$Z^TxPx^TZ = \sum_{i} P_{ii}v_i^2 \geq 0$，因此其海森矩阵半正定

在二阶导中，$xx^T$的秩为$1$，非零特征向量为$1$，$y$的值域为$(0,1)$，当$y\in (0.5, 1)$时
$$
y(y-1)(1-2y)<0
$$
二阶导半负定，则公式$(3.18)$非凸
$$
l(\beta) = \sum_{i=1}^m(-y_i\beta^T\hat{x_i} + \ln(1+e^{\beta^T\hat{x_i}}))\\
\frac{\partial}{\partial \beta^T}(\frac{\partial l}{\partial \beta}) = \sum_{i=1}^m \hat{x}_i\hat{x}_i^Tp_1(\hat{x}_i;\beta)(1-p_1(\hat{x}_i;\beta)) \geq 0
$$
所以公式$(3.27)$为凸函数

#### 3.7

在类别为4时，其可行的编码有7种

![img](https://pic4.zhimg.com/v2-157d58c89174f9b34ab925ec802ad3cf_r.jpg)

当码长为9时，那么 $f_6$之后加任意两个编码，即为最优编码，因为此时再加任意的编码都是先有编码的反码，此时，类别之间最小的海明距离都为4，不会再增加。



#### ▲在LDA多分类情形下，试计算类间散度矩阵$S_b$的秩并证明



#### ▲给出公式3.45的推导过程



#### ▲证明$X(X^TX)^{-1}X^T$是投影矩阵，并对线性回归模型从投影角度解释



#### 4.1

假设不存在与训练集一致的决策树，那么训练集训练得到的决策树至少有一个节点上存在无法划分的多个数据（若节点上没有冲突数据，那么总是能够将数据分开的） 这与前提-不含冲突数据 矛盾，因此必存在与训练集一致的决策树

#### 4.9

![image-20221012205239954](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221012205239954.png)

将基尼指数推广为:
$$
Gini_index(D,a) = \rho \times (\sum_{v=1}^{V}\widetilde{r}_vGini(\widetilde{D}^v))
$$

$$
Gini(\widetilde{D})=1-\sum_{k=1}^{|Y|}\widetilde{p}_k^2
$$

#### ▲ 假设离散随机变量$X \in \{1,\cdot \cdot \cdot,K\}$，其取值为$k$的概率$P(X=k)=p_k$，其熵为$H(p)=-\sum_{k}p_klog_2p_k$，试用拉格朗日乘子法证明熵最大的分布为均匀分布

写出拉格朗日函数:
$$
L(p_1,...,p_K)=-\sum_{i}p_ilog_2p_i-\lambda(\sum_ip_i-1)
$$
对$p_1$到$p_K$求偏导可得方程
$$
\begin{cases}
-\sum_{i}p_ilog_2p_i-\lambda(\sum_ip_i-1)=0 \\
\\
-log_2p_i-ln2-\lambda = 0 \\
\\
\sum_ip_i-1 = 0\\
\end{cases}
$$
可得到$p_i$平均分布时，可以得到熵的最大值

#### ▲习题

![image-20221012211039850](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221012211039850.png)
