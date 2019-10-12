/*****
 * 描述
从键盘输入一指定金额（以元为单位，如345），然后输出支付该金额的各种面额的人民币数量，显示100元，50元，20元，10元，5元，1元各多少张，要求尽量使用大面额的钞票。
 * 关于输入
一个小于1000的正整数。
 * 关于输出
输出分行，每行显示一个整数，从上到下分别表示100元，50元，20元，10元，5元，1元人民币的张数
*****/

#include <iostream>
using namespace std;

#define N_VALUE 6

int value[N_VALUE] = {100, 50, 20, 10, 5, 1};

int main()
{
    int money;
    cin >> money;
    for (int i = 0; i < N_VALUE; i++)
    {
        cout << money / value[i] << endl;
        money %= value[i];
    }
    return 0;
}