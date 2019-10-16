#include <iostream>
using namespace std;

bool check(int n)
{
	return n % 3 == 0 || n / 10 == 3 || n % 10 == 3;
}

int main()
{
	int n;
	while (cin >> n)
		cout << (check(n) ? "TRUE" : "FALSE") << endl;
	return 0;
}