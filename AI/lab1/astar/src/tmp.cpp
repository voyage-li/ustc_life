#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

// 定义拨轮结构体
struct Dial
{
    int row;
    int col;
    int direction;
    Dial(int a, int b, int c) : row(a), col(b), direction(c) {}
};

// 定义状态结构体
struct State
{
    // 改成bool型的锁盘状态
    vector<vector<bool>> lock; // 锁盘状态
    double steps;              // 拨动步数
    Dial dial;                 // 拨动的拨轮,父状态的拨轮
    double heuristic;          // 启发式函数的值
    // 父指针
    State *parent = NULL;
    State(double Steps, vector<vector<bool>> Lock, int a, int b, int c) : steps(Steps), lock(Lock), dial(a, b, c) {}
};
// 定义优先队列的比较函数
struct Compare
{
    bool operator()(const State *s1, const State *s2)
    {
        return s1->steps + s1->heuristic > s2->steps + s2->heuristic; // 比较两个状态的启发式函数的值
    }
};

// 检查拨轮是否在锁盘内
bool isValid(int row, int col, int N)
{
    return (row >= 0 && row < N && col >= 0 && col < N); // 在轮盘内的条件：行列都在0~N-1之间
}

// 获取下一个状态的拨轮位置和朝向
void getNextDial(int s, int row, int col, int &nextRow1, int &nextCol1, int &nextRow2, int &nextCol2)
{
    if (s == 1)
    {
        nextRow1 = row;
        nextCol1 = col + 1;
        nextRow2 = row - 1;
        nextCol2 = col;
    }
    else if (s == 2)
    {
        nextRow1 = row - 1;
        nextCol1 = col;
        nextRow2 = row;
        nextCol2 = col - 1;
    }
    else if (s == 3)
    {
        nextRow1 = row;
        nextCol1 = col - 1;
        nextRow2 = row + 1;
        nextCol2 = col;
    }
    else if (s == 4)
    {
        nextRow1 = row - 1;
        nextCol1 = col;
        nextRow2 = row - 1;
        nextCol2 = col + 1;
    }
    else if (s == 5)
    {
        nextRow1 = row - 1;
        nextCol1 = col;
        nextRow2 = row - 1;
        nextCol2 = col - 1;
    }
    else if (s == 6)
    {
        nextRow1 = row - 1;
        nextCol1 = col;
        nextRow2 = row - 1;
        nextCol2 = col + 1;
    }
    else if (s == 7)
    {
        nextRow1 = row;
        nextCol1 = col + 1;
        nextRow2 = row - 1;
        nextCol2 = col + 1;
    }
    else if (s == 8)
    {
        nextRow1 = row;
        nextCol1 = col + 1;
        nextRow2 = row + 1;
        nextCol2 = col + 1;
    }
    else if (s == 9)
    {
        nextRow1 = row + 1;
        nextCol1 = col;
        nextRow2 = row + 1;
        nextCol2 = col + 1;
    }
    else if (s == 10)
    {
        nextRow1 = row + 1;
        nextCol1 = col;
        nextRow2 = row + 1;
        nextCol2 = col - 1;
    }
    else if (s == 11)
    {
        nextRow1 = row;
        nextCol1 = col - 1;
        nextRow2 = row + 1;
        nextCol2 = col - 1;
    }
    else if (s == 12)
    {
        nextRow1 = row;
        nextCol1 = col - 1;
        nextRow2 = row - 1;
        nextCol2 = col - 1;
    }
}

void get_first_one(int &row, int &col, const vector<vector<bool>> &lock)
// 找第一个1的位置
{
    int N = lock.size();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // if (lock[i][j] == 1)
            if (lock[i][j] == true)
            {
                row = i;
                col = j;
                return;
            }
        }
    }
}

// 计算启发式函数的值

