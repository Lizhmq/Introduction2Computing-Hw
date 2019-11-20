#include <iostream>
using namespace std;

int func(int n)
{
	return n <= 1 ? 1 : func(n - 1) + func(n - 2);
}

int main()
{
	int n;
	cin >> n;
	cout << func(n) << endl;
	return 0;
}