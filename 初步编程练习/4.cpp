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
