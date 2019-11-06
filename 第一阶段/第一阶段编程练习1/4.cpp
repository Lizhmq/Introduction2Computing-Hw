/*****
 * 描述
输入一个整数，判断它能否被3，5，7整除，并输出以下信息：
（1）能同时被3，5，7整除（直接输出3 5 7，每个数中间一个空格）；
（2）能被其中两个数整除（输出两个数，小的在前，大的在后。例如：3 5或者 3 7或者5 7,中间用空格分隔）
（3）能被其中一个数整除（输出这个除数）
（4）不能被任何数整除；（输出小写字符n)
 * 关于输入
一个整数
 * 关于输出
实现题目的要求
*****/

#include <iostream>
using namespace std;

#define N_NUM 3

int main()
{
    int num, arr[N_NUM] = {3, 5, 7};
    bool found = false; // Whether we have found a number.
    cin >> num;
    for (int i = 0; i < N_NUM; i++)
        if (num % arr[i] == 0)
        {
            if (found)  // If we have already found a number,
                cout << " " << arr[i];  // use a space to seperate.
            else
            {
                cout << arr[i]; // Otherwise, this if the first number.
                found = true;   // Do not use space, and set the "found" flag.
            }
        }
    if (!found) // Cannot find any number.
        cout << "n";
    cout << endl;
    return 0;
}