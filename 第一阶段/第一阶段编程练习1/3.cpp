/*****
 * 描述
有一个正方形，四个角的坐标（x,y)分别是（1，-1），（1，1），（-1，1），（-1，-1），x是横轴，y是纵轴。写一个程序，判断一个给定的点是否在这个正方形内。
 * 关于输入
输入坐标x，y
 * 关于输出
点在正方形内，输出yes；点在正方形外，输出no
*****/

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