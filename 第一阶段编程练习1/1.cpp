/*****
 * 描述
小袁同学今年刚毕业，成为了一名光荣的程序员。他找了一份工作，年薪是X万元，并且公司保证每年给他固定加薪8%。 小袁同学很开心，他看上了一套房子，售价是M万元，于是下决心攒钱买下。假设房子的价格每年稳定上涨10%，再假设小袁不吃不喝，把所有的钱都存下来买房。
那么请你帮他算算，他多少年后可以买的起这套房子？
如果100年内(含100年) 都不可能的话，则输出“Forget it.”
 * 关于输入
一共有2行。
第一行是一个整数X，表示小袁同学的初始年薪；
第二行是一个整数M，表示房子的售价。
 * 关于输出
如果有解，输出一个整数N，表示第N年小袁可以攒够钱买房子；
如果解大于100或者无解，则输出“Forget it.”
*****/

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