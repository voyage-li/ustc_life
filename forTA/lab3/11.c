#include <stdio.h>
#include <stdlib.h>

typedef struct object
{
    int id;
    float weight, value, uni_value;
} item;

int main()
{
    int volume, n;
    item *obj = (item *)malloc(11 * sizeof(item)); // 11用来交换
    int id[10] = {0}, t_id;
    float max;
    float cur_weight = 0, cur_value = 0, rest_weight = 0, rest_value = 0;

    printf("输入背包的容量：");
    scanf("%d", &volume);
    printf("输入物品的数量：");
    scanf("%d", &n);
    printf("输入%d 个物品的编号：", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &obj[i].id);

    printf("输入%d 个物品的重量：", n);
    for (int i = 0; i < n; i++)
        scanf("%f", &obj[i].weight);

    printf("输入%d 个物品的价值：", n);
    for (int i = 0; i < n; i++)
        scanf("%f", &obj[i].value);

    for (int i = 0; i < n; i++)
        obj[i].uni_value = obj[i].value / obj[i].weight;

    printf("\n0-1背包问题的按价值贪心法求解：");
    // insert_sort
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j <= i; j++)
            if (obj[j].value < obj[i + 1].value)
            {
                obj[10] = obj[i + 1];
                for (int k = i + 1; k > j; k--)
                    obj[k] = obj[k - 1];
                obj[j] = obj[10];
                break;
            }
    /*
    for(int i=0; i<n; i++)
        printf("%.2f ",obj[i].value);
    printf("\n");
    */
    for (int i = 0; i < n && cur_weight <= volume; i++)
    {
        if (volume - cur_weight >= obj[i].weight)
        {
            printf("\n%d号物品 重量：%.2f 价值：%.2f 装入背包", obj[i].id, obj[i].weight, obj[i].value);
            cur_weight += obj[i].weight;
            cur_value += obj[i].value;
        }
    }
    printf("\n装入背包的物品总价值为：%.2f", cur_value);
    cur_weight = 0;
    cur_value = 0;

    printf("\n\n0-1背包问题的按单位价值贪心法求解：");
    // insert_sort
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j <= i; j++)
            if (obj[j].uni_value < obj[i + 1].uni_value)
            {
                obj[10] = obj[i + 1];
                for (int k = i + 1; k > j; k--)
                    obj[k] = obj[k - 1];
                obj[j] = obj[10];
                break;
            }
    /*
    for(int i=0; i<n; i++)
        printf("%.2f ",obj[i].uni_value);
    printf("\n");
    */
    for (int i = 0; i < n && cur_weight <= volume; i++)
    {
        if (volume - cur_weight >= obj[i].weight)
        {
            printf("\n%d号物品 重量：%.2f 价值：%.2f ,单位价值：%.2f,装入背包", obj[i].id, obj[i].weight, obj[i].value, obj[i].uni_value);
            cur_weight += obj[i].weight;
            cur_value += obj[i].value;
        }
    }
    printf("\n装入背包的物品总价值为：%.2f", cur_value);
    cur_weight = 0;
    cur_value = 0;

    printf("\n\n部分背包问题的按单位价值贪心法求解：");
    for (int i = 0; i < n && cur_weight <= volume; i++)
    {
        //整个装进去
        if (volume - cur_weight >= obj[i].weight)
        {
            printf("\n%d号物品 重量：%.2f 价值：%.2f ,单位价值：%.2f,装入背包", obj[i].id, obj[i].weight, obj[i].value, obj[i].uni_value);
            cur_weight += obj[i].weight;
            cur_value += obj[i].value;
        }
        else //分割
        {
            printf("\n%d号物品 重量：%.2f 价值：%.2f ,单位价值：%.2f,其中 %.2f 重价值 %.2f 装入背包",
                   obj[i].id, obj[i].weight, obj[i].value, obj[i].uni_value, volume - cur_weight, obj[i].uni_value * (volume - cur_weight));
            cur_value += obj[i].uni_value * (volume - cur_weight);
            break;
        }
    }
    printf("\n装入背包的物品总价值为：%.2f", cur_value);
    return 0;
}
