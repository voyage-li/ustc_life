#include <stdio.h>
// #include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

const int Population_size = 100;
const int Chromosome_length = 6;
double rate_crossover = 0.5;
double rate_mutation = 0.001;
int iteration_num = 50;

//灏嗘煋鑹蹭綋瀹氫箟涓虹粨鏋勪綋绫诲瀷
typedef struct Chromosome
{
    short int bit[Chromosome_length];
    double value;
    double fitness;
    double rate_fit;
    double cumu_fit;
} chromosome;

void population_initialize(chromosome (&population_current)[Population_size]);

void decode(chromosome &population_current);

double objective_function(double x);

void fresh_property(chromosome (&population_current)[Population_size]);

void seletc_prw(chromosome (&population_current)[Population_size], chromosome (&population_next_generation)[Population_size], chromosome &best_individual);

void crossover(chromosome (&population_next_generation)[Population_size]);

void mutation(chromosome (&population_next_generation)[Population_size]);

void main()
{

    clock_t start, end; //寮€濮嬭鏃�,绮剧‘鍒扮
    start = clock();

    chromosome population_current[Population_size];         //褰撳墠绉嶇兢
    chromosome population_next_generation[Population_size]; //浜х敓鐨勪笅涓€浠ｇ殑绉嶇兢
    chromosome best_individual;                             //璁板綍閫傚簲搴︾殑鏈€澶у€�
    chromosome zeros_chromosome;                            //瀹氫箟涓€涓叏涓�0鐨勪釜浣擄紝鐢ㄤ簬缇や綋涓煇涓釜浣撶殑閲嶇疆

    int i = 0, j = 0;

    for (i = 0; i < Chromosome_length; i++)
        zeros_chromosome.bit[i] = 0;
    zeros_chromosome.fitness = 0.0;
    zeros_chromosome.value = 0.0;
    zeros_chromosome.rate_fit = 0.0;
    zeros_chromosome.cumu_fit = 0.0;

    best_individual = zeros_chromosome;
    for (i = 0; i < Population_size; i++)
    {
        population_current[i] = zeros_chromosome;
        population_next_generation[i] = zeros_chromosome;
    }

    printf("\nWelcome to the Genetic Algorithm锛乗n"); //
    printf("The Algorithm is based on the function y = -x^2 + 5 to find the maximum value of the function.\n");

enter:
    printf("\nPlease enter the no. of iterations\n璇疯緭鍏ユ偍瑕佽瀹氱殑杩唬鏁� : ");
    scanf_s("%d", &iteration_num);

    if (iteration_num < 1)
        goto enter;

    population_initialize(population_current);

    fresh_property(population_current);

    for (i = 0; i < iteration_num; i++)
    {
        seletc_prw(population_current, population_next_generation, best_individual);
        crossover(population_next_generation);
        mutation(population_next_generation);
        fresh_property(population_next_generation);
        for (i = 0; i < Population_size; i++)
        {
            population_current[i] = population_next_generation[i];
            population_next_generation[i] = zeros_chromosome;
        }
        //妫€楠屾椂闂存槸鍚﹀埌90s
        end = clock();
        if (double(end - start) / CLK_TCK > 89)
            break;
    }
    //杈撳嚭鎵€鐢ㄦ椂闂�
    printf("\n 杩唬%d娆℃墍鐢ㄦ椂闂翠负锛� %f\n", iteration_num, double(end - start) / CLK_TCK);

    //杈撳嚭缁撴灉
    printf("\n 鍑芥暟寰楀埌鏈€澶у€间负锛� %f ,閫傚簲搴︿负锛�%f \n", best_individual.value, best_individual.fitness);

    for (i = 0; i < Population_size; i++)
    {
        printf(" population_current[%d]=", i);
        for (j = 0; j < Chromosome_length; j++)
            printf(" %d", population_current[i].bit[j]);
        printf("        value=%f    fitness = %f\n", population_current[i].value, population_current[i].fitness);
    }
    printf("\nPress any key to end ! ");

    system("pause");
}

void population_initialize(chromosome (&population_current)[Population_size])
{
    int i = 0, j = 0;

    srand((unsigned)time(NULL));

    for (j = 0; j < Population_size; j++)
    {
        for (i = 0; i < Chromosome_length; i++)
        {
            population_current[j].bit[i] = rand() % 2;
        }
    }
}

void decode(chromosome &population_current)
{ //姝ゅ鐨勬煋鑹蹭綋闀垮害涓猴紝鍏朵腑涓〃绀虹鍙蜂綅
    int i = 0;
    population_current.value = 0;
    //鍦颁綅鍦ㄥ墠锛岄珮浣嶅啀鍚�
    for (i = 0; i < Chromosome_length - 1; i++)
        population_current.value += (double)pow(2, i) * (double)population_current.bit[i]; //閬嶅巻鏌撹壊浣撲簩杩涘埗缂栫爜,
    //鏈€楂樹綅涓虹鍙蜂綅锛屽鏋滄槸1浠ｈ〃璐熸暟
    if (population_current.bit[Chromosome_length - 1] == 1)
        population_current.value = 0 - population_current.value;
}

