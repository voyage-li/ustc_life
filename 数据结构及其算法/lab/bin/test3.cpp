#include <iostream>
#include <iomanip>
#include <math.h>
#include <ctime>
using namespace std;
/*
 *Author:yuzewei
 *email:salanderyzw@163.com
 *Date:2020/10/24
 */

const int popSize = 20;    //绉嶇兢澶у皬
const int len = 4;         //鏌撹壊浣撻暱搴�
const double Pc = 0.7;     //浜ゅ弶姒傜巼
const double Pm = 0.001;   //鍙樺紓姒傜巼
const int generation = 20; //杩唬娆℃暟锛堢粓姝㈡潯浠讹級

typedef struct individual //涓綋缁撴瀯浣�
{
    bool chromo1[len]; //鏌撹壊浣搙1
    bool chromo2[len]; //鏌撹壊浣搙2
    double fit;        //閫傚簲搴�
    double prob;       //閫変腑姒傜巼
} individual;
struct individual pop[popSize];     //绉嶇兢
struct individual nextPop[popSize]; //涓嬩竴浠ｇ缇�
int nextPopNum = 0;                 //璁板綍褰撳墠涓嬩竴浠ｇ缇や腑涓綋鏁�
double lineProb[popSize];           //绾挎€ч€夋嫨姒傜巼锛堢敤浜庤疆鐩樿祵锛�
double totalFit;                    //鎬婚€傚簲搴�
int gen = 1;                        //褰撳墠浠ｆ暟

double getXValue(bool[]);
double getFitness(individual);
double getProb(individual);
int getRanChromo();
void getInitPop(struct individual[]);
bool inLegality(individual);
void selection(struct individual[]);
void crossover(struct individual[]);
void evolution();
void popPrintf(struct individual[]);

int main()
{
    srand((unsigned)time(NULL));

    getInitPop(pop);
    while (gen < generation)
        evolution();

    cout << "鏈€浼樿В涓猴細f(" << getXValue(pop[0].chromo1) << "," << getXValue(pop[0].chromo2) << ")="
         << pow(getXValue(pop[0].chromo1), 2) + pow(getXValue(pop[0].chromo2), 2) << endl;

    return 0;
}

/*鑾峰彇浜岃繘鍒剁紪鐮佸搴旂殑x鍊�*/
double getXValue(bool ch[len])
{
    double x;
    x = ch[0] * 8.0 + ch[1] * 4.0 + ch[2] * 2.0 + ch[3] * 1.0;
    return x;
}

/*鑾峰彇涓綋閫傚簲搴�*/
double getFitness(individual in)
{
    double x1, x2;
    double fit = 0;
    x1 = getXValue(in.chromo1);
    x2 = getXValue(in.chromo2);
    if (x1 == 0 && x2 == 0)
        return 0;
    else
        fit = 1 / (pow(x1, 2) + pow(x2, 2)); //鍊艰秺灏忥紝閫傚簲搴﹁秺楂橈紝鐢�1/f(x)琛ㄧず閫傚簲搴�
    return fit;
}

/*鑾峰彇涓綋閫夋嫨姒傜巼*/
double getProb(individual in)
{
    double prob = 0;
    prob = in.fit / totalFit;
    return prob;
}

/*闅忔満鑾峰彇x鐨勫€硷紙0 ~ 10锛�*/
int getRanChromo()
{
    int ch = 0;
    ch = rand() % 10; //鑾峰彇0~10涔嬮棿鐨勯殢鏈烘暟
    return ch;
}

/*鑾峰彇鎬婚€傚簲搴�*/
double getTotalFit(struct individual pop[])
{
    double totalFit = 0;
    for (int i = 0; i < popSize; i++)
        totalFit += pop[i].fit;
    return totalFit;
}

