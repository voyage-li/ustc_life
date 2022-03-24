#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>

using namespace std;

const int Population_size = 100;
const int Chromosome_length = 6;
double rate_crossover = 0.5;
double rate_mutation = 0.001;
int iteration_num = 50;

typedef struct Chromosome
{
    short int bit[Chromosome_length];
    double value;
    double fitness;
    double rate_fit;
    double cumu_fit;
} chromosome;

typedef int DataType;

typedef struct StackNode
{
    DataType data;
    struct StackNode *next;
} StackNode, *LinkStack;

void CreateLinkStack(LinkStack &S);

void DestroyLinkStack(LinkStack &S);

bool EmptyLinkStack(LinkStack S);

void population_initialize(chromosome (&population_current)[Population_size]);

void decode(chromosome &population_current);

double objective_function(double x);

void fresh_property(chromosome (&population_current)[Population_size]);

void seletc_prw(chromosome (&population_current)[Population_size], chromosome (&population_next_generation)[Population_size], chromosome &best_individual);

void crossover(chromosome (&population_next_generation)[Population_size]);

void mutation(chromosome (&population_next_generation)[Population_size]);

// 涓诲嚱鏁�
void main()
{
    clock_t start, end; //寮€濮嬭鏃�,绮剧‘鍒扮
    start = clock();

    /*****鍒濆鍖栧畾涔夌殑绉嶇兢鍜屼釜浣�*****/
    chromosome population_current[Population_size];         //褰撳墠绉嶇兢
    chromosome population_next_generation[Population_size]; //浜х敓鐨勪笅涓€浠ｇ殑绉嶇兢
    chromosome best_individual;                             //璁板綍閫傚簲搴︾殑鏈€澶у€�
    chromosome zeros_chromosome;                            //瀹氫箟涓€涓叏涓�0鐨勪釜浣擄紝鐢ㄤ簬缇や綋涓煇涓釜浣撶殑閲嶇疆
    /****************************************/

    int i = 0, j = 0; //寰幆鍙橀噺

    //*****鍒濆鍖栧畾涔夌殑绉嶇兢鍜屼釜浣�*****
    //棣栧厛鍒濆鍖杬eros_chromosome锛屽悗浣跨敤涔嬪垵濮嬪寲鍏朵粬涓綋
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
    /****************************************/

    printf("\nWelcome to the Genetic Algorithm锛乗n"); //
    printf("The Algorithm is based on the function y = -x^2 + 5 to find the maximum value of the function.\n");

enter:
    printf("\nPlease enter the no. of iterations\n璇疯緭鍏ユ偍瑕佽瀹氱殑杩唬鏁� : ");
    // 杈撳叆杩唬娆℃暟锛屼紶閫佺粰鍙傛暟 iteration_num
    scanf_s("%d", &iteration_num);

    // 鍒ゆ柇杈撳叆鐨勮凯浠ｆ鏁版槸鍚︿负璐熸垨闆讹紝鏄殑璇濋噸鏂拌緭鍏�
    if (iteration_num < 1)
        goto enter;

    //绉嶇兢鍒濆鍖栵紝寰楀埌涓綋鐨勪簩杩涘埗瀛楃涓�
    population_initialize(population_current);
    //鏇存柊绉嶇兢鍐呬釜浣撶殑灞炴€у€�
    fresh_property(population_current);
    // 寮€濮嬭凯浠�
    for (i = 0; i < iteration_num; i++)
    {
        // 杈撳嚭褰撳墠杩唬娆℃暟
        // printf("\ni = %d\n", i);
        //鎸戦€変紭绉€涓綋缁勬垚鏂扮殑绉嶇兢
        seletc_prw(population_current, population_next_generation, best_individual);
        //瀵归€夋嫨鍚庣殑绉嶇兢杩涜浜ゅ弶鎿嶄綔
        crossover(population_next_generation);
        //瀵逛氦鍙夊悗鐨勭缇よ繘琛屽彉寮傛搷浣�
        mutation(population_next_generation);
        //鏇存柊绉嶇兢鍐呬釜浣撶殑灞炴€у€�
        fresh_property(population_next_generation);
        //灏唒opulation_next_generation鐨勫€艰祴缁檖opulation_current锛屽苟娓呴櫎population_next_generation鐨勫€�
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

    // 娓呴櫎鎵€鏈夌紦鍐插尯
    //  flushall();
    system("pause");
}

//鍑芥暟锛氱缇ゅ垵濮嬪寲
//杈撳叆鏄暟缁勭殑寮曠敤
//璋冪敤鏃讹紝鍙渶杈撳叆鏁扮粍鍚�
void population_initialize(chromosome (&population_current)[Population_size])
{
    int i = 0, j = 0;

    //浜х敓闅忔満鏁扮瀛�
    srand((unsigned)time(NULL));
    //閬嶅巻绉嶇兢涓殑姣忎釜鏌撹壊浣�
    for (j = 0; j < Population_size; j++)
    {
        //闅忔満鍒濆鍖栨煋鑹蹭綋鐨勬瘡涓€浣�
        for (i = 0; i < Chromosome_length; i++)
        {
            // 闅忔満浜х敓鏌撹壊浣撲笂姣忎竴涓熀鍥犱綅鐨勫€硷紝0鎴�1
            population_current[j].bit[i] = rand() % 2;
        }
    }
}

// 鍑芥暟锛氬皢浜岃繘鍒舵崲绠椾负鍗佽繘鍒�
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

//鍑芥暟锛氭洿鏂扮缇ゅ唴涓綋鐨勫睘鎬у€�
//璇存槑锛氬綋绉嶇兢涓釜浣撶殑浜岃繘鍒朵覆纭畾鍚庯紝灏卞彲浠ヨ绠楁瘡涓釜浣揻itness銆乿alue銆乺ate_fit 銆乧umu_fit
//杈撳叆锛�
// chromosome (&population_current)[Population_size] 褰撳墠浠ｇ缇ょ殑寮曠敤
void fresh_property(chromosome (&population_current)[Population_size])
{
    int j = 0;
    double sum = 0;

    for (j = 0; j < Population_size; j++)
    {

        //鏌撹壊浣撹В鐮侊紝灏嗕簩杩涘埗鎹㈢畻涓哄崄杩涘埗锛屽緱鍒颁竴涓暣鏁板€�
        //璁＄畻浜岃繘鍒朵覆瀵瑰簲鐨�10杩涘埗鏁板€�
        decode(population_current[j]);
        //璁＄畻鏌撹壊浣撶殑閫傚簲搴�
        population_current[j].fitness = objective_function(population_current[j].value);
        sum = sum + population_current[j].fitness;
    }

    //璁＄畻姣忔潯鏌撹壊浣撶殑閫傚簲鍊肩櫨鍒嗘瘮鍙婄疮璁￠€傚簲搴﹀€肩殑鐧惧垎姣旓紝鍦ㄨ疆鐩樿祵閫夋嫨娉曟椂鐢ㄥ畠閫夋嫨鏌撹壊浣�
    population_current[0].rate_fit = population_current[0].fitness / sum;
    population_current[0].cumu_fit = population_current[0].rate_fit;
    for (j = 1; j < Population_size; j++)
    {
        population_current[j].rate_fit = population_current[j].fitness / sum;
        population_current[j].cumu_fit = population_current[j].rate_fit + population_current[j - 1].cumu_fit;
    }
}

//鍑芥暟锛氬熀浜庤疆鐩樿祵閫夋嫨鏂规硶锛屽绉嶇兢涓殑鏌撹壊浣撹繘琛岄€夋嫨
//杈撳叆锛�
// chromosome (&population_current)[Population_size] 褰撳墠浠ｇ缇ょ殑寮曠敤
// chromosome (&population_next_generation)[Population_size] 閫夋嫨鍑虹殑涓嬩竴浠ｇ缇ょ殑寮曠敤
// chromosome &best_individual 褰撳墠浠ｇ缇や腑鐨勬渶浼樹釜浣�
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

// 鍑芥暟锛氫氦鍙夋搷浣�
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

void StrAssign(String &S, char *cstr)
{
    int i;
    for (i = 0; cstr[i] != '\0'; i++)
    {
        S[i] = cstr[i];
    }
    S[i] = '\0';
};

//杩斿洖瀛楃涓查暱搴�
int StrLength(String S)
{
    int i;
    for (i = 0; S[i] != '\0'; i++)
    {
    }
    return i;
}

//鍒ゆ柇瀛楃涓叉槸鍚︿负绌�
bool StrEmpty(String S)
{
    return (S[0] == '\0');
}