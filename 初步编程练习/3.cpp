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
