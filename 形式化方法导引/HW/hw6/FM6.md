#### 作业1

- $[1,2]\nabla[0,2]=[-\infty,2]$
- $[0,2]\nabla[1,2]=[0,2]$
- $[1,5]\nabla[1,5]=[1,5]$
- $[2,3]\nabla[2,4]=[2,+\infty]$

#### 作业2

<img src="./assets/QQ%E5%9B%BE%E7%89%8720230609165805.jpg" style="width:50%">

#### 作业3

$P=\{x<100,\ y =  100\}$

- 即 $x<101$   则  $[*,*]$
- 即 $x<101\and y=100$   则  $[*,1]$

#### 作业4

$1\rightarrow 2$

$$
\text{wp}(\text{assume}\ x<100,\  x<100) \leftrightarrow\ x<100 \rightarrow x<100\\
\text{wp}(\text{assume}\ x<100,\  y=100) \leftrightarrow\ x<100 \rightarrow y=100\\
\text{则    } b_1:=1
$$
$2\rightarrow 1$
$$
\text{wp}(x\text{++},\ x<100) \leftrightarrow x<99\\
\text{wp}(x\text{++},\ y=100) \leftrightarrow y=100\\
$$
即x++翻译成

```bash
if(b_1) b_1:=*;
```

$$
\text{wp}(y\text{++},\ x<100) \leftrightarrow x<100\\
\text{wp}(y\text{++},\ y=100) \leftrightarrow y=99\\
$$

即y++翻译成

```bash
if(b_2) b_2:=0;
else b_2:=*;
```

