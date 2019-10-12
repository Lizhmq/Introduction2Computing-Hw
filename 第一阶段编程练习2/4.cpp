/*****
 * 描述
给定一个数组，数组长度小于1000，统计前k大的数并且把这k个数从大到小输出。
 * 关于输入
先输入一个n表示数组的长度，然后连续地输入n个数。最后输入一个k。
 * 关于输出
换行输出前k大的数
*****/

#include <iostream>
using namespace std;

#define N 1010

int arr[N], n, k;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[j] < arr[i])
            {
                arr[j] = arr[j] ^ arr[i];
                arr[i] = arr[j] ^ arr[i];
                arr[j] = arr[j] ^ arr[i];
            }
    cin >> k;
    for (int i = 0; i < k; i++)
        cout << arr[i] << endl;
    return 0;
}