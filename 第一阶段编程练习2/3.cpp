/*****
 * 描述
输出一个整数数列中不与最大数相同的数字之和
 * 关于输入
输入分为两行：
第一行为N(N为接下来数字的个数，N<=100)；
第二行为N个整数，以空格隔开；
 * 关于输出
输出为N个数中除去最大数其余数字之和。（注意，最大数可能出现多次）
*****/

#include <iostream>
using namespace std;

int main()
{
    int n, num, max = -1000000, sum = 0, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        sum += num;
        if (max < num)
        {
            max = num;
            cnt = 1;
        }
        else if (max == num)
            cnt++;
    }
    cout << sum - max * cnt << endl;
    return 0;
}