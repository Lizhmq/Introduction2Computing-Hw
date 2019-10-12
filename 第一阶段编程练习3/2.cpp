/*****
 * 描述
编写程序，读入若干个四位数（小于30），求出其中满足以下条件的数的个数：

个位数上的数字减去千位数上的数字，再减去百位数上的数字， 再减去十位数上的数字的结果大于零。
 * 关于输入
输入为两行，第一行为四位数的个数，第二行为要读入的四位数
 * 关于输出
输出为一行，即满足条件的四位数的个数
*****/

#include<iostream>
using namespace std;

int main()
{
    int n, num, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if ((num%10)-(num/1000)-(num/100%10)-(num/10%10)>0)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}