int calculateHeuristic(const vector<vector<bool>> &lock)
{
    int count = 0;
    int tmp_count = 0;
    int N = lock.size();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (lock[i][j] == 1)
            {
                count++;
            }
        }
    }
    tmp_count = count / 3;
    if ((count - tmp_count) % 2 != 0) // 奇偶判断
    {
        tmp_count++;
    }
    // return tmp_count; // 将1的个数除以3作为启发式函数的值
    return count / 3;
    // return 6*count;
}
// A*算法解锁迷锁
vector<Dial> unlockBinaryLock(const vector<vector<bool>> &lock)
{
    int N = lock.size();

    priority_queue<State *, vector<State *>, Compare> pq, pq_temp; // 优先队列，按照Compare中的比较函数进行排序，代价最小的元素排在队头

    // vector<vector<vector<bool>>> pq_history; // 历史状态栈
    set<vector<vector<bool>>> history; // 历史状态栈

    int i, j, nextRow1, nextCol1, nextRow2, nextCol2;
    // 初始化起始状态

    // 把N*N的每一个节点和所有可能的s取值都赋给start，然后push到pq里面去，然后再pop出来，然后再push进去，这样就可以遍历所有的节点了
    get_first_one(i, j, lock);
    for (int s = 1; s <= 12; s++)
    {
        getNextDial(s, i, j, nextRow1, nextCol1, nextRow2, nextCol2);
        // 先检查是否在轮盘内
        if (isValid(nextRow1, nextCol1, N) && isValid(nextRow2, nextCol2, N))
        {
            State *start = new State(0, lock, i, j, s);
            start->lock[i][j] = not(start->lock[i][j]);
            start->lock[nextRow1][nextCol1] = not(start->lock[nextRow1][nextCol1]);
            start->lock[nextRow2][nextCol2] = not(start->lock[nextRow2][nextCol2]);
            start->heuristic = calculateHeuristic(start->lock);
            pq.push(start);
            // count ++;
        }
    }
    int count = 0;
    while (!pq.empty())
    {

        State *curr = pq.top();
        // pq_history.push_back(curr->lock); // 把当前状态存入历史栈
        // 把curr->lock存入history
        history.insert(curr->lock);
        pq.pop();
        count++;
        // cout<<curr->steps<<' '<<curr->heuristic<<endl;
        // for(auto i:curr->lock)
        // {
        //     for(auto j:i)
        //     {
        //         cout<<j<<' ';
        //     }
        //     cout<<endl;
        // }
        // 检查是否达到目标状态
        bool isTarget = true;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (curr->lock[i][j] == 1)
                {
                    isTarget = false; // 存在1，不是目标状态
                    break;
                }
            }
            if (!isTarget)
            {
                break;
            }
        }

        if (isTarget) // 如果是目标状态，就返回解锁步骤
        {
            // 构造解锁步骤
            vector<Dial> steps;
            cout << "count = " << count << endl;
            while (curr->steps >= 0)
            {
                // 将拨轮加入到解锁步骤path中
                steps.push_back(curr->dial); // push_back 函数：在vector的最后添加一个元素
                if (curr->steps == 0)
                    break; // 到达初始状态，退出循环
                // 把curr设置成parent
                curr = curr->parent;
            }

            return steps;
        }
        // 把当前结果的，把N*N的每一个节点和所有可能的s取值都赋给start，然后push到pq里面去
        get_first_one(i, j, curr->lock);
        for (int s = 1; s <= 12; s++)
        {
            getNextDial(s, i, j, nextRow1, nextCol1, nextRow2, nextCol2);
            if (isValid(nextRow1, nextCol1, N) && isValid(nextRow2, nextCol2, N)) // 先检查是否在轮盘内
            {
                State *next = new State(curr->steps + 1, curr->lock, i, j, s); // 使用动态内存分配创建新的 State 对象
                next->parent = curr;
                next->lock[i][j] = not(next->lock[i][j]);
                next->lock[nextRow1][nextCol1] = not(next->lock[nextRow1][nextCol1]);
                next->lock[nextRow2][nextCol2] = not(next->lock[nextRow2][nextCol2]);
                next->heuristic = calculateHeuristic(next->lock);
                // 不在history中的状态才能入队
                if (history.find(next->lock) == history.end())
                // if (find(pq_history.begin(), pq_history.end(), next->lock) == pq_history.end())
                {
                    pq.push(next);
                }
                // pq.push(next);
            }
        }
    }

    // 无法解锁，返回空向量
    return vector<Dial>();
}

// 输出解锁步骤
void printSteps(const vector<Dial> &steps)
{
    int T = steps.size();
    cout << T << endl;
    for (int i = 0; i < T; i++)
    {

        cout << steps[i].row << "," << steps[i].col << "," << steps[i].direction;
        cout << endl;
    }
}

int main()
{

    int N;
    cin >> N;
    // 改成bool类型
    vector<vector<bool>> lock(N, vector<bool>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int value;
            cin >> value;
            lock[i][j] = (value != 0);
        }
    }
    vector<Dial> steps = unlockBinaryLock(lock);
    if (steps.empty())
    {
        cout << "No valid solution." << endl;
    }
    else
    {
        printSteps(steps);
    }
    return 0;
}