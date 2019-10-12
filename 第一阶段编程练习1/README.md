### 房价 vs 年薪

**描述**
小袁同学今年刚毕业，成为了一名光荣的程序员。他找了一份工作，年薪是X万元，并且公司保证每年给他固定加薪8%。 小袁同学很开心，他看上了一套房子，售价是M万元，于是下决心攒钱买下。假设房子的价格每年稳定上涨10%，再假设小袁不吃不喝，把所有的钱都存下来买房。
那么请你帮他算算，他多少年后可以买的起这套房子？
如果100年内(含100年) 都不可能的话，则输出“Forget it.”

**关于输入**
一共有2行。
第一行是一个整数X，表示小袁同学的初始年薪；
第二行是一个整数M，表示房子的售价。

**关于输出**
如果有解，输出一个整数N，表示第N年小袁可以攒够钱买房子；
如果解大于100或者无解，则输出“Forget it.”

```cpp
#include <iostream>
using namespace std;

int main()
{
    double salary, saving = 0, price;
    int year = 1;
    cin >> salary >> price;
    do
    {
        /* Save some money. */
        saving += salary;
        /* See if he can buy the house. */
        if (saving >= price)
        {
            /* Buy the house and return. */
            cout << year << endl;
            return 1;
        }
        /* One more year... */
        /* Raise both salary and house price. */
        salary *= 1.08;
        price *= 1.1;
        year++;
    } while (year <= 100); // 100 years later...
    cout << "Forget it." << endl;
    return 0;
}
```

### 北京地铁

**描述**
北京地铁涨价了，现在的地铁票价计算方法如下：
6公里内 3元 （包括6公里）
6-12 公里 4元 （不包括6公里，包括12公里）
12-32 公里 每10公里加1元（不包括12公里，包括32公里，不满10公里按10公里算）
32公里以上 每20公里加1元（不包括32公里，不满20公里按20公里算）
比如，50公里时，需要 4+2+1=7元

同时，北京地铁也给出了优惠方案：
每个自然月内，使用交通卡满100元，则票价可打8折；满150元，则票价可打5折；满400元，则票价不打折。

现在，小明有一张公交卡，小明想知道自己现在坐地铁的票价是多少？请你写程序完成这个功能。

**关于输入**
输入有两个整数，一个是小明现在这个月的累计消费，一个是小明本次乘坐的里程数

**关于输出**
输出为本次乘坐的票价，保留两位小数

```cpp
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int x, d;
    double p = 0;
    scanf("%d%d", &x, &d);
    /* Determine the original price. */
    if (d <= 6)
        p = 3;
    else if (d <= 12)
        p = 4;
    else if (d <= 32)
        p = 4 + ceil(double(d-12)/10);
    else 
        p = 4 + 2 + ceil(double(d-32)/20);
    /* Consider discounts. */
    if (x < 100)
        ;
    else if (x < 150)
        p *= 0.8;
    else if (x < 400)
        p *= 0.5;
    else
        ;
    printf("%.2lf\n", p);
    return 0;
}
```

### 点和正方形

**描述**
有一个正方形，四个角的坐标（x,y)分别是（1，-1），（1，1），（-1，1），（-1，-1），x是横轴，y是纵轴。写一个程序，判断一个给定的点是否在这个正方形内。

**关于输入**
输入坐标x，y

**关于输出**
点在正方形内，输出yes；点在正方形外，输出no

```cpp
#include <cstdio>
using namespace std;

int main()
{
    double x, y;
    scanf("%lf,%lf", &x, &y);
    if (x < 1 && x > -1 && y < 1 && y > -1)
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}
```

### 能被3，5，7整除的数

**描述**
输入一个整数，判断它能否被3，5，7整除，并输出以下信息：
（1）能同时被3，5，7整除（直接输出3 5 7，每个数中间一个空格）；
（2）能被其中两个数整除（输出两个数，小的在前，大的在后。例如：3 5或者 3 7或者5 7,中间用空格分隔）
（3）能被其中一个数整除（输出这个除数）
（4）不能被任何数整除；（输出小写字符n)

**关于输入**
一个整数

**关于输出**
实现题目的要求

```cpp
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
```

### 最受欢迎的医生

**描述**
北医三院近期开展了最受欢迎的医生评选活动，评选规则是：请患者及其家属给自己最喜欢的医生投票（每位参加评选的医生有一个相应的编号），票数最多的医生评选为年度最受欢迎医生，奖励年终休假一个月。

**关于输入**
输入为两行，第一行为投票的总数n（0 < n <= 100），第二行为投票情况（医生编号均为整数,最大不超过15）

**关于输出**
输出最受欢迎的医生的编号

```cpp
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
```

### 斐波那契数列

**描述**
菲波那契数列是指这样的数列: 数列的第一个和第二个数都为1，接下来每个数都等于前面2个数之和。
给出一个正整数a，要求菲波那契数列中第a个数是多少。

**关于输入**
第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数a(1 <= a <= 20)

**关于输出**
n行，每行输出对应一个输入。输出应是一个正整数，为菲波那契数列中第a个数的大小

```cpp
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
```

