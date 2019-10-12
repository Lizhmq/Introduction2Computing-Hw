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
