#include <stdio.h>

int main()
{
    int time[9];
    int moves[10]; //different moves
    int i;

    for (i = 0; i < 9; i++)
        scanf("%d", &time[i]);

    int steps = 40; //the max steps is 9*4

    int result[9];

    for (moves[1] = 0; moves[1] < 4; moves[1]++)
        for (moves[2] = 0; moves[2] < 4; moves[2]++)
            for (moves[3] = 0; moves[3] < 4; moves[3]++)
                for (moves[4] = 0; moves[4] < 4; moves[4]++)
                    for (moves[5] = 0; moves[5] < 4; moves[5]++)
                        for (moves[6] = 0; moves[6] < 4; moves[6]++)
                            for (moves[7] = 0; moves[7] < 4; moves[7]++)
                                for (moves[8] = 0; moves[8] < 4; moves[8]++)
                                    for (moves[9] = 0; moves[9] < 4; moves[9]++)
                                        //one clock are effected by many moves
                                        //for example moves 1 2 4 can change clock 1
                                        if ((moves[1] + moves[2] + moves[4] + time[0]) % 4 == 0 &&
                                            (moves[1] + moves[2] + moves[3] + moves[5] + time[1]) % 4 == 0 &&
                                            (moves[2] + moves[3] + moves[6] + time[2]) % 4 == 0 &&
                                            (moves[1] + moves[4] + moves[5] + moves[7] + time[3]) % 4 == 0 &&
                                            (moves[1] + moves[3] + moves[5] + moves[7] + moves[9] + time[4]) % 4 == 0 &&
                                            (moves[3] + moves[5] + moves[6] + moves[9] + time[5]) % 4 == 0 &&
                                            (moves[4] + moves[7] + moves[8] + time[6]) % 4 == 0 &&
                                            (moves[5] + moves[7] + moves[8] + moves[9] + time[7]) % 4 == 0 &&
                                            (moves[6] + moves[8] + moves[9] + time[8]) % 4 == 0)
                                        //judge condition
                                        {
                                            int sum = moves[1] + moves[2] + moves[3] + moves[4] + moves[5] + moves[6] + moves[7] + moves[8] + moves[9]; //record the steps of this answer
                                            if (sum < steps)
                                            {
                                                steps = sum;
                                                result[0] = moves[1];
                                                result[1] = moves[2];
                                                result[2] = moves[3];
                                                result[3] = moves[4];
                                                result[4] = moves[5];
                                                result[5] = moves[6];
                                                result[6] = moves[7];
                                                result[7] = moves[8];
                                                result[8] = moves[9];
                                            }
                                        }
    for (int j = 0; j < 9; j++)
        while (result[j] != 0)
        {
            printf("%d ", j + 1);
            result[j]--;
        }

    return 0;
}