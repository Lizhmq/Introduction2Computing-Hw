### 最大最小数之差

**描述**

给定三个整数，求这三个数中最大值与最小值之差。

**关于输入**

只有一行，包括待处理的三个整数。

**关于输出**

一共一行，输出最大数减去最小数的差。

```cpp
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
```

### 石头剪子布

**描述**

石头剪子布是一种很简单的游戏：

石头胜剪子

剪子胜布

布胜石头

A和B猜拳，已知他们出拳的序列，编程求出谁胜谁负。

**关于输入**

第一行是一个正整数n(n<200)，表明A和B一共猜了n次拳。

接下来是n行，每行有两个数字，分别表示A和B在这次猜拳中出了什么。0表示石头，1表示剪刀，2表示布

**关于输出**

输出一行，"A"表示A胜，"B"表示B胜，"Tie"表示平局。

```cpp
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
```

### 不与最大数相同的数字之和

**描述**

输出一个整数数列中不与最大数相同的数字之和

**关于输入**

输入分为两行：

第一行为N(N为接下来数字的个数，N<=100)；

第二行为N个整数，以空格隔开；

**关于输出**

输出为N个数中除去最大数其余数字之和。（注意，最大数可能出现多次）

```cpp
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
```

### 输出前k大的数

**描述**

给定一个数组，数组长度小于1000，统计前k大的数并且把这k个数从大到小输出。

**关于输入**

先输入一个n表示数组的长度，然后连续地输入n个数。最后输入一个k。

**关于输出**

换行输出前k大的数

```cpp
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
```

### 人民币支付

**描述**

从键盘输入一指定金额（以元为单位，如345），然后输出支付该金额的各种面额的人民币数量，显示100元，50元，20元，10元，5元，1元各多少张，要求尽量使用大面额的钞票。

**关于输入**

一个小于1000的正整数。

**关于输出**

输出分行，每行显示一个整数，从上到下分别表示100元，50元，20元，10元，5元，1元人民币的张数

```cpp
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
```

### 跳绳统计

**描述**

小朋友玩跳绳比赛,要计算在一分钟内跳了多少下.假设每秒钟跳一下,如果中途失败了,则要花三秒钟后才能开始重跳.一般小朋友跳绳一分钟要跳坏好几次.现在给出小朋友每次跳坏时已经跳的总数,求该小朋友在一分钟内能跳多少下.

**关于输入**

输入有一行
第一个整数是跳坏的次数m(m<20),其余m个整数是跳坏时累计跳了多少下.

**关于输出**

输出有一行
输出小朋友头一分钟内跳了多少下.

```cpp
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
```