/*鑾峰彇鍒濆绉嶇兢*/
void getInitPop(struct individual pop[])
{
    int ch1, ch2;
    ch1 = ch2 = 0;
    totalFit = 0;
    for (int i = 0; i < popSize; i++)
    {
        ch1 = getRanChromo();
        ch2 = getRanChromo();
        for (int j = len; j > 0; j--)
        {
            pop[i].chromo1[len - j] = floor(ch1 / pow(2, j - 1));
            ch1 = ch1 % (int)pow(2, j - 1);
            pop[i].chromo2[len - j] = floor(ch2 / pow(2, j - 1));
            ch2 = ch2 % (int)pow(2, j - 1);
        }
        pop[i].fit = getFitness(pop[i]);
    }
    totalFit = getTotalFit(pop);
    for (int i = 0; i < popSize; i++)
    {
        pop[i].prob = getProb(pop[i]);
    }
    //鎵撳嵃鍒濆绉嶇兢
    cout << "绗�1浠ｇ缇わ細" << endl;
    popPrintf(pop);
}

/*鍒ゆ柇锛堟潅浜や笌鍙樺紓鎵€寰楋級涓綋鍊兼槸鍚︾鍚堣姹�*/
bool inLegality(individual in)
{
    double x1, x2;
    x1 = getXValue(in.chromo1);
    x2 = getXValue(in.chromo2);
    if (x1 > 10 || x2 > 10)
        return 0;
    else
        return 1;
}

/*閫夋嫨(杞洏寮�)*/
void selection(struct individual pop[])
{
    cout << "  閫夋嫨涓€娆�" << endl;
    lineProb[0] = pop[0].prob;
    for (int i = 1; i < popSize; i++) //绱姒傜巼锛屼娇绉嶇兢鍐呬釜浣撶殑姒傜巼绾挎€у寲
    {
        lineProb[i] = lineProb[i - 1] + pop[i].prob;
    }
    double r = rand() / double(RAND_MAX); //鑾峰彇0~1涔嬮棿闅忔満鏁�
    // cout << "杞洏璧岄殢鏈烘暟锛�" << r << endl;
    for (int j = 0; j < popSize; j++) //鏌ヨ闅忔満鏁板搴旂殑杞洏涓婄殑涓綋
    {
        if (r <= lineProb[j])
        {
            nextPop[nextPopNum] = pop[j];
            nextPopNum++;
            break;
        }
    }
}

/*浜ゅ弶*/
void crossover(struct individual pop[])
{
    double r1;
    int r2, r3, r4;
    bool a, b;
    r1 = rand() / double(RAND_MAX); //鑾峰彇0~1涔嬮棿闅忔満鏁�
    if (r1 <= Pc)
    {
        r2 = (rand() % (popSize));
        r3 = (rand() % (popSize));
        r4 = (rand() % (len));

        if (nextPopNum + 1 > popSize - 1) //褰撳墠鏂扮缇ゅ彧鍓╀竴涓綅缃�
        {
            cout << "  浜ゅ弶涓€娆★紝浜х敓涓€涓柊涓綋" << endl;
            nextPop[nextPopNum] = pop[r2];
            for (int i = r4; i < len; i++)
            {
                nextPop[nextPopNum].chromo1[i] = pop[r3].chromo1[i];
                nextPop[nextPopNum].chromo2[i] = pop[r3].chromo2[i];
            }
            nextPop[nextPopNum].fit = getFitness(nextPop[nextPopNum]); //鏇存柊涓綋閫傚簲搴�
            if (inLegality(nextPop[nextPopNum]))                       //鍒ゆ柇鏂颁釜浣撳€兼槸鍚﹀悎娉�
                nextPopNum++;
            else
                nextPopNum--;
        }
        else //鏂扮缇や腑鍓╀綑绌轰綅澶т簬绛変簬2
        {
            cout << "  浜ゅ弶涓€娆★紝浜х敓浜屼釜鏂颁釜浣�" << endl;
            nextPop[nextPopNum] = pop[r2];
            nextPopNum++;
            nextPop[nextPopNum] = pop[r3];

            //涓や釜涓綋杩涜鏉備氦
            for (int i = r4; i < len; i++)
            {
                a = nextPop[nextPopNum - 1].chromo1[i];
                nextPop[nextPopNum - 1].chromo1[i] = nextPop[nextPopNum].chromo1[i];
                nextPop[nextPopNum].chromo1[i] = a;

                b = nextPop[nextPopNum - 1].chromo2[i];
                nextPop[nextPopNum - 1].chromo2[i] = nextPop[nextPopNum].chromo2[i];
                nextPop[nextPopNum].chromo2[i] = b;
            }
            //鏇存柊閫傚簲搴�
            nextPop[nextPopNum - 1].fit = getFitness(nextPop[nextPopNum - 1]);
            nextPop[nextPopNum].fit = getFitness(nextPop[nextPopNum]);

            //鍒ゆ柇鏂颁釜浣撳€兼槸鍚﹀悎娉�
            if (!inLegality(nextPop[nextPopNum - 1]))
            {
                if (!inLegality(nextPop[nextPopNum]))
                    nextPopNum--;
                else
                    nextPop[nextPopNum - 1] = nextPop[nextPopNum];
            }
            else
            {
                if (inLegality(nextPop[nextPopNum]))
                    nextPopNum++;
            }
        }
    }
    else
        cout << "  姝ゆ鏈繘琛屼氦鍙�" << endl;
}

