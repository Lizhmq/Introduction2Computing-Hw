/*****
 * 描述
给定三个整数，求这三个数中最大值与最小值之差。
 * 关于输入
只有一行，包括待处理的三个整数。
 * 关于输出
一共一行，输出最大数减去最小数的差。
*****/

#include<iostream>
using namespace std;

int main()
{
    int max, min, a;
    cin >> max >> min;
    if (max < min)
    {
        max = max ^ min;
        min = max ^ min;
        max = max ^ min;
    }
    cin >> a;
    if (max < a)
    {
        max = max ^ a;
        a = max ^ a;
        max = max ^ a;
    }
    if (min > a)
    {
        min = min ^ a;
        a = min ^ a;
        min = min ^ a;
    }
    cout << max - min << endl;
    return 0;
}