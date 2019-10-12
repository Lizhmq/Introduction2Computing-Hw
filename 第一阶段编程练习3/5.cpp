/*****
 * 描述
生日蛋糕上有三棵草莓，小F想把蛋糕切成形状完全相同的三块，并且每一块上都有一个草莓。你可以把草莓看成一个点，切块的时候不能切中草莓。请问能否切成满足相同的三块？

 * 关于输入
第一行包含一个整数t表示有t组测试数据。
每组测试数据一行，包含7个整数：r x1 y1 x2 y2 x3 y3，r表示蛋糕半径，(x1,y1)(x2,y2)(x3,y3)表示三个草莓的位置（以圆心为坐标轴原点）。
 * 关于输出
对每组数据输出一行。
如果能够切成全等的三块并且每块上有一个草莓，输出"Yes"，否则输出"No"
*****/

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