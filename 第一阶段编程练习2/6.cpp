/*****
 * 描述
小朋友玩跳绳比赛,要计算在一分钟内跳了多少下.假设每秒钟跳一下,如果中途失败了,则要花三秒钟后才能开始重跳.一般小朋友跳绳一分钟要跳坏好几次.现在给出小朋友每次跳坏时已经跳的总数,求该小朋友在一分钟内能跳多少下.
 * 关于输入
输入有一行
第一个整数是跳坏的次数m(m<20),其余m个整数是跳坏时累计跳了多少下.
 * 关于输出
输出有一行
输出小朋友头一分钟内跳了多少下.
*****/

#include <iostream>
using namespace std;

#define MINUTE 60

int cnt[100] = {0}; // Count per second
int curr = 0;       // Current time (sec)

int main()
{
    int n, br;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> br;
        if (curr > MINUTE)  // Already out of time.
            continue;       // Ignore...
        /* Jump until reaching the break point. */
        while(cnt[curr] < br)
        {
            cnt[curr+1] = cnt[curr] + 1;
            curr++;
        }
        /* Wait for 3 seconds. */
        cnt[curr+1] = cnt[curr];
        cnt[curr+2] = cnt[curr];
        cnt[curr+3] = cnt[curr];
        curr += 3;
    }
    /* Fill the minute. */
    for (; curr <= MINUTE; curr++)
        cnt[curr+1] = cnt[curr] + 1;
    cout << cnt[MINUTE] << endl;
    return 0;
}