/*****
 * 描述
菲波那契数列是指这样的数列: 数列的第一个和第二个数都为1，接下来每个数都等于前面2个数之和。
给出一个正整数a，要求菲波那契数列中第a个数是多少。
 * 关于输入
第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数a(1 <= a <= 20)
 * 关于输出
n行，每行输出对应一个输入。输出应是一个正整数，为菲波那契数列中第a个数的大小
*****/

#include <iostream>
using namespace std;

#define N_FAB 30

int main()
{
    int fab[N_FAB] = {1,1}, n, a;
    /* Compute the fabonacci sequence at first. */
    for (int i = 2; i < N_FAB; i++)
        fab[i] = fab[i-1] + fab[i-2];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        /* Print each required number. */
        cin >> a;
        cout << fab[a-1] <<endl;
    }
    return 0;
}