### 两数之和

```cpp
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    cout << "The sum is " << a + b << endl;
    return 0;
}
```

### 最大数输出

```cpp
#include <iostream>
using namespace std;

int main()
{
    int max, num;
    /* Take the larger one from the
         first two numbers. */
    cin >> max >> num;
    if (num > max)
        max = num;
    cin >> num;
    /* Compare with the third number,
         and get the largest number. */
    if (num > max)
        max = num;
    cout << max << endl;
    return 0;
}
```

### 简单计算器

```cpp
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    char ch;
    cin >> a >> b >> ch;
    switch(ch)
    {
        /* Addition. */
        case '+': cout << a + b << endl; break;
        /* Subtraction. */
        case '-': cout << a - b << endl; break;
        /* Multiplication. */
        case '*': cout << a * b << endl; break;
        /* Division. */
        case '/':
            /* The dividend is zero. */
            if (b == 0)
                cout << "Divided by zero!" << endl;
            else
                cout << a / b << endl;
            break;
        /* Other invalid operations. */
        default: cout << "Invalid operator!" << endl; break;
    }
    return 0;
}
```

### 三角形判断

```cpp
#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    /* The summation of any two sides of a
         triangle is greater than the third. */
    if (a + b > c
        && a + c > b
        && b + c > a)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}
```

### 输出绝对值

```cpp
#include <cstdio>

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
```

