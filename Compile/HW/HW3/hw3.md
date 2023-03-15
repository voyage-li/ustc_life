##### 3.17

给出拓广文法：
$$
S^{'}\rightarrow S\ \ \ \ S\rightarrow (L)\ |\ a\ \ \ \ L\rightarrow L,S\ |\ S
$$
下面构造项目集:

$I_0=closure(\{[S^{'}\rightarrow \cdot S]\})=\{S^{'}\rightarrow \cdot S,S\rightarrow \cdot (L),S\rightarrow\cdot a\}$

$I_1=goto(I_0,S)=closure(\{[S^{'}\rightarrow S \cdot]\})=\{S^{'}\rightarrow S \cdot\}$

$I_2=goto(I_0,()=closure(\{[S\rightarrow (\cdot L)]\})=\{S\rightarrow (\cdot L),L\rightarrow \cdot L,S,\ L\rightarrow \cdot S,S\rightarrow \cdot (L),S\rightarrow\cdot a\}$

$I_3=goto(I_0,a)=closure(\{[S\rightarrow a \cdot]\})=\{S\rightarrow a \cdot\}$

$I_4=goto(I_2,L)=closure(\{[S\rightarrow (L\cdot)],[L\rightarrow L \cdot,S]\})=\{S\rightarrow (L\cdot),L\rightarrow L \cdot,S\}$

$I_5=goto(I_2,S)=closure(\{[L\rightarrow S \cdot]\})=\{L \rightarrow S \cdot\}$

$I_6=goto(I_4,))=closure(\{[S\rightarrow (L)\cdot]\})=\{S\rightarrow (L)\cdot\}$

$I_7=goto(I_4,,)=closure(\{[S\rightarrow L,\cdot S]\})=\{ L\rightarrow L,\cdot S,S\rightarrow \cdot (L),S\rightarrow \cdot a\}$

$I_8=goto(I_7,S)=closure(\{[L\rightarrow L,S\cdot]\})=\{L\rightarrow L,S\cdot\}$

~~~mermaid
graph TD
	A[I<sub>0</sub>]--S-->B[I<sub>1</sub>]
	A--"("-->C[I<sub>2</sub>]
	A--a-->D[I<sub>3]
	C--L-->E[I<sub>4]
	C--S-->F[I<sub>5]
	E--")"-->G[I<sub>6]
	E--","-->H[I<sub>7]
	H--S-->I[I<sub>8]
	D--a-->C
	C--"("-->C
	H--a-->D
	H--"("-->C
~~~

##### 3.19-a

$(0) E^{'}\rightarrow E$
$(1) E\rightarrow E+T$
$(2) E\rightarrow T$
$(3) T\rightarrow TF$
$(4) T\rightarrow F$
$(5) F\rightarrow F*$
$(6) F\rightarrow a$
$(7) F\rightarrow b$


|    |b|*|a|+|$|F|T|E|
|---|---|---|---|---|---|---|---|---|
|0|	s5	|	|s4||   |3	|2|	1	|
|1|		|	|	|s6|acc|	|	|	|
|2|	s5	|	|s4|r2|r2|	7	||		|
|3|	r4	|s8	|r4|r4|r4|		|||
|4|	r6	|r6	|r6|r6|r6|		|||
|5|	r7	|r7	|r7|r7|r7|		|||
|6|	s5	|	|s4|  |	 | 3|	 9|		|
|7|	r3	|s8	|r3|r3|r3|		||		|
|8|	r5	|r5	|r5|r5|r5|		||			|
|9|	s5	|	|s4|r1|r1|	7||	|

##### 3.21-a

$FIRST(AaAb)\cap FIRST(BbBa)=\{a\}\cap \{b\}=\emptyset$

$FOLLOW(A)\cap FOLLW(B)=\{a,b\} \cap \{a,b\}\neq \emptyset$

所以是$LL(1)$文法不是$SLR(1)$文法

####
