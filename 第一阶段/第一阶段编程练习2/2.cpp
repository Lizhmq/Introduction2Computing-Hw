/*****
 * 描述
石头剪子布是一种很简单的游戏：
石头胜剪子
剪子胜布
布胜石头
A和B猜拳，已知他们出拳的序列，编程求出谁胜谁负。
 * 关于输入
第一行是一个正整数n(n<200)，表明A和B一共猜了n次拳。
接下来是n行，每行有两个数字，分别表示A和B在这次猜拳中出了什么。0表示石头，1表示剪刀，2表示布。
 * 关于输出
输出一行，"A"表示A胜，"B"表示B胜，"Tie"表示平局。
*****/

#include<iostream>
using namespace std;

int main()
{
    int n, a, b, win=0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        switch ((a-b+3)%3)
        {
            case 0: break;
            case 1: win++; break;
            case 2: win--; break;
            default: break;
        }
    }
    if (win < 0)
        cout << "A" << endl;
    else if (win > 0)
        cout << "B" << endl;
    else
        cout << "Tie" << endl;
    return 0;
}