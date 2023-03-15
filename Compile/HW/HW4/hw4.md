#### 3.4b

$$ {left}
R1 \rightarrow (R4)|a|b|R3\\
R2 \rightarrow R1*|R1\\
R3 \rightarrow R3R2 | R2\\
R4 \rightarrow R4'|'R1 | R1\\
$$ {end}

#### 3.10

|     | int                 | real                 | id                    | ,                        | $                        |
| --- | ------------------- | -------------------- | --------------------- | ------------------------ | ------------------------ |
| D   | $D\rightarrow TL$   | $D\rightarrow TL$    |                       |                          |                          |
| T   | $T \rightarrow int$ | $T \rightarrow real$ |                       |                          |                          |
| L   |                     |                      | $L \rightarrow id\ R$ |                          |                          |
| R   |                     |                      |                       | $R \rightarrow ,\ id\ R$ | $R \rightarrow \epsilon$ |

#### 3.12

$$
First(AB)=\{x\}
$$

$$
First(PQx)=\{a,d,x\}
$$

因此有

$$
First(AB) \cap First(PQx) \neq \emptyset
$$

因此不是$LL(1)$文法

#### 3.19b

|     | $   | \*  | +   | a   | b   | E   | F   | T   |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 0   | 0   | 0   | 0   | s4  | s5  | 1   | 3   | 2   |
| 1   | acc | 0   | s6  | 0   | 0   | 0   | 0   | 0   |
| 2   | r2  | 0   | r2  | s4  | s5  | 0   | 7   | 0   |
| 3   | r4  | s10 | r4  | r4  | r4  | 0   | 0   | 0   |
| 4   | r6  | r6  | r6  | r6  | r6  | 0   | 0   | 0   |
| 5   | r7  | r7  | r7  | r7  | r7  | 0   | 0   | 0   |
| 6   | 0   | 0   | 0   | s4  | s5  | 0   | 3   | 11  |
| 7   | r3  | s10 | r3  | r3  | r3  | 0   | 0   | 0   |
| 10  | r5  | r5  | r5  | r5  | r5  | 0   | 0   | 0   |
| 11  | r1  | 0   | r1  | s4  | s5  | 0   | 7   | 0   |

#### 3.27b

不是
$$
Follow(I) \cap Follow(R)=\{d\} \neq \emptyset
$$
