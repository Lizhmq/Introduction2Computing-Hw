/*****
 * 描述
给出n的值, 计算公式 e = 1 + 1/1! + 1/2! + 1/3! + 1/4! + … + 1/n!
 * 关于输入
只有一个输入，即n的值, n>=1, 且n为整数
 * 关于输出
按照上述公式求出的e的值（精确到小数点后6位）
*****/

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