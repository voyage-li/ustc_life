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

$$
rank(S_b) \leq k -1
$$

其中k为属性的数量

因为.
$$
S_b=∑_{j=1}^kN_j(μ_j−μ)(μ_j−μ)^T
$$
对于单独的$μ_j-\mu$，它的秩为1，因此协方差矩阵相加后的秩$\leq k$，但是由于均值的性质，最后一个$\mu_k$能够用前$k-1$个$\mu_j$线性表示，因此
$$
rank(S_b)\leq k-1
$$

#### ▲给出公式3.45的推导过程

$$
\max_W\frac{tr(W^tS_bW)}{tr(W^TS_wW)}=\max_W\frac{\sum w_i^TS_bw_i}{\sum w_i^TS_ww_i}
$$

上式为广义瑞利熵，其中$w_i$表示$W$只有第$i$行不为0的矩阵，$W=\sum w_i$
$$
w_i^T=\begin{bmatrix}
0 & 0 & 0& \cdot\cdot\cdot& 0\\
&&&\cdot\cdot\cdot\\

w_{i1} & w_{i2} & w_{i3} & \cdot\cdot\cdot& w_{in}\\

&&&\cdot\cdot\cdot\\
0 & 0 & 0& \cdot\cdot\cdot& 0\\
\end{bmatrix}
$$ {12321321321321321}
此时最优化问题同式$(3.35)$，利用拉格朗日乘子法，即等价于求
$$
S_bW=\lambda S_wW
$$

#### ▲证明$X(X^TX)^{-1}X^T$是投影矩阵，并对线性回归模型从投影角度解释

假设向量$b$在空间$X$上的投影为$p$，则
$$
p = \begin{bmatrix}X_1&X_2&...&X_n\end{bmatrix}
\begin{bmatrix}
x_1\\
x_2\\
...\\
x_n
\end{bmatrix}=Xx
$$
根据投影的性质，$b-p$应该和空间$X$垂直
$$
X^T(b-p)=0\\
X^T(b-Xx)=0\\
X^Tb=X^TXx\\
x = (X^TX)^{-1}X^Tb
$$
代回
$$
p=X(X^TX)^{-1}X^T b
$$
即
$$
X(X^TX)^{-1}X^T
$$
为投影矩阵

我们可以将特征矩阵$X$看作是一个向量组，每一列（特征）都是一个 $n$ 维向量，我们有 $d$ 个这样的向量。我们假设 $d<n $且所有特征都线性无关，那$X$ 张成的空间是个$d$ 维度空间。真实值 $y$ 是一个 $n×1$ 的向量，处于 $n $维空间中。多元线性回归就是在 $X$ 张成的 $d$ 维空间中，寻找 $n$ 维空间中 $y$ 的投影。

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

![image-20221012211039850](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221012211039850.png)(a)
$$
H(D) = -\frac{5}{10}log\frac{5}{10}-\frac{5}{10}log\frac{5}{10}=1
$$
(b) 
$$
\begin{align*}
g(D,A)&=H(D)-[\frac{4}{10}H(D_1)+\frac{6}{10}H(D_2)]\\
&=1-[\frac{4}{10}(-\frac{3}{4}log\frac{3}{4}-\frac{1}{4}log\frac{1}{4})+\frac{6}{10}(-\frac{2}{6}log\frac{2}{6}-\frac{4}{6}log\frac{4}{6})]\\
&=0.1245
\end{align*}
$$

$$
\begin{align*}
g(D,B)&=H(D)-[\frac{5}{10}H(D_1)+\frac{5}{10}H(D_2)]\\
&=1-[\frac{5}{10}(-\frac{2}{5}log\frac{2}{5}-\frac{3}{5}log\frac{3}{5})+\frac{5}{10}(-\frac{3}{5}log\frac{3}{5}-\frac{2}{5}log\frac{2}{5})]\\
&=0.0290
\end{align*}
$$

(c) 均为1

(d) 
$$
Gini\_index(D,A)=\frac{4}{10}(1-\frac{3}{4}^2-\frac{1}{4}^2)+\frac{6}{10}(1-\frac{2}{6}^2-\frac{4}{6}^2)=0.4167
$$

$$
Gini\_index(D,B)=\frac{5}{10}(1-\frac{2}{5}^2-\frac{3}{5}^2)+\frac{5}{10}(1-\frac{2}{5}^2-\frac{3}{5}^2)=0.48
$$

$A$是最优化分

(e)

