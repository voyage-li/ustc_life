#### 4.3

###### （a)

$$
\begin{align*}
&S' \rightarrow S &&print(S.num)\\
&S\rightarrow (L) &&S.num=L.num+1\\
&S\rightarrow a &&S.num=0\\
&L \rightarrow L_1, S&&L.num=L_1.num+S.num\\
&L\rightarrow S&&L.num=S.num
\end{align*}
$$

###### （b)

$$
\begin{align*}
&S'\rightarrow S &&print(S.max)\\
&S\rightarrow (L) &&S.max=L.max+1\\
&S\rightarrow a &&S.max=0\\
&L \rightarrow L_1, S&&L.max=if(L_1.max>S.max)\ L_1.max\ else\ S.max\\
&L\rightarrow S&&L.max=S.max
\end{align*}
$$

#### 4.9b

此时应该将小数部分和整数部分分开处理，此时的文法
$$
\begin{align*}
&S\rightarrow L.R|L\\
&L\rightarrow BL|B\\
&R\rightarrow RB|B\\
&B\rightarrow 0|1
\end{align*}
$$
$i$是B的继承属性，$val$和$c$是综合属性
$$
\begin{align*}
&S\rightarrow L.R && S.val=L.val+R.val;\\
&S\rightarrow L && S.val =L.val;\\
&L\rightarrow BL_1 && B.i=L_1.c\times2;\ L.c=L_1.c\times2;\ L_1.val=L_1.val+B.c;\\
&L\rightarrow B &&B.i=1;\ L.c=1;\ L.val=B.c;\\
&R\rightarrow R_1B &&  B.i=R_1.c/2;\ R.c=R_1.c/2;\ R_1.val=R_1.val+B.c;\\
&R\rightarrow B &&B.i=1/2;\ R.c=1/2;\ R.val=R.c;\\
&R\rightarrow 0&&B.c=0;\\
&R\rightarrow 1&&B.c=B.i;\\
\end{align*}
$$

#### 4.12

###### (a)

继承属性$depth$表示嵌套深度
$$
\begin{align*}
&S'\rightarrow \{S.depth=0;\}S\\
&S\rightarrow \{L.depth=S.depth+1;\}(L)\\
&S\rightarrow a\{print(S.depth);\}\\
&L\rightarrow\{L_1.depth=L.depth;\}L_1,\{S.depth=L.depth;\}S\\
&L\rightarrow\{S.depth=L.depth;\}S
\end{align*}
$$

###### (b)

继承属性$in$表示该文法符号推出的字符序列前面的字符个数，综合属性$out$表示该文法推出的字符序列最后一个字符是第多少个字符
$$
\begin{align*}
&S'\rightarrow \{S.in=0;\}S\\
&S\rightarrow \{L.in=S.in+1;\}(L)\{S.out=L.out+1;\}\\
&S\rightarrow a\{S.out=S.in+1;\ print(S.out);\}\\
&L\rightarrow\{L_1.in=L.in;\}L_1,\{S.in=L_1.out+1;\}S\{L.out=S.out;\}\\
&L\rightarrow\{S.in=L.in;\}S\{L.out=S.out;\}
\end{align*}
$$