/*鍙樺紓*/
void mutataion(struct individual pop[])
{
    double m1;
    int m2, m3;
    m1 = rand() / double(RAND_MAX); //鑾峰彇0~1涔嬮棿闅忔満鏁�
    if (m1 < Pm)
    {
        cout << "  鍙樺紓涓€娆★紝浜х敓涓€涓柊涓綋" << endl;
        m2 = (rand() % (popSize));
        m3 = (rand() % (len));
        nextPop[nextPopNum] = pop[m2];

        //鍙栧弽
        if (nextPop[nextPopNum].chromo1[m3] == 1)
            nextPop[nextPopNum].chromo1[m3] = 0;
        else
            nextPop[nextPopNum].chromo1[m3] = 1;

        //鍒ゆ柇鏂颁釜浣撳€兼槸鍚﹀悎娉�
        if (inLegality(nextPop[nextPopNum]))
            nextPopNum++;
        else
            nextPopNum--;
    }
    else
        cout << "  姝ゆ鏈繘琛屽彉寮�" << endl;
}

/*杩涘寲*/
void evolution()
{
    gen++;
    cout << "绗�" << gen << "浠ｇ缇わ細" << endl;
    //閬椾紶鎿嶄綔
    while (nextPopNum < popSize)
    {
        selection(pop);
        if (nextPopNum == popSize)
            break;
        crossover(pop);
        if (nextPopNum == popSize)
            break;
        mutataion(pop);
        if (nextPopNum == popSize)
            break;
    }
    //鏇存柊閫夋嫨姒傜巼
    totalFit = getTotalFit(nextPop);
    for (int i = 0; i < popSize; i++)
        nextPop[i].prob = getProb(nextPop[i]);

    //鎵撳嵃鏂扮缇�
    popPrintf(nextPop);

    //鏇存柊绉嶇兢瀛樺偍绌洪棿
    for (int i = 0; i < popSize; i++)
        pop[i] = nextPop[i];
    nextPopNum = 0;
}

/*鎵撳嵃绉嶇兢*/
void popPrintf(struct individual pop[])
{
    for (int i = 0; i < popSize; i++)
    {
        for (int j = 0; j < len; j++)
            cout << pop[i].chromo1[j];
        cout << " ";
        for (int j = 0; j < len; j++)
            cout << pop[i].chromo2[j];
        cout << " ";
        cout << setw(10) << left << pop[i].fit;
        cout << " ";
        cout << pop[i].prob;
        cout << endl;
    }
}
