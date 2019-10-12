### 埃博拉来袭

**描述**

A国出现了埃博拉疫情，第1天有N人被感染。每个病人在被感染的第2天开始感染其它健康人，每个病人每天可以感染X个健康人，病人在被感染的第Y天死去（死去的当天不再感染他人，也不计入当天存活人数）。求出第K天时，该国有多少被感染且活着的病人？

**关于输入**

输入的第一行为3个整数，用空格分隔：N，第1天的感染人数，0 < N < 10；X，每人每天感染健康人的数量，0 < X < 10；Y，病人被感染到死去的天数，2 < Y < 10。
输入的第二行为1个整数K，即欲求感染人数的日期，0 < K < 10。

**关于输出**

输出为1行，输出第K天时该国被感染且活着的病人的总数。

```cpp
#include <iostream>
using namespace std;

int main()
{
    int sick[100] = {0};
    int N, X, Y, K, cnt;
    cin >> N >> X >> Y >> K;
    sick[0] = N;
    cnt = N;
    for (int i = 1; i < K; i++)
    {
        if (i >= Y - 1)     // People die...
            cnt -= sick[i-Y+1];
        sick[i] = cnt * X;  // People get sick...
        cnt += sick[i];
    }
    cout << cnt << endl;
    return 0;
}
```

### 统计满足条件的数

**描述**

编写程序，读入若干个四位数（小于30），求出其中满足以下条件的数的个数：

个位数上的数字减去千位数上的数字，再减去百位数上的数字， 再减去十位数上的数字的结果大于零。

**关于输入**

输入为两行，第一行为四位数的个数，第二行为要读入的四位数

**关于输出**

输出为一行，即满足条件的四位数的个数

```cpp
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
```

### 求e

**描述**

给出n的值, 计算公式 e = 1 + 1/1! + 1/2! + 1/3! + 1/4! + … + 1/n!

**关于输入**

只有一个输入，即n的值, n>=1, 且n为整数

**关于输出**

按照上述公式求出的e的值（精确到小数点后6位）

```cpp
#include <cstdio>
using namespace std;

int main()
{
    int n;
    double val = 1., frac = 1.;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        val += 1. / frac;
        frac *= (i + 1);
    }
    printf("%.6lf\n", val);
    return 0;
}
```

### 鸡尾酒疗法

**描述**

鸡尾酒疗法，原指“高效抗逆转录病毒治疗”（HAART），由美籍华裔科学家何大一于1996年提出，是通过三种或三种以上的抗病毒药物联合使用来治疗艾滋病。该疗法的应用可以减少单一用药产生的抗药性，最大限度地抑制病毒的复制，使被破坏的机体免疫功能部分甚至全部恢复，从而延缓病程进展，延长患者生命，提高生活质量。人们在鸡尾酒疗法的基础上又提出了很多种改进的疗法。为了验证这些治疗方法是否在疗效上比鸡尾酒疗法更好，可用通过临床对照实验的方式进行。假设鸡尾酒疗法的有效率为x，新疗法的有效率为y，如果y-x大于5%，则效果更好，如果x-y大于5%，则效果更差，否则称为效果差不多。下面给出n组临床对照实验，其中第一组采用鸡尾酒疗法，其他n-1组为各种不同的改进疗法。请写程序判定各种改进疗法效果如何。

**关于输入**

第一行为整数n；

其余n行每行两个整数，第一个整数是临床实验的总病例数，第二个疗效有效的病例数。

这n行数据中，第一行为鸡尾酒疗法的数据，其余各行为各种改进疗法的数据。

**关于输出**

有n-1行输出，分别表示对应改进疗法的效果：

如果效果更好，输出better；如果效果更差，输出worse；否则输出same

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n;
    double total, valid, cocktail, therapy;
    cin >> n;
    cin >> total >> valid;
    cocktail = valid / total;
    for (int i = 1; i < n; i++)
    {
        cin >> total >> valid;
        therapy = valid / total;
        if (therapy - cocktail > 0.05)
            cout << "better" << endl;
        else if (therapy - cocktail < -0.05)
            cout << "worse" << endl;
        else
            cout << "same" << endl;
        
    }
    return 0;
}
```

### 生日蛋糕

**描述**

生日蛋糕上有三棵草莓，小F想把蛋糕切成形状完全相同的三块，并且每一块上都有一个草莓。你可以把草莓看成一个点，切块的时候不能切中草莓。请问能否切成满足相同的三块？

**关于输入**

第一行包含一个整数t表示有t组测试数据。

每组测试数据一行，包含7个整数：r x1 y1 x2 y2 x3 y3，r表示蛋糕半径，(x1,y1)(x2,y2)(x3,y3)表示三个草莓的位置（以圆心为坐标轴原点）。

**关于输出**

对每组数据输出一行。

如果能够切成全等的三块并且每块上有一个草莓，输出"Yes"，否则输出"No"

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main()
{   int n;
    cin >> n;
    int r;
    double x1, y1, x2, y2, x3, y3;
    double r1, r2, r3, c1, c2, c3;
    double cos1, cos2, cos3;

    int counter=0;
    for(int i = 0; i < n; i++)
    {
        cin >> r >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        /* Compute cosine values... */
        r1 = sqrt(pow(x1, 2)+pow(y1, 2));
        r2 = sqrt(pow(x2, 2)+pow(y2, 2));
        r3 = sqrt(pow(x3, 2)+pow(y3, 2));
        c1 = sqrt(pow(x2-x3, 2)+pow(y2-y3, 2));
        c2 = sqrt(pow(x3-x1, 2)+pow(y3-y1, 2));
        c3 = sqrt(pow(x1-x2, 2)+pow(y1-y2, 2));
        cos1 = (pow(r2, 2)+pow(r3, 2)-pow(c1, 2))/(2*r2*r3);
        cos2 = (pow(r3, 2)+pow(r1, 2)-pow(c2, 2))/(2*r3*r1);
        cos3 = (pow(r1, 2)+pow(r2, 2)-pow(c3, 2))/(2*r1*r2);
        /* If the strawberry is at the center... */
        if ((x1 == 0 && y1 == 0) || (x2 == 0 && y2 == 0)
            || (x3 == 0 && y3 == 0))
            cout << "No" << endl;
        else if (cos1>=-0.5 && cos2>=-0.5 && cos3>=-0.5)
            cout << "No" << endl;
        else
            cout << "Yes"<< endl;
    }
    return 0;
}
```

