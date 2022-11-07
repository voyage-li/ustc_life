#### 7.1d

$$
\begin{align*}
t_1&:=a+b\\
t_2&:=-t_1\\
t_3&:=c+d\\
t_4&:=t_2*t_3\\
t_5&:=t_1+c\\
t_7&:=t_4+t_5
\end{align*}
$$

#### 7.2c

```bash
L0: if i <= 10 goto L1
	goto L2
L1: t = i * 4 
	a[t]:=0
L2:
```

#### 7.5

$$
\begin{align*}
P&\rightarrow\ \{D.offset_1=0;\}\ D\ \{P.offset=D.offset_2\};S\\
D&\rightarrow\  \{D_1.offset_1=D.offset_1;\}\ D_1;\ \{D_2.offset_1=D_1.offset_2;\}\ D_2\ \ \{ D.offset_2=D_2.offset_2;\} \\
D&\rightarrow id:T\ \{enter(id.lexeme,T.type,D.offset_1);\ D.offset_2=D.offset_1+T.width;\}\\
T&\rightarrow integer\  \{T.type = integer;\ T.width=4;\}\\
T&\rightarrow real\  \{T.type=real;\ T.width = 8;\}\\
T&\rightarrow array[num]\ of\ T_1\ \{T.type=array(num.val,T_1.type);\ T.width=num.val\times T_1.width\}\\
T&\rightarrow \ \uparrow T_1\ \{T.type=pointer(T_1.type);\ T.width=4;\}
\end{align*}
$$

