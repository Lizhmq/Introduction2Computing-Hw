/*****
 * 描述
A国出现了埃博拉疫情，第1天有N人被感染。每个病人在被感染的第2天开始感染其它健康人，每个病人每天可以感染X个健康人，病人在被感染的第Y天死去（死去的当天不再感染他人，也不计入当天存活人数）。求出第K天时，该国有多少被感染且活着的病人？
 * 关于输入
输入的第一行为3个整数，用空格分隔：N，第1天的感染人数，0 < N < 10；X，每人每天感染健康人的数量，0 < X < 10；Y，病人被感染到死去的天数，2 < Y < 10。
输入的第二行为1个整数K，即欲求感染人数的日期，0 < K < 10。
 * 关于输出
输出为1行，输出第K天时该国被感染且活着的病人的总数。
*****/

#include <iostream>
using namespace std;

int main()
{
    int sick[100] = {0};
    int N, X, Y, K, cnt;
    cin >> N >> X >> Y >> K;
    sick[0] = N;
    cnt = N;
    for (int i = 1; i < K; i++)
    {
        if (i >= Y - 1)     // People die...
            cnt -= sick[i-Y+1];
        sick[i] = cnt * X;  // People get sick...
        cnt += sick[i];
    }
    cout << cnt << endl;
    return 0;
}