#### 5.1

如果使用$y=w^Tx$作为激活函数，单元值仍然是输入值的线性组合，类似于线性回归，达不到神经网络激活与筛选的目的

#### ▲ 讨论$\frac{e^{x_i}}{\sum_{j=1}^C e^{x_j}}$和$log \sum_{j=1}^Ce^{x_j}$的数值溢出问题

对于
$$
\frac{e^{x_i}}{\sum_{j=1}^C e^{x_j}}
$$
如果$x_i$均取相同的数，则上式的值应该为$\frac{1}{C}$

但是如果$x_i$的值比较极端，则可能出现计算时溢出的现象，这时对上式取对数
$$
log (\frac{e^{x_i}}{\sum_{j=1}^C e^{x_j}})=x_i-log(\sum_{j=1}^C e^{x_j})
$$
给$x_j$减去一个常数，处理溢出的问题，则上式等于
$$
x_i-log(\sum_{j=1}^{C}e^{x_j-Const})-Const
$$
一般的，我们可以取
$$
Const = \max_i \{x_i\}
$$
可以发现，$log \sum_{j=1}^Ce^{x_j}$其实是上述讨论式子中的一个部分，所以溢出情况和上述类似



#### ▲ 计算$\frac{e^{x_i}}{\sum_{j=1}^C e^{x_j}}$和$log \sum_{j=1}^Ce^{x_j}$关于向量$x = [x_1,\cdots,x_c]$的梯度

先计算
$$
\nabla\frac{e^{x_i}}{\sum_{j=1}^C e^{x_j}}
$$
先求
$$
\begin{align*}
\frac{\partial}{\partial x_m}\frac{e^{x_i}}{\sum_{j=1}^C e^{x_j}}&=-\frac{e^{x_i+x_m}}{(\sum_{j=1}^Ce^{x_j})^2}
\end{align*}
$$
再求当$i=m$时
$$
\begin{align*}
\frac{\partial}{\partial x_i}\frac{e^{x_i}}{\sum_{j=1}^C e^{x_j}}&=\frac{e^{x_i}(\sum_{j=1}^c e^{x_j})-e^{2x_i}}{(\sum_{j=1}^Ce^{x_j})^2}\\
&=\frac{e^{x_i}(\sum_{j=1}^Ce^{x_j}-e^{x_i})}{(\sum_{j=1}^Ce^{x_j})^2}
\end{align*}
$$
则
$$
\nabla\frac{e^{x_i}}{\sum_{j=1}^C e^{x_j}}=[-\frac{e^{x_i+x_1}}{(\sum_{j=1}^Ce^{x_j})^2},\cdots,\frac{e^{x_i}(\sum_{j=1}^Ce^{x_j}-e^{x_i})}{(\sum_{j=1}^Ce^{x_j})^2},\cdots,-\frac{e^{x_i+x_C}}{(\sum_{j=1}^Ce^{x_j})^2}]
$$
类似可以得到
$$
\nabla log\sum_{j=1}^Ce^{x_j}=[\frac{e^{x_1}}{\sum_{j=1}^Ce^{x_j}},\cdots,\frac{e^{x_C}}{\sum_{j=1}^Ce^{x_j}}]
$$

#### ▲

![image-20221022143830258](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221022143830258.png)
$$
\begin{align*}
b_1&=0.2\times0.6+0.3\times0.2=0.18\\
b_2&=0.2\times0.1+0.3\times0.7=0.23\\
\hat{y}&=0.5\times b_1+0.8\times b_2=0.274\\
&\frac{1}{2}(y-\hat{y})^2=0.025538
\end{align*}
$$

参数更新:

$$
\begin{align*}
g &= \hat{y}(1-\hat{y})(y-\hat{y})=0.04496\\
e_1&=b_1(1-b_1)w_1g=0.003318\\
e_2&=b_2(1-b_2)w_2g=0.006370\\
\Delta w_1&=\eta g b_1=0.008093\\
\Delta w_2&=\eta g b_2=0.010341\\
\Delta v_{A1}&=\eta e_1A=0.0006636\\
\Delta v_{A2}&=\eta e_2A=0.001274\\
\Delta v_{B1}&=\eta e_1B=0.0009954\\
\Delta v_{B2}&=\eta e_2B=0.001911
\end{align*}
$$

更新后的权重:
$$
\begin{align*}
w_1&=w_1+\Delta w_1=0.508093\\
w_2&=w_2+\Delta w_2=0.810341\\
v_{A1}&=v_{A1}+\Delta v_{A1}=0.6006636\\
v_{A2}&=v_{A2}+\Delta v_{A2}=0.101274\\
v_{B1}&=v_{B1}+\Delta v_{B1}=0.2009953\\
v_{B2}&=v_{B2}+\Delta v_{B2}=0.701911\\
\end{align*}
$$
更新后输出和平方损失
$$
\begin{align*}
b_1&=0.1804\\
b_2&=0.2308\\
\hat{y}&=0.2787\\
\frac{1}{2}(y-\hat{y})^2&=0.0245
\end{align*}
$$
显然，平方损失值下降了

#### 6.4

二分类问题且数据是线性可分的

#### 6.6

线性超平面是由少数支持向量决定的，噪声很有可能成为某个支持向量，则会对整个分类产生很大影响

#### 6.9

对于 $ w^{T}x+b $ 形式的模型，即线性模型，使用核技巧的关键点在于最优的 $ w^{\ast} $ 可以由训练集的线性组合表示， 即 $ w^{\ast}=\sum_{i}\beta_{i}x_{i} $ ，使得模型可表示为 $ \sum_{i}\beta_{i}\langle x_{i},x\rangle+b $ ， 进而使用核函数直接计算数据点在高维空间内积，而不显式的计算数据点从低维到高维的映射。

原命题：事实上对于任何 L2 正则化的线性模型： $ \min_{w} \frac{\lambda}{N}w^{T}w+\frac{1}{N}\sum_{n=1}^{N}err(y_{n},w^{T}x_{n}) $ ， 这里，其最优值都可以表示为 $ w^{\ast}=\sum_{i}\beta_{i}x_{i} $

#### ▲

![image-20221022152244767](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221022152244767.png)

