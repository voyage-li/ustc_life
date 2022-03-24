#include <bits/stdc++.h>

int N, M, price;
std::stack<std::pair<int, int>> park;
std::queue<std::pair<int, int>> wait;
std::map<int, int> in_time;

void come();
void leave();
void park_search();
void wait_search();
void end();

int main()
{
    freopen("./bin/Parking.txt", "r", stdin);

    std::cout << "请输入停车站容量，便道容量，单位停车价格" << std::endl;
    std::cin >> N >> M >> price;
    std::cout << N << ' ' << M << ' ' << price << std::endl;

    std::cout << "请输入操作： 车牌号： 时间" << std::endl;

    char c = getchar(); //过滤换行

    char OPE;

    while (1)
    {
        OPE = getchar();
        switch (OPE)
        {
        case 'A':
            come();
            break;
        case 'D':
            leave();
            break;
        case 'P':
            park_search();
            break;
        case 'W':
            wait_search();
            break;
        case 'E':
            end();
            break;
        }
        if (OPE == 'E')
            break;
        getchar();
    }
    fclose(stdin);
    return 0;
}

void come()
{
    int num, time;
    std::cin >> num >> time;
    std::cout << "A " << num << ' ' << time << std::endl;
    if (park.size() < N)
    {
        park.push(std::make_pair(num, time));
        std::cout << "车辆" << num << "停放在停车场上第" << park.size() << "个位置" << std::endl;
        in_time[num] = time;
    }
    else if (wait.size() < M)
    {
        wait.push(std::make_pair(num, time));
        std::cout << "车辆" << num << "停放在便道第" << wait.size() << "个位置" << std::endl;
    }
    else
    {
        std::cout << "停车场和便道都没有地方可以停放" << std::endl;
    }
}
void leave()
{
    int num, time;
    std::cin >> num >> time;
    std::cout << "D " << num << ' ' << time << std::endl;
    std::stack<std::pair<int, int>> temp;
    while (!park.empty())
    {
        if (park.top().first == num)
        {
            int park_time = time - in_time[num];
            std::cout << "停留时间：" << park_time << std::endl;
            std::cout << "收费：" << park_time * price << std::endl;
        }
        else
            temp.push(park.top());
        park.pop();
    }

    while (!temp.empty())
    {
        park.push(temp.top());
        std::cout << "车辆" << temp.top().first << "停放在停车场上第" << park.size() << "个位置" << std::endl;
        temp.pop();
    }
    if (park.size() == N - 1 && !wait.empty())
    {
        park.push(wait.front());
        std::cout << "车辆" << wait.front().first << "停放在停车场上第" << park.size() << "个位置" << std::endl;
        in_time[wait.front().first] = time;
        wait.pop();
    }
}
void park_search()
{
    int num, time;
    std::cin >> num >> time;
    std::cout << "P" << std::endl;
    std::cout << "停车场：" << std::endl;
    std::stack<std::pair<int, int>> temp;
    while (!park.empty())
    {
        temp.push(park.top());
        park.pop();
    }
    while (!temp.empty())
    {
        park.push(temp.top());
        std::cout << "车辆" << temp.top().first << "到达时间：" << temp.top().second << std::endl;
        temp.pop();
    }
}
void wait_search()
{
    int num, time;
    std::cin >> num >> time;
    std::cout << "W" << std::endl;
    std::cout << "通道：" << std::endl;
    std::queue<std::pair<int, int>> temp;
    while (!wait.empty())
    {
        temp.push(wait.front());
        wait.pop();
    }
    while (!temp.empty())
    {
        wait.push(temp.front());
        std::cout << "车辆" << temp.front().first << "到达时间：" << temp.front().second << std::endl;
        temp.pop();
    }
}
void end()
{
    int num, time;
    std::cin >> num >> time;
    std::cout << "E" << std::endl;
}