//鍑芥暟:璁＄畻閫傚簲搴�
double objective_function(double x)
{
    double y;
    // 鐩爣鍑芥暟锛歽= - ( (x-1)^ 2 ) +5
    y = -((x - 1) * (x - 1)) + 5;
    return (y);
}

void fresh_property(chromosome (&population_current)[Population_size])
{
    int j = 0;
    double sum = 0;

    for (j = 0; j < Population_size; j++)
    {
        decode(population_current[j]);
        population_current[j].fitness = objective_function(population_current[j].value);
        sum = sum + population_current[j].fitness;
    }

    population_current[0].rate_fit = population_current[0].fitness / sum;
    population_current[0].cumu_fit = population_current[0].rate_fit;
    for (j = 1; j < Population_size; j++)
    {
        population_current[j].rate_fit = population_current[j].fitness / sum;
        population_current[j].cumu_fit = population_current[j].rate_fit + population_current[j - 1].cumu_fit;
    }
}

void seletc_prw(chromosome (&population_current)[Population_size], chromosome (&population_next_generation)[Population_size], chromosome &best_individual)
{

    int i = 0, j = 0;
    double rate_rand = 0.0;
    best_individual = population_current[0];
    //浜х敓闅忔満鏁扮瀛�
    srand((unsigned)time(NULL));
    for (i = 0; i < Population_size; i++)
    {
        rate_rand = (float)rand() / (RAND_MAX);
        if (rate_rand < population_current[0].cumu_fit)
            population_next_generation[i] = population_current[0];
        else
        {
            for (j = 0; j < Population_size; j++)
            {
                if (population_current[j].cumu_fit <= rate_rand && rate_rand < population_current[j + 1].cumu_fit)
                {
                    population_next_generation[i] = population_current[j + 1];
                    break;
                }
            }
        }

        //濡傛灉褰撳墠涓綋姣旂洰鍓嶇殑鏈€鏈変釜浣撹繕瑕佷紭绉€锛屽垯灏嗗綋鍓嶄釜浣撹涓烘渶浼樹釜浣�
        if (population_current[i].fitness > best_individual.fitness)
            best_individual = population_current[i];
    }
}

void crossover(chromosome (&population_next_generation)[Population_size])
{
    int i = 0, j = 0;
    double rate_rand = 0.0;
    short int bit_temp = 0;
    int num1_rand = 0, num2_rand = 0, position_rand = 0;
    //浜х敓闅忔満鏁扮瀛�
    srand((unsigned)time(NULL));
    //搴斿綋浜ゅ弶鍙樺紓澶氬皯娆″憿锛熷厛璁惧畾涓虹缇ゆ暟閲�
    for (j = 0; j < Population_size; j++)
    {
        rate_rand = (float)rand() / (RAND_MAX);
        //濡傛灉澶т簬浜ゅ弶姒傜巼灏辫繘琛屼氦鍙夋搷浣�
        if (rate_rand <= rate_crossover)
        {
            //闅忔満浜х敓涓や釜鏌撹壊浣�
            num1_rand = (int)rand() % (Population_size);
            num2_rand = (int)rand() % (Population_size);
            //闅忔満浜х敓涓や釜鏌撹壊浣撶殑浜ゅ弶浣嶇疆
            position_rand = (int)rand() % (Chromosome_length - 1);
            //閲囩敤鍗曠偣浜ゅ弶锛屼氦鍙夌偣涔嬪悗鐨勪綅鏁颁氦鎹�
            for (i = position_rand; i < Chromosome_length; i++)
            {
                bit_temp = population_next_generation[num1_rand].bit[i];
                population_next_generation[num1_rand].bit[i] = population_next_generation[num2_rand].bit[i];
                population_next_generation[num2_rand].bit[i] = bit_temp;
            }
        }
    }
}

// 鍑芥暟锛氬彉寮傛搷浣�
void mutation(chromosome (&population_next_generation)[Population_size])
{
    int position_rand = 0;
    int i = 0;
    double rate_rand = 0.0;
    //浜х敓闅忔満鏁扮瀛�
    srand((unsigned)time(NULL));
    //鍙樺紓娆℃暟璁惧畾涓虹缇ゆ暟閲�
    for (i = 0; i < Population_size; i++)
    {
        rate_rand = (float)rand() / (RAND_MAX);
        //濡傛灉澶т簬浜ゅ弶姒傜巼灏辫繘琛屽彉寮傛搷浣�
        if (rate_rand <= rate_mutation)
        {
            //闅忔満浜х敓绐佸彉浣嶇疆
            position_rand = (int)rand() % (Chromosome_length);
            //绐佸彉
            if (population_next_generation[i].bit[position_rand] == 0)
                population_next_generation[i].bit[position_rand] = 1;
            else
                population_next_generation[i].bit[position_rand] = 0;
        }
    }
}