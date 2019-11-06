/*****
 * 描述
北医三院近期开展了最受欢迎的医生评选活动，评选规则是：请患者及其家属给自己最喜欢的医生投票（每位参加评选的医生有一个相应的编号），票数最多的医生评选为年度最受欢迎医生，奖励年终休假一个月。
 * 关于输入
输入为两行，第一行为投票的总数n（0 < n <= 100），第二行为投票情况（医生编号均为整数,最大不超过15）
 * 关于输出
输出最受欢迎的医生的编号
*****/

#include <iostream>
using namespace std;

#define MAX_DOC 16

int main()
{
    int n, vote[MAX_DOC] = {0}, max = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        vote[tmp]++;            // Vote for the corresponding dotor.
        if (vote[tmp] > max)    // Update "max" immediately.
            max = vote[tmp];
    }
    /* Find the most popular doctor. */
    for (int i = 0; i < MAX_DOC; i++)
        if (vote[i] == max)
        {
            cout << i << endl;
            break;
        }
    return 0;
}