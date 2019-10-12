#include <cstdio>
using namespace std;

int main()
{
    float a;
    /* Take multiple cases as input. */
    while(scanf("%f", &a) != EOF)
    {
        /* Take the opposite if the number is negative. */
        if (a < 0)
            a = -a;
        /* Special case: 0. */
        if (a == 0)
            printf("0.00\n");
        else
            printf("%.2f\n", a);
    }
    return 0;
}
